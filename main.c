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
        
    OPTION = 0b11000000;
    TRISGPIO = 0b1000; // input GP3 / output GP2,GP1,GP0   
    GP2=1; GP1=1; GP0=1;

    while(1) {
        
        GP2=0; GP1=1; GP0=1;
        Delay_ms(500);
        GP2=1; GP1=0; GP0=1;
        Delay_ms(500);
        GP2=1; GP1=1; GP0=0;
        Delay_ms(500);
        
    };  //  while(1)
}
