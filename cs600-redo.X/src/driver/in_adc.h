#ifndef __in_adc_h__
#define __in_adc_h__

#ifdef __cplusplus
extern "C"{
#endif
    #define in_adc_enable() do{ADCON0bits.ADON=1;}while(0);
    #define in_adc_disable() do{ADCON0bits.ADON=0;}while(0);
    #define in_adc_start()  do{ADCON0bits.GO=1;}while(0);
	#define in_adc_set_ch(ch)	do{ADCON0bits.CHS=ch;}while(0);
	#define in_adc_waite_convert_complete() while(ADCON0bits.DONE){__nop();};
    //define ch
	#define	IN_ADC_CH_BAT			0
	#define IN_ADC_CH_EXT_YALI_2	1
	#define IN_ADC_CH_EXT_YALI_1	2
	#define	IN_ADC_CH_VREF_3V		3
	//
	extern void in_adc_init(void);
    extern uint16_t in_adc_start_and_read(uint8_t ch);

#ifdef __cplusplus
}
#endif

#endif
//file end
