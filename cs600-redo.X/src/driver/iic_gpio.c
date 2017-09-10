#include "iic_gpio.h"
st_iicDeviceObj pcf8574;
//st_pcf8574PortDef st_pcf8574PortUsage;
st_BJ_Def st_Bj={0};
uint8_t pcf8574Value;
void pcf8574_init(void)
{
    //st_pcf8574PortUsage.data=0xff;
	pcf8574.slaveAddr=0x4e;
	pcf8574.iic_start=iic_start;
	pcf8574.iic_stop=iic_stop;
	pcf8574.iic_send_byte=iic_send_byte;
	//pcf8574.iic_read_byte=iic_read_byte;
	pcf8574.iic_waite_ack=iic_waite_ack;
	pcf8574.iic_received_byte_if_ack=iic_received_byte_if_ack;
	//pcf8574.iic_read_n_byte=iic_read_n_byte;
	//pcf8574.iic_write_byte=iic_write_byte;
	//pcf8574.iic_write_n_byte=iic_write_n_byte;
}
void pcf8574_write_singel(uint8_t x)
{
    pcf8574.iic_start();
    pcf8574.iic_send_byte(pcf8574.slaveAddr);
    pcf8574.iic_send_byte(x);
    pcf8574.iic_stop();
    //st_pcf8574Port.data=x;
    pcf8574Value=x;
}
//
void pcf8574_swio_annunciator(uint8_t x)
{
    uint8_t t8;
    t8=pcf8574Value;
    //if((t8 & 0x0f) == (x & 0x0f))return;
    t8 &= 0xf0;
    t8 |= (uint8_t)(x & 0x0f);
    if(t8==pcf8574Value)return;
    pcf8574_write_singel(t8);
}
//for bj
void pcf8574_swio_bj_enable(uint8_t bj)
{
    uint8_t t8;
    if(!(bj>=1 && bj<=4))return;
    //t8=bj-1;
    t8=(uint8_t)(1<<(bj-1));
    t8=(uint8_t)(pcf8574Value | t8);
    pcf8574_write_singel(t8);
    pcf8574Value=t8;
}
void pcf8574_swio_bj_disable(uint8_t bj)
{
    uint8_t t8;
    if(!(bj>=1 && bj<=4))return;
    //t8=bj-1;
    t8=(uint8_t)(1<<(bj-1));
    t8=(uint8_t)(pcf8574Value & (~t8));
    pcf8574_write_singel(t8);
    pcf8574Value=t8;
}
//for 