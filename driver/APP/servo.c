///*
// * servo.c
// *
// *  Created on: Aug 5, 2026
// *      Author: Omar Desoky
// */
//
//#define F_CPU 8000000UL
//
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/TIMR/TIMR_int.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include "../MCAL/GIE/GIE_int.h"
//#include "../MCAL/ADC/ADC_int.h"
//
//#include <avr/delay.h>
//
//
//int main()
//{
//	u16 ADC ,OCR;
//	MDIO_vInit();
//
//	MDIO_vSetPinDir(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
//	MADC_vInit();
//	MTIMERS_vInit();
//	MTIMERS_vStartTimer(TIM_1);
//	while(1)
//	{
//		ADC = MADC_vReadAnalog(CHANNEL_0);
//		OCR = 1000+(((u32)ADC*1000)/1023);
//		MTIMERS_vSetCompareMatch(TIM_1_A,OCR);
//		_delay_ms(3000);
//	}
//	return 0 ;
//}
//
