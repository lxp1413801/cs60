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
	an-225
	https://masterok.livejournal.com/513410.html
	//add a test line
	椭圆封头液位储积换算关系见《石油化工设备设计便查手册.pdf》P392
	历史:
	20170918:
		1,改为首次进入是不闪烁；
		2,修改采样占用时间太长的bug;
		
	20170925
	1,set+up进入菜单
	2,psd=6
	al1-al4
	3,psd=16
	下标从1开始
	4,psd=56
	hb 改为Hb
	数字用up和down修改
	5，168
	低温d00;
	常温c00；
	高温G00
	
	6，133里面
	加采样次数n，
	7,168，169
	进入168和169以后，快速采样，100ms以下才一次，考虑一下显示adc值；十进制，
	
	8,温度用电阻标定，输入数值
	
	
	//20170928
	1,函数调用比较深的地方屏蔽中断
	2,
	//采样时跳动的处理办法，外加4.7nF~10nF的滤波电容
	作用有2，1、滤波，2、平衡采样电容
	
	
	