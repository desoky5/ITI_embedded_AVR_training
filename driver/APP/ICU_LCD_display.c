/*
 * ICU.c
 *
 *  Created on: Aug 5, 2026
 *      Author: Omar Desoky
 */
//#define F_CPU 8000000UL
//
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/TIMR/TIMR_int.h"
//#include "../MCAL/TIMR/TIMR_cfg.h"
//#include "../MCAL/DIO/DIO_int.h"
//#include "../MCAL/GIE/GIE_int.h"
//#include "../HAL/LCD/LCD_int.h"
//
//#include <avr/delay.h>
//
//
//volatile u16 G_T1 =0;
//volatile u16 G_T2 =0;
//volatile u16 G_T3 =0;
//
//volatile u8 G_state=0;
//
//void ICU_CALLBACK()
//{
//	if(G_state == 0)
//	{
//		// CAPTURED AT RISING
//		G_T1 = MTIMERS_u16GetCapturedValue();
//		MTIMERS_vSetTrigger(TRIG_TYPE_FALLING);
//		G_state = 1;
//	}
//	else if(G_state == 1)
//	{
//		// CAPTURED AT FALLING
//		G_T2 = MTIMERS_u16GetCapturedValue();
//		MTIMERS_vSetTrigger(TRIG_TYPE_RISING);
//		G_state = 2;
//	}
//	else if(G_state == 2)
//	{
//		// CAPTURED AT RISING
//		G_T3 = MTIMERS_u16GetCapturedValue();
//
//		//MTIMERS_vDisableInterrupt(TIM_1, ICU);
//
//		G_state = 3;
//	}
//}
//
//int main()
//{
//	MDIO_vInit();
//
//	//PWM
//	MDIO_vSetPinDir(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
//
//	// ICU
//	MDIO_vSetPinDir(DIO_PORTD, DIO_PIN6, DIO_INPUT);
//
//	HLCD_vInit();
//	MTIMERS_vInit();
//
//	MTIMERS_vSetICU_CB(ICU_CALLBACK);
//
//	MTIMERS_vSetTrigger(TRIG_TYPE_RISING);
//	//PWM WITH 50% DUTY CYCLE
//	MTIMERS_vSetCompareMatch(TIM_0, 127);
//	MGIE_vEnableGlobalInterrupt();
//
//	MTIMERS_vStartTimer(TIM_0);
//	MTIMERS_vStartTimer(TIM_1);
//
//
//	while(1)
//	{
//		// DUTY CYCLE , FREQ
//		if(G_state == 3)
//		{
//			u16 Ton;
//			u16 Ttotal;
//
//			u32 Freq = 0;
//			u8 Duty =0;
//
//			Ton = G_T2-G_T1;
//			Ttotal = G_T3 - G_T1;
//			if(Ttotal != 0)
//			{
//			Freq = 10000000UL/ Ttotal;
//			Duty =  (u8)((u32)(Ton*100)/ Ttotal);
//			}
//			HLCD_vClearScreen();
//			HLCD_vSetCursorPosition(0,0);
//			HLCD_vDisplayString((const u8)"ICU TEST");
//			_delay_ms(500);
//			HLCD_vClearScreen();
//
//			HLCD_vSetCursorPosition(0,0);
//			HLCD_vDisplayString((const u8)"Freq: ");
//			HLCD_vPrintNumber(Freq);
//			HLCD_vDisplayString((const u8)"Hz");
//
//			HLCD_vSetCursorPosition(1,0);
//			HLCD_vDisplayString((const u8)"Duty: ");
//			HLCD_vPrintNumber(Duty);
//			HLCD_vDisplayString((const u8)"%");
//			_delay_ms(2000);
//			G_state = 0 ;
//			MTIMERS_vSetTrigger(TRIG_TYPE_RISING);
//			MTIMERS_vEnableInterrupt(TIM_1, ICU);
//
//		}
//
//	}
//	return 0;
//}
