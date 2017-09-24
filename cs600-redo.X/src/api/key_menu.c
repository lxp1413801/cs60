#include "../includes/includes.h"

#define goHOME  true
#define unGoHome    false

#define LONG_PRESS_TIME		2000

volatile uint16_t passWord=0x00;
volatile uint8_t menu=MENU_HOME;
volatile uint8_t subMenu=0;
volatile uint8_t keyValue=KEY_VALUE_NONE;
volatile uint8_t adjLocation=0;
volatile int32_t adjValue=0x00;
//add lxp
st_float32_m m_floatAdj={0};
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
		delay_ms(10);
	}
	*key=t8;
	return userTicker_ms;
}
//shift
void key_shift_loc(uint8_t* loc,uint8_t min,uint8_t max)
{
	uint8_t t8=*loc;
	if(min>=max){
		t8=min;
	}else{
		t8++;
		if(t8>max)t8=min;
	}
	if(m_floatAdj.stru.sign){
        if(t8==0)t8=1;
    }
	*loc=t8;
}

void key_adj_value_fixed(uint16_t* value,uint8_t loc)
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

//adj my float value
void key_adj_value_float(st_float32_m* mfp,uint8_t loc)
{
    uint16_t t16;
    uint8_t t8;
    t16=mfp->stru.significand;
    if(loc<4){
        key_adj_value_fixed(&t16,loc);
        mfp->stru.significand=t16;
    }else if(loc==4){
        t8=mfp->stru.exponent;
        t8++;
        if(t8>3 )t8=0;
		if(mfp->stru.sign){
			if(t8>2)t8=0;
		}
        mfp->stru.exponent=t8;
    }else{
        t8=mfp->stru.sign;
        t8++;
        if(t8>1)t8=0;

        mfp->stru.sign=t8;
    }
}



//set long time press process
void __enter_menu_password(void)
{	
	menu=MENU_PASSWORD;
	subMenu=0x00;
	
	passWord=0x00;
	adjLocation=0x00;
}

void __enter_menu_set_density(void)
{
	int32_t t32;
	menu=MENU_SET_DENSITY;
	subMenu=sub_MENU_SET_DENSITY;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	t32=fps->density;
	t32=__int32_2_mflot32(t32);
	m_floatAdj.t32=t32;
	adjLocation=0;
}
//
void __enter_menu_set_pose_size(void)
{
	menu=MENU_SET_POSE_SIZE;
	subMenu=sub_MENU_SET_POSE;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	adjValue=0x00ul;
	*((uint8_t*)(&adjValue))=(uint8_t)(fps->pos);
	adjLocation=0;
}

void __enter_menu_set_d(void){
	int32_t t32;
	subMenu=sub_MENU_SET_D;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	t32=fps->d;
	t32=__int32_2_mflot32(t32);
	m_floatAdj.t32=t32;
	adjLocation=0;
}

void __enter_menu_set_h(void){
	int32_t t32;
	subMenu=sub_MENU_SET_L;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	t32=(fps->h);
	t32=__int32_2_mflot32(t32);
	m_floatAdj.t32=t32;
	adjLocation=0;
}
//
void __enter_menu_set_base_zero(void)
{
	int32_t t32;
	menu=MENU_SET_BASE_ZERO;
	subMenu=0;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	t32=(fps->baseZero);
	t32=__int32_2_mflot32(t32);
	m_floatAdj.t32=t32;
	if(m_floatAdj.stru.sign){
        adjLocation=1;
    }else{
        adjLocation=0;
    }
}
//
/*
void __enter_menu_calib_press_diff(void)
{
	//git pressure calib data
	int32_t t32;
	st_prCalibTabDef* stp;    
    
	menu=MENU_DIFF_CALIB;
	subMenu=0;
	calibRow=0;
	calibCol=0;

	stp=(st_prCalibTabDef*)(&diff_prCalibTabDef);
	t32=stp->prCalibRow[calibRow].prCalibPoint[calibCol].pValue;
    
	t32=__int32_2_mflot32(t32);
	m_floatAdj.t32=t32;
	adjLocation=0;
}
*/
void __enter_menu_calib_press_diff(uint8_t row,uint8_t col)
{
	//git pressure calib data
	int32_t t32;
	st_prCalibTabDef* stp;    
    
	menu=MENU_DIFF_CALIB;
	subMenu=0;
	calibRow=row;
	calibCol=col;
    stp=(st_prCalibTabDef*)(&diff_prCalibTabDef);
	if(col==0){
		*((uint8_t*)(&adjValue))=stp->prCalibRow[row].pCount;
	}else{
        t32=stp->prCalibRow[calibRow].prCalibPoint[calibCol-1].pValue;
        t32=__int32_2_mflot32(t32);
        m_floatAdj.t32=t32;        
    }
	adjLocation=0;
}

