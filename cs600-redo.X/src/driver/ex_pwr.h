//file name :ex_pwr.h
#ifndef __ex_pwr_h__
#define __ex_pwr_h__

#ifdef __cplusplus
extern "C"{
#endif
	#include "../configs/configs.h"
    /*
	lcd电源引脚不能用作gpio，引脚定义作如下修改：
	1,STATUS-MA(pin3,re1)恢复为LCDBIAS2，
		STATUS-MA引脚由原定义为RS485_TXD(pin6,RG1)代替；
		原RS485_TXD功能去除；
	2,SET0-SLEEP(pin4,re0)恢复为LCDBIAS1，
		SET0-SLEEP引脚由原定义为GSM_IRQ_INT(pin54,RB4)代替；
		原GSM_IRQ_INT功能去除；
		
	3,KZ-SENSOR-VCC(pin5,RG0)恢复为LCDBIAS0，
		KZ-SENSOR-VCC引脚由原定义为STATUS-GSM(pin46,rc5)代替;
		原STATUS-GSM功能去除；
		修改是需去除原STATUS-GSM引脚上的上拉电阻r70;
	4,RS485_RXD引脚恢复为VLCAP1;
	5,RS485_RE引脚恢复为VLCAP2；
	6,LCDBIAS3不能悬空;
	------------------------------------------------------------------
	修改破坏原设计中的引脚如下
	RS485_TXD
	RS485_RXD
	RS485_RE
	GSM_IRQ_INT
	STATUS-GSM
	需要实现485功能由一下引脚实现
	STATUS-485
	KZ_GSM_VCC
	GSM_TXD
	GSM_RXD
	-------------------------------------------------------------------
	*/
    #if defined(PERIPH_PWR_DEF_ME)
	//rb4
	#define peripheral_power_enable() do{ \
		set_portb_mode_out(PIN4); \
		set_portb_value_hight(PIN4); \
		}while(0);
	#define peripheral_power_disable() do{ \
		set_portb_mode_out(PIN4); \
		set_portb_value_low(PIN4); \
		}while(0);		
	//rc5
	#define sensor_power_enable()	do{ \
		set_portc_mode_out(PIN5); \
		set_portc_value_hight(PIN5); \
		}while(0);	
	#define sensor_power_disable()	do{ \
		set_portc_mode_out(PIN5); \
		set_portc_value_low(PIN5); \
		}while(0);
	#elif defined(PERIPH_PWR_DEF_OTHER)
  
	//rh3
	#define peripheral_power_enable() do{ \
		set_porth_mode_out(PIN3); \
		set_porth_value_hight(PIN3); \
		}while(0);
	#define peripheral_power_disable() do{ \
		set_porth_mode_out(PIN3); \
		set_porth_value_low(PIN3); \
		}while(0);		
	//RB5
	#define sensor_power_enable()	do{ \
		set_portb_mode_out(PIN5); \
		set_portb_value_hight(PIN5); \
		}while(0);	
	#define sensor_power_disable()	do{ \
		set_portb_mode_out(PIN5); \
		set_portb_value_low(PIN5); \
		}while(0);    
	#else
		#error "peripheral power pins not be defined !!!"
	#endif
#ifdef __cplusplus
}
#endif

#endif
//file end
