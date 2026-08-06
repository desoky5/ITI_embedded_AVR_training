///*
// * name_sinsuidal_diaplay.c
// *
// *  Created on: Aug 6, 2026
// *      Author: Omar Desoky
// */
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MATH.h"
//
//#include "../MCAL/DIO/DIO_int.h"
//#include "../HAL/LCD/LCD_int.h"
//
//#include <avr/delay.h>
//
//int main()
//{
//	HLCD_vInit();
//	HLCD_vClearScreen();
//	HLCD_vSetCursorPosition(0,0);
//
//	while(1)
//	{
//		u8 i = 0 ;
//		for (int j = 0 ; j<16;j++)
//		{
//			HLCD_vClearScreen();
//			HLCD_vSetCursorPosition(i,j);
//			HLCD_vDisplayString("OMAR");
//			i = !i ;
//			_delay_ms(2000);
//		}
//		}
//	return 0 ;
//}
