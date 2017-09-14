#include "../includes/includes.h"
#include "float.h"
//uint8_t	globleBuffer0[]
uint8_t globleBuffer0[globle_BUFFER_SIZE]={0};
uint8_t globleBuffer1[globle_BUFFER_SIZE]={0};

const st_sysDataDef* fpSysData=(st_sysDataDef*)SYSTEM_DATA_ADDR;

st_iicDeviceObj* pdiff_prEepromObj=(st_iicDeviceObj*)NULL;
st_iicDeviceObj* p_prEepromObj=(st_iicDeviceObj*)NULL;

st_prCalibTabDef diff_prCalibTabDef={0};
st_prCalibTabDef prCalibTabDef={0};

//declare variables for adc
volatile int16_t 	adc_diffPr;			//
volatile int16_t	adc_diffBrg;		//
volatile int16_t	adc_diffVcc;		//
volatile int16_t	adc_diffGnd;		//

volatile int16_t	adc_exPt100;		//
volatile int16_t	adc_exPt100Line;	//
volatile int16_t	adc_Pr;

volatile int16_t	adc_iPrEx0;
volatile int16_t	adc_iPrEx1;

volatile int16_t	adc_ibat;
volatile int16_t	adc_iRef;
//declare variables for diff pressure;
volatile int32_t	x_DiffPressure;
volatile int32_t	x_Hight;
volatile int32_t	x_Weight;

volatile int32_t	x_Pressure;
volatile int32_t	x_Pemperature;
//
st_prData	x_prDiffData;


// %水平圆筒的局部容积系数,其中x=H/D
// %Vp=k*Va
// %k= k=(1/pi)*acos(1-2*x)-(1/pi)*(1-2*x)*((1-(1-2*x)^2))^0.5;
// matlab产生系数表代码示例如下：
/*
clear  all
i=0;
for x=0:0.01:1.0;
    k=(1/pi)*acos(1-2*x)-(1/pi)*(1-2*x)*((1-(1-2*x)^2))^0.5;
    fprintf('%1.4f,',k)
    i=i+1;
    if i== 8 
        fprintf('\r\n');
        i=0;
    end
end
*/
const float hKcy[]={
	0.0000,0.0017,0.0048,0.0087,0.0134,0.0187,0.0245,0.0308,0.0375,0.0446,
	0.0520,0.0598,0.0680,0.0764,0.0851,0.0941,0.1033,0.1127,0.1224,0.1323,
	0.1424,0.1527,0.1631,0.1738,0.1845,0.1955,0.2066,0.2178,0.2292,0.2407,
	0.2523,0.2640,0.2759,0.2878,0.2998,0.3119,0.3241,0.3364,0.3487,0.3611,
	0.3735,0.3860,0.3986,0.4112,0.4238,0.4364,0.4491,0.4618,0.4745,0.4873,
	0.5000,0.5127,0.5255,0.5382,0.5509,0.5636,0.5762,0.5888,0.6014,0.6140,
	0.6265,0.6389,0.6513,0.6636,0.6759,0.6881,0.7002,0.7122,0.7241,0.7360,
	0.7477,0.7593,0.7708,0.7822,0.7934,0.8045,0.8155,0.8262,0.8369,0.8473,
	0.8576,0.8677,0.8776,0.8873,0.8967,0.9059,0.9149,0.9236,0.9320,0.9402,
	0.9480,0.9554,0.9625,0.9692,0.9755,0.9813,0.9866,0.9913,0.9952,0.9983,
	1.0000,  
};

// 计算水平圆筒的椭圆封头局部容积,球形容器以及立式圆筒的椭圆封头同样适用本表
// 详见《石油化工设备设计便查手册.pdf》P379
// 当h=D时，最大容积为Vmax=pi/12*D^3=0.2618*D^3;
// 计算系数，输入x=h/D;k=V/Vmax;K=2*x^2*(3/2-x)
// matlab产生系数表代码示例如下：
/*
clear  all
i=0;
for x=0:0.01:1.0;
    k=2*x^2*(3/2-x);
    fprintf('%1.4f,',k)
    i=i+1;
    if i== 10 
        fprintf('\r\n');
        i=0;
    end
end  
*/
const float hKel[]={
	0.0000,0.0003,0.0012,0.0026,0.0047,0.0073,0.0104,0.0140,0.0182,0.0228,
	0.0280,0.0336,0.0397,0.0463,0.0533,0.0607,0.0686,0.0769,0.0855,0.0946,
	0.1040,0.1138,0.1239,0.1344,0.1452,0.1563,0.1676,0.1793,0.1913,0.2035,
	0.2160,0.2287,0.2417,0.2548,0.2682,0.2818,0.2955,0.3094,0.3235,0.3377,
	0.3520,0.3665,0.3810,0.3957,0.4104,0.4253,0.4401,0.4551,0.4700,0.4850,
	0.5000,0.5150,0.5300,0.5449,0.5599,0.5748,0.5896,0.6043,0.6190,0.6335,
	0.6480,0.6623,0.6765,0.6906,0.7045,0.7183,0.7318,0.7452,0.7583,0.7713,
	0.7840,0.7965,0.8087,0.8207,0.8324,0.8438,0.8548,0.8656,0.8761,0.8862,
	0.8960,0.9054,0.9145,0.9231,0.9314,0.9392,0.9467,0.9537,0.9603,0.9664,
	0.9720,0.9772,0.9818,0.9860,0.9896,0.9928,0.9953,0.9974,0.9988,0.9997,
	1.0000,  
};


