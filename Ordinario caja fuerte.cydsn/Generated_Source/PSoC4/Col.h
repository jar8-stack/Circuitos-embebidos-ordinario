/*******************************************************************************
* File Name: Col.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Col_H) /* Pins Col_H */
#define CY_PINS_Col_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Col_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Col_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Col_Read(void);
void    Col_Write(uint8 value);
uint8   Col_ReadDataReg(void);
#if defined(Col__PC) || (CY_PSOC4_4200L) 
    void    Col_SetDriveMode(uint8 mode);
#endif
void    Col_SetInterruptMode(uint16 position, uint16 mode);
uint8   Col_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Col_Sleep(void); 
void Col_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Col__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Col_DRIVE_MODE_BITS        (3)
    #define Col_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Col_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Col_SetDriveMode() function.
         *  @{
         */
        #define Col_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Col_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Col_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Col_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Col_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Col_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Col_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Col_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Col_MASK               Col__MASK
#define Col_SHIFT              Col__SHIFT
#define Col_WIDTH              4u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Col_SetInterruptMode() function.
     *  @{
     */
        #define Col_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Col_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Col_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Col_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Col__SIO)
    #define Col_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Col__PC) && (CY_PSOC4_4200L)
    #define Col_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Col_USBIO_DISABLE              ((uint32)(~Col_USBIO_ENABLE))
    #define Col_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Col_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Col_USBIO_ENTER_SLEEP          ((uint32)((1u << Col_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Col_USBIO_SUSPEND_DEL_SHIFT)))
    #define Col_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Col_USBIO_SUSPEND_SHIFT)))
    #define Col_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Col_USBIO_SUSPEND_DEL_SHIFT)))
    #define Col_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Col__PC)
    /* Port Configuration */
    #define Col_PC                 (* (reg32 *) Col__PC)
#endif
/* Pin State */
#define Col_PS                     (* (reg32 *) Col__PS)
/* Data Register */
#define Col_DR                     (* (reg32 *) Col__DR)
/* Input Buffer Disable Override */
#define Col_INP_DIS                (* (reg32 *) Col__PC2)

/* Interrupt configuration Registers */
#define Col_INTCFG                 (* (reg32 *) Col__INTCFG)
#define Col_INTSTAT                (* (reg32 *) Col__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Col_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Col__SIO)
    #define Col_SIO_REG            (* (reg32 *) Col__SIO)
#endif /* (Col__SIO_CFG) */

/* USBIO registers */
#if !defined(Col__PC) && (CY_PSOC4_4200L)
    #define Col_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Col_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Col_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Col_DRIVE_MODE_SHIFT       (0x00u)
#define Col_DRIVE_MODE_MASK        (0x07u << Col_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Col_H */


/* [] END OF FILE */
