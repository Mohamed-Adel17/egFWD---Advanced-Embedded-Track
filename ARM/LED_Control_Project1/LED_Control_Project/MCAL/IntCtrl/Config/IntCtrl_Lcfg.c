/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "IntCtrl_Cfg.h"
#include "IntCtrl.h"

/**********************************************************************************************************************
 *  Global Variables
 *********************************************************************************************************************/

volatile IntConfig_t IntCfg[INT_MaxNumToBeConfigured] = {
					
						
					//{_GPIO_PortA,_Enable,0}    /*here 0 is the priority level*/
			
};

/*Interrupt Modes : _Enable - _Disable - _Pend */

/*peripheral types :

	_GPIO_PortA           _GPIO_PortB           _GPIO_PortC    _GPIO_PortD           
	_GPIO_PortE           _GPIO_PortF        
						  
	_UART0          		  _UART1          			_UART2   		          _UART3				  
	_UART4				  		  _UART5                _UART6                _UART7
						  
	_SSI0 				  		  _SSI1                	_SSI2                 _SSI3
						 
	_I2C0            		  _I2C1                 _I2C2                 _I2C3  

	_PWM0_Fault           _PWM0_g0              _PWM0_g1              _PWM0_g2     _PWM0_g3  
	_PWM1_Fault			      _PWM1_g0              _PWM1_g1              _PWM1_g2     _PWM1_g3               

	_QEI0                 _QEI1
	
	_ADC0_sq0             _ADC0_sq1             _ADC0_sq2
	_ADC1_sq0             _ADC1_sq1             _ADC1_sq2             _ADC1_sq3 

	_CAN0                 _CAN1 	
	
	_WDT_0_1  
	
	_16bit_Timer_0A       _16bit_Timer_0B   		_16bit_Timer_1A       _16bit_Timer_1B             
	_16bit_Timer_2A       _16bit_Timer_2B   		_16bit_Timer_3A       _16bit_Timer_3B
	_16bit_Timer_4A       _16bit_Timer_4B   		_16bit_Timer_5A       _16bit_Timer_5B
		
    _32bit_Timer_0A     _32bit_Timer_0B       _32bit_Timer_1A       _32bit_Timer_1B		    
	_32bit_Timer_2A       _32bit_Timer_2B       _32bit_Timer_3A       _32bit_Timer_3B       
	_32bit_Timer_4A       _32bit_Timer_4B       _32bit_Timer_5A       _32bit_Timer_5B  
	
	_Analog_Comparator0   _Analog_Comparator1   
	
	_System_Control   

	_Flash_EEPROM_CTRL            
	                             
	_Hibernation_Module 
	_USB                  
	               
	_uDMA_Software        _uDMA_Error           

	_System_Exception     
	    
	
	*/
