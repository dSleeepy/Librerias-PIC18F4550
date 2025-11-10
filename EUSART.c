#include "EUSART.h"
#include "delay16mhz.h"
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 16000000
void EUSART_Init(uint16_t baudios){
    unsigned int n=0;
    TRISCbits.TRISC6=0;
    TRISCbits.TRISC7=1;
    TXSTA=0b00100100;
    RCSTA=0b10010000;
    BAUDCON=0b00001000;
    n=(((_XTAL_FREQ/baudios)/16)-1);
    SPBRG=n;
    SPBRGH =(n>>8);
}
void EUSART_Tx(char data){
     while(TXSTAbits.TRMT==0);
    TXREG=data;
    
}
char EUSART_Rx(void){
    if(RCSTAbits.OERR){
        RCSTAbits.CREN=0;
        RCSTAbits.CREN=1;
    }
    return RCREG;
}
void EUSART_Cadenas(const char *cadena){
    while(*cadena){
        EUSART_Tx(*cadena);
        cadena++;
    }
}
void EUSART_LeerCadenas(char *buffer, uint8_t len){
    uint8_t i;
    for(i = 0; i < len; i++){
        while(PIR1bits.RCIF == 0);
        buffer[i] = EUSART_Rx();
        if(buffer[i] == '\n') break;
    }
    buffer[i] = '\0';
}
