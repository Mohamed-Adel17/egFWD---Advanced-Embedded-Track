/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg
 *       Module:  IntCtrl_Driver
 *
 *  Description:  This is a configuration header file to configure some parameters
 *                like : 	- number of interrupts to be configured
 *							          - group and subgroup priority configuration
 *							          - SysTick timer priority level if enabled
 *						 
 *  
 *********************************************************************************************************************/
#ifndef IntCtrl_Cfg_H
#define IntCtrl_Cfg_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "IntCtrl.h"

/**********************************************************************************************************************
 *  GLOBAL CONFIGURABLE MACROS
 *********************************************************************************************************************/
#define INT_MaxNumToBeConfigured	0

/*choose the number of interrupts you will configure [0:138]*/

/**********************************************************************************/

#define SYSTICK_PRIORITY 0   /*SysTick priority level [0:7]*/

/**********************************************************************************/
#define PRIGROUP_VALUE _8_Groups_xxx
/*
 *choose the group and subgroup configuration from the following :
 *	- use all three bits for group (8 group levels, [0:7]) and no subgroup -------------> _8_Groups_xxx
 *	- use two bits for group (4 group levels, [0:3]), and one bit  for subgroup [0:1] --> _4_Groups_xxy
 *	- use one bit for group (2 group levels, [0:1]),  and two bits for subgroup [0:3] --> _2_Groups_xyy
 *	- use all three bits for subgroup (8 subgroup levels, [0:7]) and no group ----------> _8_Groups_xxx
 *
 */

/**********************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define NULL (void *)0

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef struct
{
	IntCtrl_Types Type;		/*peripheral type*/
	IntCtrl_Mode  Mode;		/*operating mode [Enable - Disable - Pend]*/
	u8 PriLevel; 			/*priority level [0:7]*/
	
}IntConfig_t;

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* IntCtrl_Cfg_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
