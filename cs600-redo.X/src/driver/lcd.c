#include <stdint.h>
#include <stdbool.h>
#include <xc.h>
//#include <pic18f86j93.h>
#include "p18f86j93.h"
#include "lcd_code_table.h"
// #include "lcd_com_seg_clr.h"
// #include "lcd_com_seg_set.h"
#include "lcd.h"
#include "../depend/depend.h"
#include "../driver/m_gpio.h"
#include "../configs/configs.h"

//uint8_t* pLcdReg=(uint8_t*)(&LCDDATA0); 
uint8_t pLCD[LCD_PIXEL_REGISTER_SIZE];

const uint8_t  LCDDigitalIndexTable[]="0123456789abcdefghijklmnopqrstuvwxyz.-: GH";
const uint8_t LCDDigitalTable[]=
{
    LCD_CODE_0,LCD_CODE_1,LCD_CODE_2,LCD_CODE_3,
    LCD_CODE_4,LCD_CODE_5,LCD_CODE_6,LCD_CODE_7,
    LCD_CODE_8,LCD_CODE_9,LCD_CODE_A,LCD_CODE_B,
    LCD_CODE_C,LCD_CODE_D,LCD_CODE_E,LCD_CODE_F,
    LCD_CODE_G,LCD_CODE_H,LCD_CODE_I,LCD_CODE_J,
    LCD_CODE_K,LCD_CODE_L,LCD_CODE_M,LCD_CODE_N,
    LCD_CODE_O,LCD_CODE_P,LCD_CODE_Q,LCD_CODE_R,
    LCD_CODE_S,LCD_CODE_T,LCD_CODE_U,LCD_CODE_V,
    LCD_CODE_W,LCD_CODE_X,LCD_CODE_Y,LCD_CODE_Z,
    LCD_CODE_DOT,LCD_CODE__,LCD_CODE_DDOT,0x00,
	LCD_CODE_G_U,LCD_CODE_H_U,
};
 
