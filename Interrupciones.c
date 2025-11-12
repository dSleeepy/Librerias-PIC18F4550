#include "Interrupciones.h"

void Int_Init(unsigned char n){
    // --- Configura los pines como entradas ---
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 1;

    // --- Limpia banderas ---
    INTCONbits.INT0IF = 0;
    INTCON3bits.INT1IF = 0;
    INTCON3bits.INT2IF = 0;

    // --- Flanco ascendente ---
    INTCON2bits.INTEDG0 = 1;
    INTCON2bits.INTEDG1 = 1;
    INTCON2bits.INTEDG2 = 1;

    // --- Activa modo de prioridad ---
    RCONbits.IPEN = 1;          // <--- ¡Esto es esencial!

    // --- Prioridades ---
    INTCON3bits.INT1IP = 0;     // INT1 -> baja prioridad
    INTCON3bits.INT2IP = 0;     // INT2 -> baja prioridad

    // --- Activa interrupciones globales ---
    INTCONbits.GIEH = 1;        // Global High priority enable
    INTCONbits.GIEL = 1;        // Global Low priority enable

    // --- Desactiva pull-ups de PORTB ---
    INTCON2bits.RBPU = 1;

    // --- Activa según número de interrupciones ---
    switch(n){
        case 1: // Solo RB0 (alta)
            INTCONbits.INT0IE = 1;
            break;
        case 2: // RB0 (alta) y RB1 (baja)
            INTCONbits.INT0IE = 1;
            INTCON3bits.INT1IE = 1;
            break;
        case 3: // RB0 (alta), RB1 y RB2 (baja)
            INTCONbits.INT0IE = 1;
            INTCON3bits.INT1IE = 1;
            INTCON3bits.INT2IE = 1;
            break;
    }
}
