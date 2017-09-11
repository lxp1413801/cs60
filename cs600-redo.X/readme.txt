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
	需要实现485功能由一下引脚实现(20170909)
	STATUS-485	pin2		step0-sleep(RH3)
	KZ_GSM_VCC	pin53		kz-sensor(RB5)
	GSM_TXD		pin37
	GSM_RXD 	pin38
	-------------------------------------------------------------------
	*/
	客户采用的修改方式
	pin2		step0-sleep(RH3)
	pin53		kz-sensor(RB5)	
	//github社区参考书在线阅读
	https://book.git-scm.com/book/zh/v2
	//add a test line
	
	
