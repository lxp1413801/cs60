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
	an-225
	https://masterok.livejournal.com/513410.html
	//add a test line
	��Բ��ͷҺλ���������ϵ����ʯ�ͻ����豸��Ʊ���ֲ�.pdf��P392
	��ʷ:
	20170918:
		1,��Ϊ�״ν����ǲ���˸��
		2,�޸Ĳ���ռ��ʱ��̫����bug;
		
	20170925
	1,set+up����˵�
	2,psd=6
	al1-al4
	3,psd=16
	�±��1��ʼ
	4,psd=56
	hb ��ΪHb
	������up��down�޸�
	5��168
	����d00;
	����c00��
	����G00
	
	6��133����
	�Ӳ�������n��
	7,168��169
	����168��169�Ժ󣬿��ٲ�����100ms���²�һ�Σ�����һ����ʾadcֵ��ʮ���ƣ�
	
	8,�¶��õ���궨��������ֵ
	
	
	//20170928
	1,�������ñȽ���ĵط������ж�
	2,
	//����ʱ�����Ĵ���취�����4.7nF~10nF���˲�����
	������2��1���˲���2��ƽ���������
	
	
	