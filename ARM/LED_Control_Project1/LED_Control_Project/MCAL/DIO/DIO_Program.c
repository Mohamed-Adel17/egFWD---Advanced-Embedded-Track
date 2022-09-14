/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "SysCtrl_Clock.h"

/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void Dio_WritePin(Dio_ChannelType Channel, Dio_LevelType Level)
{
	u8 PORT_Num = Channel /10;
	u8 PIN_Num  = Channel %10;
	switch(PORT_Num)
	{
		case PORTA_ID:	DIO_Write_BitBand(PORTA_BASE,GPIODATA_OFFSET,PIN_Num,Level); break;
		case PORTB_ID:	DIO_Write_BitBand(PORTB_BASE,GPIODATA_OFFSET,PIN_Num,Level); break;
		case PORTC_ID:	DIO_Write_BitBand(PORTC_BASE,GPIODATA_OFFSET,PIN_Num,Level); break;
		case PORTD_ID:	DIO_Write_BitBand(PORTD_BASE,GPIODATA_OFFSET,PIN_Num,Level); break;
		case PORTE_ID:	DIO_Write_BitBand(PORTE_BASE,GPIODATA_OFFSET,PIN_Num,Level); break;
		case PORTF_ID:	DIO_Write_BitBand(PORTF_BASE,GPIODATA_OFFSET,PIN_Num,Level); break;
	}	
}

Dio_LevelType Dio_ReadPin(Dio_ChannelType Channel)
{
	u8 PORT_Num = Channel /10;
	u8 PIN_Num  = Channel %10;
	u8 Level=0;
	switch(PORT_Num)
	{
		case PORTA_ID:	Level = DIO_Read_BitBand(PORTA_BASE,GPIODATA_OFFSET,PIN_Num); break;
		case PORTB_ID:	Level = DIO_Read_BitBand(PORTB_BASE,GPIODATA_OFFSET,PIN_Num); break;
		case PORTC_ID:	Level = DIO_Read_BitBand(PORTC_BASE,GPIODATA_OFFSET,PIN_Num); break;
		case PORTD_ID:	Level = DIO_Read_BitBand(PORTD_BASE,GPIODATA_OFFSET,PIN_Num); break;
		case PORTE_ID:	Level = DIO_Read_BitBand(PORTE_BASE,GPIODATA_OFFSET,PIN_Num); break;
		case PORTF_ID:	Level = DIO_Read_BitBand(PORTF_BASE,GPIODATA_OFFSET,PIN_Num); break;
	}		
	return Level;	
}

void Dio_WritePort(Dio_PortType PortId, u8 Level)
{
	switch(PortId)
	{
		case PORTA_ID: *(volatile u32 *)(PORTA_BASE+GPIODATA_OFFSET) |= Level;	 break;
		case PORTB_ID: *(volatile u32 *)(PORTB_BASE+GPIODATA_OFFSET) |= Level;	 break;
		case PORTC_ID: *(volatile u32 *)(PORTC_BASE+GPIODATA_OFFSET) |= Level;	 break;
		case PORTD_ID: *(volatile u32 *)(PORTD_BASE+GPIODATA_OFFSET) |= Level;	 break;
		case PORTE_ID: *(volatile u32 *)(PORTE_BASE+GPIODATA_OFFSET) |= Level;	 break;
		case PORTF_ID: *(volatile u32 *)(PORTF_BASE+GPIODATA_OFFSET) |= Level;	 break;				
	}
}

u8 Dio_ReadPort(Dio_PortType PortId)
{
	u8 Level=0;
	switch(PortId)
	{
		case PORTA_ID: Level = (u8)*(volatile u32 *)(PORTA_BASE+GPIODATA_OFFSET);  break;
		case PORTB_ID: Level = (u8)*(volatile u32 *)(PORTB_BASE+GPIODATA_OFFSET);	 break;
		case PORTC_ID: Level = (u8)*(volatile u32 *)(PORTC_BASE+GPIODATA_OFFSET);  break;
		case PORTD_ID: Level = (u8)*(volatile u32 *)(PORTD_BASE+GPIODATA_OFFSET);  break;
		case PORTE_ID: Level = (u8)*(volatile u32 *)(PORTE_BASE+GPIODATA_OFFSET);  break;
		case PORTF_ID: Level = (u8)*(volatile u32 *)(PORTF_BASE+GPIODATA_OFFSET);	 break;				
	}	
	
	return Level;
}
