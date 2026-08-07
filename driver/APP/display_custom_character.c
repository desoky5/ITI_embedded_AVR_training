///*
// * display_custom_character.c
// *
// *  Created on: Aug 6, 2026
// *      Author: Omar Desoky
// */
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include "../HAL/LCD/LCD_int.h"
//
//u8 UpperO[] = {
//  0x1F,
//  0x11,
//  0x11,
//  0x11,
//  0x11,
//  0x11,
//  0x11,
//  0x1F
//};
//
//u8 LowerO[] = {
//  0x00,
//  0x00,
//  0x0E,
//  0x0A,
//  0x0A,
//  0x0E,
//  0x00,
//  0x00
//};
//
//int main()
//{
//
//    HLCD_vInit();
//    HLCD_vClearScreen();
//
//    // Load both custom characters into CGRAM
//    HLCD_vWriteCGRAM(0, UpperO);
//    HLCD_vWriteCGRAM(1, LowerO);
//    // Display them on the screen
//    HLCD_vDisplayCGRAM(0, 0, 0);
//    HLCD_vDisplayCGRAM(1, 0, 1);
//	while(1)
//	{
//
//	}
//	return 0 ;
//}
