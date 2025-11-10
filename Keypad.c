#include "KEYPAD.h"

const unsigned char filas[4]={0x0E, 0x0D, 0x0B, 0x07};
const unsigned char keypad[4][4]={
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
void Keypad_Init(void){
    KEYPAD_TRIS=0xF0;
    KEYPAD_LAT=0x0F;
}
char Keypad_GetKey(void){
    for (uint8_t f = 0; f < 4; f++){
        KEYPAD_LAT = filas[f];
        __delay_ms(2);
        uint8_t columnas = (KEYPAD_PORT >> 4) & 0x0F;
        if (columnas != 0x0F){
            for (uint8_t c = 0; c < 4; c++){
                if ((columnas & (1 << c)) == 0){
                    while (((KEYPAD_PORT >> 4) & 0x0F) != 0x0F);
                    return keypad[f][c];
                }
            }
        }
    }
    return 0;
}