const st_sysDataDef defultSystemData={
	0x00ul	,//uint32_t 	id;
	0		,//em_posture	pos;							//立式或者卧式
	95		,//uint8_t		maxValueForlevelBar;			//状态条显示满时对应的高度值,
												//(95%或者100%)
	1000	,//uint16_t	density;//密度

	10000	,//int32_t		h;		//高
	5000	,//uint32_t	d;		//直径
	-200	,//int32_t		zero;	//零点
	//
	{0}		,//st_warnDef	diffPressureWarnSet[4];			//差压报警设置
	{0}		,//st_warnDef	pressureWarnSet;				//压力报警设置
	{40,30,20,10},	//uint8_t		simplePloyFactor[4];			//v0'=a0.v0+a1.v1+ ...+an.vn
	//
	{0}		,//uint32_t	ex_pressZero[2];				//外部差压零点
	{1000,1000}		,//uint32_t	ex_pressLine[2];				//外部差压线性系数
	{0}				,//uint32_t	ex_pressCurrentLoopLow[2];		//差压4-20ma下限
	{1000,1000}		,//uint32_t	ex_pressCurrentLoopUpper[2];	//差压4-20ma上限	
	//
	0		,//uint32_t	ex_TempZero;					//外部温度零点
	1000	,//uint32_t	ex_TempLine;					//外部温度线性系数
	0		,//uint32_t	ex_TempCurrentLoopLow;			//温度4-20ma下限
	1000	,//uint32_t	ex_TempCurrentLoopUpper;		//温度4-20ma上限	
	//
	0		,//uint16_t	crc;
};

uint8_t data_sys_init(void)
{
	uint8_t ret;
	uint8_t* buf=globleBuffer0;
	if(sizeof(globleBuffer0)<sizeof(st_sysDataDef))return 0;
	m_flash_read(SYSTEM_DATA_ADDR,buf,sizeof(st_sysDataDef));
	ret=crc_verify(buf,sizeof(st_sysDataDef));
	if(!ret){
		m_mem_cpy_len(buf,(uint8_t*)(&defultSystemData),sizeof(st_sysDataDef));
		crc_append(buf,sizeof(st_sysDataDef)-2);
		m_flash_write(SYSTEM_DATA_ADDR,buf,sizeof(st_sysDataDef));
		m_flash_read(SYSTEM_DATA_ADDR,buf,sizeof(st_sysDataDef));
		ret=crc_verify(buf,sizeof(st_sysDataDef));		
	}
	return ret;
}

uint8_t data_sys_save(uint16_t offset,uint8_t* mbuf,uint16_t len)
{
	uint8_t ret;
	uint8_t* buf=globleBuffer0;
	if(offset+len>sizeof(st_sysDataDef)-2)return 0;
	if(sizeof(globleBuffer0)<sizeof(st_sysDataDef))return 0;
	m_flash_read(SYSTEM_DATA_ADDR,buf,sizeof(st_sysDataDef));
	m_mem_cpy_len(buf+offset,mbuf,len);
	crc_append(buf,sizeof(st_sysDataDef)-2);
	m_flash_write(SYSTEM_DATA_ADDR,buf,sizeof(st_sysDataDef));
	m_flash_read(SYSTEM_DATA_ADDR,buf,sizeof(st_sysDataDef));
	ret=crc_verify(buf,sizeof(st_sysDataDef));	
	return ret;
}

