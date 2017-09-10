#include "stdint.h"
#include <xc.h>
#include "p18f86j93.h"
#include "int.h"
#include "../app/event.h"
#include "rtc.h"
#include "ticker.h"

void __interrupt(high_priority) handler_interrupt_hight(void)
{
	if(INTCONbits.TMR0IE  && INTCONbits.TMR0IF && INTCON2bits.TMR0IP){
		//TMR0_ISR();
        __nop();
	}
	if(INTCONbits.PEIE  && PIE1bits.TX1IE  && PIR1bits.TX1IF){
		//EUSART1_Transmit_ISR();
	}
	if(INTCONbits.PEIE && PIE1bits.RC1IE  && PIR1bits.RC1IF ){
		//EUSART1_Receive_ISR();
	}
	if(INTCONbits.PEIE  && PIE1bits.TMR1IE  && PIR1bits.TMR1IF ){
		//TMR1_ISR();
	}
    //if(INTCONbits.PEIE && PIE1bits.TMR2IE && PIR1bits.TMR2IF){
	if(PIE1bits.TMR2IE && PIR1bits.TMR2IF && IPR1bits.TMR2IP){
        PIR1bits.TMR2IF=0;
        glTicker++; 
        glbEvent |= flg_EVENT_TICKER; 
		sys_ticker_irq_hook();
    }
	if(PIE3bits.RTCCIE && PIR3bits.RTCCIF && IPR3bits.RTCCIP){
        PIR3bits.RTCCIF=0;
        glbEvent |= flg_EVENT_RTC;   
		rtc_alrm_irq_hook();
	}    
}

void __interrupt(low_priority) handler_interrupt_low(void)
{
	if(PIE1bits.TMR2IE && PIR1bits.TMR2IF && (!IPR1bits.TMR2IP)){
        PIR1bits.TMR2IF=0;
        glTicker++; 
        glbEvent |= flg_EVENT_TICKER; 
		sys_ticker_irq_hook();
    }
	if(PIE3bits.RTCCIE && PIR3bits.RTCCIF && (!(IPR3bits.RTCCIP))){
        PIR3bits.RTCCIF=0;
        glbEvent |= flg_EVENT_RTC;   
		rtc_alrm_irq_hook();
	}    
}
