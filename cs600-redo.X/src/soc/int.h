#ifndef __int_h__
#define __int_h__

#ifdef __cplusplus
extern "C"{
#endif
    //--------------------------------------------------------------------------
    #define INTERRUPT_GlobalInterruptEnable()       do{INTCONbits.GIE = 1;}while(0);
    #define INTERRUPT_GlobalInterruptDisable()      do{INTCONbits.GIE = 0;}while(0);
    #define INTERRUPT_PeripheralInterruptEnable()   do{INTCONbits.PEIE = 1;}while(0);
    #define INTERRUPT_PeripheralInterruptDisable()  do{INTCONbits.PEIE = 0;}while(0);
	#define __irq_enable() do{ \
        RCONbits.IPEN=1; \
		INTERRUPT_GlobalInterruptEnable(); \
		INTERRUPT_PeripheralInterruptEnable(); \
	}while(0);
    
	#define __irq_disable() do{ \
		INTERRUPT_PeripheralInterruptDisable(); \
		INTERRUPT_GlobalInterruptDisable(); \
	}while(0);


#ifdef __cplusplus
}
#endif

#endif
//file end
