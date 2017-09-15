#ifndef __event_h__
#define __event_h__

#ifdef __cplusplus
extern "C"{
#endif

	#include <stdint.h>
	#define MAX_NO_EVEN_TIME_OUT 30
	extern volatile uint8_t glbEvent;
	extern volatile uint8_t glNoEventTimeOut;
	#define flg_EVENT_TICKER 	(1<<0)
	#define flg_EVENT_RTC 		(1<<1)
	#define flg_EVENT_TIME_OUT	(1<<2)

	extern int8_t event_process(void);

#ifdef __cplusplus
}
#endif

#endif
//file end