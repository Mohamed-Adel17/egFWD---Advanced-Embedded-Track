/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysCtrl_Clock
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SysCtrl_Clock_H
#define SysCtrl_Clock_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define SYSCTRL_BASE_ADDRESS  	0x400FE000
#define RCC_OFFSET				0x060
#define RCC2_OFFSET				0x070


#define RCC_R	            ((volatile RCC_Type *)(SYSCTRL_BASE_ADDRESS+RCC_OFFSET))
#define RCC2_R	           *((volatile u32 *)(SYSCTRL_BASE_ADDRESS+RCC2_OFFSET))
#define PLLSTAT_R		   *((volatile u32 *)(SYSCTRL_BASE_ADDRESS + 0x168))
	
#define RCG1_R	           *((volatile u32 *)(SYSCTRL_BASE_ADDRESS + 0x104))
	
#define WD0_M 0
#define WD1_M 1

#define TIMER0_M 0
#define TIMER1_M 1
#define TIMER2_M 2
#define TIMER3_M 3
#define TIMER4_M 4
#define TIMER5_M 5

#define GPIOA_M 0
#define GPIOB_M 1
#define GPIOC_M 2
#define GPIOD_M 3
#define GPIOE_M 4
#define GPIOF_M 5

#define DMA_M 0

#define HIB_M 0

#define UART0_M 0
#define UART1_M 1
#define UART2_M 2
#define UART3_M 3
#define UART4_M 4
#define UART5_M 5
#define UART6_M 6
#define UART7_M 7


#define SSI0_M 0
#define SSI1_M 1
#define SSI2_M 2
#define SSI3_M 3

#define I2C0_M 0
#define I2C1_M 1
#define I2C2_M 2
#define I2C3_M 3

#define USB_M  0

#define CAN0_M 0
#define CAN1_M 1

#define ADC0_M 0
#define ADC1_M 1

#define ACMP_M 0

#define PWM0_M 0
#define PWM1_M 1

#define QEI0_M 0
#define QEI1_M 1

#define EEPROM_M 0


#define NULL (void *)0
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	_WatchDog  = 0x600 ,
	_TIMER     = 0x604 ,
	_GPIO      = 0x608 ,
	_DMA       = 0x60C ,
	_HIB       = 0x614 ,
	_UART      = 0x618 ,
	_SSI       = 0x61C ,  
	_I2C       = 0x620 ,
	_USB_Clock = 0x628 ,
	_CAN       = 0x634 ,
	_ADC       = 0x638 ,
	_AnalogCMP = 0x63C ,
	_PWM       = 0x640 ,
	_QEI       = 0x644 ,
	_EEPROM    = 0x658 ,
	_WideTIMER = 0x65C

}NUMclock_Gating_Type;



typedef enum
{
	_Main_OSC=0,
	_PreInt_OSC,
	_PreInt_OSC_by_4,
	_LowFreqInt_OSC,
	
}NUMosc_source;
typedef enum
{
	_PLL_OFF=0,
	_PLL_ON =1
	
}NUMusing_PLL;
typedef enum
{
	_SYSDIV_1=0	,
	_SYSDIV_2   ,
	_SYSDIV_3   ,
	_SYSDIV_4   ,
	_SYSDIV_5   ,
	_SYSDIV_6   ,
	_SYSDIV_7   ,
	_SYSDIV_8   ,
	_SYSDIV_9   ,
	_SYSDIV_10  ,
	_SYSDIV_11  ,
	_SYSDIV_12  ,
	_SYSDIV_13  ,
	_SYSDIV_14  ,
	_SYSDIV_15  ,
	_SYSDIV_16  
	
}NUMclock_Divisor;

typedef struct
{
	u32 MOSCDIS   :1;
	u32           :3;
	u32 OSCSRC	  :2;
	u32 XTAL      :5;
	u32 BYPASS    :1;
	u32           :1;
	u32 PWRDN     :1;
	u32           :3;
	u32 PWMDIV    :3;
	u32 USEPWMDIV :1;
	u32           :1;
	u32 USESYSDIV :1;
	u32 SYSDIV    :4;
	u32 ACG       :1;
	u32           :4;
}RCC_t;

typedef union
{
	u32 RCC_REG;
	RCC_t RCC_BITS;
	
}RCC_Type;




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void SysCtrl_ClockInit(void);

void SysCtrl_ClockEnable(NUMclock_Gating_Type Peripheral,u8 Num);

void SysCtrl_ClockDisable(NUMclock_Gating_Type Peripheral,u8 Num);
 
#endif  /* SysCtrl_Clock_H */

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl_Clock.h
 *********************************************************************************************************************/
