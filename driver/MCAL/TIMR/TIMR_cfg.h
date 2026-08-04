/*
 * TIMR_cfg.h
 *
 *  Created on: Aug 3, 2026
 *      Author: Omar Desoky
 */

#ifndef MCAL_TIMR_TIMR_CFG_H_
#define MCAL_TIMR_TIMR_CFG_H_

// to enable and disable the timers

#define TIMER0_STATE						ENABLE
#define TIMER1_STATE						ENABLE

#define TIMER0_MODE 						FAST_PWM
#define TIMER1_MODE 						FAST_PWM

#define CLK_SELLECT_PRESCALER_TIM0 			CLK_8
#define CLK_SELLECT_PRESCALER_TIM1 			CLK_8



//configure prescaler
//Define PWM MODES
#define  DISCONNECTED            0
#define  NON_INVERTING           1
#define  INVERTING               2


#define PWM_OUTPUT_MODE			NON_INVERTING

#define INTERRUPT_CONTROL      ENABLE

#endif /* MCAL_TIMR_TIMR_CFG_H_ */
