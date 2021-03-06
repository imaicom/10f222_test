#include <xc.h>         /* XC8 General Include File */
#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <pic.h>

#pragma config IOSCFS = 8MHZ    // Internal Oscillator Frequency Select bit (8 MHz)
#pragma config MCPU = OFF       // Master Clear Pull-up Enable bit (Pull-up disabled)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config CP = OFF         // Code protection bit (Code protection off)
#pragma config MCLRE = OFF      // GP3/MCLR Pin Function Select bit (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)

#define MHz 000000
#define _XTAL_FREQ 8MHz

static void Delay_ms(unsigned int DELAY_CNT) {
    for (unsigned int i = 0; i < DELAY_CNT; i++) {
        __delay_ms(1);
    }
}

void main(void) {
        
    int SELECT = 0;
    OPTION = 0b10000000; // PullUp GP0,GP1,GP3
    TRISGPIO = 0b1000; // input GP3 / output GP2,GP1,GP0

    
    while(1) {
        if(!GP3){ 
            while(!GP3) {
              Delay_ms(100);
              GP2=0; GP1=0; GP0=0;
            };
            SELECT++; if(SELECT>=3) SELECT=0;
        };
        
        GP2=0; GP1=1; GP0=0;
        Delay_ms(100 * SELECT);
        
        GP2=0; GP1=0; GP0=0;
        Delay_ms(100);
       
    };  //  while(1)
}
