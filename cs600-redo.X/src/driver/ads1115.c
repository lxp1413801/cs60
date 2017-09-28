#include "ads1115.h"
#include "../soc/soc.h"
st_ads1115ObjDef ads1115Chip0,ads1115Chip1;
st_ads1115ObjDef* pAds1115DiffPrObj;
st_ads1115ObjDef* pAds1115PrObj;
void ads1115_init(st_ads1115ObjDef* pAds1115,uint8_t slvaddr)
{
	pAds1115->chip=ADS1115;
	pAds1115->slaveAddr=slvaddr;
	pAds1115->config.data=ADS1115_CONFIG_DEFAULT;
	pAds1115->iic_start=iic_start;
	pAds1115->iic_stop=iic_stop;
	pAds1115->iic_send_byte=iic_send_byte;
	pAds1115->iic_waite_ack=iic_waite_ack;
	pAds1115->iic_received_byte_if_ack=iic_received_byte_if_ack;
}

void ads1115_write_reg(st_ads1115ObjDef* pAds1115,uint8_t addr,uint16_t value)
{
	pAds1115->iic_start();

	pAds1115->iic_send_byte(pAds1115->slaveAddr);
	pAds1115->iic_send_byte(addr);
	
	pAds1115->iic_send_byte((uint8_t)(value>>8));
	pAds1115->iic_send_byte((uint8_t)(value&0xff));
	pAds1115->iic_stop();	
}

uint16_t ads1115_read_reg(st_ads1115ObjDef* pAds1115,uint8_t addr)
{
	uint16_t t16=0;
	pAds1115->iic_start();
	//write reg. point for read;
	pAds1115->iic_send_byte(pAds1115->slaveAddr);
	pAds1115->iic_send_byte(addr);	
	pAds1115->iic_stop();
	//
	pAds1115->iic_start();
	pAds1115->iic_send_byte((pAds1115->slaveAddr)+1);
	t16=pAds1115->iic_received_byte_if_ack(IIC_ACK);
	t16<<=8;
	t16|=pAds1115->iic_received_byte_if_ack(IIC_ACK);
	
	pAds1115->iic_stop();
	return t16;
}

//
void ads1115_set_operate_status(st_ads1115ObjDef* pAds1115,em_Ads1x1xOsDef_t os)
{
	pAds1115->config.bits.OS=os;
}

void ads1115_set_mux(st_ads1115ObjDef* pAds1115,em_Ads1x1xMuxDef_t mux)
{
	pAds1115->config.bits.MUX=mux;
}

void ads1115_set_pga(st_ads1115ObjDef* pAds1115,em_Ads1x1xPgaDef_t pga)
{
	pAds1115->config.bits.PGA=pga;
}
void ads1115_set_mod(st_ads1115ObjDef* pAds1115,em_Ads1x1xModeDef_t mode)
{
    if(pAds1115->chip<ADS1113)return;
	pAds1115->config.bits.MODE=mode;
}

void ads1115_set_data_rate(st_ads1115ObjDef* pAds1115,em_Ads1x1xDrDef_t dr)
{
    pAds1115->config.bits.DR=dr;
}

void ads1115_set_data_comp_mode(st_ads1115ObjDef* pAds1115,em_Ads1x1xCompModeDef_t compMode)
{
    pAds1115->config.bits.COMP_MODE=compMode;
}

void ads1115_set_data_comp_pol(st_ads1115ObjDef* pAds1115,em_Ads1x1xCompPolarity_t compPol)
{
    pAds1115->config.bits.COMP_POL=compPol;
}

void ads1115_set_data_comp_latch(st_ads1115ObjDef* pAds1115,em_Ads1x1xCompLatch_t compLatch)
{
    pAds1115->config.bits.COMP_LAT=compLatch;
}

//apl
void ads1115_config(
	st_ads1115ObjDef* pAds1115,
	em_Ads1x1xMuxDef_t mux,
	em_Ads1x1xPgaDef_t pga)
{
	pAds1115->config.data=ADS1115_CONFIG_DEFAULT;
	pAds1115->config.bits.OS=ADS1X1X_OS_START_SINGLE_CONVERSION;
	pAds1115->config.bits.MUX=mux;
	pAds1115->config.bits.PGA=pga;
	pAds1115->config.bits.MODE=ADS1X1X_MODE_SINGLE_SHOT;
	if(pAds1115->chip>=ADS1113){
		pAds1115->config.bits.DR=ADS1X1X_DATA_RATE_250;
	}else{
		pAds1115->config.bits.DR=ADS101X_DATA_RATE_250;
	}
	pAds1115->config.bits.COMP_QUE=COMP_QUEUE_DISABLE;
}

/*
st_ads1115ObjDef* pAds1115DiffPrObj;
st_ads1115ObjDef* pAds1115PrObj;
*/
void ads1115_init_all_chip(void)
{
	//chip0 addr connect to gnd,addr=1001000
	pAds1115PrObj= &ads1115Chip0;
	ads1115_init(pAds1115PrObj,ADS1x1x_I2C_ADDRESS_ADDR_TO_GND);	//压力
	//chip0 addr connect to vcc,addr=1001001
	pAds1115DiffPrObj=&ads1115Chip1;
	ads1115_init(pAds1115DiffPrObj,ADS1x1x_I2C_ADDRESS_ADDR_TO_VCC);	//差压
}

void ads1115_start_conversion(st_ads1115ObjDef* pAds1115)
{
	ads1115_write_reg(pAds1115,ADS1x1x_REG_POINTER_CONFIG,pAds1115->config.data);
	delay_ms(1);
}

uint16_t ads1115_read_conversion(st_ads1115ObjDef* pAds1115)
{
	uint16_t result;
	result=ads1115_read_reg(pAds1115,ADS1x1x_REG_POINTER_CONVERSION);
	if(pAds1115->chip<ADS1113){
		result >>= 4;
	}
	delay_ms(1);
	return result;
}

void ads1115_set_threshold_lo(st_ads1115ObjDef* pAds1115,uint16_t value)
{
	if(pAds1115->chip<ADS1113){
		value >>= 4;
	}
	ads1115_write_reg(pAds1115,ADS1x1x_REG_POINTER_LO_THRESH,value);
}

void ads1115_set_threshold_hi(st_ads1115ObjDef* pAds1115,uint16_t value)
{
	if(pAds1115->chip<ADS1113){
		value >>= 4;
	}
	ads1115_write_reg(pAds1115,ADS1x1x_REG_POINTER_HI_THRESH,value);
}

