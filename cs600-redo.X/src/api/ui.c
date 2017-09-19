#include "../includes/includes.h"
#include <stdbool.h>
#define __STR_cs66 (uint8_t*)("cs66")
#define fi_twinkle() (RTCCFGbits.HALFSEC)
#define LCD_LINE_0		0
#define LCD_LINE_1		1
//uint8_t tmpBuffer[16];
extern st_RtcDef glRtc;
uint8_t lcdTwinkle=0;

void __x_arrange_str(uint8_t *str,uint8_t len)
{
	uint8_t i;
	for(i=0;i<len;i++){
		if(str[i]=='\0')str[i]=' ';
	}
	str[i]='\0';
}

/*
	下面两个函数非常恶心，液晶面板上面4个有效数字，3个小数点。
	显示的数据范围为0.000~9999.000。
	如果为负数
	显示范围为-0.00~999,00
	规定，int32类型固定为三个小数位，
	通过下面的函数调整小数点的位置。
*/
/*
int32_t __int32_2_mflot32(int32_t x)
{
	st_float32 mf={0};
	uint32_t t32;
	t32=x;
	if(x<0){
		t32 = ((~x) +1);
		mf.stru.sign=1;
	}
	if(mf.stru.sign){
		while(t32>999){
			mf.stru.exponent++;
			t32/=10;
			if( mf.stru.exponent>=2)break;			
		}
		if(t32>999)t32=999;
		mf.stru.significand=t32;		
	}else{
		while(t32>9999){
			mf.stru.exponent++;
			t32/=10;
			if( mf.stru.exponent>=3)break;
		}
		if(t32>9999)t32=9999;
		mf.stru.significand=t32;
	}
	return mf.t32;
}
*/
int32_t __int32_2_mflot32(int32_t x)
{
	st_float32 mf={0};
	uint32_t t32;
	t32=x;
	if(x<0){
		t32 = ((~x) +1);
		mf.stru.sign=1;
	}
	while(t32>9999){
		mf.stru.exponent++;
		t32/=10;
		if( mf.stru.exponent>=3)break;
	}
	if(t32>9999)t32=9999;
	mf.stru.significand=t32;
	return mf.t32;
}

int32_t	__mflot32_2_int32(int32_t x)
{
    uint8_t i;
	st_float32 mf={0};
    int32_t ret;
	mf.t32=x;
    ret=mf.stru.significand;
    for(i=0;i<mf.stru.exponent;i++){
        ret*=10;
    }
    if(mf.stru.sign)ret=((~ret)+1);
	return ret;
}
/*
int32_t __int32_2_parAdj_format(int32_t x)
{
	st_float32 mf={0};
	mf.t32=__int32_2_mflot32(x);
	st_paramAdjFormat tpf={0};
	tpf.stru.exponent=mf.stru.exponent;
	tpf.stru.sign=mf.stru.sign;
	uint16_t t16=mf.stru.significand;
	tpf.stru.c0=(uint8_t)(t16 %10);
	t16/=10;
	tpf.stru.c1=(uint8_t)(t16 %10);
	t16/=10;
	tpf.stru.c2=(uint8_t)(t16 %10);
	t16/=10;   
	tpf.stru.c3=(uint8_t)(t16 %10);
	return tpf.t32;
}

int32_t __parAdj_format_2_int32(int32_t x)
{
	st_paramAdjFormat tpf={0};
	tpf.t32=x;
	st_float32 mf={0};
    mf.stru.exponent=tpf.stru.exponent;
    mf.stru.sign=tpf.stru.sign;
    uint16_t t16;
    t16=tpf.stru.c3;
    t16*=10;
    t16+=tpf.stru.c2;
    t16*=10;
    t16+=tpf.stru.c1;
    t16*=10;
    t16+=tpf.stru.c0;
    mf.stru.significand=t16;
    return __mflot32_2_int32(mf.t32);
}
*/
void ui_disp_all_on(void)
{
	lcd_disp_all(0xff);
	lcd_disp_refresh();
}

void ui_disp_all_off(void)
{
	lcd_disp_all(0x00);
	lcd_disp_refresh();
}

/*
void ui_disp_clear_buffer(void)
{
	lcd_disp_all(0x00);
}
*/

