#ifndef __rtc_h__
#define __rtc_h__

#ifdef __cplusplus
extern "C"{
#endif
#include <stdint.h>
#include "p18f86j93.h"

#define rtcc_enable() 			do{RTCCFGbits.RTCEN=1;}while(0);
#define rtcc_disable() 			do{RTCCFGbits.RTCEN=0;}while(0);
    
typedef union {
    uint8_t data;
    struct {
        uint8_t RTCPTR                   :2;
        uint8_t                          :6;
    };
} st_RTCCFGbits_t;
extern volatile st_RTCCFGbits_t stRTCCFGbits @ 0xF5F;
typedef struct
{
	uint8_t year;
	uint8_t month;
	uint8_t date;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
	uint8_t day;
}st_RtcDef,*pst_RtcDef;

extern uint8_t defalutRtc[];
//uint8_t  defalutRtc[]={0x17,0x07,0x11,0x12,0x00,0x00,0x02};
extern st_RtcDef glRtc;
extern void rtc_init(void);
extern void rtc_set(uint8_t* rtc);
extern void rtc_get(void);
extern void rtc_start(void);
extern void rtc_stop(void);

extern void rtc_alrm_irq_hook(void);

#ifdef __cplusplus
}
#endif

#endif
//file end