//
void __enter_menu_calib_press(uint8_t row,uint8_t col)
{
	//git pressure calib data
	int32_t t32;
	st_prCalibTabDef* stp;    
    
	menu=MENU_PRESSURE_CALIB;
	subMenu=0;
	calibRow=row;
	calibCol=col;
    stp=(st_prCalibTabDef*)(&prCalibTabDef);
    if(col==0){
        *((uint8_t*)(&adjValue))=stp->prCalibRow[row].pCount;
    }else{
        t32=stp->prCalibRow[calibRow].prCalibPoint[calibCol-1].pValue;
        t32=__int32_2_mflot32(t32);
        m_floatAdj.t32=t32;        
    }
	adjLocation=0;
}

void __enter_menu_poly_coeffic(uint8_t __subMenu)
{
    menu=MENU_POLY_COEFFIC;
    subMenu=__subMenu;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	//adjValue=0x00ul;
	adjValue=(int32_t)(fps->ployCoeffic[subMenu]);
	adjLocation=0;    
}

void __enter_menu_warn_type(uint8_t __subMenu)
{
	menu=MENU_SET_WARN_TYPE;
	subMenu=__subMenu;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	adjValue=0x00ul;
	*((uint8_t*)(&adjValue))=(uint8_t)(fps->diffPressureWarnSet[subMenu].type);
	adjLocation=0;	
}

void __enter_menu_warn_value(uint8_t __subMenu)
{
	int32_t t32;
	menu=MENU_SET_WARN_VALUE;
	subMenu=__subMenu;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	if(subMenu>=4){
		t32=fps->diffPressureWarnSet[subMenu-4].warnValueHi;
	}else{
		t32=fps->diffPressureWarnSet[subMenu].warnValueLo;
	}
	t32=__int32_2_mflot32(t32);
	m_floatAdj.t32=t32;
	adjLocation=0;
}

void __enter_menu_epr_zero_line(uint8_t __subMenu)
{
	int32_t t32;
	menu=MENU_SET_EPR_ZERO_LINE;
	subMenu=__subMenu;
	if(subMenu>sub_MENU_SET_EPR_LINE_1)subMenu=sub_MENU_SET_EPR_LINE_1;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	if(subMenu>=2){
		t32=fps->ex_pressLine[subMenu-2];
	}else{
		t32=fps->ex_pressZero[subMenu];
	}
	t32=__int32_2_mflot32(t32);
	m_floatAdj.t32=t32;
	adjLocation=0;	
}

void __enter_menu_epr_ilp_scale(uint8_t __subMenu)
{
	menu=PSW_SET_EPR_ILOOP_SCALE;
	subMenu=__subMenu;
	if(subMenu>sub_MENU_SET_EX_DPR_ILP_Hi1)subMenu=sub_MENU_SET_EX_DPR_ILP_Hi1;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	if(subMenu>=2){
		adjValue=(int32_t)(fps->ex_pressiLoopUpper[subMenu-2]);
	}else{
		adjValue=(int32_t)(fps->ex_pressiLoopLow[subMenu]);
	}
	adjLocation=0;
}

void __enter_menu_bar_scale(void)
{
	menu=MENU_SET_BAR_LEVEL_SCALE;
	subMenu=sub_MENU_SET_BAR_LEVEL_SCALE;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	adjValue=fps->barScale;
	adjLocation=0;
}

void __enter_menu_work_mode(void)
{
	menu=MENU_SET_WORK_MODE;
	subMenu=sub_MENU_SET_WORK_MODE;
	*((uint8_t*)(&adjValue))=dwm;
	adjLocation=0;
}

void __exit_menu_to_home_unsave(void)
{
	menu=MENU_HOME;
	subMenu=0x00;

	adjValue=0;
	m_floatAdj.t32=0;
	adjLocation=0x00;
	
	calibRow=0;
	calibCol=0;
	passWord=0x00;
}