void lcd_set_com_seg(uint8_t com,uint8_t seg,uint8_t show)
{
	uint8_t offset;
	uint8_t	bits;
	if(com>3)return;
	if(seg>47)return;
	offset=com*6 + seg/8;
	bits=seg%8;
	if(show){
		pLCD[offset] |= (1<<bits);
	}else{
		pLCD[offset] &= ~(1<<bits);
	}
}
void lcd_disp_level_bar(uint8_t bar,uint8_t show)
{
	//0-49 swap 
	uint8_t __bar;
	if(bar>49)return;
	__bar=49-bar;
	switch(__bar){
		case 0:		lcd_set_com_seg(0,46,show);	break;
		case 1:		lcd_set_com_seg(1,46,show);	break;
		case 2:		lcd_set_com_seg(2,46,show);	break;
		case 3:		lcd_set_com_seg(3,46,show);	break;
		
		case 4:		lcd_set_com_seg(3,47,show);	break;
		case 5:		lcd_set_com_seg(2,47,show);	break;
		case 6:		lcd_set_com_seg(1,47,show);	break;
		case 7:		lcd_set_com_seg(0,47,show);	break;
		
		case 8:		lcd_set_com_seg(0,31,show);	break;
		case 9:		lcd_set_com_seg(1,31,show);	break;		
		case 10:	lcd_set_com_seg(2,31,show);	break;
		case 11:	lcd_set_com_seg(3,31,show);	break;
		
		case 12:	lcd_set_com_seg(3,0,show);	break;
		case 13:	lcd_set_com_seg(2,0,show);	break;
		case 14:	lcd_set_com_seg(1,0,show);	break;
		case 15:	lcd_set_com_seg(0,0,show);	break;
		
		case 16:	lcd_set_com_seg(0,1,show);	break;
		case 17:	lcd_set_com_seg(1,1,show);	break;
		case 18:	lcd_set_com_seg(2,1,show);	break;
		case 19:	lcd_set_com_seg(3,1,show);	break;
		
		case 20:	lcd_set_com_seg(3,2,show);	break;
		case 21:	lcd_set_com_seg(2,2,show);	break;
		case 22:	lcd_set_com_seg(1,2,show);	break;
		case 23:	lcd_set_com_seg(0,2,show);	break;
		
		case 24:	lcd_set_com_seg(0,3,show);	break;
		case 25:	lcd_set_com_seg(1,3,show);	break;
		case 26:	lcd_set_com_seg(2,3,show);	break;
		case 27:	lcd_set_com_seg(3,3,show);	break;
		
		case 28:	lcd_set_com_seg(3,4,show);	break;
		case 29:	lcd_set_com_seg(2,4,show);	break;		
		case 30:	lcd_set_com_seg(1,4,show);	break;
		case 31:	lcd_set_com_seg(0,4,show);	break;
		
		case 32:	lcd_set_com_seg(0,5,show);	break;
		case 33:	lcd_set_com_seg(1,5,show);	break;
		case 34:	lcd_set_com_seg(2,5,show);	break;
		case 35:	lcd_set_com_seg(3,5,show);	break;
		
		case 36:	lcd_set_com_seg(3,6,show);	break;
		case 37:	lcd_set_com_seg(2,6,show);	break;
		case 38:	lcd_set_com_seg(1,6,show);	break;
		case 39:	lcd_set_com_seg(0,6,show);	break;
		
		case 40:	lcd_set_com_seg(0,7,show);	break;
		case 41:	lcd_set_com_seg(1,7,show);	break;
		case 42:	lcd_set_com_seg(2,7,show);	break;
		case 43:	lcd_set_com_seg(3,7,show);	break;
		
		case 44:	lcd_set_com_seg(3,33,show);	break;
		case 45:	lcd_set_com_seg(2,33,show);	break;
		case 46:	lcd_set_com_seg(1,33,show);	break;
		case 47:	lcd_set_com_seg(0,33,show);	break;
		
		case 48:	lcd_set_com_seg(0,34,show);	break;
		case 49:	lcd_set_com_seg(1,34,show);	break;		
	}
}
//@bierf scale:0~99
void lcd_disp_level(uint8_t level)
{
	uint8_t i;
	if(level>=99)level=99;
	level/=2;
	for(i=0;i<level;i++){
		lcd_disp_level_bar(i,1);
	}
	for(;i<50;i++){
		lcd_disp_level_bar(i,0);
	}
}
void lcd_disp_level_off(void)
{
	uint8_t i;
	for(i=0;i<50;i++){
		lcd_disp_level_bar(i,0);
	}	
}


void lcd_disp_battary_bar(uint8_t bar,uint8_t show)
{
	if(bar>=4)bar=4;
	switch(bar){
		case 0:	lcd_set_com_seg(3,35,show);	break;
		case 1:	lcd_set_com_seg(2,35,show);	break;
		case 2:	lcd_set_com_seg(1,35,show);	break;
		case 3:	lcd_set_com_seg(0,35,show);	break;
	}
}
void lcd_disp_battary(uint8_t level)
{
	uint8_t i;
	if(level>=99)level=99;
	level/=25;
	for(i=0;i<level;i++){
		lcd_disp_battary_bar(i,1);
	}
	for(;i<4;i++){
		lcd_disp_battary_bar(i,0);
	}
}
void lcd_disp_battary_off(void)
{
	uint8_t i;
	for(i=0;i<4;i++){
		lcd_disp_battary_bar(i,0);
	}
}

void lcd_disp_rf_bar(uint8_t bar,uint8_t show)
{
	if(bar>=4)bar=4;
	switch(bar){
		case 0:	lcd_set_com_seg(0,30,show);	break;
		case 1:	lcd_set_com_seg(1,30,show);	break;
		case 2:	lcd_set_com_seg(2,30,show);	break;
		case 3:	lcd_set_com_seg(3,30,show);	break;
	}	
}
void lcd_disp_rf(uint8_t rssi)
{
	uint8_t i;
	if(rssi>=99)rssi=99;
	rssi/=25;
	for(i=0;i<rssi;i++){
		lcd_disp_rf_bar(i,1);
	}
	for(;i<4;i++){
		lcd_disp_rf_bar(i,0);
	}
}
void lcd_disp_rf_off(void)
{
	uint8_t i;
	for(i=0;i<4;i++){
		lcd_disp_rf_bar(i,0);
	}
}

