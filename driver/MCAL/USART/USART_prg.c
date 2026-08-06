/*
 * USART_prg.c
 *
 *  Created on: Aug 6, 2026
 *      Author: Omar Desoky
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "USART_int.h"
#include "USART_prv.h"

void MUSART_vInit(void)
{

//enable UCSRD  -- asynchronus mode - no parity - 1 stop bit - 8 bit data - No polarity
	 UCSRB = 0b00011000;
	UCSRC = 0b10000110;

 UBRRL = 51 ;
 UBRRH = 0 ;
}
void MUSART_vTransmit(u8 A_u8Byte)
{
	u8 val ;
	GET_BIT(UCSRA,5,val);
    while (!val);
    UDR = A_u8Byte ;
}


u8 MUSART_vRecieve(void)
{
	u8 val;
	do
	{
		GET_BIT(UCSRA, 7, val);
	} while (!val);

	return UDR;
}

