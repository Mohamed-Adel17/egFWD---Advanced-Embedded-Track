/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef IntCtrl_H
#define IntCtrl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define  PERIPHERALS_BASE_ADDRESS	0xE000E000
#define  EN0_OFFSET					0x100

#define  DIS0_OFFSET				0x180
#define  PEND_OFFSET				0x200
#define  PRI_OFFSET					0x400

#define APINT_R    *((volatile u32*)(PERIPHERALS_BASE_ADDRESS+0xD0C))


#define PRIGROUP_START 8
#define PRIGROUP_LEN   3


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	_GPIO_PortA=0         ,
	_GPIO_PortB           ,
	_GPIO_PortC           ,
	_GPIO_PortD           ,
	_GPIO_PortE           ,
	_UART0                ,
	_UART1                ,
	_SSI0                 ,
	__2C0                 ,
	_PWM0_Fault           ,
	_PWM0_g0              ,
	_PWM0_g1              ,
	_PWM0_g2              ,
	_QEI0                 ,
	_ADC0_sq0             ,
	_ADC0_sq1             ,
	_ADC0_sq2             ,
	_ADC0_sq3             ,
	_WDT_0_1              ,
	_Timer_0A             ,
	_Timer_0B             ,
	_Timer_1A             ,
	_Timer_1B             ,
	_Timer_2A             ,
	_Timer_2B             ,
	_Analog_Comparator0   ,
	_Analog_Comparator1   ,
	_System_Control  =28  ,
	_Flash_EEPROM_CTRL    ,
	_GPIO_Port_F	 	      ,
	_UART2          = 33  ,
	_SSI1                 ,
	_Timer_3A             ,
	_Timer_3B             ,
	_I2C1                 ,
	_QEI1                 ,
	_CAN0                 ,
	_CAN1                 ,
	_Hibernation_Module=43, 
	_USB                  ,
	_PWM_g3               ,
	_uDMA_Software        ,
	_uDMA_Error           ,
	_ADC1_sq0             ,
	_ADC1_sq1             ,
	_ADC1_sq2             ,
	_ADC1_sq3             ,
	_SSI2           = 57  ,
	_SSI3                 ,
	_UART3                ,
	_UART4                ,
	_UART5                ,
	_UART6                ,
	_UART7                ,
	_I2C2           = 68  ,
	_I2C3                 ,
	_Timer_4A       			,
	_Timer_4B       			,
	_Timer_5A       = 92	,
	_Timer_5B      			  ,
	_32bit_Timer_0A       ,
	_32bit_Timer_0B       ,
	_32bit_Timer_1A       ,				     
	_32bit_Timer_1B		    ,
	_32bit_Timer_2A       ,
	_32bit_Timer_2B       ,
	_32bit_Timer_3A       ,
	_32bit_Timer_3B       ,
	_32bit_Timer_4A       ,
	_32bit_Timer_4B       ,
	_32bit_Timer_5A       ,
	_32bit_Timer_5B       ,
	_System_Exception     ,
	_PWM1_g0        = 134 ,
	_PWM1_g1              ,
	_PWM1_g2              ,
	_PWM1_g3              ,
	_PWM1_Fault         
		
}IntCtrl_Types;


typedef enum
{
	_Enable,
	_Disable,
	_Pend
}IntCtrl_Mode;

typedef struct
{
	u32      :5;
	u32 INTA :3;
	u32      :5;
	u32 INTB :3;
	u32      :5;
	u32 INTC :3;
	u32      :5;
	u32 INTD :3;
	
}IntCtrl_Pri;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void IntCtrl_init(void);
 
#endif  /* IntCtrl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.h
 *********************************************************************************************************************/