void lcd_disp_light_bar(uint8_t bar,uint8_t show)
{
	if(bar>=1)bar=1;
	switch(bar){
		case 0:	lcd_set_com_seg(3,34,show);	break;
		case 1:	lcd_set_com_seg(2,34,show);	break;
	}	
}
void lcd_disp_light(uint8_t light)
{
	uint8_t i;
	if(light>=99)light=99;
	light/=50;
	if(1==light){
		lcd_disp_light_bar(0,1);
		lcd_disp_light_bar(1,1);
	}else{
		lcd_disp_light_bar(0,1);
	}
}
void lcd_disp_light_off(void)
{
	lcd_disp_light_bar(0,0);
	lcd_disp_light_bar(1,0);
}

//show dig.
void lcd_disp_chr_loc_0(uint8_t code)
{
	lcd_set_com_seg(0,25,code&LCD_DSEG_A);
	lcd_set_com_seg(1,25,code&LCD_DSEG_F);
    lcd_set_com_seg(2,25,code&LCD_DSEG_E);
    lcd_set_com_seg(3,25,code&LCD_DSEG_D);
    
    lcd_set_com_seg(0,24,code&LCD_DSEG_B);
    lcd_set_com_seg(1,24,code&LCD_DSEG_G);
    lcd_set_com_seg(2,24,code&LCD_DSEG_C);
    //lcd_disp_com_seg(3,00,code&LCD_DSEG_DP);
}
void lcd_disp_dp_loc_0(bool dp)
{
	if(dp)
		lcd_set_com_seg(3,24,LCD_DSEG_DP);
	else 
		lcd_set_com_seg(3,24,0);
}

void lcd_disp_chr_loc_1(uint8_t code)
{
	lcd_set_com_seg(0,23,code&LCD_DSEG_A);
	lcd_set_com_seg(1,23,code&LCD_DSEG_F);
    lcd_set_com_seg(2,23,code&LCD_DSEG_E);
    lcd_set_com_seg(3,23,code&LCD_DSEG_D);
    
    lcd_set_com_seg(0,22,code&LCD_DSEG_B);
    lcd_set_com_seg(1,22,code&LCD_DSEG_G);
    lcd_set_com_seg(2,22,code&LCD_DSEG_C);	
}
void lcd_disp_dp_loc_1(bool dp)
{
	if(dp)
		lcd_set_com_seg(3,22,LCD_DSEG_DP);
	else 
		lcd_set_com_seg(3,22,0);
}

void lcd_disp_chr_loc_2(uint8_t code)
{
	lcd_set_com_seg(0,21,code&LCD_DSEG_A);
	lcd_set_com_seg(1,21,code&LCD_DSEG_F);
    lcd_set_com_seg(2,21,code&LCD_DSEG_E);
    lcd_set_com_seg(3,21,code&LCD_DSEG_D);
    
    lcd_set_com_seg(0,20,code&LCD_DSEG_B);
    lcd_set_com_seg(1,20,code&LCD_DSEG_G);
    lcd_set_com_seg(2,20,code&LCD_DSEG_C);	
}
void lcd_disp_dp_loc_2(bool dp)
{
	if(dp)
		lcd_set_com_seg(3,20,LCD_DSEG_DP);
	else 
		lcd_set_com_seg(3,20,0);
}

void lcd_disp_chr_loc_3(uint8_t code)
{
	lcd_set_com_seg(0,43,code&LCD_DSEG_A);
	lcd_set_com_seg(1,43,code&LCD_DSEG_F);
    lcd_set_com_seg(2,43,code&LCD_DSEG_E);
    lcd_set_com_seg(3,43,code&LCD_DSEG_D);
    
    lcd_set_com_seg(0,42,code&LCD_DSEG_B);
    lcd_set_com_seg(1,42,code&LCD_DSEG_G);
    lcd_set_com_seg(2,42,code&LCD_DSEG_C);	
}

