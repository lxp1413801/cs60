//
#include "stdint.h"
#include <stdbool.h>
#include <xc.h>
#include "p18f86j93.h"
#include "clock.h"
//...
#include "ticker.h"
//used timer2
//#define OSC_FREQ 11059200 
volatile uint32_t glTicker=0x00ul;
volatile uint16_t	userTicker_ms=0x00;

extern uint8_t lcdTwinkle;
uint16_t dlyTicker=0;
bool dlyTickerEn=false;

void sys_ticker_start(void)
{
	T2CON=0x7f;
	//T2CONbits.T2OUTPS=0x0f;//16:1
    //T2CONbits.T2CKPS=0x03;//16:1	
}
void sys_ticker_stop(void)
{
    T2CON=0x00;
}

void sys_ticker_init(void)
{
	//T2CON=0x00;
    PR2=(uint8_t)(PR2_VALUE);
    IPR1bits.TMR2IP=1;
	PIR1bits.TMR2IF=0;
	PIE1bits.TMR2IE=1;
	//start timer2;
	T2CON=0x7f;
}

void sys_ticker_irq_hook(void)
{
	if(dlyTickerEn){
		dlyTicker+=10;
	}
	userTicker_ms+=20;

}

void ticker_dly(uint16_t ms)
{
	dlyTicker=0;
	dlyTickerEn=true;
	while(dlyTicker<ms){
		__nop();
	}
	dlyTickerEn=false;
	dlyTicker=0;
}
//file end
