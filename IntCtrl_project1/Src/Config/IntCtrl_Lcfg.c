#include "STD_types.h"
#include "IntCtrl_Cfg.h"

void IntCtrl_Config(IntCtrl_Types Type, IntCtrl_Mode Mode, u8 PriLevel)
{
	u8 temp_Type = Type;
	if(Type % 4 == 0)
	{
		volatile IntCtrl_Pri ptr* = (PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + Type);
		ptr->INTA = PriLevel;
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
				volatile IntCtrl_Pri ptr* = (PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + temp_Type);
				ptr->INTA = PriLevel;
				break;
			case 2:
				volatile IntCtrl_Pri ptr* = (PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + temp_Type);
				ptr->INTB = PriLevel;
				break;
			case 3:
				volatile IntCtrl_Pri ptr* = (PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + temp_Type);
				ptr->INTC = PriLevel;
				break;
			case 4:
				volatile IntCtrl_Pri ptr* = (PERIPHERALS_BASE_ADDRESS + PRI_OFFSET + temp_Type);
				ptr->INTD = PriLevel;
				break;				
		}
	}
	
	switch(Mode)
	{
		case _Enable:
			if(Type<=31 && Type>=0)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + EN0_OFFSET);
				SET_BIT(*ptr,Type);
			}
			else if(Type<=63 && Type>=32)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+4);
				SET_BIT(*ptr,Type-32);				
			}
			else if(Type<=95 && Type>=64)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+8);
				SET_BIT(*ptr,Type-64);				
			}			
			else if(Type<=127 && Type>=96)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+12);
				SET_BIT(*ptr,Type-96);			
			}
			else if(Type<=138 && Type>=128)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + EN0_OFFSET+16);
				SET_BIT(*ptr,Type-128);			
			}	
		break;
		case _Disable:
			if(Type<=31 && Type>=0)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET);
				CLEAR_BIT(*ptr,Type);
			}
			else if(Type<=63 && Type>=32)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+4);
				CLEAR_BIT(*ptr,Type-32);				
			}
			else if(Type<=95 && Type>=64)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+8);
				CLEAR_BIT(*ptr,Type-64);				
			}			
			else if(Type<=127 && Type>=96)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+12);
				CLEAR_BIT(*ptr,Type-96);			
			}
			else if(Type<=138 && Type>=128)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + DIS0_OFFSET+16);
				CLEAR_BIT(*ptr,Type-128);			
			}	
		break;
		case _Pend:
			if(Type<=31 && Type>=0)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + PEND_OFFSET);
				SET_BIT(*ptr,Type);
			}
			else if(Type<=63 && Type>=32)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+4);
				SET_BIT(*ptr,Type-32);				
			}
			else if(Type<=95 && Type>=64)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+8);
				SET_BIT(*ptr,Type-64);				
			}			
			else if(Type<=127 && Type>=96)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+12);
				SET_BIT(*ptr,Type-96);			
			}
			else if(Type<=138 && Type>=128)
			{
				volatile u32 ptr* = (PERIPHERALS_BASE_ADDRESS + PEND_OFFSET+16);
				SET_BIT(*ptr,Type-128);			
			}	
		break;		
	}
	
}