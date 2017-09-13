#ifndef __ads_1115_h__
#define __ads_1115_h__

#ifdef __cplusplus
extern "C"{
#endif
	#include "stdint.h"
	#include <xc.h>
	//#include <pic18f86j93.h>
	#include "p18f86j93.h"
	#include "i2c.h"
	
	//
	#define ADS1115_CONFIG_DEFAULT	0x8583;
	//#define ADS1X1X_OS_START_SINGLE_CONVERSION 	1
	#define ADS1X1X_OS_CONVERSING				0
	#define ADS1X1X_OS_CONVERSED				1
	// I2C definitions.
	#define ADS1x1x_I2C_ADDRESS_ADDR_TO_GND  (0x90)
	#define ADS1x1x_I2C_ADDRESS_ADDR_TO_VCC  (0x92)
	#define ADS1x1x_I2C_ADDRESS_ADDR_TO_SDA  (0x94)
	#define ADS1x1x_I2C_ADDRESS_ADDR_TO_SCL  (0x96)

	// Chip "pointer" registers
	#define ADS1x1x_REG_POINTER_MASK  (0x03)
	#define ADS1x1x_REG_POINTER_CONVERSION  (0x00)
	#define ADS1x1x_REG_POINTER_CONFIG  (0x01)
	#define ADS1x1x_REG_POINTER_LO_THRESH  (0x02)
	#define ADS1x1x_REG_POINTER_HI_THRESH  (0x03)	
	
	//mux
	typedef enum{
		ADS1X1X_OS_START_SINGLE_CONVERSION=1,
	}em_Ads1x1xOsDef_t;
	typedef enum{ 
		ADS1X1X_MUX_DIFF_0_1 = 0x00,  // Differential P = AIN0, N = AIN1 (default)
		ADS1X1X_MUX_DIFF_0_3 = 0x01,  // Differential P = AIN0, N = AIN3
		ADS1X1X_MUX_DIFF_1_3 = 0x02,  // Differential P = AIN1, N = AIN3
		ADS1X1X_MUX_DIFF_2_3 = 0x03,  // Differential P = AIN2, N = AIN3
		ADS1X1X_MUX_SINGLE_0 = 0x04,  // Single-ended AIN0
		ADS1X1X_MUX_SINGLE_1 = 0x05,  // Single-ended AIN1
		ADS1X1X_MUX_SINGLE_2 = 0x06,  // Single-ended AIN2
		ADS1X1X_MUX_SINGLE_3 = 0x07   // Single-ended AIN3
	}em_Ads1x1xMuxDef_t,em_ADS1X1X_MUX;
	//gpa
	typedef enum
	{
		ADS1X1X_PGA_6144 = 	0x00,  // +/-6.144V range = Gain 2/3
		ADS1X1X_PGA_4096 = 	0x01,  // +/-4.096V range = Gain 1
		ADS1X1X_PGA_2048 = 	0x02,  // +/-2.048V range = Gain 2 (default)
		ADS1X1X_PGA_1024 = 	0x03,  // +/-1.024V range = Gain 4
		ADS1X1X_PGA_512 = 	0x04,  // +/-0.512V range = Gain 8
		ADS1X1X_PGA_256 = 	0x05  // +/-0.256V range = Gain 16
		//ADS1X1X_PGA_256 = 	0x06  // +/-0.256V range = Gain 16		
	}em_Ads1x1xPgaDef_t,em_ADS1X1X_PGA;
	
	typedef enum
	{
		ADS1X1X_MODE_CONTINUOUS = 0,  // Continuous conversion mode
		ADS1X1X_MODE_SINGLE_SHOT = 1  // Power-down single-shot mode (default)
	}em_Ads1x1xModeDef_t,em_ADS1X1X_MODE;
	typedef enum
	{
		// ADS101x
		ADS101X_DATA_RATE_128 = 0,  // 128 samples per second
		ADS101X_DATA_RATE_250 = 1,  // 250 samples per second
		ADS101X_DATA_RATE_490 = 2,  // 490 samples per second
		ADS101X_DATA_RATE_920 = 3,  // 920 samples per second
		ADS101X_DATA_RATE_1600 = 4,  // 1600 samples per second (default)
		ADS101X_DATA_RATE_A2400 = 5,  // 2400 samples per second
		ADS101X_DATA_RATE_3300 = 6,  // 3300 samples per second
		// ADS111x
		ADS1X1X_DATA_RATE_8 = 0,  // 8 samples per second
		ADS1X1X_DATA_RATE_16 = 1,  // 16 samples per second
		ADS1X1X_DATA_RATE_32 = 2,  // 32 samples per second
		ADS1X1X_DATA_RATE_64 = 3,  // 64 samples per second
		ADS1X1X_DATA_RATE_128 = 4,  // 128 samples per second (default)
		ADS1X1X_DATA_RATE_250 = 5,  // 250 samples per second
		ADS1X1X_DATA_RATE_475 = 6,  // 475 samples per second
		ADS1X1X_DATA_RATE_860 = 7  // 860 samples per second
	}em_Ads1x1xDrDef_t,em_ADS1X1X_DR;
	typedef enum
	{
		COMP_MODE_TRADITIONAL = 0,  // Traditional comparator with hysteresis (default)
		COMP_MODE_WINDOW = 1  // Window comparator
	}em_Ads1x1xCompModeDef_t,em_ADS1X1X_COMPARATOR_MODE;
	typedef enum
	{
		COMP_POLARITY_ACTIVE_LO = 0,  // ALERT/RDY pin is low when active (default)
		COMP_POLARITY_ACTIVE_HI = 1  // ALERT/RDY pin is high when active
	}em_Ads1x1xCompPolarity_t;
	typedef enum
	{
		COMP_NON_LATCHING = 0,  // Non-latching comparator (default)
		COMP_LATCHING = 1  // Latching comparator
	}em_Ads1x1xCompLatch_t;
	typedef enum
	{
		COMP_QUEUE_1 = 0,  // Assert ALERT/RDY after one conversions
		COMP_QUEUE_2 = 1,  // Assert ALERT/RDY after two conversions
		COMP_QUEUE_4 = 2,  // Assert ALERT/RDY after four conversions
		COMP_QUEUE_DISABLE = 4  // Disable the comparator and put ALERT/RDY in high state (default)
	}em_Ads1x1xCompQueue_t;

	typedef enum{
		ADS1013,
		ADS1014,
		ADS1015,
		ADS1113,
		ADS1114,
		ADS1115		
	}em_Ads1x1xChip_t;
	typedef union{
		
		uint16_t data;
		struct{
			uint16_t 	COMP_QUE:2;
			uint16_t	COMP_LAT:1;
			uint16_t	COMP_POL:1;
			uint16_t	COMP_MODE:1;
			uint16_t	DR:3;
			uint16_t	MODE:1;
			uint16_t	PGA:3;
			uint16_t	MUX:3;
			uint16_t	OS;
		}bits;
	}st_ads1115ConfigDef;
	typedef struct{
		em_Ads1x1xChip_t chip;
		uint8_t slaveAddr;
		st_ads1115ConfigDef config;
		void (*iic_start)(void);
		void (*iic_stop)(void);
		uint8_t (*iic_send_byte)(uint8_t);
		uint8_t (*iic_waite_ack)(void);
		uint8_t (*iic_received_byte_if_ack)(uint8_t ack);
	}st_ads1115ObjDef;
	
	extern st_ads1115ObjDef ads1115Chip0,ads1115Chip1;
	extern st_ads1115ObjDef* pAds1115DiffPrObj;
	extern st_ads1115ObjDef* pAds1115PrObj;
	extern void ads1115_init(st_ads1115ObjDef* pAds1115,uint8_t slvaddr);
	extern void ads1115_init_all_chip(void);
	extern void ads1115_start_conversion(st_ads1115ObjDef* pAds1115);
    extern uint16_t ads1115_read_conversion(st_ads1115ObjDef* pAds1115);
    extern void ads1115_set_mux(st_ads1115ObjDef* pAds1115,em_Ads1x1xMuxDef_t mux);
    extern uint16_t ads1115_read_reg(st_ads1115ObjDef* pAds1115,uint8_t addr);
	
	//extern void 
	
	
#ifdef __cplusplus
}
#endif

#endif
//file end