void __down_pose_size(void)
{
	switch(subMenu){
	case sub_MENU_SET_L:
	case sub_MENU_SET_D:
		key_shift_loc((uint8_t*)(&adjLocation),0,4);break;
	default:break;
	}
}

void __down_dpr_calib(void)
{
	if(calibCol){
		key_shift_loc((uint8_t*)(&adjLocation),0,4);
	}
}

void __down_pr_calib(void)
{
	if(calibCol){
		key_shift_loc((uint8_t*)(&adjLocation),0,4);
	}
}

void key_process_down(void)
{
	switch(menu){
		case MENU_HOME:break;
		case MENU_PASSWORD:key_shift_loc((uint8_t*)(&adjLocation),0,3);break;
		case MENU_SET_DENSITY:key_shift_loc((uint8_t*)(&adjLocation),0,4);break;
		case MENU_SET_POSE_SIZE:__down_pose_size();break;
		case MENU_SET_BASE_ZERO:key_shift_loc((uint8_t*)(&adjLocation),0,5);break;
		case MENU_DIFF_CALIB:__down_dpr_calib();break;
		case MENU_PRESSURE_CALIB:__down_pr_calib();break;
		default:break;
	}	
}

void __up_home_adj(void)
{
	subMenu++;
	if(subMenu>sub_MENU_HOME_02)subMenu=sub_MENU_HOME_00;
}

void __up_psw_adj(void)
{
	key_adj_value_fixed((uint16_t*)(&passWord),adjLocation);
}

void __up_density_adj(void)
{
	key_adj_value_float(&m_floatAdj,adjLocation);
}

void __up_pose_size_adj(void)
{
	uint8_t* p;
	switch(subMenu){
		case sub_MENU_SET_POSE:
			p=(uint8_t*)(&adjValue);
			(*p)=(*p)+1;
			if(*p>VERTICAL)*p=HOTIZONTAL;
			break;
		case sub_MENU_SET_L:
		case sub_MENU_SET_D:
			key_adj_value_float(&m_floatAdj,adjLocation);
			break;
		default:break;
	}
}

void __up_base_zero_adj(void)
{
	key_adj_value_float(&m_floatAdj,adjLocation);
}



void __up_diff_calib_adj(void)
{
	uint8_t t8;
	if(calibCol==0){
		t8=*(uint8_t*)(&adjValue);
		t8++;
		if(t8>=6)t8=2;
		*(uint8_t*)(&adjValue)=t8;
	}else{
		key_adj_value_float(&m_floatAdj,adjLocation);
	}
}

void __up_pr_calib_adj(void)
{
	uint8_t t8;
	if(calibCol==0){
		t8=*(uint8_t*)(&adjValue);
		t8++;
		if(t8>=6)t8=2;
		*(uint8_t*)(&adjValue)=t8;
	}else{	
		key_adj_value_float(&m_floatAdj,adjLocation);
	}
}

void __up_poly_coefic_adj(void)
{
	key_adj_value_fixed((uint16_t*)(&adjValue),adjLocation);
}

void __up_warn_type_adj(void)
{
	uint8_t* p;
	p=(uint8_t*)(&adjValue);
	(*p)=(*p)+1;
	if(*p>PRESSURE_LO)*p=HIGHT_HI;
}

void __up_warn_value_adj(void)
{
	key_adj_value_float(&m_floatAdj,adjLocation);
}

void __up_epr_param_adj(void)
{
	switch(subMenu){
		case sub_MENU_SET_EPR_ZERO_0:
		case sub_MENU_SET_EPR_ZERO_1:
			key_adj_value_float(&m_floatAdj,adjLocation);
			break;
		case sub_MENU_SET_EPR_LINE_0:
		case sub_MENU_SET_EPR_LINE_1:
			key_adj_value_fixed((uint16_t*)(&adjValue),adjLocation);
			break;
		default:break;
	}
}

void __up_epr_ilp_scale_adj(void)
{
	key_adj_value_fixed((uint16_t*)(&adjValue),adjLocation);
}

//-----------------------------------------------------
void __up_adj_bar_level_scale(void)
{
	key_adj_value_fixed((uint16_t*)(&adjValue),adjLocation);
}

void __up_adj_work_mode(void)
{
	uint8_t* p;
	p=(uint8_t*)(&adjValue);
	if(*p==TEST_MODE){
		*p=WORK_MODE;
	}else{
		*p=TEST_MODE;
	}
}

