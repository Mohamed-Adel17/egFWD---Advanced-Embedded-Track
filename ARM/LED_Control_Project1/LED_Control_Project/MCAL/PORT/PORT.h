/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT.h
 *       Module:  PORT_driver
 *
 *  Description:  This is a static header file for PORT driver
 *
 *  
 *********************************************************************************************************************/

#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORT_HEADER

#define PERI_BASE        0x40000000

#define PERI_ALIASE_BASE 0x42000000


#define	PORTA_BASE 0x40004000
#define	PORTB_BASE 0x40005000
#define	PORTC_BASE 0x40006000
#define	PORTD_BASE 0x40007000
#define	PORTE_BASE 0x40024000
#define	PORTF_BASE 0x40025000

	
#define GPIODATA_OFFSET	 0x3FC
#define GPIODIR_OFFSET	 0x400
#define GPIOAFSEL_OFFSET 0x420
#define GPIODEN_OFFSET   0x51C
#define GPIOPUR_OFFSET   0x510
#define	GPIOPDR_OFFSET	 0x514
#define	GPIOODR_OFFSET	 0x50C
#define	GPIOPCTL_OFFSET	 0x52C
#define GPIOLOCK_OFFSET  0x520
#define GPIOCR_OFFSET    0x524

#define UNLOCK_GPIOLOCK  0x4C4F434B


#define DIO_Mode  0 

 /*Alternate functions for each pin*/

#define PA0_U0Rx		     1
#define PA1_U0Tx         1
#define PB0_U1Rx         1
#define PB1_U1Tx         1
#define PC0_TCKSWCLK     1
#define PC1_TMSSWDIO     1
#define PC2_TDI          1
#define PC3_TDOSWO       1
#define PC4_U4Rx         1
#define PC5_U4Tx         1
#define PC6_U3Rx         1
#define PC7_U3Tx         1
#define PD0_SSI3Clk      1
#define PD1_SSI3Fss      1
#define PD2_SSI3Rx       1
#define PD3_SSI3Tx       1
#define PD4_U6Rx         1
#define PD5_U6Tx         1
#define PD6_U2Rx         1
#define PD7_U2Tx         1
#define PE0_U7Rx         1
#define PE1_U7Tx         1
#define PE4_U5Rx		     1 
#define PE5_U5Tx         1
#define PF0_U1RTS        1
#define PF1_U1CTS        1


#define PA2_SSI0Clk		   2
#define PA3_SSI0Fss      2
#define PA4_SSI0Rx       2
#define PA5_SSI0Tx       2
#define PB4_SSI2Clk      2
#define PB5_SSI2Fss      2
#define PB6_SSI2Rx       2
#define PB7_SSI2Tx       2
#define PC4_U1Rx         2
#define PC5_U1Tx         2
#define PD0_SSI1Clk      2
#define PD1_SSI1Fss      2
#define PD2_SSI1Rx       2
#define PD3_SSI1Tx       2
#define PF0_SSI1Rx		   2
#define PF1_SSI1Tx       2
#define PF2_SSI1Clk      2
#define PF3_SSI1Fss      2


#define PA6_I2C1SCL		   3
#define PA7_I2C1SDA      3
#define PB2_I2C0SCL      3
#define PB3_I2C0SDA      3
#define PD0_I2C3SCL      3
#define PD1_I2C3SDA      3
#define PE4_I2C2SCL		   3
#define PE5_I2C2SDA      3
#define PF0_CAN0Rx       3
#define PF3_CAN0Tx       3


#define PB4_M0PWM2		   4
#define PB5_M0PWM3       4
#define PB6_M0PWM0       4
#define PB7_M0PWM1       4
#define PC4_M0PWM6       4
#define PC5_M0PWM7       4
#define PD0_M0PWM6       4
#define PD1_M0PWM7       4
#define PD2_M0FAULT0     4
#define PD6_M0FAULT0     4
#define PE4_M0PWM4		   4
#define PE5_M0PWM5       4
#define PF2_M0FAULT0     4


