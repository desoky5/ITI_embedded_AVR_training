///*
// * main.c
// *
// *  Created on: Jul 29, 2026
// *      Author: Omar Desoky
// */
//#define F_CPU 8000000UL
//
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/TIMR/TIMR_int.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include "../MCAL/GIE/GIE_int.h"
//#include "../MCAL/ADC/ADC_int.h"
//
//
//void toggbuzzer(void)
//{
//	MDIO_vTogPinVal(DIO_PORTB,DIO_PIN1);
//}
//int main()
//{
//	u16 ADC ,OCR;
//	MDIO_vInit();
//	MADC_vInit();
//	MTIMERS_vInit();
//	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
//	MGIE_vEnableGlobalInterrupt();
//	MTIMERS_vSetCompareMatch(TIM_0,100);
//	MTIMERS_vSetInterval_CTC(toggbuzzer,1);
//	MTIMERS_vStartTimer(TIM_0);
//	while(1)
//	{
//		ADC = MADC_vReadAnalog(CHANNEL_0);
//		OCR = 20 + ((ADC*230)/10);
//		MTIMERS_vSetCompareMatch(TIM_0,OCR);
//	}
//	return 0 ;
//}