void key_process_up(void)
{
	switch(menu){
		case MENU_HOME:					__up_home_adj();				break;
		case MENU_PASSWORD:				__up_psw_adj();					break;
		case MENU_SET_DENSITY:			__up_density_adj();				break;
		case MENU_SET_POSE_SIZE:		__up_pose_size_adj();			break;
		case MENU_SET_BASE_ZERO:		__up_base_zero_adj();			break;
		case MENU_DIFF_CALIB:			__up_diff_calib_adj();			break;
		case MENU_PRESSURE_CALIB:		__up_pr_calib_adj();			break;
		case MENU_POLY_COEFFIC:			__up_poly_coefic_adj();			break;
		case MENU_SET_WARN_TYPE:		__up_warn_type_adj();			break;
		case MENU_SET_WARN_VALUE:		__up_warn_value_adj();			break;
		case MENU_SET_EPR_ZERO_LINE:	__up_epr_param_adj();			break;
		case MENU_SET_EPR_ILOOP_SCALE:	__up_epr_ilp_scale_adj();		break;
		
		case MENU_SET_BAR_LEVEL_SCALE:	__up_adj_bar_level_scale();	break;
		case MENU_SET_WORK_MODE:        __up_adj_work_mode();		break;
		//case 
		default:break;
	}		
}

void key_process_set_down_long(void)
{
	if(menu==MENU_PASSWORD){
		switch(passWord){
		case PSW_SET_DENSITY:           __enter_menu_set_density();             break;
		case PSW_SET_POSE_SIZE:         __enter_menu_set_pose_size();           break;  
		case PSW_SET_BASE_ZERO:         __enter_menu_set_base_zero();           break;
		case PSW_CALIB_DIFF_PRESSURE:   __enter_menu_calib_press_diff(0,0);     break;
		case PSW_CALIB_PRESSURE:        __enter_menu_calib_press(0,0);          break;   
		case PSW_SET_POLY_COEFFIC:		__enter_menu_poly_coeffic(0);			break;
		case PSW_SET_WARN_TYPE:			__enter_menu_warn_type(0);				break;
		case PSW_SET_WARN_VALUE:		__enter_menu_warn_value(0);				break;
		case PSW_SET_EPR_ZERO_LINE:		__enter_menu_epr_zero_line(0);			break;
		case PSW_SET_EPR_ILOOP_SCALE:	__enter_menu_epr_ilp_scale(0);			break;
		case PSW_SET_BAR_LEVEL_SCALE:	__enter_menu_bar_scale();				break;
		case PSW_SET_WORK_MODE:			__enter_menu_work_mode();				break;
		default:break;
		}
	}
}
//============================================================================
// uint8_t __sys_data_save_load_buf(void)
// {
	// uint8_t* buf=ldbuf;
    
	// if(sizeof(globleBuffer1)<sizeof(st_sysDataDef))return 0;
	// m_flash_read(SYSTEM_DATA_ADDR,buf,sizeof(st_sysDataDef));	
	// return 1;
// }
uint8_t __sys_data_save_write_flash(void)
{
    uint8_t ret=0;
    st_sysDataDef* stp=(st_sysDataDef*)globleBuffer1; 
    stp->V1=data_sys_cal_v1(stp);
    stp->V2=data_sys_cal_v2(stp);
    crc_append(globleBuffer1,sizeof(st_sysDataDef)-2);
    m_flash_write(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));
    m_flash_read(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));
    ret=crc_verify(globleBuffer1,sizeof(st_sysDataDef));
    return ret;
}