void ui_disp_start_cs600(uint8_t dly)
{
	uint8_t t8;
	uint8_t buf[6]="-00-";
	lcd_disp_clear_buffer();
	lcd_show_string_l0(__STR_cs66);
	lcd_disp_logo(true);
	t8=dly;
	if(t8<1)t8=1;
	while(t8){
		m_int8_2_hex(buf+1,t8-1);
		buf[4]='\0';
		lcd_show_string_l1(buf);
        //lcd_disp_level(60);
		lcd_disp_refresh();
		ticker_dly(1000);
		t8--;
	}
}

void ui_disp_rtc_mm_ss(void)
{
    uint8_t buf[10];
    uint8_t t8;
    if(RTCCFGbits.HALFSEC){
        lcd_show_dp(1,false);
    }else{
        rtc_get();
        t8=glRtc.hour;
        m_int8_2_hex(buf,t8);
        t8=glRtc.minute;
        m_int8_2_hex(buf+2,t8);
        //buf[4]='\0';
        t8=glRtc.month;
        m_int8_2_hex(buf+4,t8);
        t8=glRtc.date;
        m_int8_2_hex(buf+6,t8);
        buf[8]='\0';
        //lcd_show_string_l0(buf); 
        lcd_show_string(buf); 
        lcd_show_dp(1,true);
        lcd_show_dp(5,true);
    }
    lcd_disp_level(60);
    lcd_disp_refresh();
}
void ui_disp_clear_num_dp(void)
{
	lcd_show_string((uint8_t*)"        ");
	lcd_show_dp(0,false);
    lcd_show_dp(1,false);
    lcd_show_dp(2,false);
    lcd_show_dp(4,false);
    lcd_show_dp(5,false);
    lcd_show_dp(6,false);
}

void ui_disp_adj_xfloat_pt(uint8_t* str,st_float32_m* xpf,uint8_t loc)
{
    uint8_t buf[10];
    uint8_t t8;
	uint16_t x;
	x=xpf->stru.significand;
	m_mem_cpy(buf,str);
	if(xpf->stru.sign){
		x/=10;
        if(x>999)x=999;
		m_int16_2_str_4(buf+4,x);
		buf[4]='-';
		if(loc>2)loc=2;
		loc++;
    }else{
		if(x>9999)x=9999;
		m_int16_2_str_4(buf+4,x);
		if(loc>3)loc=3;
	}
	__x_arrange_str(buf,8);
	if(!fi_lcd_twinkle_lock()){
		if(!fi_twinkle())buf[4+loc]=' ';
	}
	t8=xpf->stru.exponent+xpf->stru.sign;
	if(t8<3)lcd_show_dp(4+t8,true);
	lcd_show_string(buf); 
	lcd_disp_refresh();    
}

void ui_disp_adj_xfixed_pt(uint8_t* str,uint16_t x,uint8_t loc)
{
    uint8_t buf[10];
	ui_disp_clear_num_dp();
	if(x>9999)x=9999;
	m_mem_cpy(buf,str);
	m_int16_2_str_4(buf+4,x);
	__x_arrange_str(buf,8);
	if(loc>3)loc=3;
	loc=3-loc;
	if(!fi_lcd_twinkle_lock()){
		if(!fi_twinkle())buf[4+loc]=' ';
	}
	lcd_show_string(buf); 
	lcd_disp_refresh();
}

void ui_disp_xfloat_pt(st_float32_m* xpf,uint8_t line)
{
    uint8_t buf[10];
    uint8_t t8;
	uint16_t x;
	if(line>1)return; 
	x=xpf->stru.significand;
	if(xpf->stru.sign){
		x/=10;
        if(x>999)x=999;
        m_int16_2_str_4(buf,x);
        buf[0]='-';
    }else{
        if(x>9999)x=9999;
        m_int16_2_str_4(buf,x);
    }
    buf[5]='\0';
	if(line==0){
		lcd_show_string_l0(buf);
	}else{
		lcd_show_string_l1(buf);
	}
    t8=xpf->stru.exponent+xpf->stru.sign;
    if(t8<3)lcd_show_dp(t8+4*line,true);
	//lcd_disp_refresh();    
}

void ui_disp_menu_psw_adj(void)
{
	lcd_clear_all();
	lcd_disp_logo(true);
	ui_disp_adj_xfixed_pt((uint8_t*)" psd",passWord,adjLocation);
}

