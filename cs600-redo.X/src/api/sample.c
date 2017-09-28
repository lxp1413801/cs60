//file name :sample.c
#include "../includes/includes.h"

volatile uint16_t diffPrChipSampleTimer=0;
volatile uint8_t diffPrChipSampleCount=0;
volatile uint8_t diffPrChipSampCh=0;
#define pr_DIFF_CHIP_SAMPLE_BUF_LEN 4
int16_t sampBufDiffPr_D01[pr_DIFF_CHIP_SAMPLE_BUF_LEN]={0};
int16_t sampBufDiffPr_D23[pr_DIFF_CHIP_SAMPLE_BUF_LEN]={0};
int16_t sampBufDiffPr_S1[pr_DIFF_CHIP_SAMPLE_BUF_LEN]={0};
bool diffPrChipSampleFinish=false;
//bool diffPrChipcalFinish=false;

volatile uint16_t PrChipSampleTimer=0;
volatile uint8_t prChipSampleCh=0;
volatile uint8_t prChipSampleCount=0;
#define pr_CHIP_SAMPLE_BUF_LEN 4
int16_t	sampBufPt100ExA[pr_CHIP_SAMPLE_BUF_LEN]={0};
int16_t	sampBufPt100ExB[pr_CHIP_SAMPLE_BUF_LEN]={0};
int16_t	sampBufPr[pr_CHIP_SAMPLE_BUF_LEN]={0};

bool PrChipSampleFinish=false;
//bool PrChipCalFinish=false;

volatile uint16_t inSocAdcSampleTimer=0;
volatile uint8_t inSocAdcSampleCount=0;
volatile uint8_t inSocAdcSampleCh=0;
#define IN_SOC_ADC_SAMPLE_BUF_LEN 4
uint16_t sampBufExPr0InSoc[IN_SOC_ADC_SAMPLE_BUF_LEN]={0};
uint16_t sampBufExPr1InSoc[IN_SOC_ADC_SAMPLE_BUF_LEN]={0};
uint16_t sampBufBatInSoc[IN_SOC_ADC_SAMPLE_BUF_LEN]={0};
uint16_t sampBufRefInSoc[IN_SOC_ADC_SAMPLE_BUF_LEN]={0};

bool inSocAdcSampleFinish=false;
//bool inSocAdcCalFinish=false;


volatile bool sensorSimpleEn=false;
volatile uint8_t sensorSimpleTsLong=0;
volatile bool sensorPowerOn=false;

int16_t __x_sample_fliter(int16_t* buf,uint8_t len,uint8_t loop)
{
	int16_t max,min;
	uint8_t i,maxLoc,minLoc;
	int32_t t32=0;
	if(len<3)return 0;
	while(loop>0){
		min=max=buf[0];
		t32=0;
		for(i=0;i<len;i++){
			if(min>buf[i]){min=buf[i];minLoc=i;}
			if(max<buf[i]){max=buf[i];maxLoc=i;}
			t32+=buf[i];
		}
		//t32-=(max+min);
        t32=t32-(int32_t)max;
        t32=t32-(int32_t)min;
		t32=t32/(len-2);
		buf[minLoc]=(int16_t)t32;
		buf[maxLoc]=(int16_t)t32;
		loop--;
	}
	return (int16_t)t32;
}

int16_t __x_sample_fifo(int16_t* buf,int16_t x,uint8_t len)
{
	int32_t ret=0;
	uint8_t i;
	for(i=len-1;i>0;i--){
		buf[i]=buf[i-1];
		ret+=buf[i];
	}
	buf[i]=x;
	ret+=x;
	ret/=len;
	return (int16_t)(ret);
}
uint8_t sample_diff_pr_fliter(st_prData* xin)
{
    xin->tAdcValue=__x_sample_fliter(sampBufDiffPr_D01,pr_DIFF_CHIP_SAMPLE_BUF_LEN,4);
    xin->pAdcValue=__x_sample_fliter(sampBufDiffPr_D23,pr_DIFF_CHIP_SAMPLE_BUF_LEN,4);
    xin->pValue=0;
    return 0;
}

void sample_all_power_on(void)
{
	if(!sensorPowerOn){
		peripheral_power_enable();
		sensor_power_enable();
		sensorPowerOn=true;
	}
}

void sample_all_power_off(void)
{
	peripheral_power_disable();
	sensor_power_disable();
	sensorPowerOn=false;
}

void sample_variable_init(void)
{
	diffPrChipSampleTimer=0;
	diffPrChipSampleCount=0;
	diffPrChipSampCh=0;	

	PrChipSampleTimer=0;
	prChipSampleCh=0;
	prChipSampleCount=0;

	inSocAdcSampleTimer=0;
	inSocAdcSampleCount=0;
	inSocAdcSampleCh=0;
	
	diffPrChipSampleFinish=false;
	PrChipSampleFinish=false;
	inSocAdcSampleFinish=false;	
}

