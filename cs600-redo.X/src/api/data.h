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
		TEST_MODE=0,
		WORK_MODE,
	}st_deviceOpMode;
	
	extern volatile st_deviceOpMode dwm;
	
	typedef enum{
		HIGHT_HI=0,	//高度报警
		HIGHT_LO,
		PRESSURE_HI,	//压力报警,
		PRESSURE_LO,
	}em_warnType,warnType_t;	
	
	typedef struct{
		uint32_t 	warnValueLo;//报警值
		uint32_t	warnValueHi;//回差
		//bool upLimit;
		em_warnType	type;
		uint8_t[3];
	}st_warnDef,warnDef_t;
	
	//定点数固定放大1000倍
	typedef struct{
		uint32_t 	id;
		em_posture	pos;							//立式或者卧式
		uint8_t		maxValueForlevelBar;			//状态条显示满时对应的高度值,
													//(95%或者100%)
		uint16_t	density;						//密度
		
		int32_t		h;								//高
		uint32_t	d;								//直径
		
		int32_t		V1;								//圆筒部分体积
		int32_t		V2;								//封头椭球体积
		
		int32_t		baseZero;						//基础零位
		//
		st_warnDef	diffPressureWarnSet[4];			//差压报警设置
		st_warnDef	pressureWarnSet;				//压力报警设置
		uint16_t	ployCoeffic[4];					//v0'=a0.v0+a1.v1+ ...+an.vn
		
		uint32_t	TempZero;						//外部温度零点
		uint32_t	TempLine;						//外部温度线性系数		
		
		//
		uint32_t	ex_pressZero[2];				//外部差压零点
		uint32_t	ex_pressLine[2];				//外部差压线性系数
		uint32_t	ex_pressiLoopLow[2];			//差压4-20ma下限
		uint32_t	ex_pressiLoopUpper[2];			//差压4-20ma上限	
		//
		uint32_t	ex_TempZero;					//外部温度零点
		uint32_t	ex_TempLine;					//外部温度线性系数
		
		uint32_t	ex_TempCurrentLoopLow;			//温度4-20ma下限
		uint32_t	ex_TempCurrentLoopUpper;		//温度4-20ma上限	
		uint16_t	barScale;
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
	}st_prCalibPointDef,prCalibPoint_t,st_prData;
	
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
	//declare variables for adc
	// extern volatile int16_t 	adc_diffPr;			//
	// extern volatile int16_t		adc_diffBrg;		//
	// extern volatile int16_t		adc_diffVcc;		//
	// extern volatile int16_t		adc_diffGnd;		//
	
	extern volatile int16_t 	adc_inPt100;
	
	extern volatile int16_t		adc_pressure;
	extern volatile int16_t		adc_exPt100;

	// extern volatile int16_t		adc_exPt100;		//
	// extern volatile int16_t		adc_exPt100Line;	//
	// extern volatile int16_t		adc_Pr;

	extern volatile int16_t		adc_iPrEx[2];
	//extern volatile int16_t		adc_iPrEx1;

	extern volatile int16_t		adc_ibat;
	extern volatile int16_t		adc_iRef;
	// declare variables for 	diff pressure;
	// extern volatile int32_t		x_DiffPressure;
	// extern volatile int32_t		x_Hight;
	// extern volatile int32_t		x_Weight;

	// extern volatile int32_t		x_Pressure;
	// extern volatile int32_t		x_Pemperature;
	
	extern st_prData	x_prDiffData;
    extern volatile int32_t	rtDiffPressure;
	extern volatile int32_t	rtVolume;
    extern volatile int32_t	rtHight;
	extern volatile int32_t	rtWeight;
	
	volatile int32_t    rtPressure;
	//fk 
    extern uint32_t data_sys_cal_v1(st_sysDataDef* stp);
    extern uint32_t data_sys_cal_v2(st_sysDataDef* stp);
	extern void calib_data_put_piont_tab(st_prCalibTabDef* ptab,st_prCalibPointDef* pp,uint8_t row,uint8_t col);


    //apl
	extern uint8_t cal_diff_press(void);
	extern uint8_t cal_diff_hight_level(void);
	extern  void cal_pt100_temperature_in(void);

	extern uint8_t cal_press(void);
	extern  void cal_pt100_temperature_ex(void);
	
	extern void cal_additional_pressute(uint8_t index);

	extern void data_init_all(void);
#ifdef __cplusplus
}
#endif

#endif
//file end
