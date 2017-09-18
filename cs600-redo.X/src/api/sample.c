//file name :sample.c
#include "../includes/includes.h"

int16_t sampBufDiffPr_D01[DIFF_SAMPLE_FREQ/3+2]={0};
int16_t sampBufDiffPr_D23[DIFF_SAMPLE_FREQ/3+2]={0};

volatile int16_t sampBufDiffPr_S1;

uint8_t diffSampCount_D01=0;
uint8_t diffSampCount_D23=0;
uint8_t	diffSampCh=0;	

bool diffPrSampleUpdate=false;
bool in_pt100SampleUpdate=false;

int16_t	sampBufPt100ExA[4]={0};
int16_t	sampBufPt100ExB[4]={0};
int16_t	sampBufPr[4]={0};


bool ex_pt100SampleUpdate=false;
bool prSampleUpdate=false;

uint16_t sampBufExPr0InSoc;
uint16_t sampBufExPr1InSoc;
uint16_t sampBufBatInSoc;
uint16_t sampBufRefInSoc;

bool inSocAdcSampleUpdate=false;

volatile uint16_t fastSampTimer=0;
volatile uint8_t slowSampleTimer=0;
volatile uint8_t commonSampleTimer=0;
volatile uint8_t inSocSampleTimer=0;

volatile bool diffPrChipFastSampleEn=false;

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
		t32-=(max+min);
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
    xin->tAdcValue=__x_sample_fliter(sampBufDiffPr_D01,DIFF_SAMPLE_FREQ/3,4);
    xin->pAdcValue=__x_sample_fliter(sampBufDiffPr_D23,DIFF_SAMPLE_FREQ/3,4);
    xin->pValue=0;
    return 0;
}

uint8_t sample_diff_pr_chip_fast(void)
{
	uint8_t ret=0;
	int16_t t16;
	fastSampTimer+=TICKER_FREQUENCY_Hz;
	if(fastSampTimer>(1000/DIFF_SAMPLE_FREQ)){
		fastSampTimer=0;
		t16=ads1115_read_conversion(pAds1115DiffPrObj);
		if(diffSampCh==0){
			if(diffSampCount_D01<DIFF_SAMPLE_FREQ/3){
				sampBufDiffPr_D01[diffSampCount_D01]=t16;
				diffSampCount_D01++;
			}
			ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_DIFF_2_3);
			diffSampCh=1;
		}else if(diffSampCh==1){
			if(diffSampCount_D23<DIFF_SAMPLE_FREQ/3){
				sampBufDiffPr_D23[diffSampCount_D23]=t16;
				diffSampCount_D23++;
			}
			ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_SINGLE_1);
			diffSampCh=2;
		}else{
			sampBufDiffPr_S1=t16;
			adc_inPt100=t16;
			ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_DIFF_0_1);
			diffSampCh=0;
		}
		//some bug
		ads1115_start_conversion(pAds1115DiffPrObj);
		
		if((diffSampCount_D01 >=  diffSampCount_D23) && (diffSampCount_D01 >= DIFF_SAMPLE_FREQ/3)){
			sample_diff_pr_fliter(&x_prDiffData);
			diffSampCount_D01=diffSampCount_D23=0;
			diffPrSampleUpdate=true;
			
			in_pt100SampleUpdate=true;
			
		}
        return 1;
	}
	return 0;
}

