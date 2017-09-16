#include "../includes/includes.h"
#include <stdint.h>

volatile uint8_t glNoEventTimeOut=MAX_NO_EVEN_TIME_OUT;

int8_t event_process_rtc(void)
{
	uint8_t ret=0;
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
	if(diffPrSampleUpdate){
		//数据已经装入x_prDiffData
		diffPrSampleUpdate=false;
		cal_diff_press();
	}
	if(in_pt100SampleUpdate){
		in_pt100SampleUpdate=0;
		cal_pt100_temperature_in();
	}
	if(prSampleUpdate){
		prSampleUpdate=false;
		cal_press();
	}
	if(ex_pt100SampleUpdate){
		ex_pt100SampleUpdate=false;
		cal_pt100_temperature_ex();
	}
	if(inSocAdcSampleUpdate){
		inSocAdcSampleUpdate=false;
		cal_additional_pressute(0);
		cal_additional_pressute(1);
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