//============================================================================
void __set_short_pose_size(bool gohome)
{
	uint8_t* p;
	int32_t t32;
	st_sysDataDef* stp=(st_sysDataDef*)globleBuffer1; 
	m_flash_read(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));
	switch(subMenu){
        case sub_MENU_SET_POSE:
            p=(uint8_t*)(&adjValue);
			stp->pos=(*p);
			break;
		case sub_MENU_SET_L:
			t32=__mflot32_2_int32(m_floatAdj.t32);
			stp->h=t32;
            break;
		case sub_MENU_SET_D:
            t32=__mflot32_2_int32(m_floatAdj.t32);
            stp->d=t32;
			break;
    }
	if(gohome){__exit_menu_to_home_unsave(); return;}
    __sys_data_save_write_flash();
    subMenu++;
    if(subMenu>sub_MENU_SET_D)subMenu=sub_MENU_SET_POSE;
    switch(subMenu){
        case sub_MENU_SET_POSE: __enter_menu_set_pose_size();   break;
        case sub_MENU_SET_L:    __enter_menu_set_h();           break;
        case sub_MENU_SET_D:    __enter_menu_set_d();           break;
        default:break;
    }
}
extern st_iicDeviceObj* pdiff_prEepromObj;
extern st_iicDeviceObj* p_prEepromObj;
void __set_short_diff_calib(bool gohome)
{
    bool saveFlg=false;
    uint8_t t8,adjv;
	uint16_t t16;
    uint32_t t32,pra;
    if(calibCol==0){
        t8=diff_prCalibTabDef.prCalibRow[calibRow].pCount;
        adjv=*(uint8_t*)(&adjValue);
        if(t8!=adjv){
            saveFlg=true;
            diff_prCalibTabDef.prCalibRow[calibRow].pCount=adjv;
        }
    }else{
        t32=__mflot32_2_int32(m_floatAdj.t32);
        pra=diff_prCalibTabDef.prCalibRow[calibRow].prCalibPoint[calibCol-1].pValue;
        if(pra!=t32){
            diff_prCalibTabDef.prCalibRow[calibRow].prCalibPoint[calibCol-1].pValue=t32;
            diff_prCalibTabDef.prCalibRow[calibRow].prCalibPoint[calibCol-1].pAdcValue=x_prDiffData.pAdcValue;
            diff_prCalibTabDef.prCalibRow[calibRow].prCalibPoint[calibCol-1].tAdcValue=x_prDiffData.tAdcValue;
            saveFlg=true;
        }
    }
	
	if(saveFlg){
		t16=sizeof(diff_prCalibTabDef);
		crc_append((uint8_t*)&diff_prCalibTabDef,t16-2);
		at24c02_write_n_byte(pdiff_prEepromObj,0,(uint8_t*)&diff_prCalibTabDef,t16);        
    }
	if(gohome){__exit_menu_to_home_unsave(); return;}
	calibCol++;
	if(calibCol>diff_prCalibTabDef.prCalibRow[calibRow].pCount){
        calibCol=0;
        calibRow++;
        if(calibRow>2)calibRow=0;
    }
    __enter_menu_calib_press_diff(calibRow,calibCol);
	
}

void __set_short_pr_calib(bool gohome)
{
    bool saveFlg=false;
    uint8_t t8,adjv;
	uint16_t t16;
    uint32_t t32,pra;
    if(calibCol==0){
        t8=prCalibTabDef.prCalibRow[calibRow].pCount;
        adjv=*(uint8_t*)(&adjValue);
        if(t8!=adjv){
            saveFlg=true;
            prCalibTabDef.prCalibRow[calibRow].pCount=adjv;
        }
    }else{
        t32=__mflot32_2_int32(m_floatAdj.t32);
        pra=prCalibTabDef.prCalibRow[calibRow].prCalibPoint[calibCol-1].pValue;
        if(pra!=t32){
            prCalibTabDef.prCalibRow[calibRow].prCalibPoint[calibCol-1].pValue=t32;
            prCalibTabDef.prCalibRow[calibRow].prCalibPoint[calibCol-1].pAdcValue=x_prDiffData.pAdcValue;
            prCalibTabDef.prCalibRow[calibRow].prCalibPoint[calibCol-1].tAdcValue=x_prDiffData.tAdcValue;
            saveFlg=true;
        }
    }
	
	if(saveFlg){
		t16=sizeof(prCalibTabDef);
		crc_append((uint8_t*)&prCalibTabDef,t16-2);
		at24c02_write_n_byte(pdiff_prEepromObj,0,(uint8_t*)&prCalibTabDef,t16);        
    }
	if(gohome){__exit_menu_to_home_unsave(); return;}
	calibCol++;
	if(calibCol>prCalibTabDef.prCalibRow[calibRow].pCount){
        calibCol=0;
        //calibRow++;
        //if(calibRow>2)calibRow=0;
    }
    __enter_menu_calib_press_diff(0,calibCol);
	
}