/*
#define SLOW_SAMPLE_USED_FIFO_EN 1 
uint8_t sample_diff_pr_chip_slow(void)
{
	uint8_t ret=0;
	int16_t t16;	
	slowSampleTimer++;
	if(slowSampleTimer>=60){//one minute
		slowSampleTimer=0;
		peripheral_power_enable();
		sensor_power_enable();
		delay_ms(20);
		ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_DIFF_0_1);
		ads1115_start_conversion(pAds1115DiffPrObj);
		delay_ms(20);
		t16=ads1115_read_conversion(pAds1115DiffPrObj);
		//
		#if SLOW_SAMPLE_USED_FIFO_EN
		__x_sample_fifo(sampBufDiffPr_D01,t16,sizeof(sampBufDiffPr_D01)/sizeof(sampBufDiffPr_D01[0]));
		#else
		if(diffSampCount_D01<DIFF_SAMPLE_FREQ/3){
			sampBufDiffPr_D01[diffSampCount_D01]=t16;
			diffSampCount_D01++;
		}
		#endif
		ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_DIFF_2_3);
		ads1115_start_conversion(pAds1115DiffPrObj);
		delay_ms(20);
		t16=ads1115_read_conversion(pAds1115DiffPrObj);
		#if SLOW_SAMPLE_USED_FIFO_EN
		__x_sample_fifo(sampBufDiffPr_D23,t16,sizeof(sampBufDiffPr_D23)/sizeof(sampBufDiffPr_D23[0]));
		#else
		if(diffSampCount_D23<DIFF_SAMPLE_FREQ/3){
			sampBufDiffPr_D23[diffSampCount_D23]=t16;
			diffSampCount_D23++;
		}
		#endif
		ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_SINGLE_1);
		ads1115_start_conversion(pAds1115DiffPrObj);
		delay_ms(20);
		t16=ads1115_read_conversion(pAds1115DiffPrObj);
		sampBufDiffPr_S1=t16;
		sensor_power_disable();

		if((diffSampCount_D01 >=  diffSampCount_D23) && (diffSampCount_D01 >= DIFF_SAMPLE_FREQ/3)){
			sample_diff_pr_fliter(&x_prDiffData);
			#if !(SLOW_SAMPLE_USED_FIFO_EN) 
			diffSampCount_D01=diffSampCount_D23=0;
			#endif
			diffPrSampleUpdate=true;
		}			
        return 1;
	}
	return 0;
}
*/
uint8_t sample_diff_pr_chip_slow(void)
{
	slowSampleTimer++;
	if(slowSampleTimer>=60){//one minute
		slowSampleTimer=0;
		peripheral_power_enable();
		sensor_power_enable();
		diffPrChipFastSampleEn=true;
	}
	return 1;
}
uint8_t sample_pr_chip_comm(void)
{
	uint8_t ret=0;
	int16_t t16;	
	commonSampleTimer++;
	if(commonSampleTimer>=60){//one minute
		commonSampleTimer=0;
		peripheral_power_enable();
		sensor_power_enable();
		delay_ms(20);
		ads1115_set_mux(pAds1115PrObj,ADS1X1X_MUX_SINGLE_0);
		ads1115_start_conversion(pAds1115PrObj);
		delay_ms(20);
		t16=ads1115_read_conversion(pAds1115PrObj);
		adc_exPt100=__x_sample_fifo(sampBufPt100ExA,t16,sizeof(sampBufPt100ExA)/sizeof(int16_t));
		
		
		ads1115_set_mux(pAds1115PrObj,ADS1X1X_MUX_SINGLE_0);
		ads1115_start_conversion(pAds1115PrObj);
		delay_ms(20);
		t16=ads1115_read_conversion(pAds1115PrObj);
		t16=__x_sample_fifo(sampBufPt100ExB,t16,sizeof(sampBufPt100ExB)/sizeof(int16_t));
		adc_exPt100=adc_exPt100-t16-t16;
		ex_pt100SampleUpdate=true;
		
		ads1115_set_mux(pAds1115PrObj,ADS1X1X_MUX_DIFF_2_3);
		ads1115_start_conversion(pAds1115PrObj);
		delay_ms(20);
		t16=ads1115_read_conversion(pAds1115PrObj);
		adc_pressure=__x_sample_fifo(sampBufPr,t16,sizeof(sampBufPr)/sizeof(int16_t));
		prSampleUpdate=true;
		
		sensor_power_disable();
		peripheral_power_disable();
        return 1;
	}
	return 0;
}
#define IN_SOC_ADC_SAMPLE_OV 4
uint8_t sample_in_soc_adc_ch(void)
{
	uint8_t i;
	uint16_t t16;	
	uint32_t ret=0;
	inSocSampleTimer++;
	if(inSocSampleTimer>=60){
		inSocSampleTimer=0;
		
		in_adc_init();
		ret=0;
		for(i=0;i<IN_SOC_ADC_SAMPLE_OV;i++){
			t16=in_adc_start_and_read(IN_ADC_CH_EXT_YALI_1);
			ret+=t16;
		}
		adc_iPrEx[0]=(uint16_t)(ret/IN_SOC_ADC_SAMPLE_OV);
		
		
		ret=0;
		for(i=0;i<IN_SOC_ADC_SAMPLE_OV;i++){
			t16=in_adc_start_and_read(IN_ADC_CH_EXT_YALI_2);
			ret+=t16;
		}
		adc_iPrEx[1]=(uint16_t)(ret/IN_SOC_ADC_SAMPLE_OV);		
		
		ret=0;
		for(i=0;i<IN_SOC_ADC_SAMPLE_OV;i++){
			t16=in_adc_start_and_read(IN_ADC_CH_BAT);
			ret+=t16;
		}
		sampBufBatInSoc=(uint16_t)(ret/IN_SOC_ADC_SAMPLE_OV);			
		
		ret=0;
		for(i=0;i<IN_SOC_ADC_SAMPLE_OV;i++){
			t16=in_adc_start_and_read(IN_ADC_CH_VREF_3V);
			ret+=t16;
		}
		sampBufRefInSoc=(uint16_t)(ret/IN_SOC_ADC_SAMPLE_OV);	
		inSocAdcSampleUpdate=true;
		return 1;
	}
	return 0;
}

//file end
