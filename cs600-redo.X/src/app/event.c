#include "../includes/includes.h"
#include <stdint.h>

volatile uint8_t glNoEventTimeOut=MAX_NO_EVEN_TIME_OUT;

int8_t event_process_rtc(void)
{
	if(dwm==WORK_MODE){
		sample_diff_pr_chip_slow();
	}
	sample_pr_chip_comm();
	sample_in_soc_adc_ch();
	if(glNoEventTimeOut){
		glNoEventTimeOut--;
		if(!glNoEventTimeOut){
			glbEvent |= flg_EVENT_TIME_OUT;
		}
	}
	
	ui_disp_menu();
	return 1;
}

int8_t event_process_ticker(void)
{
	if(dwm!=WORK_MODE){
		sample_diff_pr_chip_fast();
	}
	return 1;
}

int8_t event_process_time_out(void)
{
	if(dwm!=WORK_MODE){
		sample_diff_pr_chip_fast();
	}
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
	if(keyValue!=KEY_VALUE_NONE)key_process();	
	
	return 1;
}
//file end
