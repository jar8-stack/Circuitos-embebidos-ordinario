/*******************************************************************************
* File Name: Led_pins.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Led_pins_ALIASES_H) /* Pins Led_pins_ALIASES_H */
#define CY_PINS_Led_pins_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Led_pins_0			(Led_pins__0__PC)
#define Led_pins_0_PS		(Led_pins__0__PS)
#define Led_pins_0_PC		(Led_pins__0__PC)
#define Led_pins_0_DR		(Led_pins__0__DR)
#define Led_pins_0_SHIFT	(Led_pins__0__SHIFT)
#define Led_pins_0_INTR	((uint16)((uint16)0x0003u << (Led_pins__0__SHIFT*2u)))

#define Led_pins_1			(Led_pins__1__PC)
#define Led_pins_1_PS		(Led_pins__1__PS)
#define Led_pins_1_PC		(Led_pins__1__PC)
#define Led_pins_1_DR		(Led_pins__1__DR)
#define Led_pins_1_SHIFT	(Led_pins__1__SHIFT)
#define Led_pins_1_INTR	((uint16)((uint16)0x0003u << (Led_pins__1__SHIFT*2u)))

#define Led_pins_2			(Led_pins__2__PC)
#define Led_pins_2_PS		(Led_pins__2__PS)
#define Led_pins_2_PC		(Led_pins__2__PC)
#define Led_pins_2_DR		(Led_pins__2__DR)
#define Led_pins_2_SHIFT	(Led_pins__2__SHIFT)
#define Led_pins_2_INTR	((uint16)((uint16)0x0003u << (Led_pins__2__SHIFT*2u)))

#define Led_pins_INTR_ALL	 ((uint16)(Led_pins_0_INTR| Led_pins_1_INTR| Led_pins_2_INTR))


#endif /* End Pins Led_pins_ALIASES_H */


/* [] END OF FILE */
