#define F_CPU 8000000UL
#include<avr/io.h>

int main(void)
{
 DDRB =0b11100000;
 PORTB=0b11100000;

    while (1) {
        // main loop
    }

    return 0;
}