void lcd_disp_chr_loc_4(uint8_t code)
{
	lcd_set_com_seg(0,36,code&LCD_DSEG_D);
	lcd_set_com_seg(1,36,code&LCD_DSEG_E);
    lcd_set_com_seg(2,36,code&LCD_DSEG_F);
    lcd_set_com_seg(3,36,code&LCD_DSEG_A);
    
    lcd_set_com_seg(1,37,code&LCD_DSEG_C);
    lcd_set_com_seg(2,37,code&LCD_DSEG_G);
    lcd_set_com_seg(3,37,code&LCD_DSEG_B);	
}
void lcd_disp_dp_loc_4(bool dp)
{
	if(dp)
		lcd_set_com_seg(0,37,LCD_DSEG_DP);
	else 
		lcd_set_com_seg(0,37,0);
}

void lcd_disp_chr_loc_5(uint8_t code)
{
	lcd_set_com_seg(0,38,code&LCD_DSEG_D);
	lcd_set_com_seg(1,38,code&LCD_DSEG_E);
    lcd_set_com_seg(2,38,code&LCD_DSEG_F);
    lcd_set_com_seg(3,38,code&LCD_DSEG_A);
    
    lcd_set_com_seg(1,39,code&LCD_DSEG_C);
    lcd_set_com_seg(2,39,code&LCD_DSEG_G);
    lcd_set_com_seg(3,39,code&LCD_DSEG_B);	
}
void lcd_disp_dp_loc_5(bool dp)
{
	if(dp)
		lcd_set_com_seg(0,39,LCD_DSEG_DP);
	else 
		lcd_set_com_seg(0,39,0);
}

void lcd_disp_chr_loc_6(uint8_t code)
{
	lcd_set_com_seg(0,14,code&LCD_DSEG_D);
	lcd_set_com_seg(1,14,code&LCD_DSEG_E);
    lcd_set_com_seg(2,14,code&LCD_DSEG_F);
    lcd_set_com_seg(3,14,code&LCD_DSEG_A);
    
    lcd_set_com_seg(1,15,code&LCD_DSEG_C);
    lcd_set_com_seg(2,15,code&LCD_DSEG_G);
    lcd_set_com_seg(3,15,code&LCD_DSEG_B);	
}
void lcd_disp_dp_loc_6(bool dp)
{
	if(dp)
		lcd_set_com_seg(0,15,LCD_DSEG_DP);
	else 
		lcd_set_com_seg(0,15,0);
}

void lcd_disp_chr_loc_7(uint8_t code)
{
	lcd_set_com_seg(0,19,code&LCD_DSEG_D);
	lcd_set_com_seg(1,19,code&LCD_DSEG_E);
    lcd_set_com_seg(2,19,code&LCD_DSEG_F);
    lcd_set_com_seg(3,19,code&LCD_DSEG_A);
    
    lcd_set_com_seg(1,40,code&LCD_DSEG_C);
    lcd_set_com_seg(2,40,code&LCD_DSEG_G);
    lcd_set_com_seg(3,40,code&LCD_DSEG_B);	
}
/*
void lcd_disp_dp_loc(bool dp,uint8_t loc)
{
	switch(loc){
		case 0:	lcd_disp_dp_loc_0(dp);break;
		case 1:	lcd_disp_dp_loc_1(dp);break;
		case 2:	lcd_disp_dp_loc_2(dp);break;
		case 4:	lcd_disp_dp_loc_4(dp);break;
		case 5:	lcd_disp_dp_loc_5(dp);break;
		case 6:	lcd_disp_dp_loc_6(dp);break;
	}		
}
*/
//show unit
void lcd_disp_logo(bool show)
{
	if(show)
		lcd_set_com_seg(2,13,1);
	else
		lcd_set_com_seg(2,13,0);
}

void lcd_disp_unit_t(bool show)
{
	lcd_set_com_seg(3,41,0);
	lcd_set_com_seg(2,41,0);
	if(show)
		lcd_set_com_seg(3,42,1);
	else
		lcd_set_com_seg(3,42,0);
}

