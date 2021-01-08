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
#include "project.h"
#include "Lib_led.h"
#include "Lib_led.h"

int t=500; 

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        PrenderVerde();
        CyDelay(t);
        ApagarVerde();
        CyDelay(t);
        /* Camarada que diantre*/
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
