#include "soc.h"
void soc_init(void)
{
    //osc_setup();
    sys_ticker_init();
    rtc_init();
    //__irq_enable();
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    //
    RCONbits.IPEN=0;
    //asm("bsf INTCON,7,1");
    //RCONbits.IPEN=1;
    //rtc_init();
}