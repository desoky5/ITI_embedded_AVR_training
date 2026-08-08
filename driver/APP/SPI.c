///*
// * SPI.c
// *
// *  Created on: Aug 8, 2026
// *      Author: Omar Desoky
// */
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MATH.h"
//
//#include"../MCAL/SPI/SPI_int.h"
//#include"../MCAL/DIO/DIO_int.h"
//#include<util/delay.h>
//
//int main()
//{
//	MSPI_vInit();
//	u8 valsent = 10  ;
//	u8 valrecieved ;
//	MDIO_vSetPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
//	MDIO_vSetPinDir(DIO_PORTA,DIO_PIN0,DIO_HIGH);
//	valrecieved=MSPI_u8Transieve(valsent);
//	if (valrecieved == valsent) MDIO_vTogPinVal(DIO_PORTA,DIO_PIN0);
//	MDIO_vSetPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
//	MDIO_vSetPinDir(DIO_PORTA,DIO_PIN0,DIO_HIGH);
//	_delay_ms(1000);
//	while(1)
//	{
//		u8 valsent = 10  ;
//		u8 valrecieved ;
//		valrecieved=MSPI_u8Transieve(valsent);
//		if (valrecieved == valsent) MDIO_vTogPinVal(DIO_PORTA,DIO_PIN0);
//		_delay_ms(1000);
//
//	}
//
//
//
//}