// 第一个界面第一行显示高度,第二行压力MPA;
void ui_disp_menu_home_00(void)
{
	//差压
	uint8_t t8;
	st_float32 mf;
	ui_disp_clear_num_dp();
	mf.t32=__int32_2_mflot32(rtHight);
	ui_disp_xfloat_pt(&mf,LCD_LINE_0);
	lcd_disp_unit_1st_m(true);
	
	mf.t32=__int32_2_mflot32(rtDiffPressure);//rtPressure
	ui_disp_xfloat_pt(&mf,LCD_LINE_1);
	lcd_disp_unit_mpa(true);
	t8=cal_diff_hight_level();
	lcd_disp_level(t8);

	lcd_disp_refresh(); 
}

// 第二个界面第一行显示体积,第二行压力MPA;
void ui_disp_menu_home_01(void)
{
	//差压
	uint8_t t8;
	st_float32 mf;
	ui_disp_clear_num_dp();
	mf.t32=__int32_2_mflot32(rtVolume);
	ui_disp_xfloat_pt(&mf,LCD_LINE_0);
	lcd_disp_unit_1st_m3(true);
	
	mf.t32=__int32_2_mflot32(rtDiffPressure);
	ui_disp_xfloat_pt(&mf,LCD_LINE_1);
	lcd_disp_unit_mpa(true);
	t8=cal_diff_hight_level();
	lcd_disp_level(t8);

	lcd_disp_refresh(); 
}

// 第三个界面第一行显示重量吨,第二行压力MPA;
void ui_disp_menu_home_02(void)
{
	//差压
	uint8_t t8;
	st_float32 mf;
	ui_disp_clear_num_dp();
	mf.t32=__int32_2_mflot32(rtWeight);
	ui_disp_xfloat_pt(&mf,LCD_LINE_0);
	//lcd_disp_unit_1st_m3(true);
	lcd_disp_unit_t(true);
	
	mf.t32=__int32_2_mflot32(rtDiffPressure);
	ui_disp_xfloat_pt(&mf,LCD_LINE_1);
	lcd_disp_unit_mpa(true);
	t8=cal_diff_hight_level();
	lcd_disp_level(t8);

	lcd_disp_refresh(); 
}
void ui_disp_menu_home(void)
{
	switch(subMenu){
		case sub_MENU_HOME_00:ui_disp_menu_home_00();break;
		case sub_MENU_HOME_01:ui_disp_menu_home_01();break;
		case sub_MENU_HOME_02:ui_disp_menu_home_02();break;
		default:break;
	}
}
void ui_disp_menu_density_adj(void)
{
	lcd_clear_all();
	lcd_disp_logo(true);
	ui_disp_adj_xfixed_pt((uint8_t*)"   p",&m_floatAdj,adjLocation);		
}

void ui_disp_menu_pos_adj(void)
{
	uint8_t buf[6];
	lcd_clear_all();
	lcd_disp_logo(true);
	m_mem_cpy(buf,(uint8_t*)"  fs");
	lcd_show_string_l0(buf);
	uint8_t* p=(uint8_t*)(&adjValue);
	m_mem_cpy(buf,(uint8_t*)"    ");
	if(*p==HOTIZONTAL){
		buf[3]='l';
	}else{
		buf[3]='h';
	}
	lcd_show_string_l1(buf);
	lcd_disp_refresh(); 
}

void ui_disp_menu_h_adj(void)
{
	lcd_clear_all();
	lcd_disp_logo(true);
	ui_disp_adj_xfixed_pt((uint8_t*)"   h",&m_floatAdj,adjLocation);	
}

void ui_disp_menu_d_adj(void)
{
	lcd_clear_all();
	lcd_disp_logo(true);
	ui_disp_adj_xfixed_pt((uint8_t*)"   d",&m_floatAdj,adjLocation);		
}
void ui_disp_menu_pose_size(void)
{
    switch(subMenu){
        case sub_MENU_SET_POSE: ui_disp_menu_pos_adj(); break;
        case sub_MENU_SET_L:    ui_disp_menu_h_adj();   break;
        case sub_MENU_SET_D:    ui_disp_menu_d_adj();   break;
        default:break;
    }

}
void ui_disp_menu_bzero_adj(void)
{
	lcd_clear_all();
	lcd_disp_logo(true);
	ui_disp_adj_xfixed_pt((uint8_t*)"  hd",&m_floatAdj,adjLocation);	
}

void ui_disp_menu_calib_diff_adj(void)
{
	
}

void ui_disp_menu_calib_pr_adj(void)
{
	
}

