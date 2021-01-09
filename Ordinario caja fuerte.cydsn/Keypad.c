#include "stdbool.h"
#include "project.h"
#include "Keypad.h"
#include "Lib_seg.h"

static bool validkey= false;

uint8 value= 0x00;

int key;

void Keypad_stop(void){
    
    
}


void Keypad_start(void){
    IsrRowPins_StartEx(InterrupRowButtons);    
    Col_Write(0x00);
    IsrRowPins_Enable();
    
}

CY_ISR(InterrupRowButtons){
    Filas_ClearInterrupt();
    
    uint8 i, j;
    
    for(i=0, j=0;i<255; ++i){
        if(Filas_Read()==0x07 || Filas_Read()==0x0B || Filas_Read()==0x0D || Filas_Read()==0x0E){
            j++;
            if(j==100){
                validkey=true;
                break;
            }
        }else{
            j=0; 
        }
    }
    
    if(validkey==true){
        Col_Write(0x0e);
        value= Filas_Read();
        
        if(value !=0x0F){
            switch(Filas_Read()){
                case 0x0e:
                    key=1; 
                    Prender1();
                    break;
                case 0x0d:
                    key=4;
                    Prender4();
                    break;
                case 0x0b: 
                    key=7;
                    Prender7();
                    break; 
                case 0x07:
                    key=0;
                    Prender4();
                    break;
                default:
                    return;
                
            }
        }
        
        Col_Write(0x0d);
        value=Filas_Read();
        
        if(value != 0x0F){
            switch(value){
                case 0x0e:
                    Prender2();
                    break;
                    
                case 0x0d:
                    Prender5();
                    break; 
                
                case 0x0b:
                    Prender8();
                    break;
                
                case 0x07:
                    Prender4();
                    break;

                default: 
                    return;
            }
        }
        
        Col_Write(0x0b);
        
        value= Filas_Read();
        
        if(value !=0x0F){
            switch(value){
                case 0x0e:
                    Prender3();
                    break;
                    
                case 0x0d:
                    Prender6();
                    break;
                
                default:
                    break;
                    
            }
        }
    }
}