#define PA6_M1PWM2		   5
#define PA7_M1PWM3       5
#define PD0_M1PWM0       5
#define PD1_M1PWM1       5   
#define PE4_M1PWM2		   5
#define PE5_M1PWM3       5
#define PF0_M1PWM4       5
#define PF1_M1PWM5       5
#define PF2_M1PWM6       5
#define PF3_M1PWM7       5
#define PF4_M1FAULT0     5
		 
				
#define PC4_IDX1		     6
#define PC5_PhA1         6
#define PC6_PhB1         6
#define PD3_IDX0         6
#define PD6_PhA0         6
#define PD7_PhB0         6                 
#define PF0_PhA0		     6
#define PF1_PhB0         6
#define PF4_IDX0         6

			   
#define PB0_T2CCP0		   7
#define PB1_T2CCP1       7
#define PB2_T3CCP0       7
#define PB3_T3CCP1       7
#define PB4_T1CCP0       7
#define PB5_T1CCP1       7
#define PB6_T0CCP0       7
#define PB7_T0CCP1       7
#define PC0_T4CCP0       7
#define PC1_T4CCP1       7
#define PC2_T5CCP0       7
#define PC3_T5CCP1       7
#define PC4_WT0CCP0      7
#define PC5_WT0CCP1      7
#define PC6_WT1CCP0      7
#define PC7_WT1CCP1      7
#define PD0_WT2CCP0      7
#define PD1_WT2CCP1      7
#define PD2_WT3CCP0      7
#define PD3_WT3CCP1      7
#define PD4_WT4CCP0      7
#define PD5_WT4CCP1      7
#define PD6_WT5CCP0      7
#define PD7_WT5CCP1      7     
#define PF0_T0CCP0		   7
#define PF1_T0CCP1       7
#define PF2_T1CCP0       7
#define PF3_T1CCP1       7
#define PF4_T2CCP0       7

	
					  
#define PA0_CAN1Rx		   8
#define PA1_CAN1Tx       8
#define PB4_CAN0Rx       8
#define PB5_CAN0Tx       8
#define PC4_U1RTS        8
#define PC5_U1CTS        8
#define PC6_USB0EPEN     8
#define PC7_USB0PFLT     8
#define PD2_USB0EPEN     8
#define PD3_USB0PFLT     8
#define PD7_NMI          8
#define PE4_CAN0Rx		   8
#define PE5_CAN0Tx       8
#define PF0_NMI          8
#define PF4_USB0EPEN     8


#define PF0_C0o			     9
#define PF1_C1o			     9


#define PF1_TRD1		     14
#define PF2_TRD0         14
#define PF3_TRCLK        14

 /*********************************************************************************************************************/
 
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define	DIO_Write_BitBand(_PORT,REG_OFFSET,_PIN,VALUE)   *((volatile u32 *)(PERI_ALIASE_BASE + ((_PORT+REG_OFFSET-PERI_BASE)*32 +(_PIN*4)))) = VALUE
#define	DIO_Read_BitBand(_PORT,REG_OFFSET,_PIN)          *((volatile u32 *)(PERI_ALIASE_BASE + ((_PORT+REG_OFFSET-PERI_BASE)*32 +(_PIN*4))))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	PA0=0 ,
	PA1   ,
	PA2   ,
	PA3   ,
	PA4   ,
	PA5   ,
	PA6   ,
	PA7   ,
	      
	PB0=10,
	PB1   ,
	PB2   ,
	PB3   ,
	PB4   ,
	PB5   ,
	PB6   ,
	PB7   ,
	      
	PC0=20,
	PC1   ,
	PC2   ,
	PC3   ,
	PC4   ,
	PC5   ,
	PC6   ,
	PC7   ,
	      
	PD0=30,
	PD1   ,
	PD2   ,
	PD3   ,
	PD4   ,
	PD5   ,
	PD6   ,
	PD7   ,	
	      
	PE0=40,
	PE1   ,
	PE2   ,
	PE3   ,
	PE4   ,
	PE5   ,
	      
	PF0=50,
	PF1   ,
	PF2   ,
	PF3   ,
	PF4		
	
}PORT_PinType;


typedef enum
{
	PIN_INPUT  =0,
	PIN_OUTPUT =1,
	
}Port_PinDirectionType;
typedef enum
{
	PIN_LOW  =0,
	PIN_HIGH =1,
	
}Port_PinLevelType;

typedef enum
{
	PullDown =0,
	PullUp   =1,
	OpenDrain=2
}Port_PinInternalAttachType;

typedef enum
{
	PORTA_ID ,
	PORTB_ID ,
	PORTC_ID ,
	PORTD_ID ,
	PORTE_ID ,
	PORTF_ID 
	
}PORT_PortType;

typedef struct
{
	u32 PMC0 :4;
	u32 PMC1 :4;
	u32 PMC2 :4;
	u32 PMC3 :4;
	u32 PMC4 :4;
	u32 PMC5 :4;
	u32 PMC6 :4;
	u32 PMC7 :4;
	
}GPIOCTRL_t;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void PORT_Init(void);


#endif  /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT.h
 *********************************************************************************************************************/
