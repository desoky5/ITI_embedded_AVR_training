/*
 * TIM0_prv.h
 *
 *  Created on: Aug 3, 2026
 *      Author: Omar Desoky
 */

#ifndef MCAL_TIMR_TIMR_PRV_H_
#define MCAL_TIMR_TIMR_PRV_H_

// REGISTERS ADDRESSES OF TIM0
#define TCCR0 *((volatile u8*)(0X53)) // TIMER/COUNTER CONTROL REGISTER FOR TIMER0
#define TCNT0 *((volatile u8*)(0X52))
#define OCR0 *((volatile u8*)(0x5C)) // OUTPUT COMPARE REGISTER FOR TIMER0
#define TIMSK *((volatile u8*)(0X59))
#define TIFR *((volatile u8*)(0X58)) // TIMER INTERRUPT FLAG REGISTER FOR TIMER0

// TCCR0 BITS MACROS

#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7

// TCNT0 BITS MACROS

// OCR0 BITS MACROS

// MODES
#define NORMAL_OVERFLOW      0
#define CTC                  1
#define PWM_PHASE_CORRECT    2
#define FAST_PWM             3

//PRESCALER

#define NO_CLK               0x00
#define CLK_NO_PRESCALLING   0x01
#define CLK_8                0x02
#define CLK_64               0x03
#define CLK_256              0x04
#define CLK_1024             0x05


#define EXTERNAL_TO_FALLING  0X06
#define EXTERNAL_TO_RISING   0X07


//ENABLE TIMER
#define ENABLE                    1
#define DISABLE                   0



























#endif /* MCAL_TIMR_TIMR_PRV_H_ */
