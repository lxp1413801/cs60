//file name :sample.c
#include "../includes/includes.h"

int16_t sampBufDiffPr_D01[FAST_SAMPLE_FREQ/3+2]={0};
int16_t sampBufDiffPr_D23[FAST_SAMPLE_FREQ/3+2]={0};
int16_t sampBufDiffPr_S1;
uint8_t diffSampCount_D01=0;
uint8_t diffSampCount_D23=0;
uint8_t	diffSampCh=0;	

int16_t __x_fliter(int16_t* buf,uint8_t len,uint8_t loop)
{
	int16_t max,min;
	uint8_t i,maxLoc,minLoc;
	int32_t t32=0;
	if(len<3)return 0;
	while(loop>0){
		max=-32768;
		min=32767;
		t32=0;		
		for(i=0;i<len;i++;){
			if(min>buf[i]){min=buf[i];minLoc=i;}
			if(max<buf[i]){max=buf[i];maxLoc=i;}
			t32+=buf[i];
		}
		t32-=(max+min);
		t32=t32/(len-2);
		buf[minLoc]=t32;
		buf[maxLoc]=t32;
		loop--;
	}
	return (int16_t)t32;
}

uint8_t diff_pr_sample_fliter(void)
{
	int16_t max,min;
	uint8_t i,loop,maxLoc,minLoc;
	int32_t t32=0;
	int16_t t16;
	for(loop=0;loop<4;loop++){
		max=-32768;
		min=32767;
		t32=0;		
		for(i=0;i<FAST_SAMPLE_FREQ/3;i++;){
			if(min>sampBufDiffPr_D01[i]){min=sampBufDiffPr_D01[i];minLoc=i;}
			if(max<sampBufDiffPr_D01[i]){max=sampBufDiffPr_D01[i];maxLoc=i;}
			t32+=sampBufDiffPr_D01[i];
		}
		t32-=(max+min);
		t32=t32/(FAST_SAMPLE_FREQ/3-2);
		sampBufDiffPr_D01[minLoc]=t32;
		sampBufDiffPr_D01[maxLoc]=t32;
	}
}

uint8_t diff_pr_chip_sample_fast(void)
{
	uint8_t ret=0;
	int16_t t16;
	fastSampTimer+=TICKER_FREQUENCY_Hz;
	if(fastSampTimer>(1000/FAST_SAMPLE_FREQ)){
		fastSampTimer=0;
		t16=ads1115_read_conversion(pAds1115DiffPrObj);
		if(diffSampCh==0){
			sampBufDiffPr_D01[diffSampCount_D01]=t16;
			diffSampCount_D01++;
			ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_DIFF_2_3);
			diffSampCh=1;
		}else if(diffSampCh==1){
			sampBufDiffPr_D23[diffSampCount_D23]=t16;
			diffSampCount_D23++;
			ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_SINGLE_1);
			diffSampCh=2;
		}else{
			sampBufDiffPr_S1=t16;
			ads1115_set_mux(pAds1115DiffPrObj,ADS1X1X_MUX_DIFF_0_1);
			diffSampCh=0;
		}

		ads1115_start_conversion(pAds1115DiffPrObj);
		if((sampBufDiffPr_D23 =  sampBufDiffPr_D01) && (sampBufDiffPr_D01>=FAST_SAMPLE_FREQ/3)){
			diff_pr_sample_fliter();
		}
	}
	return ret;
}
//file end
