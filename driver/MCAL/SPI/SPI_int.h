/*
 * SPI_int.h
 *
 *  Created on: Aug 6, 2026
 *      Author: Omar Desoky
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

void MSPI_vInit(void);

void MSPI_vTransmit(u8 A_u8Byte);

u8 MSPI_vRecieve(void);

u8 MSPI_u8Transieve(u8 A_u8Byte);

#endif /* MCAL_SPI_SPI_INT_H_ */
