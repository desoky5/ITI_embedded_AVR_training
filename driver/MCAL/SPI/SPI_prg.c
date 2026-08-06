/*
 * SPI_prg.c
 *
 *  Created on: Aug 6, 2026
 *      Author: Omar Desoky
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"

#include"SPI_int.h"
#include "SPI_prv.h"
#include"SPI_cfg.h"
void MSPI_vInit()
{
  #if SPI_MODE == SPI_MASTER
	  MDIO_vSetPinDir(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);//MOSI
	  MDIO_vSetPinDir(DIO_PORTB,DIO_PIN6,DIO_INPUT);//MISO
	  MDIO_vSetPinDir(DIO_PORTB,DIO_PIN7,DIO_INPUT);//SCK
	  MDIO_vSetPinDir(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);//SS

	  MDIO_vSetPinVal(DIO_PORTB,DIO_PIN6,DIO_HIGH);


	  SPCR = 0b01011010;


 #endif

#if SPI_MODE == SPI_SLAVE
	  MDIO_vSetPinDir(DIO_PORTB,DIO_PIN5,DIO_INPUT);//MOSI
	  MDIO_vSetPinDir(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);//MISO
	  MDIO_vSetPinDir(DIO_PORTB,DIO_PIN7,DIO_INPUT);//SCK
	  MDIO_vSetPinDir(DIO_PORTB,DIO_PIN4,DIO_INPUT);//SS




	  SPCR = 0b01001010;


#endif

}
void MSPI_vTransmit(u8 A_u8Byte)
{
  SPDR = A_u8Byte;
  u8 val;
  while (!GET_BIT(SPSR,7,val));

}

u8 MSPI_vRecieve(void)
{
	  while (!GET_BIT_NV(SPSR,7));
	  return SPDR;

}

u8 MSPI_u8Transieve(u8 A_u8Byte)
{
	SPDR = A_u8Byte;
	while (!GET_BIT_NV(SPSR,7));
	u8 val;
	while (!GET_BIT_NV(SPSR,7));
	return SPDR;

}

