    /*
	lcd��Դ���Ų�������gpio�����Ŷ����������޸ģ�
	1,STATUS-MA(pin3,re1)�ָ�ΪLCDBIAS2��
		STATUS-MA������ԭ����ΪRS485_TXD(pin6,RG1)���棻
		ԭRS485_TXD����ȥ����
	2,SET0-SLEEP(pin4,re0)�ָ�ΪLCDBIAS1��
		SET0-SLEEP������ԭ����ΪGSM_IRQ_INT(pin54,RB4)���棻
		ԭGSM_IRQ_INT����ȥ����
		
	3,KZ-SENSOR-VCC(pin5,RG0)�ָ�ΪLCDBIAS0��
		KZ-SENSOR-VCC������ԭ����ΪSTATUS-GSM(pin46,rc5)����;
		ԭSTATUS-GSM����ȥ����
		�޸�����ȥ��ԭSTATUS-GSM�����ϵ���������r70;
	4,RS485_RXD���Żָ�ΪVLCAP1;
	5,RS485_RE���Żָ�ΪVLCAP2��
	6,LCDBIAS3��������;
	------------------------------------------------------------------
	�޸��ƻ�ԭ����е���������
	RS485_TXD
	RS485_RXD
	RS485_RE
	GSM_IRQ_INT
	STATUS-GSM
	��Ҫʵ��485������һ������ʵ��(20170909)
	STATUS-485	pin2		step0-sleep(RH3)
	KZ_GSM_VCC	pin53		kz-sensor(RB5)
	GSM_TXD		pin37
	GSM_RXD 	pin38
	-------------------------------------------------------------------
	*/
	�ͻ����õ��޸ķ�ʽ
	pin2		step0-sleep(RH3)
	pin53		kz-sensor(RB5)	
	//github�����ο��������Ķ�
	https://book.git-scm.com/book/zh/v2
	
	