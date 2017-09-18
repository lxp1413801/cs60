//file name :sample.h
#ifndef __sample_h__
#define __sample_h__

#ifdef __cplusplus
	extern "C"{
#endif
	#include <stdint.h>
	#include <stdbool.h>
	#include <float.h>

	#define DIFF_SAMPLE_FREQ				20
    #define DIFF_PRESSURE_CHIP_SAMPLE_TS    100
	
    #define PRESSURE_CHIP_SAMPLE_FREQ 		20
    #define PRESSURE_CHIP_SAMPLE_TS 		100
	
	#define IN_SOC_ADC_SAMPLE_TS			100
	
	#define SENSEOR_SLEEP_TIME_s			30

	extern int16_t sampBufDiffPr_S1[];	//内部pt100的值
	//#define adcValueIn	sampBufDiffPr_S1
	//extern volatile  uint16_t fastSampTimer;		//快速采样定时器
    extern volatile bool diffPrChipFastSampleEn;
	extern volatile uint16_t commonSampTimer;		//普通速度采样定时器
	extern volatile uint16_t lowSampTimer;			//慢速采样定时器
	
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
	//
    extern uint8_t sample_diff_pr_chip_fast(void);
	extern uint8_t sample_pr_chip_fast(void);
	extern uint8_t sample_in_soc_adc_ch(void);
	
	extern void sample_call_in_ticker(void);
	extern void sample_function_enable_fi_in_rtc(void);
	
	extern void sample_variable_init(void);

#ifdef __cplusplus
	}
#endif


#endif
//file end