//保存标定点数据到数据表
void calib_data_put_piont_tab(st_prCalibTabDef* ptab,st_prCalibPointDef* pp,uint8_t row,uint8_t col)
{
	uint8_t t8;
	st_prCalibPointDef* stp;
	t8=ptab->rowCount;
	if(row>t8-1)return;
	if(col>CALIB_P_POINT_NUM-1)return;
	stp=&(ptab->prCalibRow[row].prCalibPoint[col]);
	stp->pValue=pp->pValue;
	stp->pAdcValue=pp->pAdcValue;
	stp->tAdcValue=pp->tAdcValue;
	/*
	//另外一种写法
	uint8_t t8;
	uint8_t* pt;
	t8=ptab->rowCount;
	if(row>t8-1)return;
	if(col>CALIB_P_POINT_NUM-1)return;
	pt=(uint8_t*)ptab+4+sizeof(st_prCalibRowDef)*row+4+sizeof(st_prCalibPointDef)*col;
	m_mem_cpy_len(pt,(uint8_t*)pp,sizeof(st_prCalibPointDef));
	*/
}

// 差压标定数据初始化
// at24c02_init(&at24c02Ch0,0xaa);//压力
// at24c02_init(&at24c02Ch1,0xac);//差压
void calib_data_set_default_diff_pr(void)
{
    uint8_t i,j;
	diff_prCalibTabDef.rowCount=3;
    for(i=0;i<3;i++){
        diff_prCalibTabDef.prCalibRow[i].pCount=CALIB_P_POINT_NUM;
        for(j=0;j<CALIB_P_POINT_NUM;j++){
            diff_prCalibTabDef.prCalibRow[i].prCalibPoint[j].pAdcValue=j*6000+i*500;
            diff_prCalibTabDef.prCalibRow[i].prCalibPoint[j].pValue=j*6000;
            diff_prCalibTabDef.prCalibRow[i].prCalibPoint[j].tAdcValue=i+1000;
        }
    }
    //crc_append((uint8_t*)(&diff_prCalibTabDef),sizeof(diff_prCalibTabDef)-2);
}

void calib_data_set_default_pr(void)
{
    uint8_t i,j;
	prCalibTabDef.rowCount=1;
    for(i=0;i<1;i++){
        prCalibTabDef.prCalibRow[i].pCount=CALIB_P_POINT_NUM;
        for(j=0;j<CALIB_P_POINT_NUM;j++){
            prCalibTabDef.prCalibRow[i].prCalibPoint[j].pAdcValue=j*6000+i*500;
            prCalibTabDef.prCalibRow[i].prCalibPoint[j].pValue=j*6000;
            prCalibTabDef.prCalibRow[i].prCalibPoint[j].tAdcValue=0;
        }
    }
    //crc_append((uint8_t*)(&prCalibTabDef),sizeof(prCalibTabDef)-2);
}

uint8_t  calib_data_init_diff_pr(void)
{
	uint8_t ret=0;
	uint16_t t16;
	uint8_t* buf=(uint8_t*)(&diff_prCalibTabDef);
	
	pdiff_prEepromObj= &at24c02Ch1;
	at24c02_init(pdiff_prEepromObj,0xac);
	t16=sizeof(st_prCalibTabDef);
	at24c02_read_n_byte(pdiff_prEepromObj,0,buf,t16);
	ret=crc_verify(buf,t16);
	if(!ret){
		calib_data_set_default_diff_pr();
		crc_append(buf,t16-2);
		at24c02_write_n_byte(pdiff_prEepromObj,0,buf,t16);
		at24c02_read_n_byte(pdiff_prEepromObj,0,buf,t16);
		ret=crc_verify(buf,t16);		
	}
	return ret;
}

//压力标定数据初始化
uint8_t  calib_data_init_pr(void)
{
	uint8_t ret=0;
	uint16_t t16;
	uint8_t* buf=(uint8_t*)(&prCalibTabDef);
	
	p_prEepromObj=&at24c02Ch0;
	at24c02_init(p_prEepromObj,0xaa);
	t16=sizeof(st_prCalibTabDef);
	at24c02_read_n_byte(p_prEepromObj,0,buf,t16);
	ret=crc_verify(buf,t16);
	if(!ret){
		calib_data_set_default_pr();
		crc_append(buf,t16-2);
		at24c02_write_n_byte(p_prEepromObj,0,buf,t16);
		at24c02_read_n_byte(p_prEepromObj,0,buf,t16);
		ret=crc_verify(buf,t16);		
	}
	return ret;	
}

