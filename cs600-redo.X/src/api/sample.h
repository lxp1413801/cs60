//file name :sample.h
#ifndef __sample_h__
#define __sample_h__

#ifdef __cplusplus
	extern "C"{
#endif
	#include <stdint.h>
	#include <stdbool.h>
	#include <float.h>

	#define DIFF_SAMPLE_FREQ	20
	extern volatile int16_t sampBufDiffPr_S1;	//内部pt100的值
	#define adcValueIn	sampBufDiffPr_S1
	extern volatile  uint16_t fastSampTimer;		//快速采样定时器
	extern volatile  uint16_t commonSampTimer;		//普通速度采样定时器
	extern volatile  uint16_t lowSampTimer;			//慢速采样定时器
	
	extern bool diffPrSampleUpdate;
	extern bool in_pt100SampleUpdate;
	
	extern bool prSampleUpdate;
	extern bool ex_pt100SampleUpdate;
	
	extern bool inSocAdcSampleUpdate;
    
	
	extern uint8_t sample_fast(void);	
	extern uint8_t sample_common(void);
	extern uint8_t sample_low(void);
	
	extern void hook_sample_fast_timer(void);
	//extern 
	

#ifdef __cplusplus
	}
#endif


#endif
//file end
