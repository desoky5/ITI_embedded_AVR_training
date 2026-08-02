/*
 * main.c
 *
 *  Created on: Jul 30, 2026
 *      Author: Omar Desoky
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include<util/delay.h>


void motor_control(void)
{

	MDIO_vSetPinVal(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	_delay_ms(2000);
	MDIO_vSetPinVal(DIO_PORTA, DIO_PIN0, DIO_LOW);
	_delay_ms(1000);
}


int main()
{

	MDIO_vSetPinDir(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	MDIO_vSetPinVal(DIO_PORTD,DIO_PIN2,DIO_HIGH);

	MDIO_vSetPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);


	MEXTI_vInit();

	MGIE_vEnableGlobalInterrupt();

	MEXTI_vCallBackFunction(motor_control, 0);

	while(1)
	{

	}
return 0;
}
