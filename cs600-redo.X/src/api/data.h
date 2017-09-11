#ifndef __data_h__
#define __data_h__

#ifdef __cplusplus
extern "C"{
#endif

	//#include "ui.h"
	#include <stdint.h>
	#include <stdbool.h>
	
	#define get_offset_addr_of_str(TYPE, MEMBER) ((uint32_t) (&((TYPE *)0)->MEMBER))
	#define __STR_OFFSET get_offset_addr_of_str
	
    #define globle_BUFFER_SIZE  256
    extern uint8_t globleBuffer0[globle_BUFFER_SIZE];
	extern uint8_t globleBuffer1[globle_BUFFER_SIZE];
	typedef enum{
		HOTIZONTAL=0,//horizontal,
		VERTICAL,//Vertical,
		
	}em_posture,posture_t;


	
	typedef enum{
		HIGHT=0,	//高度报警
		PRESSURE,	//压力报警,
	}em_warnType,warnType_t;	
	
	typedef struct{
		uint32_t 	warnValue;//报警值
		uint32_t	retDiff;//回差
		bool upLimit;
		em_warnType	type;
		uint8_t[2];
	}st_warnDef,warnDef_t;
	
	typedef struct{
		uint32_t 	id;
		em_posture	pos;							//立式或者卧式
		uint8_t		maxValueForlevelBar;			//状态条显示满时对应的高度值,
													//(95%或者100%)
		uint16_t	density;//密度
		
		int32_t		h;		//高
		uint32_t	d;		//直径
		int32_t		baseZero;	//基础零位
		//
		st_warnDef	diffPressureWarnSet[4];			//差压报警设置
		st_warnDef	pressureWarnSet;				//压力报警设置
		uint8_t		simplePloyFactor[4];			//v0'=a0.v0+a1.v1+ ...+an.vn
		//
		uint32_t	ex_pressZero[2];				//外部差压零点
		uint32_t	ex_pressLine[2];				//外部差压线性系数
		uint32_t	ex_pressCurrentLoopLow[2];		//差压4-20ma下限
		uint32_t	ex_pressCurrentLoopUpper[2];	//差压4-20ma上限	
		//
		uint32_t	ex_TempZero;					//外部温度零点
		uint32_t	ex_TempLine;					//外部温度线性系数
		uint32_t	ex_TempCurrentLoopLow;			//温度4-20ma下限
		uint32_t	ex_TempCurrentLoopUpper;		//温度4-20ma上限	
		//
		uint16_t	crc;
	}st_sysDataDef,sysDataDef_t;
	extern const st_sysDataDef defultSystemData;
	#define SYSTEM_DATA_ADDR	0xf400
	extern uint8_t data_sys_init(void); 
    extern uint8_t data_sys_save(uint16_t offset,uint8_t* mbuf,uint16_t len);
	
	//定义修正表格式
	//这段算法好像很恶心
	#define CALIB_P_POINT_NUM 6
	typedef struct{
		int32_t	pValue;
		int16_t	pAdcValue;
		int16_t tAdcValue;		
	}st_prCalibPointDef,prCalibPoint_t;
	
	typedef struct{
		uint8_t pCount;	//有效点个数
		uint8_t reverse0[3];
		st_prCalibPointDef prCalibPoint[CALIB_P_POINT_NUM];
	}st_prCalibRowDef,prCalibRow_t;
	
	typedef struct{
		uint8_t rowCount;	//有效的行数,组数,
		uint8_t reverse0[3];
		st_prCalibRowDef prCalibRow[3];
		//uint8_t reverse1[2];
		uint16_t crc;		
	}st_prCalibTabDef,prCalibTab_t;	
	//
	extern st_prCalibTabDef diff_prCalibTabDef;
	extern st_prCalibTabDef prCalibTabDef;
	//
	
	//fk 
	extern void calib_data_put_piont_tab(st_prCalibTabDef* ptab,st_prCalibPointDef* pp,uint8_t row,uint8_t col);

#ifdef __cplusplus
}
#endif

#endif
//file end
