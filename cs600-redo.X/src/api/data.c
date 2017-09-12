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
    m_interp1_cal_p_t(&tmpx,xin,i);
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
