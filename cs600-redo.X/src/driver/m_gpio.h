#ifndef __m_gpio_h__
#define __m_gpio_h__

#ifdef __cplusplus
extern "C"{
#endif
	#include "stdint.h"
	#include <xc.h>
	#include "p18f86j93.h"
    
    //#include <pic18f86j93.h>
    #define GPIO_PIN_DIR_OUT    0
    #define GPIO_PIN_DIR_IN     1

    #define     PIN0    (1<<0)
    #define     PIN1    (1<<1)
    #define     PIN2    (1<<2)
    #define     PIN3    (1<<3)
    #define     PIN4    (1<<4)
    #define     PIN5    (1<<5)
    #define     PIN6    (1<<6)
    #define     PIN7    (1<<7)
    //port a
    #define set_porta_mode_out(pin)     do{TRISA &= ~pin;}while(0);
    #define set_porta_mode_in(pin)      do{TRISA |= pin;}while(0);
    #define set_porta_value_hight(pin)	do{LATA  |= pin;}while(0);
    #define set_porta_value_low(pin)	do{LATA  &= ~pin;}while(0);
    #define get_porta_value(pin)        (PORTA & pin)
    //port b
    #define set_portb_mode_out(pin)		do{TRISB &= ~pin;}while(0);
    #define set_portb_mode_in(pin)		do{TRISB |= pin;}while(0);
    #define set_portb_value_hight(pin)	do{LATB  |= pin;}while(0);
    #define set_portb_value_low(pin)	do{LATB  &= ~pin;}while(0);
    #define get_portb_value(pin)		(PORTB & pin)
    //port c
    #define set_portc_mode_out(pin)		do{TRISC &= ~pin;}while(0);
    #define set_portc_mode_in(pin)		do{TRISC |= pin;}while(0);
    #define set_portc_value_hight(pin)	do{LATC  |= pin;}while(0);
    #define set_portc_value_low(pin)	do{LATC  &= ~pin;}while(0);
    #define get_portc_value(pin)		(PORTC & pin)
    //port d
    #define set_portd_mode_out(pin)		do{TRISD &= ~pin;}while(0);
    #define set_portd_mode_in(pin)		do{TRISD |= pin;}while(0);
    #define set_portd_value_hight(pin)	do{LATD  |= pin;}while(0);
    #define set_portd_value_low(pin)	do{LATD  &= ~pin;}while(0);
    #define get_portd_value(pin)		(PORTD & pin)
    //port e
    #define set_porte_mode_out(pin)		do{TRISE &= ~pin;}while(0);
    #define set_porte_mode_in(pin)		do{TRISE |= pin;}while(0);
    #define set_porte_value_hight(pin)	do{LATE  |= pin;}while(0);
    #define set_porte_value_low(pin)	do{LATE  &= ~pin;}while(0);
    #define get_porte_value(pin)		(PORTE & pin)
    //port f
    #define set_portf_mode_out(pin)		do{TRISF &= ~pin;}while(0);
    #define set_portf_mode_in(pin)		do{TRISF |= pin;}while(0);
    #define set_portf_value_hight(pin)	do{LATF  |= pin;}while(0);
    #define set_portf_value_low(pin)	do{LATF  &= ~pin;}while(0);
    #define get_portf_value(pin)		(PORTF & pin)	
    //port g
    #define set_portg_mode_out(pin)     do{TRISG &= ~pin;}while(0);
    #define set_portg_mode_in(pin)      do{TRISG |= pin;}while(0);
    #define set_portg_value_hight(pin)  do{LATG  |= pin;}while(0);
    #define set_portg_value_low(pin)    do{LATG  &= ~pin;}while(0);
    #define get_portg_value(pin)     PORTG & pin
    //port h
    #define set_porth_mode_out(pin)     do{TRISH &= ~pin;}while(0);
    #define set_porth_mode_in(pin)      do{TRISH |= pin;}while(0);
    #define set_porth_value_hight(pin)  do{LATH  |= pin;}while(0);
    #define set_porth_value_low(pin)    do{LATH  &= ~pin;}while(0);
    #define get_porth_value(pin)     PORTH & pin
    //port j
    #define set_portj_mode_out(pin)     do{TRISJ &= ~pin;}while(0);
    #define set_portj_mode_in(pin)      do{TRISJ |= pin;}while(0);
    #define set_portj_value_hight(pin)  do{LATJ  |= pin;}while(0);
    #define set_portj_value_low(pin)    do{LATJ  &= ~pin;}while(0);
    #define get_portj_value(pin)     PORTJ & pin	
    //rg0
    //#define close_x_power() do{set_portg_mode_out(PIN0);set_portg_value_low(PIN0);}while(0);
    //#define open_x_power()	do{set_portg_mode_out(PIN0);set_portg_value_hight(PIN0);}while(0);
#ifdef __cplusplus
}
#endif

#endif
//file end