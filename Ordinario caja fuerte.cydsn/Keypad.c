#include "stdbool.h"
#include "project.h"
#include "Keypad.h"
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
                    break;
                case 0x0d:
                    key=4;                    
                    break;
                case 0x0b: 
                    key=7;                   
                    break; 
                case 0x07:
                    key='*'; 
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
                    key=2;
                    break;
                    
                case 0x0d:
                    key=5;
                    break; 
                
                case 0x0b:
                    key=8;
                    break;
                
                case 0x07:
                    key=0;
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
                    key=3;
                    break;
                    
                case 0x0d:
                    key=6;
                    break;
                
                case 0x0b:
                    key=9;
                    break;
                
                case 0x07:
                    key='#';
                    break;
                
                
                default:
                    break;
                    
            }
        }
        
        Col_Write(0x07);
        value= Filas_Read();
        if(value !=0x0F){
            switch(value){
                case 0x0e:
                    key='A';
                    break;
                case 0x0d:
                    key='B';
                    break;
                
                case 0x0b:
                    key='C';
                    break;
                case 0x07:
                    key='D';
                    break;
                default:
                    break;
            }
        }
        Col_Write(0x00);
        
    }
}