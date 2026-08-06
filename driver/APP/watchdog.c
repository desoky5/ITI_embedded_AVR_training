///*
// * watchdog.c
// *
// *  Created on: Aug 6, 2026
// *      Author: Omar Desoky
// */
//
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/TIMR/TIMR_int.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include "../MCAL/WDT/WDT_int.h"
//#include <util/delay.h>
//
//int main()
//{
//
//	MDIO_vInit();
//	MDIO_vSetPinDir(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);
//	MDIO_vSetPinVal(DIO_PORTA,DIO_PIN7,DIO_HIGH);
//
//	_delay_ms(500);
//
//	MDIO_vSetPinVal(DIO_PORTA,DIO_PIN7,DIO_LOW);
//	MWDT_vSleep();
//	MWDT_vEnable();
//	//STUCK
//	while(1)
//	{
//
//	}
//	return 0 ;
//}
