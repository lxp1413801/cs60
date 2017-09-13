//file name :sample.c
#include "../includes/includes.h"

int16_t sampBufDiffPr_D01[FAST_SAMPLE_FREQ/3+2]={0};
int16_t sampBufDiffPr_D23[FAST_SAMPLE_FREQ/3+2]={0};
int16_t sampBufDiffPr_S1;
uint8_t diffSampCount_D01=0;
uint8_t diffSampCount_D23=0;
uint8_t	diffSampCh=0;	

uint8_t diff_pr_sample_fliter(void)
{
	
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
