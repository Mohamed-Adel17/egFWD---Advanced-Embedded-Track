#include "STD_TYPES.h"
#include "IntCtrl_Cfg.h"
#include "IntCtrl.h"
#include "BIT_math.h"

	
void IntCtrl_Config(IntCtrl_Types Type, IntCtrl_Mode Mode, u8 PriLevel)
{
	u8 temp_Type = Type;
	volatile IntCtrl_Pri *ptr_n = NULL;
	if(Type % 4 == 0)
	{
		ptr_n = ((volatile IntCtrl_Pri*)(PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + Type));
		ptr_n->INTA = PriLevel;
	}else
	{
		u8 counter=0;
		while(temp_Type%4 !=0)
		{
			temp_Type--;
			counter++;
		}
		switch(counter)
		{
			case 1:
				ptr_n = ((volatile IntCtrl_Pri*)(PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + temp_Type));
				ptr_n->INTB = PriLevel;
				break;
			case 2:
				ptr_n = ((volatile IntCtrl_Pri*)(PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + temp_Type));
				ptr_n->INTC = PriLevel;
				break;
			case 3:
				ptr_n = ((volatile IntCtrl_Pri*)(PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + temp_Type));
				ptr_n->INTD = PriLevel;
				break;				
		}
	}
	volatile u32 *ptr = NULL;
	switch(Mode)
	{
		case _Enable:
			if(Type <= 31)
			{
				 ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + EN0_OFFSET));
				 SET_BIT(*ptr,Type);
			}
			else if(Type<=63 && Type>=32)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+4));
				SET_BIT(*ptr,(Type-32));				
			}
			else if(Type<=95 && Type>=64)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+8));
				SET_BIT(*ptr,(Type-64));				
			}			
			else if(Type<=127 && Type>=96)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+12));
				SET_BIT(*ptr,(Type-96));			
			}
			else if(Type<=138 && Type>=128)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+16));
				SET_BIT(*ptr,(Type-128));			
			}	
		break;
		case _Disable:
			if(Type<=31)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET));
				CLEAR_BIT(*ptr,Type);
			}
			else if(Type<=63 && Type>=32)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+4));
				CLEAR_BIT(*ptr,(Type-32));				
			}
			else if(Type<=95 && Type>=64)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+8));
				CLEAR_BIT(*ptr,(Type-64));				
			}			
			else if(Type<=127 && Type>=96)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+12));
				CLEAR_BIT(*ptr,(Type-96));			
			}
			else if(Type<=138 && Type>=128)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+16));
				CLEAR_BIT(*ptr,(Type-128));			
			}	
		break;
		case _Pend:
			if(Type<=31)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + PEND_OFFSET));
				SET_BIT(*ptr,Type);
			}
			else if(Type<=63 && Type>=32)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+4));
				SET_BIT(*ptr,(Type-32));				
			}
			else if(Type<=95 && Type>=64)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+8));
				SET_BIT(*ptr,(Type-64));				
			}			
			else if(Type<=127 && Type>=96)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+12));
				SET_BIT(*ptr,(Type-96));			
			}
			else if(Type<=138 && Type>=128)
			{
				ptr = ((volatile u32 *)(PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+16));
				SET_BIT(*ptr,(Type-128));			
			}	
		break;		
	}
	
}
