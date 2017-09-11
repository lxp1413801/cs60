#include "../includes/includes.h"
#include <stdbool.h>
#define __STR_cs66 (uint8_t*)("cs66")
#define fi_twinkle() (RTCCFGbits.HALFSEC)
//uint8_t tmpBuffer[16];
extern st_RtcDef glRtc;


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
	规定，int32类型固定为三个小数位，
	通过下面的函数调整小数点的位置。
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
		if( mf.stru.exponent==3)break;
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
        lcd_disp_level(60);
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
	if(x>9999)x=9999;
	m_mem_cpy(buf,str);
	m_int16_2_str_4(buf+4,x);
	__x_arrange_str(buf,8);
	if(loc>3)loc=3;
	if(!fi_twinkle())buf[4+loc]=' ';
    t8=xpf->stru.exponent;
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
	if(!fi_twinkle())buf[4+loc]=' ';
	lcd_show_string(buf); 
	lcd_disp_refresh();
}

void ui_disp_menu_psw_adj(void)
{
	ui_disp_adj_xfixed_pt((uint8_t*)" psd",passWord,adjLocation);
}

void ui_disp_menu(void)
{
	switch(menu){
		case MENU_HOME_00:
		case MENU_HOME_01:
		case MENU_HOME_02:
			break;
		case MENU_PASSWORD:ui_disp_menu_psw_adj();break;
		default:break;

	}	
}
//file end
