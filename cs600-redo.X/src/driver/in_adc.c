#include <stdint.h>
#include <xc.h>
//#include <pic18f86j93.h>
#include "p18f86j93.h"
#include "m_gpio.h"
#include "in_adc.h"
#include "../soc/clock.h"

void in_adc_init(void)
{
    ADCON1=0b00001101;//ain0~ain3
    ADCON2bits.ADFM=1;
    ADCON2bits.ACQT=0x07;
    ADCON2bits.ADCS=0x07;
    ADCON0bits.ADCAL=1;
    in_adc_set_ch(IN_ADC_CH_VREF_3V);
    PIR1bits.ADIF=0;
    PIE1bits.ADIE=0;
    IPR1bits.ADIP=0;
}
uint16_t in_adc_start_and_read(uint8_t ch)
{
    uint16_t ret=0;
    in_adc_enable();
    in_adc_set_ch(ch);
    delay_us(2);
    in_adc_start();
	in_adc_waite_convert_complete();
	
    ret=ADRESH;
    ret<<=8;
    ret |= ADRESL;
    delay_us(2);
    in_adc_disable();
    return ret;
}
