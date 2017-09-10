#ifndef __ticker_h__
#define __ticker_h__

#ifdef __cplusplus
extern "C"{
#endif
	#include <stdint.h>
	#define TICKER_FREQUENCY_Hz 100
	//#define TICKER_FREQUENCY_Hz
	//oscFreq/6/
	#define PR2_VALUE	(OSC_FREQ/4/16/16/TICKER_FREQUENCY_Hz)
	extern void sys_ticker_init(void);
	extern void sys_ticker_start(void);
	extern void sys_ticker_stop(void);
	extern volatile uint32_t glTicker;
	extern void sys_ticker_irq_hook(void);
	//
	void ticker_dly(uint16_t ms);
#ifdef __cplusplus
}
#endif

#endif
//file end
