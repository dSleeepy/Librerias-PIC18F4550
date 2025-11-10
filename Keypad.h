#ifndef KEYPAD_H
#define KEYPAD_H

#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 16000000

#define KEYPAD_PORT PORTB
#define KEYPAD_LAT  LATB
#define KEYPAD_TRIS TRISB

void Keypad_Init(void);
char Keypad_GetKey(void);

#endif
