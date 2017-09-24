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
	data_init_all();
    in_adc_init();

	ui_disp_start_cs600(4);
    
    //lcd_disp_level(60);
  
    //peripheral_power_enable();
    __nop();    
    while(1){
        if(glbEvent & flg_EVENT_RTC){
            glbEvent &= ~flg_EVENT_RTC;
            event_process_rtc();
        }
        if(glbEvent & flg_EVENT_TICKER){
            glbEvent &= ~flg_EVENT_TICKER;
            event_process_ticker();
        }
        if(glbEvent & flg_EVENT_TIME_OUT){
            glbEvent &= ~flg_EVENT_TIME_OUT;
            event_process_time_out();
        }

        keyValue=key_polling();
        if(keyValue!=KEY_VALUE_NONE){
            key_process();	
        }
    }
}
//file end

