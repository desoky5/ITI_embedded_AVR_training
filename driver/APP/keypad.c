/*
 * keypad.c
 *
 *  Created on: Aug 7, 2026
 *      Author: Omar Desoky
 */
#define F_CPU 8000000UL
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/keypad/keypad_int.h"
#include <util/delay.h>

#define LED_COUNT_MAX   8U

const u8 KeyMap[KPD_ROWS][KPD_COLS] =
{
    {'1', '2', '3', '4'},
    {'5', '6', '7', '8'},
    {'8', '*', '#', '%'},
    {'&', '@', '+', '~'}
};

int main(void)
{
    u8 key;
    u8 numLeds;
    u8 i;

    MDIO_vInit();
    HKPD_vInit();
    MDIO_vSetPortDir(DIO_PORTB, DIO_OUTPUT);

    while(1)
    {
        key = HKPD_u8GetPressedKey(KeyMap);

        if (key >= '1' && key <= '8')
        {
            numLeds = key - '0';

            /* Clear all LEDs first so each keypress shows a clean count */
            for (i = 0; i < LED_COUNT_MAX; i++)
            {
                MDIO_vSetPinVal(DIO_PORTB, i, DIO_LOW);
            }

            /* Light up 'numLeds' LEDs starting from PIN0 */
            for (i = 0; i < numLeds; i++)
            {
                MDIO_vSetPinVal(DIO_PORTB, i, DIO_HIGH);
            }

            _delay_ms(1000);
        }
    }

    return 0;
}