//一阶插值p-vin 压力--电压
//输入xin:	[pvalue(未知),pAdcvalue(已知),tAdcValue(实际温度)];
//返回xin:	[pvalue(已知),pAdcvalue(已知),tAdcValue(实际温度)];并且返回的pvalue无实际意义;
//返回xout:	[pvalue(已知),pAdcvalue(已知),tAdcValue(图表中选定的温度)];
//无温度补偿的情况，直接用xin返回计算结果;
uint8_t m_interp1_cal_p_v(st_prCalibRowDef* tabrow,st_prData* xin,st_prData* xout)
{
	uint8_t i;
	int32_t x,y;
	for(i=0;i< (tabrow->pCount) - 1 ;i++){
		//waht !!!!
		if(tabrow->prCalibPoint[i].pAdcValue < tabrow->prCalibPoint[i+1].pAdcValue){
			if(xin->pAdcValue < tabrow->prCalibPoint[i+1].pAdcValue)break;
		}else{
			if(xin->pAdcValue >= tabrow->prCalibPoint[i+1].pAdcValue)break;
		}		
	}
    xin->pValue=tabrow->prCalibPoint[i].pValue;
    y = tabrow->prCalibPoint[i+1].pValue - tabrow->prCalibPoint[i].pValue ;
    x = tabrow->prCalibPoint[i+1].pAdcValue - tabrow->prCalibPoint[i].pAdcValue;
    if(x != 0){
        xin->pValue = xin->pValue + (y/x)*(xin->pAdcValue -  tabrow->prCalibPoint[i].pAdcValue);
    }
	if(xout){
		xout->pValue =   xin->pValue;
		xout->pAdcValue = xin->pAdcValue;
		xout->tAdcValue = tabrow->prCalibPoint[0].tAdcValue;
	}
    return i;
}

//一阶线性插值p-t 压力温度
//输入tmpx[]:在温度曲线簇上与x=(pAdcValue)相交的一组点，表示温度压力关系;
//输入xin:	[pvalue(未知),pAdcvalue(已知),tAdcValue(实际温度)];
uint8_t m_interp1_cal_p_t(st_prData* tmpx,st_prData* xin,uint8_t tmpxLen)
{
	uint8_t i;
	int32_t x,y;
    for(i=0;i<tmpxLen-1;i++){
        if(tmpx[i].tAdcValue < tmpx[i+1].tAdcValue){
            if(xin->tAdcValue < tmpx[i+1].tAdcValue)break;
        }else{
            if(xin->tAdcValue >= tmpx[i+1].tAdcValue)break;
        }
    }
    xin->pValue=tmpx[i].pValue;
    y=tmpx[i+1].pValue-tmpx[i].pValue;
    x=tmpx[i+1].tAdcValue-tmpx[i].tAdcValue;
    if(x!=0){
        xin->pValue = xin->pValue + (y/x)*(xin->tAdcValue - tmpx[i].tAdcValue);
    }
    return i;
}

//计算差压
//计算结果直接用xin返回
uint8_t cal_diff_press(st_prData* xin)
{
	//table data used globle 
	st_prData tmpx[3];
	uint8_t i=0;
	st_prCalibRowDef* tabrow;
    for(i=0;i<diff_prCalibTabDef.rowCount;i++){
        tabrow = &(diff_prCalibTabDef.prCalibRow[i]);
        m_interp1_cal_p_v(tabrow,xin,&tmpx[i]);
    }
    m_interp1_cal_p_t(&tmpx[0],xin,i);
	return i;
}

//计算压力
//计算结果直接用xin返回
uint8_t cal_press(st_prData* xin)
{
	uint8_t ret;
	st_prCalibRowDef* tabrow;
	tabrow= &prCalibTabDef.prCalibRow[0];
	ret=m_interp1_cal_p_v(tabrow,xin,NULL);
	return ret;
}

// -----------------------------------------------------
// 计算温度
// a=3.90802e-3;b=-5.8e-7;c=-4.2735e-12;
// b/a=-1.484e-4;默认3个小数位
// t=ax-b+c*t^2;//c=1.484e-4
// t0=ax-b;
// t1=t0+c*t0^2;
// -----------------------------------------------------
#define __kT (1.484e-4f)
uint32_t cal_pt100_temperature(int16_t x,uint16_t l,uint16_t b)
{
	int32_t t32,ret;
	t32=(int32_t)l*x-b;
	//三个小数位
	if(t32>200000)t32=200000;
	if(t32<-200000)t32=-200000;
	ret=t32;
	t32/=10;
	t32=t32*t32/10000;
	t32*=1484;
	t32/=10000;
	ret=ret+t32;
	return ret;
}


//file end
