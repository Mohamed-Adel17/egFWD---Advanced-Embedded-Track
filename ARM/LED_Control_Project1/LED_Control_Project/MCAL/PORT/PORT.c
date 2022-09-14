/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "PORT.h"
#include "PORT_Cfg.h"
#include "SysCtrl_Clock.h"

/**********************************************************************************************************************
 *  Global Variables
 *********************************************************************************************************************/
extern volatile ChannelConfig_t PinConfig[NumberOfPins];

/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void PORT_Init(void)
{
	u8 i=0;
	for(i=0;i<NumberOfPins;i++)
	{
		u8 PORT_Num = PinConfig[i].PortPinType /10;
		u8 PIN_Num  = PinConfig[i].PortPinType %10;
		
		
		switch(PORT_Num)
		{
			case PORTA_ID:
				SysCtrl_ClockEnable(_GPIO,PORT_Num);
				DIO_Write_BitBand(PORTA_BASE,GPIODIR_OFFSET,PIN_Num,PinConfig[i].PortPinDirectionType);
				/*Configure Mode -> (DIO , NOT_DIO)*/
				if(PinConfig[i].PortPinMode == DIO_Mode)
				{
					DIO_Write_BitBand(PORTA_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTA_BASE,GPIODEN_OFFSET,PIN_Num,PIN_HIGH);
				}else
				{
					DIO_Write_BitBand(PORTA_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_HIGH);
					DIO_Write_BitBand(PORTA_BASE,GPIODEN_OFFSET,PIN_Num,PIN_LOW);
				}
				
				/*Configure internal attachment*/
				if(PinConfig[i].PortPinInternalAttachType == PullUp)
				{
					DIO_Write_BitBand(PORTA_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_HIGH);
				}else if(PinConfig[i].PortPinInternalAttachType == PullDown)
				{
					DIO_Write_BitBand(PORTA_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_HIGH);
				}else //open drain
				{
					DIO_Write_BitBand(PORTA_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTA_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTA_BASE,GPIOODR_OFFSET,PIN_Num,PIN_HIGH);
				}
				break;
				
			case PORTB_ID:
				SysCtrl_ClockEnable(_GPIO,PORT_Num);
				DIO_Write_BitBand(PORTB_BASE,GPIODIR_OFFSET,PIN_Num,PinConfig[i].PortPinDirectionType);
				/*Configure Mode -> (DIO , NOT_DIO)*/
				if(PinConfig[i].PortPinMode == DIO_Mode)
					{
						DIO_Write_BitBand(PORTB_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_LOW);
						DIO_Write_BitBand(PORTB_BASE,GPIODEN_OFFSET,PIN_Num,PIN_HIGH);
				}else
				{
					DIO_Write_BitBand(PORTB_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_HIGH);
					DIO_Write_BitBand(PORTB_BASE,GPIODEN_OFFSET,PIN_Num,PIN_LOW);
				}
				
				/*Configure internal attachment*/
				if(PinConfig[i].PortPinInternalAttachType == PullUp)
				{
					DIO_Write_BitBand(PORTB_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_HIGH);
				}else if(PinConfig[i].PortPinInternalAttachType == PullDown)
				{
					DIO_Write_BitBand(PORTB_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_HIGH);
				}else //open drain
				{
					DIO_Write_BitBand(PORTB_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTB_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTB_BASE,GPIOODR_OFFSET,PIN_Num,PIN_HIGH);
				}								
				break;
				
			case PORTC_ID:
				SysCtrl_ClockEnable(_GPIO,PORT_Num);
				DIO_Write_BitBand(PORTC_BASE,GPIODIR_OFFSET,PIN_Num,PinConfig[i].PortPinDirectionType);
				/*Configure Mode -> (DIO , NOT_DIO)*/
				if(PinConfig[i].PortPinMode == DIO_Mode)
				{
						DIO_Write_BitBand(PORTC_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_LOW);
						DIO_Write_BitBand(PORTC_BASE,GPIODEN_OFFSET,PIN_Num,PIN_HIGH);
				}else
				{
					DIO_Write_BitBand(PORTC_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_HIGH);
					DIO_Write_BitBand(PORTC_BASE,GPIODEN_OFFSET,PIN_Num,PIN_LOW);
				}
				
				/*Configure internal attachment*/
				if(PinConfig[i].PortPinInternalAttachType == PullUp)
				{
					DIO_Write_BitBand(PORTC_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_HIGH);
				}else if(PinConfig[i].PortPinInternalAttachType == PullDown)
				{
					DIO_Write_BitBand(PORTC_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_HIGH);
				}else //open drain
				{
					DIO_Write_BitBand(PORTC_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTC_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTC_BASE,GPIOODR_OFFSET,PIN_Num,PIN_HIGH);
				}																
				break;
				
			case PORTD_ID:
				SysCtrl_ClockEnable(_GPIO,PORT_Num);
				if(PIN_Num == 7)
				{
					*((volatile u32*)(PORTD_BASE+GPIOLOCK_OFFSET))=  UNLOCK_GPIOLOCK;  //unlocking PD7
					DIO_Write_BitBand(PORTD_BASE,GPIOCR_OFFSET,PIN_Num,PIN_HIGH);      //uncommiting PD7
				}			
				DIO_Write_BitBand(PORTD_BASE,GPIODIR_OFFSET,PIN_Num,PinConfig[i].PortPinDirectionType);
				/*Configure Mode -> (DIO , NOT_DIO)*/
				if(PinConfig[i].PortPinMode == DIO_Mode)
				{
						DIO_Write_BitBand(PORTD_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_LOW);
						DIO_Write_BitBand(PORTD_BASE,GPIODEN_OFFSET,PIN_Num,PIN_HIGH);
				}else
				{
					DIO_Write_BitBand(PORTD_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_HIGH);
					DIO_Write_BitBand(PORTD_BASE,GPIODEN_OFFSET,PIN_Num,PIN_LOW);
				}
				
				/*Configure internal attachment*/
				if(PinConfig[i].PortPinInternalAttachType == PullUp)
				{
					DIO_Write_BitBand(PORTD_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_HIGH);
				}else if(PinConfig[i].PortPinInternalAttachType == PullDown)
				{
					DIO_Write_BitBand(PORTD_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_HIGH);
				}else //open drain
				{
					DIO_Write_BitBand(PORTD_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTD_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTD_BASE,GPIOODR_OFFSET,PIN_Num,PIN_HIGH);
				}							
				break;
				
			case PORTE_ID:
				SysCtrl_ClockEnable(_GPIO,PORT_Num);
				DIO_Write_BitBand(PORTE_BASE,GPIODIR_OFFSET,PIN_Num,PinConfig[i].PortPinDirectionType);
				/*Configure Mode -> (DIO , NOT_DIO)*/
				if(PinConfig[i].PortPinMode == DIO_Mode)
				{
						DIO_Write_BitBand(PORTE_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_LOW);
						DIO_Write_BitBand(PORTE_BASE,GPIODEN_OFFSET,PIN_Num,PIN_HIGH);
				}else
				{
					DIO_Write_BitBand(PORTE_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_HIGH);
					DIO_Write_BitBand(PORTE_BASE,GPIODEN_OFFSET,PIN_Num,PIN_LOW);
				}
				/*Configure internal attachment*/
				if(PinConfig[i].PortPinInternalAttachType == PullUp)
				{
					DIO_Write_BitBand(PORTE_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_HIGH);
				}else if(PinConfig[i].PortPinInternalAttachType == PullDown)
				{
					DIO_Write_BitBand(PORTE_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_HIGH);
				}else //open drain
				{
					DIO_Write_BitBand(PORTE_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTE_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTE_BASE,GPIOODR_OFFSET,PIN_Num,PIN_HIGH);
				}								
				break;
				
			case PORTF_ID:
				SysCtrl_ClockEnable(_GPIO,PORT_Num);
				if(PIN_Num == 0)
				{
					*((volatile u32*)(PORTF_BASE+GPIOLOCK_OFFSET))=  UNLOCK_GPIOLOCK;  //unlocking PF0
					DIO_Write_BitBand(PORTF_BASE,GPIOCR_OFFSET,PIN_Num,PIN_HIGH);      //uncommiting PF0
				}
				DIO_Write_BitBand(PORTF_BASE,GPIODIR_OFFSET,PIN_Num,PinConfig[i].PortPinDirectionType);
				/*Configure Mode -> (DIO , NOT_DIO)*/
				if(PinConfig[i].PortPinMode == DIO_Mode)
				{
						DIO_Write_BitBand(PORTF_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_LOW);
						DIO_Write_BitBand(PORTF_BASE,GPIODEN_OFFSET,PIN_Num,PIN_HIGH);
				}else
				{
					DIO_Write_BitBand(PORTF_BASE,GPIOAFSEL_OFFSET,PIN_Num,PIN_HIGH);
					DIO_Write_BitBand(PORTF_BASE,GPIODEN_OFFSET,PIN_Num,PIN_LOW);
				}
				/*Configure internal attachment*/
				if(PinConfig[i].PortPinInternalAttachType == PullUp)
				{
					DIO_Write_BitBand(PORTF_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_HIGH);
				}else if(PinConfig[i].PortPinInternalAttachType == PullDown)
				{
					DIO_Write_BitBand(PORTF_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_HIGH);
				}else //open drain
				{
					DIO_Write_BitBand(PORTF_BASE,GPIOPUR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTF_BASE,GPIOPDR_OFFSET,PIN_Num,PIN_LOW);
					DIO_Write_BitBand(PORTF_BASE,GPIOODR_OFFSET,PIN_Num,PIN_HIGH);
				}				
				break;					
		}

		if(PinConfig[i].PortPinMode != DIO_Mode)
		{		
			switch(PORT_Num)
			{
				case PORTA_ID:
					switch(PIN_Num)
					{
						case 0:((volatile GPIOCTRL_t *)(PORTA_BASE+GPIOPCTL_OFFSET))->PMC0 = PinConfig[i].PortPinMode; break;
						case 1:((volatile GPIOCTRL_t *)(PORTA_BASE+GPIOPCTL_OFFSET))->PMC1 = PinConfig[i].PortPinMode; break;
						case 2:((volatile GPIOCTRL_t *)(PORTA_BASE+GPIOPCTL_OFFSET))->PMC2 = PinConfig[i].PortPinMode; break;
						case 3:((volatile GPIOCTRL_t *)(PORTA_BASE+GPIOPCTL_OFFSET))->PMC3 = PinConfig[i].PortPinMode; break;
						case 4:((volatile GPIOCTRL_t *)(PORTA_BASE+GPIOPCTL_OFFSET))->PMC4 = PinConfig[i].PortPinMode; break;
						case 5:((volatile GPIOCTRL_t *)(PORTA_BASE+GPIOPCTL_OFFSET))->PMC5 = PinConfig[i].PortPinMode; break;
						case 6:((volatile GPIOCTRL_t *)(PORTA_BASE+GPIOPCTL_OFFSET))->PMC6 = PinConfig[i].PortPinMode; break;
						case 7:((volatile GPIOCTRL_t *)(PORTA_BASE+GPIOPCTL_OFFSET))->PMC7 = PinConfig[i].PortPinMode; break;		
					}
					break;
				case PORTB_ID:
					switch(PIN_Num)
					{
						case 0:((volatile GPIOCTRL_t *)(PORTB_BASE+GPIOPCTL_OFFSET))->PMC0 = PinConfig[i].PortPinMode; break;
						case 1:((volatile GPIOCTRL_t *)(PORTB_BASE+GPIOPCTL_OFFSET))->PMC1 = PinConfig[i].PortPinMode; break;
						case 2:((volatile GPIOCTRL_t *)(PORTB_BASE+GPIOPCTL_OFFSET))->PMC2 = PinConfig[i].PortPinMode; break;
						case 3:((volatile GPIOCTRL_t *)(PORTB_BASE+GPIOPCTL_OFFSET))->PMC3 = PinConfig[i].PortPinMode; break;
						case 4:((volatile GPIOCTRL_t *)(PORTB_BASE+GPIOPCTL_OFFSET))->PMC4 = PinConfig[i].PortPinMode; break;
						case 5:((volatile GPIOCTRL_t *)(PORTB_BASE+GPIOPCTL_OFFSET))->PMC5 = PinConfig[i].PortPinMode; break;
						case 6:((volatile GPIOCTRL_t *)(PORTB_BASE+GPIOPCTL_OFFSET))->PMC6 = PinConfig[i].PortPinMode; break;
						case 7:((volatile GPIOCTRL_t *)(PORTB_BASE+GPIOPCTL_OFFSET))->PMC7 = PinConfig[i].PortPinMode; break;		
					}
					break;
				case PORTC_ID:
					switch(PIN_Num)
					{
						case 0:((volatile GPIOCTRL_t *)(PORTC_BASE+GPIOPCTL_OFFSET))->PMC0 = PinConfig[i].PortPinMode; break;
						case 1:((volatile GPIOCTRL_t *)(PORTC_BASE+GPIOPCTL_OFFSET))->PMC1 = PinConfig[i].PortPinMode; break;
						case 2:((volatile GPIOCTRL_t *)(PORTC_BASE+GPIOPCTL_OFFSET))->PMC2 = PinConfig[i].PortPinMode; break;
						case 3:((volatile GPIOCTRL_t *)(PORTC_BASE+GPIOPCTL_OFFSET))->PMC3 = PinConfig[i].PortPinMode; break;
						case 4:((volatile GPIOCTRL_t *)(PORTC_BASE+GPIOPCTL_OFFSET))->PMC4 = PinConfig[i].PortPinMode; break;
						case 5:((volatile GPIOCTRL_t *)(PORTC_BASE+GPIOPCTL_OFFSET))->PMC5 = PinConfig[i].PortPinMode; break;
						case 6:((volatile GPIOCTRL_t *)(PORTC_BASE+GPIOPCTL_OFFSET))->PMC6 = PinConfig[i].PortPinMode; break;
						case 7:((volatile GPIOCTRL_t *)(PORTC_BASE+GPIOPCTL_OFFSET))->PMC7 = PinConfig[i].PortPinMode; break;		
					}
					break;	
				case PORTD_ID:
					switch(PIN_Num)
					{
						case 0:((volatile GPIOCTRL_t *)(PORTD_BASE+GPIOPCTL_OFFSET))->PMC0 = PinConfig[i].PortPinMode; break;
						case 1:((volatile GPIOCTRL_t *)(PORTD_BASE+GPIOPCTL_OFFSET))->PMC1 = PinConfig[i].PortPinMode; break;
						case 2:((volatile GPIOCTRL_t *)(PORTD_BASE+GPIOPCTL_OFFSET))->PMC2 = PinConfig[i].PortPinMode; break;
						case 3:((volatile GPIOCTRL_t *)(PORTD_BASE+GPIOPCTL_OFFSET))->PMC3 = PinConfig[i].PortPinMode; break;
						case 4:((volatile GPIOCTRL_t *)(PORTD_BASE+GPIOPCTL_OFFSET))->PMC4 = PinConfig[i].PortPinMode; break;
						case 5:((volatile GPIOCTRL_t *)(PORTD_BASE+GPIOPCTL_OFFSET))->PMC5 = PinConfig[i].PortPinMode; break;
						case 6:((volatile GPIOCTRL_t *)(PORTD_BASE+GPIOPCTL_OFFSET))->PMC6 = PinConfig[i].PortPinMode; break;
						case 7:((volatile GPIOCTRL_t *)(PORTD_BASE+GPIOPCTL_OFFSET))->PMC7 = PinConfig[i].PortPinMode; break;		
					}
					break;
				case PORTE_ID:
					switch(PIN_Num)
					{
						case 0:((volatile GPIOCTRL_t *)(PORTE_BASE+GPIOPCTL_OFFSET))->PMC0 = PinConfig[i].PortPinMode; break;
						case 1:((volatile GPIOCTRL_t *)(PORTE_BASE+GPIOPCTL_OFFSET))->PMC1 = PinConfig[i].PortPinMode; break;
						case 2:((volatile GPIOCTRL_t *)(PORTE_BASE+GPIOPCTL_OFFSET))->PMC2 = PinConfig[i].PortPinMode; break;
						case 3:((volatile GPIOCTRL_t *)(PORTE_BASE+GPIOPCTL_OFFSET))->PMC3 = PinConfig[i].PortPinMode; break;
						case 4:((volatile GPIOCTRL_t *)(PORTE_BASE+GPIOPCTL_OFFSET))->PMC4 = PinConfig[i].PortPinMode; break;
						case 5:((volatile GPIOCTRL_t *)(PORTE_BASE+GPIOPCTL_OFFSET))->PMC5 = PinConfig[i].PortPinMode; break;	
					}
					break;
				case PORTF_ID:
					switch(PIN_Num)
					{
						case 0:((volatile GPIOCTRL_t *)(PORTF_BASE+GPIOPCTL_OFFSET))->PMC0 = PinConfig[i].PortPinMode; break;
						case 1:((volatile GPIOCTRL_t *)(PORTF_BASE+GPIOPCTL_OFFSET))->PMC1 = PinConfig[i].PortPinMode; break;
						case 2:((volatile GPIOCTRL_t *)(PORTF_BASE+GPIOPCTL_OFFSET))->PMC2 = PinConfig[i].PortPinMode; break;
						case 3:((volatile GPIOCTRL_t *)(PORTF_BASE+GPIOPCTL_OFFSET))->PMC3 = PinConfig[i].PortPinMode; break;
						case 4:((volatile GPIOCTRL_t *)(PORTF_BASE+GPIOPCTL_OFFSET))->PMC4 = PinConfig[i].PortPinMode; break;		
					}
					break;						
			}			
		}			
	}
}
