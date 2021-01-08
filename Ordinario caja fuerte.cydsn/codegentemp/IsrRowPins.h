/*******************************************************************************
* File Name: IsrRowPins.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_IsrRowPins_H)
#define CY_ISR_IsrRowPins_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void IsrRowPins_Start(void);
void IsrRowPins_StartEx(cyisraddress address);
void IsrRowPins_Stop(void);

CY_ISR_PROTO(IsrRowPins_Interrupt);

void IsrRowPins_SetVector(cyisraddress address);
cyisraddress IsrRowPins_GetVector(void);

void IsrRowPins_SetPriority(uint8 priority);
uint8 IsrRowPins_GetPriority(void);

void IsrRowPins_Enable(void);
uint8 IsrRowPins_GetState(void);
void IsrRowPins_Disable(void);

void IsrRowPins_SetPending(void);
void IsrRowPins_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the IsrRowPins ISR. */
#define IsrRowPins_INTC_VECTOR            ((reg32 *) IsrRowPins__INTC_VECT)

/* Address of the IsrRowPins ISR priority. */
#define IsrRowPins_INTC_PRIOR             ((reg32 *) IsrRowPins__INTC_PRIOR_REG)

/* Priority of the IsrRowPins interrupt. */
#define IsrRowPins_INTC_PRIOR_NUMBER      IsrRowPins__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable IsrRowPins interrupt. */
#define IsrRowPins_INTC_SET_EN            ((reg32 *) IsrRowPins__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the IsrRowPins interrupt. */
#define IsrRowPins_INTC_CLR_EN            ((reg32 *) IsrRowPins__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the IsrRowPins interrupt state to pending. */
#define IsrRowPins_INTC_SET_PD            ((reg32 *) IsrRowPins__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the IsrRowPins interrupt. */
#define IsrRowPins_INTC_CLR_PD            ((reg32 *) IsrRowPins__INTC_CLR_PD_REG)



#endif /* CY_ISR_IsrRowPins_H */


/* [] END OF FILE */
