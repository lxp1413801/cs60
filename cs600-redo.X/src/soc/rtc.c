#include "stdint.h"
#include <xc.h>
#include "p18f86j93.h"
#include "rtc.h"
#include "../app/event.h"
st_RtcDef glRtc;
uint8_t defalutRtc[]={0x17,0x07,0x31,0x23,0x55,0x55,0x02};

void rtcc_reg_wr_enable(void)
{
    asm("movlw 0x55");
    asm("movwf EECON2");
    asm("movlw 0xAA");
    asm("movwf EECON2");
    asm("bsf RTCCFG,5,1");    
}
void rtcc_reg_wr_disable(void)
{
    asm("movlw 0x55");
    asm("movwf EECON2");
    asm("movlw 0xAA");
    asm("movwf EECON2");    
    asm("bcf RTCCFG,5,1");   
}
void rtc_init(void)
{
	PADCFG1bits.RTSECSEL1=0;
	PADCFG1bits.RTSECSEL0=1;
	RTCCFGbits.RTCOE=0;

	ALRMRPT=0xff;

	ALRMCFGbits.ALRMEN=1;
	ALRMCFGbits.CHIME=1;
	ALRMCFGbits.AMASK=0;

	__nop();
	rtcc_reg_wr_enable();
	//
	RTCCFGbits.RTCEN=1;
	//rtcc_enable();
	rtcc_reg_wr_disable();       
	__nop();
	//enable rtc interrupt;
	//IPR3bits.RTCCIP=0;
	IPR3bits.RTCCIP=1;
	PIR3bits.RTCCIF=0;
	PIE3bits.RTCCIE=1;
	//T1CON
	T1CONbits.T1OSCEN=1;  
	__nop();
}

void rtc_set(uint8_t* rtc)
{
	st_RtcDef* stp;
	stp=(st_RtcDef*)rtc;
	rtcc_reg_wr_enable();
    
	stRTCCFGbits.RTCPTR=0;//read minute
    RTCVALL=stp->second;
	RTCVALH=stp->minute;
	stRTCCFGbits.RTCPTR=1;//read day
    RTCVALL=stp->hour;
	RTCVALH=stp->day;
	stRTCCFGbits.RTCPTR=2;//read month
    RTCVALL=stp->date;
	RTCVALH=stp->month;
	stRTCCFGbits.RTCPTR=3;//read  year
	RTCVALL=stp->year;
	rtcc_reg_wr_disable();	
}

void rtc_get(void)
{
    uint8_t t8;
	stRTCCFGbits.RTCPTR=3;//read  year
    glRtc.year=RTCVALL;
	//glRtc.year=RTCVALH;
	t8=RTCVALH;
 	stRTCCFGbits.RTCPTR=2;//read month
	glRtc.date=RTCVALL;       
	glRtc.month=RTCVALH;
  	stRTCCFGbits.RTCPTR=1;//read day
 	glRtc.hour=RTCVALL;   
	glRtc.day=RTCVALH;
 	stRTCCFGbits.RTCPTR=0;//read minute
 	glRtc.second=RTCVALL;      
	glRtc.minute=RTCVALH;
	//rtcc_reg_wr_disable();
}

void rtc_start(void)
{
	rtcc_enable();
}

void rtc_stop(void)
{
    rtcc_disable();
}

void rtc_alrm_irq_hook(void)
{

}

//file end
