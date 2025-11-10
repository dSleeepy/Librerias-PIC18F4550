#ifndef EUSART_H
#define	EUSART_H

#include <stdint.h>
void EUSART_Init(uint16_t baudios);
void EUSART_Tx(char data);
char EUSART_Rx(void);
void EUSART_Cadenas(const char *cadena);
void EUSART_Cadenas(const char *cadena);
void EUSART_LeerCadenas(char *buffer, uint8_t len);

#endif	/* EUSART_H */
