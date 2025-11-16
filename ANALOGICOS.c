#include "ANALOGICOS.h"
#include <stdint.h>
#include <xc.h>
#include "delay16mhz.h"
#define _XTAL_FREQ 16000000

void ADC_Init(void){
    ADCON1bits.VCFG0=0;  //0=Usa voltaje negativo del micro ; 1=Usa voltaje negativo diferente
    ADCON1bits.VCFG1=0;  //0=Usa voltaje positivo del micro ; 1=Usa voltaje positivo diferente
    ADCON2bits.ADFM=1;
    ADCON2bits.ACQT=0b101;
    ADCON2bits.ADCS=0b110;
    ADCON0bits.ADON=1;
}
uint16_t CANAL(uint8_t canal){
    ADCON0bits.CHS=canal;
    __delay_ms(50);
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)((ADRESH<<8)|ADRESL);
}
