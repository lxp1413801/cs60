
#include <xc.h>

// PIC18F86J93 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L

#pragma config WDTEN = OFF      // Watchdog Timer (Disabled-Controlled by SWDTEN bit)
#pragma config STVREN = OFF     // Stack Overflow Reset (Disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Disabled)

// CONFIG1H
#pragma config CP0 = OFF        // Code Protect (Disabled)

// CONFIG2L
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config T1DIG = OFF      // Secondary Clock Source T1OSCEN Enforcement (Secondary Oscillator clock source may not be selected)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 oscillator configured for higher power operation)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Two-Speed Start-up (Internal/External Oscillator Switchover) Control bit (Two-Speed Start-up disabled)

// CONFIG2H
#pragma config WDTPS = 32768    // Watchdog Timer Postscaler Select bits (1:32768)

// CONFIG3L
#pragma config RTCSOSC = T1OSCREF// RTCC Reference Clock Select bit (RTCC uses T1OSC/T1CKI as reference clock)

// CONFIG3H
#pragma config CCP2MX = DEFAULT // CCP2 MUX (RC1)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include "soc.h"
void osc_setup(void)
{
	/*
	OSCCONbits.IRCF = 7;
	// internal osc used 
	*/
	//OSCCONbits.SCS = 2;
	// idle mode enable so that peripherals are
	// clocked with SCS when cpu is sleeping. 
	//OSCCONbits.IDLEN = 1;
	// wait for stable freq 
	//while (!OSCCONbits.IOFS);
    /*
    // SCS FOSC; SPLLEN disabled; IRCF 16MHz_HF; 
    OSCCON = 0x78;
    // TUN 0; 
    OSCTUNE = 0x00;
     */

}

void osc_set_power(em_oscMode oscMode)
{
	switch (oscMode){
		case OSC_PMODE_SLEEP:
			OSCCONbits.IDLEN = 0;
			//__asm sleep __endasm;
            Sleep();
			break;
		case OSC_PMODE_PRI_IDLE:
		case OSC_PMODE_SEC_IDLE:
		case OSC_PMODE_RC_IDLE:
			// assume the current clock 
			OSCCONbits.IDLEN = 1;
			//__asm sleep __endasm;
			Sleep();
			break;
		case OSC_PMODE_PRI_RUN:
		case OSC_PMODE_SEC_RUN:
		case OSC_PMODE_RC_RUN:
		default:
			break;
	}
}
void delay_us(uint16_t dly)
{
    uint16_t i;
    for(i=0;i<dly;i++){
        __nop();
        __nop();
        __nop();
        __nop();
        
        __nop();
        __nop();
        __nop();
        __nop();
    }
}
void delay_ms(uint16_t dly)
{
	while(dly>0){
		delay_us(1000);
		dly--;
	}
}
//file end