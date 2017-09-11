#include "../includes/includes.h"

//uint8_t	globleBuffer0[]
uint8_t globleBuffer0[globle_BUFFER_SIZE]={0};
uint8_t globleBuffer1[globle_BUFFER_SIZE]={0};
const st_sysDataDef* fpSysData=(st_sysDataDef*)SYSTEM_DATA_ADDR;
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

void data_put_point_to_calib(st_prCalibTabDef* ptab,st_prCalibPointDef* pp,uint8_t row,uint8_t col)
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

//file end