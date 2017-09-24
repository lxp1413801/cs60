#include <xc.h>
#include <pic18f86j93.h>
#include "p18f86j93.h"
#include "m_flash.h"
#include "../depend/m_string.h"
#include "../driver/lcd.h"
#include "../api/data.h"

void m_flash_unlock(void)
{
	volatile unsigned char oldGIE;

	//oldGIE = INTCONbits.GIE;
	oldGIE=INTCON;
	INTCONbits.GIE = 0;
	__nop();
	asm("movlw 0x55");
	asm("movwf EECON2");
	asm("movlw 0xAA");
	asm("movwf EECON2");
	//asm("bsf EECON1, 1,1");
	EECON1bits.WR=1;
	__nop();
	//while(EECON1bits.WR);                       // Wait for write to complete
	//EECON1 = 0b00000000;                        // Clear WREN
	//INTCONbits.GIE = oldGIE;                    // Restore GIE
	INTCON=oldGIE;
	return;
}
void m_flash_erase(uint32_t addr)
{
	uint32_t t32=addr;
	t32 &= (~0x3fful);

	//t32 &= 0x00fffffful;
	TBLPTRL=(uint8_t)(t32 & 0xfful);
	t32>>=8;
	TBLPTRH=(uint8_t)(t32 & 0xfful);
	t32>>=8;
	TBLPTRU=(uint8_t)(t32 & 0xfful);
	EECON1bits.WREN=1;
	EECON1bits.FREE=1;
	m_flash_unlock();
	EECON1bits.WREN=0;
}
uint16_t m_flash_read(uint32_t addr,uint8_t*buf,uint16_t len)
{
	uint16_t i;
	uint32_t t32=addr;

	TBLPTRL=(uint8_t)(t32 & 0xfful);
	t32>>=8;
	TBLPTRH=(uint8_t)(t32 & 0xfful);
	t32>>=8;
	TBLPTRU=(uint8_t)(t32 & 0xfful);	

	for(i=0;i<len;i++){
		asm("TBLRD*+");
		buf[i]=TABLAT;
	}
	return len;
}
uint16_t m_flash_write(uint32_t addr,uint8_t* buf,uint16_t len)
{
	uint8_t i,j,writeTimes;
	uint32_t pageAddr;
	uint16_t t16;
	uint8_t* tmpBuf=globleBuffer;
	//uint8_t tmpBuf[MAX_FLASH_USED_SIZE_IN_BLOCK];
	t16=addr & (FLASH_PAGE_SIZE-1);
	if(t16+len>MAX_FLASH_USED_SIZE_IN_BLOCK)return 0;
	
	pageAddr=addr & ~(FLASH_PAGE_SIZE-1);
	m_flash_read(pageAddr,tmpBuf,MAX_FLASH_USED_SIZE_IN_BLOCK);
	m_mem_cpy_len(tmpBuf+t16,buf,len);
	//
	m_flash_erase(pageAddr);
    
	writeTimes=MAX_FLASH_USED_SIZE_IN_BLOCK/FLASH_WRITE_BLOCK_SIZE;
	t16=(uint16_t)(tmpBuf);
	
	FSR0L=(uint8_t)(t16&0x00ff);
	t16>>=8;
	FSR0H=(uint8_t)(t16&0x00ff);
	
	for(i=0;i<writeTimes;i++){
		for(j=0;j<FLASH_WRITE_BLOCK_SIZE;j++){
			asm("MOVFF POSTINC0, WREG");
			asm("MOVWF TABLAT");
			asm("TBLWT*+");
		}
		asm("TBLRDPOSTDEC");        
		EECON1bits.WREN=1;
		m_flash_unlock();
		EECON1bits.WREN=0;
		asm("TBLWTPOSTINC");
	}
	return len;
}
const uint8_t flashTestbuf[]="0123456789012345678901234567890123456789012345678901234567890123";
void m_flash_test(void)
{
	uint8_t tmp[16];
	m_mem_cpy_len(tmp,(uint8_t*)flashTestbuf,sizeof(flashTestbuf));
	m_flash_write(USER_FLASH_ADDR_START,tmp,sizeof(flashTestbuf));
	__nop();
	m_flash_read(USER_FLASH_ADDR_START,tmp,sizeof(flashTestbuf));
	__nop(); 
}
//file end
