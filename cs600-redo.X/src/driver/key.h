#ifndef __key_h__
#define __key_h__

#ifdef __cplusplus
extern "C"{
#endif
    
	#define pins_KEY_DOWN	PIN3
	#define pins_KEY_UP		PIN2
	#define pins_KEY_SET	PIN1
	#define pins_KEY_ALL	(PIN1 | PIN2 | PIN3 )

	//rb3
	#define get_key_down_value(kvalue) do{ \
		set_portb_mode_in(PIN3); \
		kvalue=get_portb_value(PIN3); \
		}while(0);
	//rb2
	#define get_key_up_value(kvalue) do{ \
		set_portb_mode_in(PIN2); \
		kvalue=get_portb_value(PIN2); \
		}while(0);
	//rb1
	#define get_key_set_value(kvalue) do{ \
		set_portb_mode_in(PIN1); \
		kvalue=get_portb_value(PIN1); \
		}while(0);	
	#define get_key_all_value(kvalue) do{ \
		set_portb_mode_in(pins_KEY_ALL); \
		kvalue=get_portb_value(pins_KEY_ALL); \
		}while(0);
	/*	
	typedef enum
	{
		KEY_NONE	=	0x00,
		KEY_UP		=	(0x01<<0),
		KEY_DOWN	=	(0x01<<1),
		KEY_SET		=	(0x01<<2),
		KEY_MAX		=	(0xff),
	}em_keyDef;
	*/

	
	#define KEY_VALUE_DOWN 	(0x01<<0x0)
	#define KEY_VALUE_UP 	(0x01<<0x01)
	#define KEY_VALUE_SET	(0x01<<0x02)
	#define KEY_VALUE_NONE	(0x0)
	#define KEY_VALUE_MASK	(KEY_VALUE_UP | KEY_VALUE_DOWN | KEY_VALUE_SET)
	
	
	extern uint8_t key_polling(void);
#ifdef __cplusplus
}
#endif

#endif
