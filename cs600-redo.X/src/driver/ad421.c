#include "iic_gpio.h"
#include "ad421.h"

//void pcf8574_write_singel(uint8_t x)
extern uint8_t pcf8574Value;
void ad421_write_via_pcf8574(uint16_t dacValue,uint8_t ch)
{
    uint8_t i;
    uint16_t t16;
    st_pcf8574PortDef pcfValueTemp;
    pcfValueTemp.data=pcf8574Value;
    if(ch>1)return;
    if(ch==0){
        pcfValueTemp.bits.AD421_LATCH_1=0;
    }else{
        pcfValueTemp.bits.AD421_LATCH_2=0;
    }
    pcf8574.iic_start();
    for(i=0;i<16;i++){
        if(dacValue & 0x8000){
            pcfValueTemp.bits.PGD_AD421_DATA=1;
        }else{
            pcfValueTemp.bits.PGD_AD421_DATA=0;
        }
        dacValue<<=1;
        //clock=0;
        pcfValueTemp.bits.PGC_AD421_CLOCK=0;
        //pcf8574.iic_start();
        pcf8574.iic_send_byte(pcf8574.slaveAddr);
        pcf8574.iic_send_byte(pcfValueTemp.data);
        //clock=1;
        pcfValueTemp.bits.PGC_AD421_CLOCK=1;
        pcf8574.iic_send_byte(pcfValueTemp.data);
        //pcf8574.iic_stop();
    }
    if(ch==0){
        pcfValueTemp.bits.AD421_LATCH_1=1;
        pcf8574.iic_send_byte(pcfValueTemp.data);
        pcfValueTemp.bits.AD421_LATCH_1=0;
        pcf8574.iic_send_byte(pcfValueTemp.data);        
    }else{
        pcfValueTemp.bits.AD421_LATCH_2=1;
        pcf8574.iic_send_byte(pcfValueTemp.data);
        pcfValueTemp.bits.AD421_LATCH_2=0;
        pcf8574.iic_send_byte(pcfValueTemp.data);
    }
    pcf8574.iic_stop();
}