void __set_short_poly_coefic(bool gohome)
{
	int16_t* p;
	//int32_t t32;
	st_sysDataDef* stp=(st_sysDataDef*)globleBuffer1; 
	m_flash_read(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));	
	//t32=adjValue;
    p=(int16_t*)(&adjValue);
    stp->ployCoeffic[subMenu]=*p;
    __sys_data_save_write_flash();
	
	if(gohome){__exit_menu_to_home_unsave(); return;}
	
    subMenu++;
    if(subMenu>sub_MENU_POLY_COEFFIC_d)subMenu=sub_MENU_POLY_COEFFIC_a;
    __enter_menu_poly_coeffic(subMenu);
}

void __set_short_warn_type(bool gohome)
{
	uint8_t* p;
	//int32_t t32;
	st_sysDataDef* stp=(st_sysDataDef*)globleBuffer1; 
	m_flash_read(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));	
	p=(uint8_t*)(&adjValue);
	stp->diffPressureWarnSet[subMenu].type=*p;
    __sys_data_save_write_flash();
    
    if(gohome){__exit_menu_to_home_unsave(); return;}
    
    subMenu++;
    if(subMenu>sub_MENU_SET_WARN_TYPE_3)subMenu=sub_MENU_SET_WARN_TYPE_0;
    __enter_menu_warn_type(subMenu);  
}

void  __set_short_warn_value(bool gohome)
{
	uint8_t* p;
	int32_t t32;
	st_sysDataDef* stp=(st_sysDataDef*)globleBuffer1; 
	m_flash_read(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));	
	t32=__mflot32_2_int32(m_floatAdj.t32);	
	if(subMenu<sub_MENU_SET_WARN_VALUE_4){
		stp->diffPressureWarnSet[subMenu].warnValueLo=t32;
	}else{
        stp->diffPressureWarnSet[subMenu-sub_MENU_SET_WARN_VALUE_4].warnValueHi=t32;
    }
	__sys_data_save_write_flash();
    
    if(gohome){__exit_menu_to_home_unsave(); return;}
    
    subMenu++;
    if(subMenu>sub_MENU_SET_WARN_VALUE_7)subMenu=sub_MENU_SET_WARN_VALUE_0;
    __enter_menu_warn_value(subMenu);     
}

void __set_short_epr_param(bool gohome)
{
	uint8_t* p;
	int32_t t32;
	st_sysDataDef* stp=(st_sysDataDef*)globleBuffer1; 
	m_flash_read(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));	
    t32=__mflot32_2_int32(m_floatAdj.t32);
    switch(subMenu){
        case sub_MENU_SET_EPR_ZERO_0:
		case sub_MENU_SET_EPR_ZERO_1:
            stp->ex_pressZero[subMenu]=t32;
            break;
		case sub_MENU_SET_EPR_LINE_0:
		case sub_MENU_SET_EPR_LINE_1:
			stp->ex_pressLine[subMenu-sub_MENU_SET_EPR_LINE_0]=t32;
            break;
		default:break;
    }
	__sys_data_save_write_flash();
	
    if(gohome){__exit_menu_to_home_unsave(); return;}
    
    subMenu++;
    if(subMenu>sub_MENU_SET_EPR_LINE_1)subMenu=sub_MENU_SET_EPR_ZERO_0;
    __enter_menu_warn_value(subMenu);   	
}

void __set_short_epr_ilp_scale(bool gohome)
{
	uint8_t* p;
	int32_t t32;
	st_sysDataDef* stp=(st_sysDataDef*)globleBuffer1; 
	m_flash_read(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));	
    t32=__mflot32_2_int32(m_floatAdj.t32);
	switch(subMenu){
		case sub_MENU_SET_EX_DPR_ILP_Lo0:
		case sub_MENU_SET_EX_DPR_ILP_Lo1:
			stp->ex_pressiLoopLow[subMenu]=t32;
			break;
		case sub_MENU_SET_EX_DPR_ILP_Hi0:
		case sub_MENU_SET_EX_DPR_ILP_Hi1:
            stp->ex_pressiLoopUpper[subMenu-sub_MENU_SET_EX_DPR_ILP_Hi0]=t32;
		default:break;
	}
	__sys_data_save_write_flash();
    
    if(gohome){__exit_menu_to_home_unsave(); return;}
    
    subMenu++;
    if(subMenu>sub_MENU_SET_EX_DPR_ILP_Hi1)subMenu=sub_MENU_SET_EX_DPR_ILP_Lo0;
    __enter_menu_epr_ilp_scale(subMenu); 	
}

