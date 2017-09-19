#include "../includes/includes.h"
#include <stdint.h>

volatile uint8_t glNoEventTimeOut=MAX_NO_EVEN_TIME_OUT;

int8_t event_process_rtc(void)
{
	uint8_t ret=0;
    sample_function_enable_fi_in_rtc();
	
	if(glNoEventTimeOut){
		glNoEventTimeOut--;
		if(!glNoEventTimeOut){
			glbEvent |= flg_EVENT_TIME_OUT;
		}
	}		
	//重秒事件进入显示，运行需要闪烁的数位闪烁
	if(lcdTwinkle>0)lcdTwinkle--;
	ui_disp_menu();
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
int8_t event_process(void)
{
	if(glbEvent & flg_EVENT_RTC){
		glbEvent &= ~flg_EVENT_RTC;
		//ui_disp_rtc_mm_ss();
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
	
	return 1;
}
//file end
