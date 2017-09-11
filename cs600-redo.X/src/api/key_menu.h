//file name:key_menu.h
#ifndef __key_menu_h__
#define __key_menu_h__

#ifdef __cplusplus
extern "C"{
#endif
	#include <stdint.h>
	#include <stdbool.h>
	
	#define PSW_SET_DENSITY						36	
	#define PSW_SET_SIZE						66
	
	#define PSW_SET_BASE_ZERO_LEVEL				56
	//calibration
	#define PSW_CALIB_DIFF_PRESSURE				168
	#define PSW_CALIB_PRESSURE					169
	//Polynomial coefficients(滤波多项式系数)
	#define PSW_SET_POLY_COEFFIC				133
	#define PSW_SET_WARN_TYPE					6
	#define PSW_SET_WARN_VALUE_DIFF				16
	//外部差压零点和线性
	#define PSW_SET_EX_DIFF_PRESSURE_ZERO_LINE	138
	//外部差压输出范围
	#define PSW_SET_EX_DIFF_PRESSURE_ILOOP_OUT	139
	//高度条满刻度对应的值95%还是100%
	#define PSW_SET_FULL_LEVEL_BAR				188
	#define PSW_SET_PRESSURE_DISP_TYPE			18
	
	//==============================================================
	//定义菜单,主界面
	#define MENU_HOME_00						0x00
	#define MENU_HOME_01						0x01
	#define MENU_HOME_02						0x02
	//密码验证界面
	#define MENU_PASSWORD						0x10
	//设置密度	psd=36
	#define MENU_SET_DENSITY					0x20
	//设置尺寸 psd=66
	#define MENU_SET_SIZE						0x30
	#define MENU_SET_POSE						MENU_SET_SIZE
	#define MENU_SET_L							0x31
	#define MENU_SET_D							0x32
	//设置基础零位	psd=56	
	#define MENU_SET_BASE_ZERO					0x40
	//差压标定,psd=168
	#define MENU_DIFF_CALIB						0x50
	//压力标定,psd=169
	#define MENU_PRESSURE_CALIB					0x60
	//滤波多项式系数psd=133
	#define MENU_POLY_COEFFIC					0x70
	//报警方式,psd=6								
	#define MENU_SET_WARN_TYPE					0x80
	//报警值和回差,psd=16
	#define MENU_SET_WARN_VALUE_DIFF			0x90
	//外部差压零点和线性,psd=138
	#define MENU_SET_EX_DIFF_PRESSURE_ZERO_LINE	0xa0
	//外部差压输出范围,psd=139
	#define MENU_SET_EX_DIFF_PRESSURE_ILOOP_OUT	0xb0
	//高度条满刻度对应的值95%还是100%,psd=188	
	#define MENU_SET_FULL_LEVEL_BAR				0xc0
	//显示方式,显示即时值还是平均值
	#define MENU_SET_PRESSURE_DISP_TYPE				0xf0
	
	//variable
	extern volatile uint8_t menu;
	extern volatile uint8_t keyValue;
	extern volatile uint16_t passWord;
	extern volatile uint8_t adjLocation;
	//
	extern volatile uint8_t  calibRow;
	extern volatile uint8_t  calibCol;	
	//function
	extern void key_process(void);
	
#ifdef __cplusplus
}
#endif
#endif
//file  end
