/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "STD_TYPES.h"
#include "SysCtrl_Clock.h"
#include "SysTick.h"
#include "IntCtrl.h"
#include "PORT.h"
#include "DIO_Interface.h"
#include "Blink_LED.h"

/**********************************************************************************************************************
 *  Global Variables
 *********************************************************************************************************************/
static volatile u8 Global_LED_ON=0,Global_LED_OFF=0, Temp_ON=0, Temp_OFF=0;



/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

/*LED Toggle function on given time periods in seconds*/
void LED_Toggle(u8 ON_TIME, u8 OFF_TIME)
{
	
	/*Clock initialization*/
	SysCtrl_ClockInit();
	
	/*SysTick Timer initialization*/
	SysTick_Init();
	
	/*Interrupts and SysTick periority initialization*/
	IntCtrl_Init();
	
	/*Port and configuired Pins initialization */
	PORT_Init();	
	
	/*setting the initial timeout values in seconds which passed by user*/
	Global_LED_ON  = ON_TIME;
	Temp_ON = ON_TIME;
	
	Global_LED_OFF = OFF_TIME;
	Temp_OFF = OFF_TIME;
	
	
	/*ISR will happen every 1000ms (1 second), and will call SysTick_ISR_Func() function*/
	SysTick_Timer_Start_CB(1000,&SysTick_ISR_Func);   
	
}


/*ISR function which will be called back by SysTick_Handler ISR*/
void SysTick_ISR_Func(void)
{
	if(Global_LED_ON != 0)
	{
		Dio_WritePin(LED_PIN,DIO_HIGH);
		Global_LED_ON--;
	}else
	{
		if(Global_LED_OFF != 0)
		{
			Dio_WritePin(LED_PIN,DIO_LOW);
			Global_LED_OFF--;
		}else
		{
			Dio_WritePin(LED_PIN,DIO_HIGH);
			Global_LED_ON = Temp_ON-1;
			Global_LED_OFF = Temp_OFF;
		}
	}
}

