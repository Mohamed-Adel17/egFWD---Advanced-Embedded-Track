#include "STD_TYPES.h"
#include "IntCtrl_Cfg.h"

int main(void)
{
	
	IntCtrl_init();
	IntCtrl_Config(_Timer_0A,_Enable,0x2);
	IntCtrl_Config(_Timer_5B,_Enable,0x3);
	IntCtrl_Config(_CAN0,_Pend,0x2);
	
	
	while(1)
	{
		
	}
}
