#ifndef __iic_gpio_h__
#define __iic_gpio_h__

#ifdef __cplusplus
extern "C"{
#endif

	#include "stdint.h"
	#include <xc.h>
	//#include <pic18f86j93.h>
	#include "p18f86j93.h"
	#include "i2c.h"
	extern st_iicDeviceObj pcf8574;
    
	typedef union{
		uint8_t data;
		struct{
			uint8_t BJ_1:1;
			uint8_t BJ_2:1;
			uint8_t BJ_3:1;
			uint8_t BJ_4:1;
			//
			uint8_t AD421_LATCH_1:1;
            uint8_t AD421_LATCH_2:1;
			uint8_t PGC_AD421_CLOCK:1;
            uint8_t PGD_AD421_DATA:1;
		}bits;
	}st_pcf8574PortDef;
    
    typedef union{
        uint8_t data;
        struct{
			uint8_t BJ_1:1;
			uint8_t BJ_2:1;
			uint8_t BJ_3:1;
			uint8_t BJ_4:1;
            uint8_t :4;
        }bjBits;
    }st_BJ_Def;
	extern st_BJ_Def st_Bj;
    extern st_pcf8574PortDef st_pcf8574PortUsage;
    extern uint8_t pcf8574Value;
    extern void pcf8574_init(void);
    extern void pcf8574_write_singel(uint8_t x);
    
#ifdef __cplusplus
}
#endif

#endif
//file end
