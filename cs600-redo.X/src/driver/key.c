#include "stdint.h"
#include <xc.h>
#include "p18f86j93.h"
#include "m_gpio.h"
#include "key.h"

#ifndef delay_10ms()
#define delay_10ms() __nop();
#endif
uint8_t keyValue=KEY_VALUE_NONE;
void key_polling(void)
{
	uint8_t ktemp=KEY_VALUE_NONE;
	uint8_t t8=0xff;

    set_portb_mode_in(pins_KEY_ALL);
	t8=get_portb_value(pins_KEY_ALL); 
	if((t8 & pins_KEY_ALL) !=pins_KEY_ALL){
		delay_10ms();
		t8=get_portb_value(pins_KEY_ALL); 
		if(!( t8 & pins_KEY_DOWN)){
			ktemp |= KEY_VALUE_DOWN;
		}
		if(!( t8 & pins_KEY_UP)){
			ktemp |= KEY_VALUE_UP;
		}
		if(!( t8 & pins_KEY_SET)){
			ktemp |= KEY_VALUE_SET;
		}		
	}
	keyValue= ktemp;
}
