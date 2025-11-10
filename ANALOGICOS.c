#include "ANALOGICOS.h"
#include <stdint.h>
#include <xc.h>

void leer_adc(void){
    ADCON1bits.VCFG01=0;
    ADCON2bits.ACQT=0b010;
    ADCON2bits.ADCS=0b101;
    ADCON0bits.ADON=1;
}
uint16_t CANAL0(void){
    ADCON0bits.CHS=0x00;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL1(void){
    ADCON0bits.CHS=0x01;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL2(void){
    ADCON0bits.CHS=0x02;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL3(void){
    ADCON0bits.CHS=0x03;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL4(void){
    ADCON0bits.CHS=0x04;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL5(void){
    ADCON0bits.CHS=0x05;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL6(void){
    ADCON0bits.CHS=0x06;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL7(void){
    ADCON0bits.CHS=0x07;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL8(void){
    ADCON0bits.CHS=0x08;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL9(void){
    ADCON0bits.CHS=0x09;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL10(void){
    ADCON0bits.CHS=0x0A;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL11(void){
    ADCON0bits.CHS=0x0B;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
uint16_t CANAL12(void){
    ADCON0bits.CHS=0x0C;
    ADCON0bits.GO_DONE=1;
    while(ADCON0bits.GO_DONE==1);
    return (uint16_t)(ADRESL|(ADRESH<<8));
}
