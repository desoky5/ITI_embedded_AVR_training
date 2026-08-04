/*
 * TIM0_prg.c
 *  Created on: Aug 3, 2026
 *      Author: Omar Desoky
 */
#include "../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "TIMR_int.h"
#include "TIMR_prv.h"
#include "TIMR_cfg.h"

static void (*G_TIMER_OVF_CB)(void) = {NULL};
static void (*G_TIMER_CTC_CB)(void) = {NULL};

static u8 G_u8Timer0Preload = 0 ;
static u32 G_u32IntervalCount = 0 ;

void MTIMERS_vInit()
{
#if TIMER0_STATE == ENABLE

	#if TIMER0_MODE  == NORMAL_OVERFLOW
		CLEAR_BIT(TCCR0, WGM01);
		CLEAR_BIT(TCCR0, WGM00);

	#elif  TIMER0_MODE ==  CTC
		SET_BIT(TCCR0, WGM01);
		CLEAR_BIT(TCCR0, WGM00);

	#elif  TIMER0_MODE == PWM_PHASE_CORRECT
		SET_BIT(TCCR0, WGM00);
		CLEAR_BIT(TCCR0, WGM01);


		#if PWM_OUTPUT_MODE == NON_INVERTING
				CLEAR_BIT(TCCR0, COM00);
				SET_BIT(TCCR0, COM01);

		#elif PWM_OUTPUT_MODE == INVERTING
				SET_BIT(TCCR0, COM00);
				SET_BIT(TCCR0, COM01);

		#elif PWM_OUTPUT_MODE == DISCONNECTED
				CLEAR_BIT(TCCR0, COM00);
				CLEAR_BIT(TCCR0, COM01);
       #endif

	#elif  TIMER0_MODE == FAST_PWM
		SET_BIT(TCCR0, WGM01);
		SET_BIT(TCCR0, WGM00);

		#if PWM_OUTPUT_MODE == NON_INVERTING
			CLEAR_BIT(TCCR0, COM00);
			SET_BIT(TCCR0, COM01);

		#elif PWM_OUTPUT_MODE == INVERTING
			SET_BIT(TCCR0, COM00);
			SET_BIT(TCCR0, COM01);

		#elif PWM_OUTPUT_MODE == DISCONNECTED
			CLEAR_BIT(TCCR0, COM00);
			CLEAR_BIT(TCCR0, COM01);
		#endif
	#endif

#if  INTERRUPT_CONTROL == ENABLE
	MTIMERS_vEnableInterrupt(TIM_0,TIMER0_MODE);

#endif
	// STOP TIMER0
	CLEAR_BIT(TCCR0, CS00);
	CLEAR_BIT(TCCR0, CS01);
	CLEAR_BIT(TCCR0, CS02);
#endif


#if TIMER1_STATE == ENABLE

#if TIMER1_MODE ==  FAST_PWM
	CLEAR_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);

	// Non Inverting MODE

	CLEAR_BIT(TCCR1A , 6);
	SET_BIT(TCCR1A , 7);

	ICR1 = 20000;



#endif
#endif

}

void MTIMERS_vStartTimer(u8 A_u8TimerID)
{
	if ( A_u8TimerID==TIM_0)
	{
	TCCR0 = (TCCR0 & 0XF8) | (CLK_SELLECT_PRESCALER_TIM0 & 0x07); // Anding with 0x07 is safety to change only the numbers of the first three bits
	}

	if ( A_u8TimerID==TIM_1)
		{
		TCCR1B = (TCCR1B & 0XF8) | (CLK_SELLECT_PRESCALER_TIM1 & 0x07); // Anding with 0x07 is safety to change only the numbers of the first three bits
		}
}
void MTIMERS_vStopTimer(u8 A_u8TimerID)
{
	if ( A_u8TimerID==TIM_0)
	{
	TCCR0 = (TCCR0 & 0XF8) | (0x00 & 0x07);

	}

	if ( A_u8TimerID==TIM_1)
		{
		TCCR1B = (TCCR1B & 0XF8) | (0x00 & 0x07);

		}
}
//OVF
void MTIMERS_vSetPreloadValue(u8 A_u8TimerID,u16 A_u16Preload)
{
	switch (A_u8TimerID)
	{
	case TIM_0 :
		TCNT0 = (u8) A_u16Preload ;
		G_u8Timer0Preload = (u8) A_u16Preload ;
		break;
	}

}

//CTC
void MTIMERS_vSetCompareMatch(u8 A_u8TimerID,u16 A_u16OCR_val)
{
	switch (A_u8TimerID)
	{
	case TIM_0 :
		OCR0 = (u8) A_u16OCR_val ;
		break;
	case TIM_1_A :
			OCR1A = A_u16OCR_val ;
			break;
	}
}

void MTIMERS_vEnableInterrupt(u8 A_u8TimerID,u8 A_u8TimerMode)
{
	if ( A_u8TimerID == TIM_0)
		{
			switch (A_u8TimerMode)
			{
			case  NORMAL_OVERFLOW :
				SET_BIT(TIMSK,0);
				break;

			case  CTC :
				SET_BIT(TIMSK,1);
				break;
			}

		}
}
void MTIMERS_vDisableInterrupt(u8 A_u8TimerID,u8 A_u8TimerMode)
{
	if ( A_u8TimerID == TIM_0)
		{
			switch (A_u8TimerMode)
			{
			case  NORMAL_OVERFLOW :
				CLEAR_BIT(TIMSK,0);
				break;

			case  CTC :
				CLEAR_BIT(TIMSK,1);
				break;
			}

		}
}

void MTIMERS_vSetInterval_OVF(void(*Fptr)(void),u32 A_u32Intervalcount)
{
	 G_u32IntervalCount = A_u32Intervalcount ;
	 G_TIMER_OVF_CB = Fptr ;

}

void MTIMERS_vSetInterval_CTC(void(*Fptr)(void),u32 A_u32Intervalcount)
{
	 G_u32IntervalCount = A_u32Intervalcount ;
	G_TIMER_CTC_CB = Fptr ;

}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u32 LS_u32Counter = 0 ;

	LS_u32Counter ++ ;

	if(LS_u32Counter ==  G_u32IntervalCount )
	{
	TCNT0 = G_u8Timer0Preload ;

	if(G_TIMER_CTC_CB != NULL )
	{
		G_TIMER_CTC_CB();
	}
	LS_u32Counter = 0;
	}
}

void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{
	static u32 LS_u32T_OVF = 0 ;

	LS_u32T_OVF ++ ;

	if(LS_u32T_OVF ==  G_u32IntervalCount )
	{
	TCNT0 = G_u8Timer0Preload ;

	if(G_TIMER_OVF_CB != NULL )
	{
		G_TIMER_OVF_CB();
	}
	LS_u32T_OVF = 0;
	}
}
