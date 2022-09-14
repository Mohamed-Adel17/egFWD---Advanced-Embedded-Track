/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "Blink_LED.h"


#define ON_TIME_in_SECONDS	  2
#define OFF_TIME_in_SECONDS   2

/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/
 
 /*Main function of Application layer*/
int main(void)
{
	
	/*Calling LED_Toggle function of HAL-Layer which will implicity start SysTick Timer,ISR handler 
	 *  to perform the blinking Led functionality
	 *This function takes Led ON/OFF periods recpectively in seconds
	 */
	LED_Toggle(ON_TIME_in_SECONDS,OFF_TIME_in_SECONDS);
	
	/*Empty super loop for safety purposes*/
	while(1)
	{
		
	}
}


