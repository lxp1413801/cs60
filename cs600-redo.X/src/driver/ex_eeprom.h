#ifndef __ex_eeprom_h__
#define __ex_eeprom_h__

#ifdef __cplusplus
extern "C"{
#endif
	#include "stdint.h"
	#include <xc.h>
	//#include <pic18f86j93.h>
	#include "p18f86j93.h"
	#include "i2c.h"
	
	extern st_iicDeviceObj at24c02Ch0,at24c02Ch1;	
	extern void at24c02_init(st_iicDeviceObj* pAt24c02, uint8_t slv);
	extern void at24c02_init_all_chip(void);
    extern uint8_t at24c02_read_byte(st_iicDeviceObj* pAt24c02,uint8_t addr);
	extern void at24c02_read_n_byte(st_iicDeviceObj* pAt24c02,uint8_t addr,uint8_t* buf,uint16_t len);
	extern void at24c02_write_byte(st_iicDeviceObj* pAt24c02,uint8_t addr,uint8_t x);
	extern void at24c02_write_n_byte(st_iicDeviceObj* pAt24c02,uint8_t addr,uint8_t* buf,uint16_t len);
	

#ifdef __cplusplus
}
#endif

#endif
//file end
