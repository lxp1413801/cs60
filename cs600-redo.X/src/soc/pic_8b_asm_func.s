 
   ; #include "xc.h"
    #include pic18F86J93.inc
PROG CODE          ; Set the start of code from 16f877.lkr script
 
dddd              ; Main code entry called from example2.asm
    global dddd    ; Define as global so can be used in example2.asm
    nop            ; Main does nothing -- Put your code here
    goto   dddd    ; Our sample "main" is just an infinite loop
 
service            ; Interrupt routine, called from example2.asm
    global service ; Define as global so can be used in example2.asm
    nop            ; Interrupt code would go here
    nop
    retfie
 
IDLOCS  CODE       ; ID location data, address is in 16f877.lkr
    dw 0x0102
    dw 0x0304
 
CONBITS CODE       ; Set config bits from defines in p16f877.inc
                   ; Config address for device programmer is
                   ; in 16f877.lkr
    dw _LP_OSC & _PWRTE_OFF & _WDT_OFF & _CP_OFF
 
    end