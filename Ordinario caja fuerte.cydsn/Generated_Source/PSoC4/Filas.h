/*******************************************************************************
* File Name: Filas.h  
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

#if !defined(CY_PINS_Filas_H) /* Pins Filas_H */
#define CY_PINS_Filas_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Filas_aliases.h"


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
} Filas_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Filas_Read(void);
void    Filas_Write(uint8 value);
uint8   Filas_ReadDataReg(void);
#if defined(Filas__PC) || (CY_PSOC4_4200L) 
    void    Filas_SetDriveMode(uint8 mode);
#endif
void    Filas_SetInterruptMode(uint16 position, uint16 mode);
uint8   Filas_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Filas_Sleep(void); 
void Filas_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Filas__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Filas_DRIVE_MODE_BITS        (3)
    #define Filas_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Filas_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Filas_SetDriveMode() function.
         *  @{
         */
        #define Filas_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Filas_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Filas_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Filas_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Filas_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Filas_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Filas_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Filas_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Filas_MASK               Filas__MASK
#define Filas_SHIFT              Filas__SHIFT
#define Filas_WIDTH              4u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Filas_SetInterruptMode() function.
     *  @{
     */
        #define Filas_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Filas_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Filas_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Filas_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Filas__SIO)
    #define Filas_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Filas__PC) && (CY_PSOC4_4200L)
    #define Filas_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Filas_USBIO_DISABLE              ((uint32)(~Filas_USBIO_ENABLE))
    #define Filas_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Filas_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Filas_USBIO_ENTER_SLEEP          ((uint32)((1u << Filas_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Filas_USBIO_SUSPEND_DEL_SHIFT)))
    #define Filas_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Filas_USBIO_SUSPEND_SHIFT)))
    #define Filas_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Filas_USBIO_SUSPEND_DEL_SHIFT)))
    #define Filas_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Filas__PC)
    /* Port Configuration */
    #define Filas_PC                 (* (reg32 *) Filas__PC)
#endif
/* Pin State */
#define Filas_PS                     (* (reg32 *) Filas__PS)
/* Data Register */
#define Filas_DR                     (* (reg32 *) Filas__DR)
/* Input Buffer Disable Override */
#define Filas_INP_DIS                (* (reg32 *) Filas__PC2)

/* Interrupt configuration Registers */
#define Filas_INTCFG                 (* (reg32 *) Filas__INTCFG)
#define Filas_INTSTAT                (* (reg32 *) Filas__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Filas_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Filas__SIO)
    #define Filas_SIO_REG            (* (reg32 *) Filas__SIO)
#endif /* (Filas__SIO_CFG) */

/* USBIO registers */
#if !defined(Filas__PC) && (CY_PSOC4_4200L)
    #define Filas_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Filas_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Filas_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Filas_DRIVE_MODE_SHIFT       (0x00u)
#define Filas_DRIVE_MODE_MASK        (0x07u << Filas_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Filas_H */


/* [] END OF FILE */
