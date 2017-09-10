//file name:m_flash.h
#ifndef __m_flash_h__
#define __m_flash_h__
#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>
#define FLASH_PAGE_SIZE					(1024)
#define FLASH_WRITE_BLOCK_SIZE			(64)
//#define FLASH_WRITE_BLOCK_SIZE			(2)
#define MAX_FLASH_USED_SIZE_IN_BLOCK	FLASH_WRITE_BLOCK_SIZE*4

#define FLASH_MIN_ADDR					(0)
#define FLASH_MAX_ADDR					(0xFFFF)	
#define TOTAL_CHIP_FLASH_SIZE			(FLASH_MAX_ADDR-FLASH_MIN_ADDR+1)
    
#define USER_FLASH_ADDR_START       0xf800
#define	USER_FLASH_SIZE				0x400

extern uint16_t m_flash_read(uint32_t addr,uint8_t*buf,uint16_t len);
extern uint16_t m_flash_write(uint32_t addr,uint8_t*buf,uint16_t len);
extern void m_flash_unlock(void);
extern void	m_flash_test(void);

#ifdef __cplusplus
}
#endif
#endif
//file end