uint8_t sample_call_cal_diff_pr(void)
{
	if(!diffPrChipSampleFinish)return 0;
	cal_diff_press();
	//cal_pt100_temperature_in();
	diffPrChipSampleFinish=false;
	return 1;
}
uint8_t sample_call_cal_pr(void)
{
	if(!PrChipSampleFinish)return 0;
	//cal_press();
	//cal_pt100_temperature_ex();
	PrChipSampleFinish=false;
	return 1;
}
uint8_t sample_call_cal_in_soc(void)
{
	if(!inSocAdcSampleFinish)return 0;
	//cal_additional_pressute(0);
	//cal_additional_pressute(1);	
	inSocAdcSampleFinish=false;
	return 1;
}
//采样调用函数在ticker事件中调用
void sample_call_in_ticker(void)
{
	uint8_t ret=0;
	if(!sensorSimpleEn)return;
	if(dwm!=WORK_MODE){
		if(sample_call_cal_diff_pr())return;
		//if(sample_call_cal_pr())return;
		//if(sample_call_cal_in_soc())return;
	}	
	if(sample_diff_pr_chip_fast())return;
	if(sample_pr_chip_fast())return;
	if(sample_in_soc_adc_ch())return;
}
//!!!在rtc秒事件中调用!!!
void sample_function_enable_fi_in_rtc(void)
{
	uint8_t ret=0;
	//正常工作模式，间隙采样模式
	if(dwm==WORK_MODE){
		if(sensorSimpleEn){
			if(diffPrChipSampleFinish && PrChipSampleFinish && inSocAdcSampleFinish){
				//采样完成
				sensorSimpleEn=false;
				sample_all_power_off();	
				sensorSimpleTsLong=0;
			}
		}else{
			if(diffPrChipSampleFinish || PrChipSampleFinish || inSocAdcSampleFinish){
				//采样完成等待理算
				if(diffPrChipSampleFinish)ret=sample_call_cal_diff_pr();
				if(!ret && PrChipSampleFinish)ret=sample_call_cal_pr();
				if(!ret && inSocAdcSampleFinish)ret=sample_call_cal_in_soc();				
			}else if(sensorSimpleTsLong>=SENSEOR_SLEEP_TIME_s*2){
				//休眠时间到准备采样
				sensorSimpleEn=true;
				sample_all_power_on();	
				sample_variable_init();				
			}else{
				//睡眠
				sensorSimpleTsLong++;
			}
		}
	}else{
		sensorSimpleEn=true;
		sample_all_power_on();
		sensorSimpleTsLong=0;
	}
}

uint8_t sample_diff_pr_chip_fast(void)
{
	int16_t t16;
	diffPrChipSampleTimer+=(1000/TICKER_FREQUENCY_Hz);
	if(diffPrChipSampleTimer<DIFF_PRESSURE_CHIP_SAMPLE_TS)return 0;
	diffPrChipSampleTimer=0;
	if(diffPrChipSampleCount==0){
		//diffPrChipSampCh=ADS1X1X_MUX_DIFF_0_1;
		diffPrChipSampCh=ADS1X1X_MUX_DIFF_0_1;
		ads1115_set_data_rate(pAds1115DiffPrObj,ADS1X1X_DATA_RATE_32);
		ads1115_set_mux(pAds1115DiffPrObj,diffPrChipSampCh);
		ads1115_set_pga(pAds1115DiffPrObj,ADS1X1X_PGA_6144);
		ads1115_start_conversion(pAds1115DiffPrObj);	
		diffPrChipSampleCount=1;
		return 1;
	}
	t16=ads1115_read_conversion(pAds1115DiffPrObj);
	if(diffPrChipSampCh==ADS1X1X_MUX_DIFF_0_1){
		__x_sample_fifo(sampBufDiffPr_D01,t16,pr_DIFF_CHIP_SAMPLE_BUF_LEN);
		diffPrChipSampCh=ADS1X1X_MUX_DIFF_2_3;
		ads1115_set_pga(pAds1115DiffPrObj,ADS1X1X_PGA_256);
	}else if(diffPrChipSampCh==ADS1X1X_MUX_DIFF_2_3){
		__x_sample_fifo(sampBufDiffPr_D23,t16,pr_DIFF_CHIP_SAMPLE_BUF_LEN);
		diffPrChipSampCh=ADS1X1X_MUX_SINGLE_1;
		ads1115_set_pga(pAds1115DiffPrObj,ADS1X1X_PGA_512);
	}else if(diffPrChipSampCh==ADS1X1X_MUX_SINGLE_1){
		adc_inPt100=__x_sample_fifo(sampBufDiffPr_S1,t16,pr_DIFF_CHIP_SAMPLE_BUF_LEN);
		diffPrChipSampCh=ADS1X1X_MUX_DIFF_0_1;
		ads1115_set_pga(pAds1115DiffPrObj,ADS1X1X_PGA_6144);
		diffPrChipSampleCount++;
	}else{
		ads1115_set_pga(pAds1115DiffPrObj,ADS1X1X_PGA_6144);
		diffPrChipSampCh=ADS1X1X_MUX_DIFF_0_1;
	}
	ads1115_set_data_rate(pAds1115DiffPrObj,ADS1X1X_DATA_RATE_32);
	ads1115_set_mux(pAds1115DiffPrObj,diffPrChipSampCh);
	ads1115_start_conversion(pAds1115DiffPrObj);
	if(diffPrChipSampleCount>pr_DIFF_CHIP_SAMPLE_BUF_LEN){
		sample_diff_pr_fliter(&x_prDiffData);
		diffPrChipSampleFinish=true;
		diffPrChipSampleCount=0;
	}
	return 1;
}

