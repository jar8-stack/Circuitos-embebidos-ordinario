/*******************************************************************************
* File Name: Col.h  
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

#if !defined(CY_PINS_Col_ALIASES_H) /* Pins Col_ALIASES_H */
#define CY_PINS_Col_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Col_0			(Col__0__PC)
#define Col_0_PS		(Col__0__PS)
#define Col_0_PC		(Col__0__PC)
#define Col_0_DR		(Col__0__DR)
#define Col_0_SHIFT	(Col__0__SHIFT)
#define Col_0_INTR	((uint16)((uint16)0x0003u << (Col__0__SHIFT*2u)))

#define Col_1			(Col__1__PC)
#define Col_1_PS		(Col__1__PS)
#define Col_1_PC		(Col__1__PC)
#define Col_1_DR		(Col__1__DR)
#define Col_1_SHIFT	(Col__1__SHIFT)
#define Col_1_INTR	((uint16)((uint16)0x0003u << (Col__1__SHIFT*2u)))

#define Col_2			(Col__2__PC)
#define Col_2_PS		(Col__2__PS)
#define Col_2_PC		(Col__2__PC)
#define Col_2_DR		(Col__2__DR)
#define Col_2_SHIFT	(Col__2__SHIFT)
#define Col_2_INTR	((uint16)((uint16)0x0003u << (Col__2__SHIFT*2u)))

#define Col_3			(Col__3__PC)
#define Col_3_PS		(Col__3__PS)
#define Col_3_PC		(Col__3__PC)
#define Col_3_DR		(Col__3__DR)
#define Col_3_SHIFT	(Col__3__SHIFT)
#define Col_3_INTR	((uint16)((uint16)0x0003u << (Col__3__SHIFT*2u)))

#define Col_INTR_ALL	 ((uint16)(Col_0_INTR| Col_1_INTR| Col_2_INTR| Col_3_INTR))


#endif /* End Pins Col_ALIASES_H */


/* [] END OF FILE */
