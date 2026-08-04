/*
 * TIM0_int.h
 *
 *  Created on: Aug 3, 2026
 *      Author: Omar Desoky
 */

#ifndef MCAL_TIMR_TIMR_INT_H_
#define MCAL_TIMR_TIMR_INT_H_

#define TIM_0        0
#define TIM_1        1
#define TIM_1_A      2


void MTIMERS_vInit(void);

void MTIMERS_vStartTimer(u8 A_u8TimerID);
void MTIMERS_vStopTimer(u8 A_u8TimerID);

//OVF
void MTIMERS_vSetPreloadValue(u8 A_u8TimerID,u16 A_u16Preload);
void MTIMERS_vSetInterval_OVF(void(*Fptr)(void),u32 A_u32Intervalcount); //  A_u32Intervalcount is the number of times for overflow to happen to get the desired time interval

//CTC
void MTIMERS_vSetCompareMatch(u8 A_u8TimerID,u16 A_u16OCR_val);
void MTIMERS_vSetInterval_CTC(void(*Fptr)(void),u32 A_u32Intervalcount);

void MTIMERS_vEnableInterrupt(u8 A_u8TimerID,u8 A_u8TimerMode);
void MTIMERS_vDisableInterrupt(u8 A_u8TimerID,u8 A_u8TimerMode);


#endif /* MCAL_TIMR_TIMR_INT_H_ */
