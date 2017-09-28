#include "../includes/includes.h"
#include <stdint.h>


/*
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
*/
//file end
