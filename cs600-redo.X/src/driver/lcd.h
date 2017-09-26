#ifndef __lcd_h__
#define __lcd_h__

#ifdef __cplusplus
extern "C"{
#endif
	
	#include <stdint.h>
    #include <stdbool.h>
	extern uint8_t* pLcdReg;
	#define LCD_PIXEL_REGISTER_SIZE 24
	extern uint8_t pLCD[];
	
    //#define lcd_bl_on() set_portg_value_hight(PIN4);
    //#define lcd_bl_off() set_portg_value_low(PIN4);
    #define lcd_on() LCDCON=0x8f;
	#define lcd_clear_all() lcd_disp_all(0x00);
	extern void lcd_set_com_seg(uint8_t com,uint8_t s,uint8_t show);
	extern void lcd_disp_all(uint8_t x);
	extern void lcd_init(void);
	
	extern void lcd_bl_on(void);
	extern void lcd_bl_off(void);
	
	extern void lcd_disp_refresh(void);
	extern void lcd_show_string_l0(uint8_t* str);
	extern void lcd_show_string_l1(uint8_t* str);
	extern void lcd_show_string(uint8_t* str);
	extern void lcd_clear_all_dp(void);
	extern void lcd_show_dp(uint8_t loc,bool show);
	extern void lcd_disp_logo(bool show);
    
    extern void lcd_disp_level(uint8_t level);
	
	extern void lcd_disp_battary(uint8_t level);
	extern void lcd_disp_rf(uint8_t rssi);
	extern void lcd_disp_light(uint8_t light);
	
	extern void lcd_disp_unit_1st_m(bool show);
	extern void lcd_disp_unit_1st_m3(bool show);
	extern void lcd_disp_unit_t(bool show);
    extern void lcd_disp_unit_2nd_m(bool show);
	extern void lcd_disp_unit_temperature(bool show);
	extern void lcd_disp_unit_2nd_m3(bool show);
	extern void lcd_disp_unit_2nd_m(bool show);
	
	extern void lcd_disp_unit_mpa(bool show);
	#define lcd_disp_clear_buffer() lcd_disp_all(0);
#ifdef __cplusplus
}
#endif

#endif
//file end
