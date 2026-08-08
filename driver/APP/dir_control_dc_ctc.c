/*
 * dir_control_dc_ctc.c
 *
 *  Created on: Aug 8, 2026
 *      Author: Omar Desoky
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/TIMR/TIMR_int.h"
#include"../MCAL/GIE/GIE_int.h"

#define Q1_PIN     DIO_PIN0
#define Q2_PIN     DIO_PIN1
#define Q3_PIN     DIO_PIN2
#define Q4_PIN     DIO_PIN3

#define MOTOR_PORT DIO_PORTA


void Motor_CW(void)
{
    MDIO_vSetPinVal(MOTOR_PORT, Q1_PIN, DIO_HIGH);
    MDIO_vSetPinVal(MOTOR_PORT, Q2_PIN, DIO_LOW);
    MDIO_vSetPinVal(MOTOR_PORT, Q3_PIN, DIO_LOW);
    MDIO_vSetPinVal(MOTOR_PORT, Q4_PIN, DIO_HIGH);
}


void Motor_CCW(void)
{
    MDIO_vSetPinVal(MOTOR_PORT, Q1_PIN, DIO_LOW);
    MDIO_vSetPinVal(MOTOR_PORT, Q2_PIN, DIO_HIGH);
    MDIO_vSetPinVal(MOTOR_PORT, Q3_PIN, DIO_HIGH);
    MDIO_vSetPinVal(MOTOR_PORT, Q4_PIN, DIO_LOW);
}


void Motor_Stop(void)
{
    MDIO_vSetPinVal(MOTOR_PORT, Q1_PIN, DIO_LOW);
    MDIO_vSetPinVal(MOTOR_PORT, Q2_PIN, DIO_LOW);
    MDIO_vSetPinVal(MOTOR_PORT, Q3_PIN, DIO_LOW);
    MDIO_vSetPinVal(MOTOR_PORT, Q4_PIN, DIO_LOW);
}


void Timer_Callback(void)
{
    static u8 state = 0;

    if(state == 0)
    {

        Motor_CCW();

        MTIMERS_vSetInterval_CTC(Timer_Callback, 12000);

        state = 1;
    }

    else if(state == 1)
    {
        Motor_Stop();

        MTIMERS_vSetInterval_CTC(Timer_Callback, 20000);

        state = 2;
    }

    else if(state == 2)
    {
        Motor_CW();

        MTIMERS_vSetInterval_CTC(Timer_Callback, 20000);

        state = 0;
    }
}


int main(void)
{
    // Initialize DIO
    MDIO_vInit();

    // Motor pins
    MDIO_vSetPinDir(MOTOR_PORT, Q1_PIN, DIO_OUTPUT);
    MDIO_vSetPinDir(MOTOR_PORT, Q2_PIN, DIO_OUTPUT);
    MDIO_vSetPinDir(MOTOR_PORT, Q3_PIN, DIO_OUTPUT);
    MDIO_vSetPinDir(MOTOR_PORT, Q4_PIN, DIO_OUTPUT);

    MTIMERS_vInit();

    MTIMERS_vSetCompareMatch(TIM_0, 249);


    MTIMERS_vSetInterval_CTC(Timer_Callback, 20000);


    MTIMERS_vStartTimer(TIM_0);

    MGIE_vEnableGlobalInterrupt();

    Motor_CW();

    while(1)
    {
        // Timer interrupt handles the sequence
    }

    return 0;
}

