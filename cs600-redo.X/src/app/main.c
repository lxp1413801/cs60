#include "../includes/includes.h"

volatile uint8_t glbEvent=0x00;

int main(void)
{
    uint16_t t16;	
    __nop();
	//isInBootLoader=0xaa;
	soc_init();
	rtc_set((st_RtcDef*)defalutRtc);
    lcd_init();
    //m_flash_test();
	ads1115_init_all_chip();	
    //ads1115_set_mux(&ads1115Chip0,ADS1X1X_MUX_DIFF_2_3);
	ads1115_start_conversion(&ads1115Chip0);
    t16=ads1115_read_reg(&ads1115Chip1,ADS1x1x_REG_POINTER_CONFIG);
	ticker_dly(100);
	t16=ads1115_read_conversion(&ads1115Chip0);
    //
    in_adc_init();
    t16=in_adc_start_and_read(IN_ADC_CH_VREF_3V);
	ui_disp_start_cs600(10);
    
    lcd_disp_level(60);
    
    peripheral_power_enable();

    __nop();    
    while(1){
        if(glbEvent & flg_EVENT_RTC){
            glbEvent &= ~flg_EVENT_RTC;
			__nop();
			ui_disp_rtc_mm_ss();
			__nop();
        }
        if(glbEvent & flg_EVENT_TICKER){
			glbEvent &= ~flg_EVENT_TICKER;
			
			__nop();
        }
		keyValue=key_polling();
        if(keyValue!=KEY_VALUE_NONE)key_process();
        
    }
}
