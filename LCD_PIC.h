#ifndef LCD_PIC_H
#define LCD_PIC_H

#include <xc.h>
#include <stdint.h>

#define RS LATDbits.LD2
#define EN LATDbits.LD3
#define D4 LATDbits.LD4
#define D5 LATDbits.LD5
#define D6 LATDbits.LD6
#define D7 LATDbits.LD7

#define RS_DIR TRISDbits.TRISD2
#define EN_DIR TRISDbits.TRISD3
#define D4_DIR TRISDbits.TRISD4
#define D5_DIR TRISDbits.TRISD5
#define D6_DIR TRISDbits.TRISD6
#define D7_DIR TRISDbits.TRISD7
void Lcd_Init(void);
void Lcd_Clear(void);
void Lcd_Set_Cursor(unsigned char fila, unsigned char col);
void Lcd_Write_Char(char data);
void Lcd_Write_String(const char *dato);

#endif
