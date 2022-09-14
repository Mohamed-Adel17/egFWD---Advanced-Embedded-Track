/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_Interface.h
 *       Module:  DIO_driver
 *
 *  Description:  This is a static header file for DIO driver
 *
 *  
 *********************************************************************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

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
#define GPIODEN_OFFSET 0x51C
#define GPIOPUR_OFFSET 0x510


	
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
	
#define	DIO_Write_BitBand(_PORT,REG_OFFSET,_PIN,VALUE)     *((volatile u32 *)(PERI_ALIASE_BASE + ((_PORT+REG_OFFSET-PERI_BASE)*32 +(_PIN*4)))) = VALUE
#define	DIO_Read_BitBand(_PORT,REG_OFFSET,_PIN)             (u8)*((volatile u32 *)(PERI_ALIASE_BASE + ((_PORT+REG_OFFSET-PERI_BASE)*32 +(_PIN*4))))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#ifndef PORT_HEADER
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
	
}Dio_ChannelType;
#endif
typedef enum
{
	DIO_LOW    =0,
	DIO_HIGH   =1,
	DIO_PORT_OUTPUT = 0xFF
	
}Dio_LevelType;

#ifndef PORT_HEADER
typedef enum
{
	PORTA_ID ,
	PORTB_ID ,
	PORTC_ID ,
	PORTD_ID ,
	PORTE_ID ,
	PORTF_ID 
	
}Dio_PortType;
#endif
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#ifndef PORT_HEADER
void Dio_WritePin(Dio_ChannelType Pin, Dio_LevelType Level);

Dio_LevelType Dio_ReadPin(Dio_ChannelType Channel);

void Dio_WritePort(Dio_PortType PortId, u8 Level);

u8 Dio_ReadPort(Dio_PortType PortId);

#else
void Dio_WritePin(PORT_PinType Pin, Dio_LevelType Level);

Dio_LevelType Dio_ReadPin(PORT_PinType Channel);

void Dio_WritePort(PORT_PortType PortId, u8 Level);

u8 Dio_ReadPort(PORT_PortType PortId);
#endif


#endif  /* PORT_H */
/**********************************************************************************************************************
 *  END OF FILE: DIO_Interface.h
 *********************************************************************************************************************/

	