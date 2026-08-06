///*
// * USART.c
// *
// *  Created on: Aug 6, 2026
// *      Author: Omar Desoky
// */
//#define F_CPU 8000000UL
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include "../MCAL/GIE/GIE_int.h"
//#include "../MCAL/TIMR/TIMR_int.h"
//#include "../HAL/LCD/LCD_int.h"
//#include "../MCAL/WDT/WDT_int.h"
//#include "../MCAL/USART/USART_int.h"
//#include <util/delay.h>
//
//
//
//int main()
//{
//	MDIO_vInit();
//	MDIO_vSetPinDir(DIO_PORTD,DIO_PIN6,DIO_OUTPUT);
//	MDIO_vSetPinDir(DIO_PORTD,DIO_PIN7,DIO_OUTPUT);
//
//	MUSART_vInit();
//	u8 val ;
//	while (1)
//	{
//		val = MUSART_vRecieve();
//		if (val == '1')
//		{
//			MDIO_vSetPinVal(DIO_PORTD,DIO_PIN6,DIO_HIGH);
//			MDIO_vSetPinVal(DIO_PORTD,DIO_PIN7,DIO_LOW);
//		}
//		else if (val == '2')
//		{
//			MDIO_vSetPinVal(DIO_PORTD,DIO_PIN7,DIO_HIGH);
//			MDIO_vSetPinVal(DIO_PORTD,DIO_PIN6,DIO_LOW);
//		}
//
//
//	}
//	return 0 ;
//}



#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/USART/USART_int.h"

int main(void)
{
    u8 L_u8ReceivedChar = 0;

    /* 1. Set the entire LED port as Output */
    MDIO_vSetPortDir(DIO_PORTA, DIO_OUTPUT);

    /* Turn off all LEDs initially */
    MDIO_vSetPortVal(DIO_PORTA, DIO_LOW);

    /* 2. Initialize USART driver */
    MUSART_vInit();

    while (1)
    {
        /* 3. Wait to receive a character from PuTTY */
        L_u8ReceivedChar = MUSART_vRecieve();

        /* 4. Match the ASCII character ('1' to '8') to the corresponding LED pin */
        switch (L_u8ReceivedChar)
        {
            case '1':
                MDIO_vTogPinVal(DIO_PORTA, DIO_PIN0);
                MUSART_vTransmit('1'); // Echoes '1' back to PuTTY terminal
                break;

            case '2':
            	MDIO_vTogPinVal(DIO_PORTA, DIO_PIN1);
                MUSART_vTransmit('2');
                break;
            default:
                /* Ignore any other key press */
                break;
        }
    }

    return 0;
}
