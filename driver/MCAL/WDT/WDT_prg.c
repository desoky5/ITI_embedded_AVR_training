/*
 * WDT_prg.c
 *
 *  Created on: Aug 5, 2026
 *      Author: Omar Desoky
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "WDT_int.h"
#include "WDT_prv.h"
#include "WDT_cfg.h"

void MWDT_vEnable(void)
{
	SET_BIT(WDTCR,3); // Enable WDT
}

void MWDT_vDisable(void)
{
	WDTCR |= 0b00011000 ;
	WDTCR = 0x00 ;
}

void MWDT_vSleep(void)
{
	WDTCR &= 0xF8 ;
	WDTCR |= WDT_PRESCALER ;
}


