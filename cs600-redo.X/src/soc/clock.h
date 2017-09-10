#ifndef __clock_h__
#define __clock_h__

#ifdef __cplusplus
extern "C"{
#endif


	#define OSC_FREQ 11059200
	typedef enum __OSC_MODE
	{
		// sleep mode: both cpu and peripherals not clocked 
		OSC_PMODE_SLEEP = 0,
		// run mode: both cpu and peripherals clocked 
		OSC_PMODE_PRI_RUN,
		OSC_PMODE_SEC_RUN,
		OSC_PMODE_RC_RUN,
#define OSC_PMODE_RUN OSC_PMODE_PRI_RUN

		// idle mode: cpu not clocked, peripherals clocked 
		OSC_PMODE_PRI_IDLE,
		OSC_PMODE_SEC_IDLE,
		OSC_PMODE_RC_IDLE,
#define OSC_PMODE_IDLE OSC_PMODE_PRI_IDLE

		OSC_PMODE_MAX
	}em_oscMode;
	
	void osc_setup(void);
	void osc_set_power(em_oscMode oscMode);	
    //
    extern void delay_us(uint16_t dly);

#ifdef __cplusplus
}
#endif

#endif
//file end
