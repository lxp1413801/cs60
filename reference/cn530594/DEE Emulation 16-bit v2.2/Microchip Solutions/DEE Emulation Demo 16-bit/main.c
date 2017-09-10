/************************************************************************
*
*   Emulating Data EEPROM for PIC24 Microcontrollers and
*           dsPIC Digital Signal Controllers
*
* This routine is an example of a write and read operation using emulated
* Data EEPROM algorithm. Add the variable "value" to the MPLAB IDE Watch
* Window using an emulator. The expected value is 25 after the read
* function executes.
* The configuration bit settings match those of the Explorer16
* Development Board. Compatable settings are selected at compile time
* based on the device selected in MPLAB IDE.
*************************************************************************
* FileName:     main.c
* Dependencies: Flash Operations.s
*               DEE Emulation 16-bit.c
*               DEE Emulation 16-bit.h
* Compiler:     MPLAB C30, v3.30 or higher
* Company:      Microchip Technology, Inc.
*
* Software License Agreement
*
* Copyright © 2007 Microchip Technology Inc. All rights reserved.
*
* Microchip licenses to you the right to use, modify, copy and distribute
* Software only when embedded on a Microchip microcontroller or digital
* signal controller, which is integrated into your product or third party
* product (pursuant to the sublicense terms in the accompanying license
* agreement).
*
* You should refer to the license agreement accompanying this Software for
* additional information regarding your rights and obligations.
*
* SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
* KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY
* WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A
* PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE
* LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY,
* CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY
* DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY
* INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST
* PROFITS OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY,
* SERVICES, OR ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO
* ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*
* Author                Date        Comment
*************************************************************************
* D. Otten              2007/05/01  Version 1.0.0 - Initial Release
* D. Otten              2007/05/15  Version 1.0.1 - First publication release
* Pradeep Budagutta 2007/05/15  Version 1.1.0 - Increased addressing capacity   
* Priyabrata Sinha    2011/01/20  Version 2.0.0 - Added dsPIC33E/PIC24E support
* Priyabrata Sinha	2012/04/19 Version 2.2.0 - Removed absolute path
************************************************************************/
#if defined (__dsPIC33F__)
    #include <p33Fxxxx.h>
#elif defined (__PIC24H__)
    #include <p24Hxxxx.h>
#elif defined (__PIC24F__)
    #include <p24Fxxxx.h>
#elif defined (__dsPIC33E__)
    #include <p33Exxxx.h>
#elif defined (__PIC24E__)
    #include <p24Exxxx.h>
#else
    #error Selected processor not supported
#endif

#include <.\DEE Emulation 16-bit\DEE Emulation 16-bit.h>

#if defined (__dsPIC33F__)
    _FOSCSEL(FNOSC_PRIPLL);
    _FOSC(FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMD_XT);
    _FWDT(FWDTEN_OFF);
#elif defined (__PIC24H__)
    _FOSCSEL(FNOSC_PRIPLL);
    _FOSC(FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMD_XT);
    _FWDT(FWDTEN_OFF);
#elif defined (__PIC24F__)
    _CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & COE_OFF & FWDTEN_OFF & ICS_PGx2)
    _CONFIG2( FCKSM_CSDCMD & OSCIOFNC_ON & POSCMOD_HS & FNOSC_PRI )
#elif defined (__dsPIC33E__)
    _FOSCSEL(FNOSC_FRC);			
    _FOSC(FCKSM_CSECMD & POSCMD_XT & OSCIOFNC_OFF & IOL1WAY_OFF);
    _FWDT(FWDTEN_OFF);
    _FPOR(FPWRT_PWR128 & BOREN_ON & ALTI2C1_ON & ALTI2C2_ON);
    _FICD(ICS_PGD1 & RSTPRI_PF & JTAGEN_OFF);
#elif defined (__PIC24E__)
    _FOSCSEL(FNOSC_FRC);			
    _FOSC(FCKSM_CSECMD & POSCMD_XT & OSCIOFNC_OFF & IOL1WAY_OFF);
    _FWDT(FWDTEN_OFF);
    _FPOR(FPWRT_PWR128 & BOREN_ON & ALTI2C1_ON & ALTI2C2_ON);
    _FICD(ICS_PGD1 & RSTPRI_PF & JTAGEN_OFF);
#else
    #error Selected processor not supported
#endif

unsigned char value1, value2, value3;
unsigned char DEEdata = 0;
unsigned int DEEaddr1 = 4, DEEaddr2 = 261, DEEaddr3 = 302;

int main(void)
{

#if defined(__dsPIC33E__) || defined(__PIC24E__)
    PLLFBD = 58;			/* M  = 60	*/
    CLKDIVbits.PLLPOST = 0;		/* N1 = 2	*/
    CLKDIVbits.PLLPRE = 0;		/* N2 = 2	*/
    OSCTUN = 0;
    __builtin_write_OSCCONH(0x03);		
    __builtin_write_OSCCONL(0x01);
    while (OSCCONbits.COSC != 0x3); 
    while (_LOCK == 0);
#endif

    DataEEInit();
    dataEEFlags.val = 0;

	while(1)
	{
	    DataEEWrite(DEEdata,DEEaddr1);
	    value1 = DataEERead(DEEaddr1);
	    Nop();
	    Nop();

	    DataEEWrite(DEEdata*10,DEEaddr2);
	    value2 = DataEERead(DEEaddr2);
	    Nop();
	    Nop();

	    DataEEWrite(DEEdata*20,DEEaddr3);
	    value3 = DataEERead(DEEaddr3);
	    Nop();    
	    Nop();

		DEEdata++;
		if (DEEdata == 13)
		{
			DEEdata = 0;
		}
	}

}
