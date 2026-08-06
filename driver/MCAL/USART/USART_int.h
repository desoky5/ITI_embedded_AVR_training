/*
 * USART_int.h
 *
 *  Created on: Aug 6, 2026
 *      Author: Omar Desoky
 */

#ifndef MCAL_USART_USART_INT_H_
#define MCAL_USART_USART_INT_H_

void MUSART_vInit(void);
void MUSART_vTransmit(u8 A_u8Byte);
u8 MUSART_vRecieve(void);

#endif /* MCAL_USART_USART_INT_H_ */
