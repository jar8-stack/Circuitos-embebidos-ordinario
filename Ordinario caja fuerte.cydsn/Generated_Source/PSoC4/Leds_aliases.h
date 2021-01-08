/*******************************************************************************
* File Name: Leds.h  
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

#if !defined(CY_PINS_Leds_ALIASES_H) /* Pins Leds_ALIASES_H */
#define CY_PINS_Leds_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Leds_0			(Leds__0__PC)
#define Leds_0_PS		(Leds__0__PS)
#define Leds_0_PC		(Leds__0__PC)
#define Leds_0_DR		(Leds__0__DR)
#define Leds_0_SHIFT	(Leds__0__SHIFT)
#define Leds_0_INTR	((uint16)((uint16)0x0003u << (Leds__0__SHIFT*2u)))

#define Leds_1			(Leds__1__PC)
#define Leds_1_PS		(Leds__1__PS)
#define Leds_1_PC		(Leds__1__PC)
#define Leds_1_DR		(Leds__1__DR)
#define Leds_1_SHIFT	(Leds__1__SHIFT)
#define Leds_1_INTR	((uint16)((uint16)0x0003u << (Leds__1__SHIFT*2u)))

#define Leds_2			(Leds__2__PC)
#define Leds_2_PS		(Leds__2__PS)
#define Leds_2_PC		(Leds__2__PC)
#define Leds_2_DR		(Leds__2__DR)
#define Leds_2_SHIFT	(Leds__2__SHIFT)
#define Leds_2_INTR	((uint16)((uint16)0x0003u << (Leds__2__SHIFT*2u)))

#define Leds_INTR_ALL	 ((uint16)(Leds_0_INTR| Leds_1_INTR| Leds_2_INTR))


#endif /* End Pins Leds_ALIASES_H */


/* [] END OF FILE */