void __set_long_density(void)
{
	uint8_t* p;
	int32_t t32;
	st_sysDataDef* stp=(st_sysDataDef*)globleBuffer1; 
	m_flash_read(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));	
    t32=__mflot32_2_int32(m_floatAdj.t32);	
	stp->density=t32;
    
    __sys_data_save_write_flash();
    
    __exit_menu_to_home_unsave();
}

void __set_long_base_zero(void)
{
	uint8_t* p;
	int32_t t32;
	st_sysDataDef* stp=(st_sysDataDef*)globleBuffer1; 
	m_flash_read(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));	
    t32=__mflot32_2_int32(m_floatAdj.t32);	
	stp->baseZero=t32;
    
    __sys_data_save_write_flash();
    
    __exit_menu_to_home_unsave();
}
void __set_long_bar_level_scale(void)
{
	int16_t* p;
	int32_t t32;
	st_sysDataDef* stp=(st_sysDataDef*)globleBuffer1; 
	m_flash_read(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));	
    p=(uint16_t*)(&adjValue);	
	stp->barScale=*p;
    
    __sys_data_save_write_flash();
    
    __exit_menu_to_home_unsave();    
}

void __set_long_work_mode(void)
{
	uint8_t* p;
	int32_t t32;
	//st_sysDataDef* stp=(st_sysDataDef*)globleBuffer1; 
	//m_flash_read(SYSTEM_DATA_ADDR,globleBuffer1,sizeof(st_sysDataDef));	
    p=(uint8_t*)(&adjValue);	
	//stp->barScale=*p;
    dwm=*p;
    __exit_menu_to_home_unsave();  	
}
//============================================================================
void key_process_set_long(void)
{
	switch(menu){
		case MENU_HOME:
		case MENU_PASSWORD:             __exit_menu_to_home_unsave();       break;
		case MENU_SET_DENSITY:          __set_long_density();               break;
        case MENU_SET_POSE_SIZE:        __set_short_pose_size(goHOME);      break;
        case MENU_SET_BASE_ZERO:        __set_long_base_zero();             break;
		case MENU_DIFF_CALIB:			__set_short_diff_calib(goHOME);     break;
		case MENU_PRESSURE_CALIB:		__set_short_pr_calib(goHOME);		break;
 		case MENU_POLY_COEFFIC:			__set_short_poly_coefic(goHOME);	break;    
		case MENU_SET_WARN_TYPE:		__set_short_warn_type(goHOME);      break;        
        case MENU_SET_WARN_VALUE:		__set_short_warn_value(goHOME);     break;
		case MENU_SET_EPR_ZERO_LINE:	__set_short_epr_param(goHOME);      break;
		case MENU_SET_EPR_ILOOP_SCALE:	__set_short_epr_ilp_scale(goHOME);  break;    
        
		case MENU_SET_BAR_LEVEL_SCALE:	__set_long_bar_level_scale();       break;
		case MENU_SET_WORK_MODE:        __set_long_work_mode();             break;		
		default:break;
	}
}
//============================================================================
void key_process_set(void)
{
	switch(menu){
		case MENU_HOME:             	__enter_menu_password();	break;
		case MENU_PASSWORD:				break;
		case MENU_SET_DENSITY:			break;
		case MENU_SET_POSE_SIZE:		__set_short_pose_size(unGoHome);	break;
		case MENU_SET_BASE_ZERO:		break;
		case MENU_DIFF_CALIB:			__set_short_diff_calib(unGoHome);	break;
		case MENU_PRESSURE_CALIB:		__set_short_pr_calib(unGoHome);		break;
		
		case MENU_POLY_COEFFIC:			__set_short_poly_coefic(unGoHome);	break;
		case MENU_SET_WARN_TYPE:		__set_short_warn_type(unGoHome);	break;
		
		case MENU_SET_WARN_VALUE:		__set_short_warn_value(unGoHome);	break;
		case MENU_SET_EPR_ZERO_LINE:	__set_short_epr_param(unGoHome);	break;
		case MENU_SET_EPR_ILOOP_SCALE:	__set_short_epr_ilp_scale(unGoHome);break;
		
		case MENU_SET_BAR_LEVEL_SCALE:	break;
		case MENU_SET_WORK_MODE:        break;		
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
		}else if(key == (KEY_VALUE_SET+KEY_VALUE_DOWN)){
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
