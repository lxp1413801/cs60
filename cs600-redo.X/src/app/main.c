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
        event_process();
    }
}
//file end

