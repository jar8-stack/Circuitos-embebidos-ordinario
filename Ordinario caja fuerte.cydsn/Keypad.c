#include "stdbool.h"
#include "project.h"
#include "Keypad.h"
#include <stdio.h>
#include "Lib_led.h"
#include <string.h>

static bool validkey= false;

uint8 value= 0x00;

char show[250];

int key;
char contrasena[4];
char inputPassword[4];


const char *keyast = "*";
const char *key4 = "4";
const char *key7 = "7";
const char *key1 = "1";


void CheckPassword(char input[4]){
    strcat(contrasena, "1");
    strcat(contrasena, "4");
    strcat(contrasena, "7");
    strcat(contrasena, "*");
    
    if(contrasena==input){
        PrenderVerde();
        CyDelay(5000);
    }
    
}

void Keypad_stop(void){  
    
}


void Keypad_start(void){
    UART_Start();
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
                    key='*';
                    strcat(inputPassword,keyast);                    
                    CyDelay(500);
                    break;
                case 0x0d:
                    key=7;
                    strcat(inputPassword,key7);
                    CyDelay(500);
                    break;
                case 0x0b: 
                    key=4;
                    strcat(inputPassword,key4);
                    CyDelay(500);
                    break; 
                case 0x07:
                    key=1;
                    strcat(inputPassword,key1);
                    CyDelay(500);
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
                    key=0;
                    CyDelay(500);
                    break;
                    
                case 0x0d:
                    key=8;
                    CyDelay(500);
                    break; 
                
                case 0x0b:
                    key=5;
                    CyDelay(500);
                    break;
                
                case 0x07:
                    key=2;
                    CyDelay(500);
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
                    key='D';
                    CyDelay(500);
                    break;
                    
                case 0x0d:
                    key='C';
                    CyDelay(500);
                    break;
                
                case 0x0b:
                    key='B';
                    CyDelay(500);
                    break;
                
                case 0x07:
                    key='A';
                    CheckPassword(inputPassword);
                    CyDelay(500);                
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
                    key='#';
                    CyDelay(500);
                    break;
                case 0x0d:
                    key=9;
                    CyDelay(500);
                    break;
                
                case 0x0b:
                    key=6;
                    CyDelay(500);
                    break;
                case 0x07:
                    key=3;
                    CyDelay(500);
                    break;
                default:
                    break;
            }
        }
        Col_Write(0x00);
        
    }
}