uint8_t sample_pr_chip_fast(void)
{
    uint8_t ret=0;
    uint16_t t16;
    PrChipSampleTimer+=(1000/TICKER_FREQUENCY_Hz);
	if(PrChipSampleTimer<PRESSURE_CHIP_SAMPLE_TS)return 0;
	PrChipSampleTimer=0;
	if(prChipSampleCount==0){
		prChipSampleCh=ADS1X1X_MUX_SINGLE_0;
		ads1115_set_mux(pAds1115PrObj,prChipSampleCh);
		ads1115_start_conversion(pAds1115PrObj);
		prChipSampleCount++;
		return 1;
	}
	
	t16=ads1115_read_conversion(pAds1115PrObj);
	if(prChipSampleCh==ADS1X1X_MUX_SINGLE_0){
		adc_exPt100=__x_sample_fifo(sampBufPt100ExA,t16,pr_CHIP_SAMPLE_BUF_LEN);
		prChipSampleCh=ADS1X1X_MUX_SINGLE_1;
	}else if(prChipSampleCh==ADS1X1X_MUX_SINGLE_1){
		t16=__x_sample_fifo(sampBufPt100ExB,t16,pr_CHIP_SAMPLE_BUF_LEN);
		t16*=2;
		adc_exPt100-=t16;
		prChipSampleCh=ADS1X1X_MUX_DIFF_2_3;	
	}else if(prChipSampleCh==ADS1X1X_MUX_DIFF_2_3){
		adc_pressure=__x_sample_fifo(sampBufPr,t16,pr_CHIP_SAMPLE_BUF_LEN);
		prChipSampleCh=ADS1X1X_MUX_SINGLE_0;
		prChipSampleCount++;
	}else{
		prChipSampleCh=ADS1X1X_MUX_SINGLE_0;			
	}
	
	ads1115_set_mux(pAds1115PrObj,prChipSampleCh);	
	ads1115_start_conversion(pAds1115PrObj);
	if(prChipSampleCount>pr_CHIP_SAMPLE_BUF_LEN){
		PrChipSampleFinish=true;
		prChipSampleCount=0;
	}
	return 1;
}

uint8_t sample_in_soc_adc_ch(void)
{
	uint16_t t16;
	inSocAdcSampleTimer+=(1000/TICKER_FREQUENCY_Hz);
	if(inSocAdcSampleTimer<IN_SOC_ADC_SAMPLE_TS)return 0;
	inSocAdcSampleTimer=0;
	if(inSocAdcSampleCount==0){
		in_adc_init();
		inSocAdcSampleCh=IN_ADC_CH_EXT_YALI_1;
		inSocAdcSampleCount=1;
		return 1;
	}
	if(inSocAdcSampleCh==IN_ADC_CH_EXT_YALI_1){
		t16=in_adc_start_and_read(inSocAdcSampleCh);
		adc_iPrEx[0]=__x_sample_fifo((int16_t*)sampBufExPr0InSoc,t16,IN_SOC_ADC_SAMPLE_BUF_LEN);
		inSocAdcSampleCh=IN_ADC_CH_EXT_YALI_2;
	}else if(inSocAdcSampleCh==IN_ADC_CH_EXT_YALI_2){
		t16=in_adc_start_and_read(inSocAdcSampleCh);
		adc_iPrEx[1]=__x_sample_fifo((int16_t*)sampBufExPr1InSoc,t16,IN_SOC_ADC_SAMPLE_BUF_LEN);
		inSocAdcSampleCh=IN_ADC_CH_BAT;
	}else if(inSocAdcSampleCh==IN_ADC_CH_BAT){
		t16=in_adc_start_and_read(inSocAdcSampleCh);
		__x_sample_fifo((int16_t*)sampBufBatInSoc,t16,IN_SOC_ADC_SAMPLE_BUF_LEN);
		inSocAdcSampleCh=IN_ADC_CH_VREF_3V;
	}else if(inSocAdcSampleCh==IN_ADC_CH_VREF_3V){
		t16=in_adc_start_and_read(inSocAdcSampleCh);
		__x_sample_fifo((int16_t*)sampBufRefInSoc,t16,IN_SOC_ADC_SAMPLE_BUF_LEN);
		inSocAdcSampleCh=IN_ADC_CH_EXT_YALI_1;
		inSocAdcSampleCount++;
	}else{
		inSocAdcSampleCh=IN_ADC_CH_EXT_YALI_1;
	}
	if(inSocAdcSampleCount>IN_SOC_ADC_SAMPLE_BUF_LEN){
		inSocAdcSampleFinish=true;
        inSocAdcSampleCount=0;
	}
	return 1;	
}

//file end
