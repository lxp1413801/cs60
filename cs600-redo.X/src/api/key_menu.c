#include "../includes/includes.h"

#define LONG_PRESS_TIME		2000

volatile uint16_t passWord=0x00;
volatile uint8_t menu=MENU_HOME_00;
volatile uint8_t keyValue=KEY_VALUE_NONE;
volatile uint8_t adjLocation=0;
volatile uint32_t adjValue=0x00;
volatile uint8_t* pAdjValue;
//
volatile uint8_t  calibRow=0x00;
volatile uint8_t  calibCol=0x00;

uint16_t __exp_10(uint8_t n)
{
	switch(n){
		case 0:return 	1;
		case 1:return 	10;
		case 2:return 	100;
		case 3:return 	1000;
		default:return 	1000;		
	}
}

uint16_t key_waite_release(uint16_t timeout,uint8_t* key)
{
	uint8_t t8;
	//uint16_t tm=0x00;
	userTicker_ms=0;
	while(userTicker_ms<timeout){
		t8=key_polling();
		if(t8==KEY_VALUE_NONE)break;
	}
	*key=t8;
	return userTicker_ms;
}
//shift
void key_shift_loc_fixed_point(uint8_t* loc,uint8_t min,uint8_t max)
{
	uint8_t t8=*loc;
	if(min>=max){
		t8=min;
	}else{
		t8++;
		if(t8>max)t8=min;
	}
	*loc=t8;
}

//adj value
void key_adj_value_fixed_point(uint16_t* value,uint8_t loc)
{
	uint16_t dloc;
	uint16_t t16=*value;
	if(loc>3)loc=3;
	dloc=(t16/__exp_10(loc))%10;
	t16=t16-dloc*__exp_10(loc);
	dloc++;
	if(dloc>9)dloc=0;
	t16+=(dloc*__exp_10(loc));
	*value=t16;
}

//set long time press process
void __enter_menu_set_density(void){
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	adjValue=fps->density;
	adjLocation=0;
}

void __enter_menu_set_pose(void){
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	adjValue=(uint8_t)(fps->pos);
	adjLocation=0;
}
void __enter_menu_set_base_zero(void){
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	adjValue=(fps->baseZero);
	adjValue=__int32_2_mflot32(adjValue);
	adjLocation=0;
}
void __enter_menu_calib_press_diff(void){
	//git pressure calib data
	
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	adjValue=(fps->baseZero);
	adjValue=__int32_2_mflot32(adjValue);
	adjLocation=0;
}

void key_process_down(void)
{
	switch(menu){
		case MENU_HOME_00:
		case MENU_HOME_01:
		case MENU_HOME_02:break;
		case MENU_PASSWORD:key_shift_loc_fixed_point((uint8_t*)(&adjLocation),0,3);break;
		default:break;
	}	
}
void key_process_up(void)
{
	switch(menu){
		case MENU_HOME_00:
		case MENU_HOME_01:
		case MENU_HOME_02:break;
		case MENU_PASSWORD:key_adj_value_fixed_point((uint16_t*)(&passWord),adjLocation);break;
		default:break;
	}		
}
void key_process_set_down_long(void)
{
	if(menu==MENU_PASSWORD){
		switch(passWord){
		case PSW_SET_DENSITY:	
			menu=MENU_SET_DENSITY;	__enter_menu_set_density();     break;
		case PSW_SET_SIZE:
			menu=MENU_SET_SIZE;     __enter_menu_set_pose();        break;
		case PSW_SET_BASE_ZERO_LEVEL:
			menu=MENU_SET_BASE_ZERO;__enter_menu_set_base_zero();	break;
		case PSW_CALIB_DIFF_PRESSURE:
			menu=MENU_DIFF_CALIB;						break;
		case PSW_CALIB_PRESSURE:
			menu=MENU_PRESSURE_CALIB;					break;
		case PSW_SET_POLY_COEFFIC:
			menu=MENU_POLY_COEFFIC;						break;
		case PSW_SET_WARN_TYPE:
			menu=MENU_SET_WARN_TYPE;					break;
		case PSW_SET_WARN_VALUE_DIFF:
			menu=MENU_SET_WARN_VALUE_DIFF;				break;
		case PSW_SET_EX_DIFF_PRESSURE_ZERO_LINE:
			menu=MENU_SET_EX_DIFF_PRESSURE_ZERO_LINE;	break;
		case PSW_SET_EX_DIFF_PRESSURE_ILOOP_OUT:	
			menu=MENU_SET_EX_DIFF_PRESSURE_ILOOP_OUT;	break;
		case PSW_SET_FULL_LEVEL_BAR:
			menu=MENU_SET_FULL_LEVEL_BAR;				break;
		case PSW_SET_PRESSURE_DISP_TYPE:
			menu=MENU_SET_PRESSURE_DISP_TYPE;			break;
		default:break;
		}
	}
}

void key_process_set_long(void)
{
	switch(menu){
		case MENU_HOME_00:
		case MENU_HOME_01:
		case MENU_HOME_02:
		case MENU_PASSWORD:
			{passWord=0x00;adjLocation=0x00;menu=MENU_HOME_00;break;}
		default:break;
	}
}

void key_process_set(void)
{
	switch(menu){
		case MENU_HOME_00:
		case MENU_HOME_01:
		case MENU_HOME_02:{passWord=0x00;adjLocation=0x00;menu=MENU_PASSWORD;break;}
		default:break;
	}
}

void key_process(void)
{
	uint16_t tm;
	uint8_t key;
	tm=key_waite_release(LONG_PRESS_TIME,&key);
	if(tm>=LONG_PRESS_TIME){
		//长按
		if(key==KEY_VALUE_SET){
			key_process_set_long();
		}else if(keyValue == (KEY_VALUE_SET+KEY_VALUE_DOWN)){
			key_process_set_down_long();
		}
	}else{
		//短按
		if(keyValue == KEY_VALUE_DOWN){
			key_process_down();		
		}else if(keyValue == KEY_VALUE_UP){
			key_process_up();		
		}else if(keyValue == KEY_VALUE_SET){
			key_process_set();		
		}	
	}
	//点亮闪烁的数位，禁止闪烁

	lcd_twinkle_lock(TWINKLE_LOCK_TIME_s);
	ui_disp_menu();
	key_waite_release(LONG_PRESS_TIME,&key);
}

//file end
