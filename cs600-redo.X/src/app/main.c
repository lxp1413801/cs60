#include "../includes/includes.h"

volatile uint8_t glbEvent=0x00;
volatile uint8_t glNoEventTimeOut=MAX_NO_EVEN_TIME_OUT;

int8_t event_process_rtc(void)
{
	uint8_t ret=0;
    //sample_function_enable_fi_in_rtc();
	
	if(glNoEventTimeOut){
		glNoEventTimeOut--;
		if(!glNoEventTimeOut){
			glbEvent |= flg_EVENT_TIME_OUT;
		}
	}		
	//重秒事件进入显示，运行需要闪烁的数位闪烁
	if(lcdTwinkle>0)lcdTwinkle--;
	sys_ticker_stop();
	ui_disp_menu();
	sys_ticker_start();
	return 1;
}

int8_t event_process_ticker(void)
{
	uint8_t ret=0;
	sample_call_in_ticker();
	return ret;
}

int8_t event_process_time_out(void)
{

	return 1;
}
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
    lcd_bl_off();
    //lcd_disp_level(60);
  
    //sensor_power_enable();
	sample_all_power_on();
    
	// while(1)
	// {
		// extern st_iicDeviceObj* pdiff_prEepromObj;
		// extern st_prCalibTabDef diff_prCalibTabDef;
		// at24c02_read_n_byte(pdiff_prEepromObj,0,(uint8_t*)&diff_prCalibTabDef,sizeof(diff_prCalibTabDef));
		// delay_ms(10);
	// }
    __nop();    
    while(1){
        if(glbEvent & flg_EVENT_RTC){
            glbEvent &= ~flg_EVENT_RTC;
            event_process_rtc();
        }
        if(glbEvent & flg_EVENT_TICKER){
            glbEvent &= ~flg_EVENT_TICKER;
            sys_ticker_stop();
            //event_process_ticker();
            sample_call_in_ticker();
            sys_ticker_start();
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

