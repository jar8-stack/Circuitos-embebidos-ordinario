/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/* [] END OF FILE */

# ifndef _Lib_led_H_
#define _Lib_led_H_

#include <cytypes.h>    
# define LedVerde 0x01
# define LedAmarillo 0x02
# define LedRojo 0x04
    
extern void PrenderVerde(void);    
extern void ApagarVerde(void);    

extern void PrenderAmarillo(void);    
extern void ApagarAmarillo(void);    

extern void PrenderRojo(void);    
extern void ApagarRojo(void);    

    
# endif