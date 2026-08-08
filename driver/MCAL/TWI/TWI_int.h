/*
 * TWI_int.h
 *
 *  Created on: Aug 8, 2026
 *      Author: Omar Desoky
 */

#ifndef MCAL_TWI_TWI_INT_H_
#define MCAL_TWI_TWI_INT_H_

#define TWI_ACK 1
#define TWI_NACK 0
#define TWI_WRITE 0
#define TWI_READ 1


void MTWI_vInit(void);

u8 MTWIT_u8SendStartCondition(void);

u8 MTWIT_u8ReSendStartCondition(void);

u8 MTWIT_u8SendEndCondition(void);

u8 MTWI_u8SendSLA_RW(u8 A_u8SLA,u8 A_u8RW);

u8 MTWI_u8SendByte(u8 A_u8Byte);

u8 MTWI_u8RecieveByte(u8* PtrByte,u8 A_u8Ack_NAck); // The function can not have more than one returned value

u8 MTWI_u8GetStatusCode(void);

#define ACK 1
#define NACK 0
#endif /* MCAL_TWI_TWI_INT_H_ */
