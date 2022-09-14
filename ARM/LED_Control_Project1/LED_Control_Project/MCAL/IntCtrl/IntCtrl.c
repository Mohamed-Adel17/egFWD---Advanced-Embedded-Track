/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "IntCtrl.h"
#include "BIT_math.h"
#include "IntCtrl_Cfg.h"

extern IntConfig_t IntCfg[INT_MaxNumToBeConfigured];

/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/
 
void IntCtrl_Init(void)
{
	
#if (INT_MaxNumToBeConfigured != 0)	
	
	/*APINT reg group priority
	 *We must write 0x05FA in the upper half register while trying to write any other bit
	 *otherwise, write operation will be ignored
	 */
	
	APINT_R = 0x05FA0000 | (PRIGROUP_VALUE<<PRIGROUP_START);
	
	
	/*
	 *This loop will configure interrupt for every peripheral included in 'IntCfg' --> global array of structs
	 *depending on the number of interrupt to be configured which specified in macro : INT_MaxNumToBeConfigured
	 */

	u8 i=0;
	for(i=0;i<INT_MaxNumToBeConfigured;i++)
	{
		u8 temp_Type = IntCfg[i].Type;
		volatile IntCtrl_Pri *ptr_n = NULL;
		
		/*if type is multiple of 4, it means we will write on the first section INTA */
		if(IntCfg[i].Type % 4 == 0)
		{
			ptr_n = ((volatile IntCtrl_Pri*)(PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + IntCfg[i].Type));
			ptr_n->INTA = IntCfg[i].PriLevel;
		}
		else /*it means we need to write on following sections and not the first one
			  *to determine which section, we will use some loop and counter down till the type be multiple of 4
			  *by this we can determine which register/peripheral we should access and which section to write on 
			  */
		{
				u8 counter=0;
			while(temp_Type%4 !=0)
			{
				temp_Type--;
				counter++;
			}
			switch(counter)
			{
				case 1: /*section 2 : INTB*/
					ptr_n = ((volatile IntCtrl_Pri*)(PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + temp_Type));
					ptr_n->INTB = IntCfg[i].PriLevel;
					break;
				case 2: /*section 3 : INTC*/
					ptr_n = ((volatile IntCtrl_Pri*)(PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + temp_Type));
					ptr_n->INTC = IntCfg[i].PriLevel;
					break;
				case 3: /*section 4 : INTD*/
					ptr_n = ((volatile IntCtrl_Pri*)(PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + temp_Type));
					ptr_n->INTD = IntCfg[i].PriLevel;
					break;				
			}
		}
		volatile u32 *ptr = NULL;
		
		/*This part is responsible to enable , disable, pend peripheral interrupt*/
		switch(IntCfg[i].Mode)
		{
			case _Enable:
				 /*using datasheet, I implemented this technique to access all peripherals
					*by dividing peripherals interrupt number in vector table into ranges
			   	*and increament of EN register offset to access next ones(EN1,EN2,...)
					*/
				if(IntCfg[i].Type <= 31) 
				{	ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + EN0_OFFSET));
					SET_BIT(*ptr,IntCfg[i].Type);
				}
				else if(IntCfg[i].Type<=63 && IntCfg[i].Type>=32)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+4));
					SET_BIT(*ptr,(IntCfg[i].Type-32));				
				}
				else if(IntCfg[i].Type<=95 && IntCfg[i].Type>=64)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+8));
					SET_BIT(*ptr,(IntCfg[i].Type-64));				
				}			
				else if(IntCfg[i].Type<=127 && IntCfg[i].Type>=96)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+12));
					SET_BIT(*ptr,(IntCfg[i].Type-96));			
				}
				else if(IntCfg[i].Type<=138 && IntCfg[i].Type>=128)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+16));
					SET_BIT(*ptr,(IntCfg[i].Type-128));			
				}	
			break;
			case _Disable:
				if(IntCfg[i].Type<=31)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET));
					CLEAR_BIT(*ptr,IntCfg[i].Type);
				}
				else if(IntCfg[i].Type<=63 && IntCfg[i].Type>=32)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+4));
					CLEAR_BIT(*ptr,(IntCfg[i].Type-32));				
				}
				else if(IntCfg[i].Type<=95 && IntCfg[i].Type>=64)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+8));
					CLEAR_BIT(*ptr,(IntCfg[i].Type-64));				
				}			
				else if(IntCfg[i].Type<=127 && IntCfg[i].Type>=96)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+12));
					CLEAR_BIT(*ptr,(IntCfg[i].Type-96));			
				}
				else if(IntCfg[i].Type<=138 && IntCfg[i].Type>=128)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+16));
					CLEAR_BIT(*ptr,(IntCfg[i].Type-128));			
				}	
			break;
			case _Pend:
				if(IntCfg[i].Type<=31)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + PEND_OFFSET));
					SET_BIT(*ptr,IntCfg[i].Type);
				}
				else if(IntCfg[i].Type<=63 && IntCfg[i].Type>=32)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+4));
					SET_BIT(*ptr,(IntCfg[i].Type-32));				
				}
				else if(IntCfg[i].Type<=95 && IntCfg[i].Type>=64)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+8));
					SET_BIT(*ptr,(IntCfg[i].Type-64));				
				}			
				else if(IntCfg[i].Type<=127 && IntCfg[i].Type>=96)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+12));
					SET_BIT(*ptr,(IntCfg[i].Type-96));			
				}
				else if(IntCfg[i].Type<=138 && IntCfg[i].Type>=128)
				{
					ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+16));
					SET_BIT(*ptr,(IntCfg[i].Type-128));			
				}	
			break;		
		}
	}
#endif
	
	
	/*If systick is enabled, configure its priority level using user configuration of "IntCtrl_Cfg.h"*/	
	#if (SYSTICK_PRIORITY != 0)
		
		((volatile SYSPRI3_REG_t *)(PERIPHERALS_BASE_ADDRESS+SYSPRI3_OFFSET))->TICK = SYSTICK_PRIORITY;
	
	#endif
		

}
