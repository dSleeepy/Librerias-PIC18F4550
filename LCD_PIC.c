#include "LCD_PIC.h"
#include "delay16mhz.h"
#define _XTAL_FREQ 16000000

static void Lcd_Port(char data){
    D4 = (data >> 0) & 0x01;
    D5 = (data >> 1) & 0x01;
    D6 = (data >> 2) & 0x01;
    D7 = (data >> 3) & 0x01;
}
static void Lcd_Cmd(unsigned char cmd){
    RS = 0;
    Lcd_Port(cmd >> 4);
    EN = 1;
    __delay_us(40);
    EN = 0;
    Lcd_Port(cmd & 0x0F);
    EN = 1;
    __delay_us(40);
    EN = 0;
}
void Lcd_Init(void){
    RS_DIR = 0;
    EN_DIR = 0;
    D4_DIR = 0;
    D5_DIR = 0;
    D6_DIR = 0;
    D7_DIR = 0;
    __delay_ms(20);
    Lcd_Cmd(0x33);
    Lcd_Cmd(0x32);
    Lcd_Cmd(0x28);
    Lcd_Cmd(0x0C);
    Lcd_Cmd(0x06);
    Lcd_Clear();
}
void Lcd_Clear(void){
    Lcd_Cmd(0x01);
    __delay_ms(2);
}
void Lcd_Set_Cursor(unsigned char fila, unsigned char col){
    unsigned char temp;
    switch(fila)
    {
        case 1: temp = 0x80 + (col - 1); break;
        case 2: temp = 0xC0 + (col - 1); break;
        case 3: temp = 0x94 + (col - 1); break;
        case 4: temp = 0xD4 + (col - 1); break;
        default: temp = 0x80; break;
    }
    Lcd_Cmd(temp);
}
void Lcd_Write_Char(char data){
    RS = 1;
    Lcd_Port(data >> 4);
    EN = 1;
    __delay_us(40);
    EN = 0;
    Lcd_Port(data & 0x0F);
    EN = 1;
    __delay_us(40);
    EN = 0;
}
void Lcd_Write_String(const char *dato){
    while(*dato)
    {
        Lcd_Write_Char(*dato++);
    }
}
