//file name :sample.c
#include "../includes/includes.h"

int16_t sampBufDiffPr_D01[DIFF_SAMPLE_FREQ/3+2]={0};
int16_t sampBufDiffPr_D23[DIFF_SAMPLE_FREQ/3+2]={0};
int16_t sampBufDiffPr_S1;
uint8_t diffSampCount_D01=0;
uint8_t diffSampCount_D23=0;
uint8_t	diffSampCh=0;	
volatile uint16_t fastSampTimer=0;
volatile uint8_t slowSampleTimer=0;

int16_t __x_fliter(int16_t* buf,uint8_t len,uint8_t loop)
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

uint8_t diff_pr_sample_fliter(st_prData* xin)
{
    xin->tAdcValue=__x_fliter(sampBufDiffPr_D01,DIFF_SAMPLE_FREQ/3,4);
    xin->pAdcValue=__x_fliter(sampBufDiffPr_D23,DIFF_SAMPLE_FREQ/3,4);
    xin->pValue=0;
    return 0;
}

uint8_t diff_pr_chip_sample_fast(void)
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
			ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_DIFF_0_1);
			diffSampCh=0;
		}
		//some bug
		ads1115_start_conversion(pAds1115DiffPrObj);
		
		if((diffSampCount_D01 >=  diffSampCount_D23) && (diffSampCount_D01 >= DIFF_SAMPLE_FREQ/3)){
			diff_pr_sample_fliter(&x_prDiffData);
			diffSampCount_D01=diffSampCount_D23=0;
		}
	}
	return ret;
}

uint8_t diff_pr_chip_sample_slow(void)
{
	uint8_t ret=0;
	int16_t t16;	
	slowSampleTimer++;
	if(slowSampleTimer>=60){//one minute
		peripheral_power_enable();
		sensor_power_enable();
		delay_ms(20);
		ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_DIFF_0_1);
		ads1115_start_conversion(pAds1115DiffPrObj);
		delay_ms(20);
		t16=ads1115_read_conversion(pAds1115DiffPrObj);
		if(diffSampCount_D01<DIFF_SAMPLE_FREQ/3){
			sampBufDiffPr_D01[diffSampCount_D01]=t16;
			diffSampCount_D01++;
		}
		ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_DIFF_2_3);
		ads1115_start_conversion(pAds1115DiffPrObj);
		delay_ms(20);
		t16=ads1115_read_conversion(pAds1115DiffPrObj);
		if(diffSampCount_D23<DIFF_SAMPLE_FREQ/3){
			sampBufDiffPr_D23[diffSampCount_D23]=t16;
			diffSampCount_D23++;
		}		
		ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_SINGLE_1);
		ads1115_start_conversion(pAds1115DiffPrObj);
		delay_ms(20);
		t16=ads1115_read_conversion(pAds1115DiffPrObj);
		sampBufDiffPr_S1=t16;
		sensor_power_disable();

		if((diffSampCount_D01 >=  diffSampCount_D23) && (diffSampCount_D01 >= DIFF_SAMPLE_FREQ/3)){
			diff_pr_sample_fliter(&x_prDiffData);
			diffSampCount_D01=diffSampCount_D23=0;
		}	
        return ret;
	}
}
//file end