void lcd_disp_unit_1st_m(bool show)
{
	//t2=3;t3=m
	lcd_set_com_seg(3,42,0);
	lcd_set_com_seg(3,41,0);
	if(show){
		lcd_set_com_seg(2,41,1);
	}else{
		lcd_set_com_seg(2,41,0);
	}
}

void lcd_disp_unit_1st_m3(bool show)
{
	//t2=3;t3=m
	lcd_set_com_seg(3,42,0);
	if(show){
		lcd_set_com_seg(2,41,1);
		lcd_set_com_seg(3,41,1);
	}else{
		lcd_set_com_seg(2,41,0);
		lcd_set_com_seg(3,41,0);
	}
}

void lcd_disp_unit_temperature(bool show)
{
	//0C=t7
	if(show){
		lcd_set_com_seg(3,13,1);
	}else{
		lcd_set_com_seg(3,13,0);
	}
}

void lcd_disp_unit_2nd_m(bool show)
{
	//t4=3;t5=m
	lcd_set_com_seg(0,40,0);
	lcd_set_com_seg(1,41,0);
	lcd_set_com_seg(3,13,0);
	if(show)
		lcd_set_com_seg(0,41,1);
	else
		lcd_set_com_seg(0,41,0);
}

void lcd_disp_unit_2nd_m3(bool show)
{
	//t4=3;t5=m
	lcd_set_com_seg(0,40,0);
	lcd_set_com_seg(3,13,0);
	
	if(show){
		lcd_set_com_seg(0,41,1);
		lcd_set_com_seg(1,41,1);
	}else{
		lcd_set_com_seg(0,41,0);
		lcd_set_com_seg(1,41,0);
	}
}

void lcd_disp_unit_mpa(bool show)
{
	//mpa=t6
	lcd_set_com_seg(3,13,0);
	lcd_set_com_seg(1,41,0);
	lcd_set_com_seg(0,41,0);
	if(show){
		lcd_set_com_seg(0,40,1);
	}else{
		lcd_set_com_seg(0,40,0);
	}
}
//enn unit
//api
uint8_t lcd_disp_get_code(uint8_t chr)
{
	uint8_t i;
	uint8_t ret;
	for(i=0;i<sizeof(LCDDigitalIndexTable);i++){
		if(chr==LCDDigitalIndexTable[i])break;
	}
	if(i<sizeof(LCDDigitalIndexTable)){
		ret= LCDDigitalTable[i];
	}
	return ret;
}

void lcd_clear_all_dp(void)
{
	lcd_disp_dp_loc_0(false);
	lcd_disp_dp_loc_1(false);
	lcd_disp_dp_loc_2(false);
	lcd_disp_dp_loc_4(false);
	lcd_disp_dp_loc_5(false);
	lcd_disp_dp_loc_6(false);
}

void lcd_show_dp(uint8_t loc,bool show)
{
	switch(loc){
		case 0:lcd_disp_dp_loc_0(show);break;
		case 1:lcd_disp_dp_loc_1(show);break;
		case 2:lcd_disp_dp_loc_2(show);break;
		//case 3:
		case 4:lcd_disp_dp_loc_4(show);break;
		case 5:lcd_disp_dp_loc_5(show);break;
		case 6:lcd_disp_dp_loc_6(show);break;
		//case 7:
		default:break;
	}		
}

void lcd_show_chr(uint8_t loc,uint8_t chr)
{
    uint8_t code=lcd_disp_get_code(chr);
	switch(loc){
		case 0:lcd_disp_chr_loc_0(code);break;
		case 1:lcd_disp_chr_loc_1(code);break;
		case 2:lcd_disp_chr_loc_2(code);break;
		case 3:lcd_disp_chr_loc_3(code);break;
		case 4:lcd_disp_chr_loc_4(code);break;
		case 5:lcd_disp_chr_loc_5(code);break;
		case 6:lcd_disp_chr_loc_6(code);break;
		case 7:lcd_disp_chr_loc_7(code);break;
		default:break;
	}		
}
//line col.
void lcd_show_chr_lc(uint8_t line,uint8_t col,uint8_t chr)
{
	uint8_t loc;
	if(line>1)return;
	if(col>3)return;
	loc=(line<<1)+col;
	lcd_show_chr(loc,chr);
}

