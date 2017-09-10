#ifndef __event_h__
#define __event_h__

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
extern volatile uint8_t glbEvent;
#define flg_EVENT_TICKER 	(0x01)
#define flg_EVENT_RTC 		(0x02)

#ifdef __cplusplus
}
#endif

#endif
//file end