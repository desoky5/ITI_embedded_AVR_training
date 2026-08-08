/*
 * TWI_prg.c
 *
 *  Created on: Aug 8, 2026
 *      Author: Omar Desoky
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TWI_int.h"
#include "TWI_prv.h"


void MTWI_vInit(void)
{
	//Disable Interrupt
	CLEAR_BIT(TWCR,0);
	//Prescaler value of 1
	CLEAR_BIT(TWSR,0);
	CLEAR_BIT(TWSR,1);

	TWBR = 32;
}

u8 MTWIT_u8SendStartCondition(void)
{
	TWCR = (1<<TWINT) |(1<<TWSTA) | (1<<TWEN);
	while(!(TWCR &(1<<TWINT)));

	return ((TWSR & 0xF8)) ;

}

u8 MTWIT_u8ReSendStartCondition(void)
{
	TWCR = (1<<TWINT) |(1<<TWSTA) | (1<<TWEN);
	while(!(TWCR &(1<<TWINT)));

	return ((TWSR & 0xF8)) ;

}

u8 MTWIT_u8SendEndCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	return ((TWSR & 0xF8)) ;
}

u8 MTWI_u8SendSLA_RW(u8 A_u8SLA,u8 A_u8RW)
{
	TWDR = (A_u8SLA<<1) | A_u8RW ;
	TWCR = (1<<TWINT) | (1<<TWEN);
	CLEAR_BIT(TWCR,TWSTA);
	while (!(TWCR & (1<<TWINT)));
	return ((TWSR & 0xF8)) ;
}

u8 MTWI_u8SendByte(u8 A_u8Byte)
{
	TWDR = A_u8Byte ;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	return ((TWSR & 0xF8)) ;


}


u8 MTWI_u8GetStatusCode(void)
{
	return ((TWSR & 0xF8)) ;
}



// The function can not have more than one returned value
u8 MTWI_u8RecieveByte(u8* PtrByte,u8 A_u8Ack_NAck)
{
	switch (A_u8Ack_NAck)
	{
	case TWI_ACK :
		TWCR = (1<<TWINT) | (1<<TWEN);
		SET_BIT(TWCR,TWEA);
		break;

	case TWI_NACK :
		TWCR = (1<<TWINT) | (1<<TWEN);
		CLEAR_BIT(TWCR,TWEA);
			break;
	}
	*PtrByte = TWDR ;
	return ((TWSR & 0xF8)) ;

}