void lcd_show_string_l0(uint8_t* str)
{
	uint8_t t8=0;
	while(*str!='\0' && t8<4){
		lcd_show_chr(t8,*str);
		str++;
		t8++;
	}
}

void lcd_show_string_l1(uint8_t* str)
{
	uint8_t t8=0;
	while(*str!='\0' && t8<4){
		lcd_show_chr(t8+4,*str);
		str++;
		t8++;
	}
}

void lcd_show_string(uint8_t* str)
{
	uint8_t t8=0;
	while(*str!='\0' && t8<8){
		lcd_show_chr(t8,*str);
		str++;
		t8++;
	}
	
}



void lcd_disp_refresh(void)
{
	//m_mem_cpy_len(pLcdReg,pLCD,LCD_PIXEL_REGISTER_SIZE);
	LCDDATA0=pLCD[0];
	LCDDATA1=pLCD[1];
	LCDDATA2=pLCD[2];
	LCDDATA3=pLCD[3];
	LCDDATA4=pLCD[4];
	LCDDATA5=pLCD[5];
	LCDDATA6=pLCD[6];
	LCDDATA7=pLCD[7];
	LCDDATA8=pLCD[8];
	LCDDATA9=pLCD[9];
	
	LCDDATA10=pLCD[10];
	LCDDATA11=pLCD[11];
	LCDDATA12=pLCD[12];
	LCDDATA13=pLCD[13];
	LCDDATA14=pLCD[14];
	LCDDATA15=pLCD[15];
	LCDDATA16=pLCD[16];
	LCDDATA17=pLCD[17];
	LCDDATA18=pLCD[18];
	LCDDATA19=pLCD[19];
	
	LCDDATA20=pLCD[20];	
	LCDDATA21=pLCD[21];
	LCDDATA22=pLCD[22];
	LCDDATA23=pLCD[23];
}

void lcd_disp_all(uint8_t x)
{
    uint8_t i;
    for(i=0;i<LCD_PIXEL_REGISTER_SIZE;i++)
    {
        pLCD[i]=x;
    }
	//lcd_disp_refresh();
}

void lcd_config(void)
{
	//LCDREG=0x32f;
#if LCD_BAILS_MODE==0
     LCDREG=0x7f;
#elif LCD_BAILS_MODE==1
     LCDREG=0x3f;
#elif LCD_BAILS_MODE==2
      //LCDREG=0x78;
     LCDREG=0;
     LCDREGbits.CPEN=1;
     LCDREGbits.BIAS=7;
     LCDREGbits.MODE13=1;
#endif
	LCDPSbits.WFT     = 0;   //0 - TypeA
	LCDPSbits.BIASMD  = 0;
	LCDPSbits.LP3 = 0;
	LCDPSbits.LP2 = 1;
	LCDPSbits.LP1 = 0;
	LCDPSbits.LP0 = 0;

	// TRISDbits.TRISD0=0;//debug
	LCDSE0 = 0b11111111;
	LCDSE1 = 0b11100000;
	LCDSE2 = 0b11111000;
	LCDSE3 = 0b11000011; // Disable Seg30, Seg28 and Seg27
	LCDSE4 = 0b11111110; // Disable unused segments
	LCDSE5 = 0b11001111; // Disable unused segments

	//clear all pixel data
	lcd_clear_all();
	//config reference voltage

	//lcd_on();
}
void lcd_bl_on(void)
{
    set_portg_mode_out(PIN4);
    RTCCFGbits.RTCOE=1;
    set_portg_value_hight(PIN4);
}

void lcd_bl_off(void)
{
    set_portg_mode_in(PIN4);
     RTCCFGbits.RTCOE=0;
    // set_portg_value_hight(PIN4);
}

void lcd_bl_init(void)
{
	set_portg_mode_out(PIN4);
	set_portg_value_hight(PIN4);
}
void lcd_init(void)
{
	lcd_config();
	//lcd_bl_init();
	lcd_on();
	lcd_bl_off();
}
//file end
