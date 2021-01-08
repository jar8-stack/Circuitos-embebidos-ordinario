/*******************************************************************************
* File Name: Leds.h  
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

#if !defined(CY_PINS_Leds_H) /* Pins Leds_H */
#define CY_PINS_Leds_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Leds_aliases.h"


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
} Leds_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Leds_Read(void);
void    Leds_Write(uint8 value);
uint8   Leds_ReadDataReg(void);
#if defined(Leds__PC) || (CY_PSOC4_4200L) 
    void    Leds_SetDriveMode(uint8 mode);
#endif
void    Leds_SetInterruptMode(uint16 position, uint16 mode);
uint8   Leds_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Leds_Sleep(void); 
void Leds_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Leds__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Leds_DRIVE_MODE_BITS        (3)
    #define Leds_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Leds_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Leds_SetDriveMode() function.
         *  @{
         */
        #define Leds_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Leds_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Leds_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Leds_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Leds_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Leds_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Leds_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Leds_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Leds_MASK               Leds__MASK
#define Leds_SHIFT              Leds__SHIFT
#define Leds_WIDTH              3u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Leds_SetInterruptMode() function.
     *  @{
     */
        #define Leds_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Leds_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Leds_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Leds_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Leds__SIO)
    #define Leds_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Leds__PC) && (CY_PSOC4_4200L)
    #define Leds_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Leds_USBIO_DISABLE              ((uint32)(~Leds_USBIO_ENABLE))
    #define Leds_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Leds_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Leds_USBIO_ENTER_SLEEP          ((uint32)((1u << Leds_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Leds_USBIO_SUSPEND_DEL_SHIFT)))
    #define Leds_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Leds_USBIO_SUSPEND_SHIFT)))
    #define Leds_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Leds_USBIO_SUSPEND_DEL_SHIFT)))
    #define Leds_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Leds__PC)
    /* Port Configuration */
    #define Leds_PC                 (* (reg32 *) Leds__PC)
#endif
/* Pin State */
#define Leds_PS                     (* (reg32 *) Leds__PS)
/* Data Register */
#define Leds_DR                     (* (reg32 *) Leds__DR)
/* Input Buffer Disable Override */
#define Leds_INP_DIS                (* (reg32 *) Leds__PC2)

/* Interrupt configuration Registers */
#define Leds_INTCFG                 (* (reg32 *) Leds__INTCFG)
#define Leds_INTSTAT                (* (reg32 *) Leds__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Leds_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Leds__SIO)
    #define Leds_SIO_REG            (* (reg32 *) Leds__SIO)
#endif /* (Leds__SIO_CFG) */

/* USBIO registers */
#if !defined(Leds__PC) && (CY_PSOC4_4200L)
    #define Leds_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Leds_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Leds_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Leds_DRIVE_MODE_SHIFT       (0x00u)
#define Leds_DRIVE_MODE_MASK        (0x07u << Leds_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Leds_H */


/* [] END OF FILE */
