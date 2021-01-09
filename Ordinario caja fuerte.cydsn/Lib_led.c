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

#include "project.h"
#include "Lib_led.h"



static uint8 EstadoLeds=0x00;

void PrenderVerde(void){
    EstadoLeds |=LedVerde; 
    Led_pins_Write(EstadoLeds); 
}
void ApagarVerde(void){
    EstadoLeds &=~(LedVerde); 
    Led_pins_Write(EstadoLeds);
}
void PrenderAmarillo(void){
    EstadoLeds |=LedAmarillo; 
    Led_pins_Write(EstadoLeds); 
} 
void ApagarAmarillo(void){
    EstadoLeds &=~(LedAmarillo); 
    Led_pins_Write(EstadoLeds);
}
void PrenderRojo(void){
    EstadoLeds |=LedRojo; 
    Led_pins_Write(EstadoLeds); 
}
void ApagarRojo(void){
    EstadoLeds &=~(LedRojo); 
    Led_pins_Write(EstadoLeds);
}