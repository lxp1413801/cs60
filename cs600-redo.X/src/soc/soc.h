#ifndef __soc_h__
#define __soc_h__

#ifdef __cplusplus
extern "C"{
#endif
	#include "stdint.h"
	#include <xc.h>
	//#include <pic18f86j93.h>
	#include "p18f86j93.h"
	#include "clock.h"
	
	#include "bootloader.h"
	#include "ticker.h"
	#include "rtc.h"
	#include "int.h"
	//#include "ticker.h"
	//--------------------------------------------------------------------------
	#ifndef NULL 
	#define NULL ((void*)0)
	#endif
	#ifndef null
	#define null NULL
	#endif
    

	//extern volatile unsigned char           isInBootLoader             @ 0x00;
	extern void soc_init(void);
#ifdef __cplusplus
}
#endif

#endif
//file end
