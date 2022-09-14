/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_math.h"
#include "SysCtrl_Clock_Cfg.h"
#include "SysCtrl_Clock.h"

/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/
 
void SysCtrl_ClockInit(void)
{
	switch(ClOCK_SOURCE)
	{
		case _Main_OSC:
			RCC_R->RCC_BITS.MOSCDIS = 0;
			RCC_R->RCC_BITS.OSCSRC  = 0;
			RCC_R->RCC_BITS.XTAL  = XTAL_clock;
			break;
		case _PreInt_OSC:
			RCC_R->RCC_BITS.MOSCDIS = 1;
			RCC_R->RCC_BITS.OSCSRC  = 1;
			break;
		case _PreInt_OSC_by_4:
			RCC_R->RCC_BITS.MOSCDIS = 1;
			RCC_R->RCC_BITS.OSCSRC  = 2;
			break;	
		case _LowFreqInt_OSC:
			RCC_R->RCC_BITS.MOSCDIS = 1;
			RCC_R->RCC_BITS.OSCSRC  = 3;
			break;							
	}
		


	#if (PLL_MODE == 1)
		RCC_R->RCC_BITS.BYPASS  = 0;
		RCC_R->RCC_BITS.PWRDN  =  0;
	
		while(GET_BIT(PLLSTAT_R,0)==0);
		RCC_R->RCC_BITS.USESYSDIV  =  1;
		RCC_R->RCC_BITS.SYSDIV  =  CLOCK_DIVISOR;	
	
	#else
	
		RCC_R->RCC_BITS.BYPASS  = 1;
		RCC_R->RCC_BITS.PWRDN  =  1;
		while(GET_BIT(PLLSTAT_R,0)!=0);
	#endif

		
}

void SysCtrl_ClockEnable(NUMclock_Gating_Type Peripheral,u8 Num)
{
	volatile u32 *ptr = NULL;
	ptr = ((volatile u32 *)(SYSCTRL_BASE_ADDRESS+Peripheral));
	SET_BIT(*ptr,Num);
}

void SysCtrl_ClockDisable(NUMclock_Gating_Type Peripheral,u8 Num)
{
	//EnablePrivilegedMode();
	volatile u32 *ptr = NULL;
	ptr = ((volatile u32 *)(SYSCTRL_BASE_ADDRESS+Peripheral));
	CLEAR_BIT(*ptr,Num);	
}