void ui_disp_menu_poly_c_adj(void)
{
	uint8_t buf[6];
	uint8_t t8;
	
	lcd_clear_all();
	lcd_disp_logo(true);
	
	t8=subMenu;
	if(t8>3)return;
	m_mem_cpy(buf,(uint8_t*)"    ");
	
	buf[3]='a'+t8;
	ui_disp_adj_xfixed_pt(buf,adjValue,adjLocation);
}

void ui_disp_menu_warn_t_adj(void)
{
	uint8_t buf[6];
	uint8_t t8;		
	lcd_clear_all();
	lcd_disp_logo(true);
	t8=subMenu;
	if(t8>3)return;
	//这个地方的显示字符需要确认用atx还是alx
	m_mem_cpy(buf,(uint8_t*)"alt0");
	buf[3]='0'+t8;
	
	lcd_show_string_l0(buf);
	uint8_t* p=(uint8_t*)(&adjValue);
	m_mem_cpy(buf,(uint8_t*)"    ");
	if(*p==HIGHT_HI){
		m_mem_cpy(buf,(uint8_t*)" h-u");
	}else if(*p==HIGHT_LO){
		m_mem_cpy(buf,(uint8_t*)" h-d");
	}else if(*p==PRESSURE_HI){
		m_mem_cpy(buf,(uint8_t*)" p-u");
	}else{
		m_mem_cpy(buf,(uint8_t*)" p-d");
	}
	lcd_show_string_l1(buf);
	lcd_disp_refresh(); 
	
}

void ui_disp_menu_warn_v_adj(void)
{
	uint8_t buf[6];
	uint8_t t8,type;
	int32_t t32	;
	lcd_clear_all();
	lcd_disp_logo(true);
	t8=subMenu;
	if(t8>7)return;
	st_sysDataDef* fps=(st_sysDataDef*)SYSTEM_DATA_ADDR;
	//if(fps->diffPressureWarnSet[t8>>1].type);
	if(t8<3){
		//t32=fps->diffPressureWarnSet[t8].warnValueLo;
		type=fps->diffPressureWarnSet[t8].type;
		m_mem_cpy(buf,(uint8_t*)" al0");
	}else{
		t8=t8-4;
		//t32=fps->diffPressureWarnSet[t8].warnValueHi;
		type=fps->diffPressureWarnSet[t8].type;	
		m_mem_cpy(buf,(uint8_t*)" ah0");
	}
	buf[3]='0'+t8;
	
	if(type == HIGHT_HI || type== HIGHT_HI){
		lcd_disp_unit_2nd_m(true);
	}else{
		lcd_disp_unit_mpa(true);
	}
	ui_disp_adj_xfixed_pt(buf,&m_floatAdj,adjLocation);
}

void ui_disp_menu_ep_z_adj(void)
{
	
	
}

void ui_disp_menu_ep_l_adj(void)
{
	
	
}

void ui_disp_menu_epr_param_adj(void)
{
    
}
void ui_disp_menu_ep_ilp_lo_adj(void)
{
	
}

void ui_disp_menu_ep_ilp_hi_adj(void)
{
	
}
void ui_disp_menu_epr_ilp_param_adj(void)
{
    
}

void ui_disp_menu_bar_full_adj(void)
{
	
}

void ui_disp_menu(void)
{
	switch(menu){
		case MENU_HOME:					ui_disp_menu_home();			break;
		case MENU_PASSWORD:				ui_disp_menu_psw_adj();			break;		
		case MENU_SET_DENSITY:			ui_disp_menu_density_adj();		break;		
		case MENU_SET_POSE_SIZE:		ui_disp_menu_pose_size();		break;
		case MENU_SET_BASE_ZERO:		ui_disp_menu_bzero_adj();		break;
		
		case MENU_DIFF_CALIB:			ui_disp_menu_calib_diff_adj();	break;
		case MENU_PRESSURE_CALIB:		ui_disp_menu_calib_pr_adj();	break;
		
		case MENU_POLY_COEFFIC:			ui_disp_menu_poly_c_adj();		break;
		
		case MENU_SET_WARN_TYPE:        ui_disp_menu_warn_t_adj();		break;
		case MENU_SET_WARN_VALUE:		ui_disp_menu_warn_v_adj();		break;
		
		case MENU_SET_EPR_ZERO_LINE:		
									ui_disp_menu_epr_param_adj();		break;
		case MENU_SET_EPR_ILOOP_SCALE:	
									ui_disp_menu_epr_ilp_param_adj();	break;
		case MENU_SET_FULL_LEVEL_BAR:	ui_disp_menu_bar_full_adj();	break;
		default:break;
	}	
}
//file end
