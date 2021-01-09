#ifndef _Keypad_H_
#define _Keypad_H_

#include <cytypes.h>    
    
CY_ISR_PROTO(InterrupRowButtons);    

extern void Keypad_start(void);
extern void Keypad_stop(void);

extern uint8 ReadKey(void);
    
#endif