/*
 * SPI_prv.h
 *
 *  Created on: Aug 6, 2026
 *      Author: Omar Desoky
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

#define SPDR			*((volatile u8*)(0x2F))
#define SPSR			*((volatile u8*)(0x2E))
#define SPCR			*((volatile u8*)(0x2D))


#define SPI_MASTER   0
#define SPI_SLAVE    1
#endif /* MCAL_SPI_SPI_PRV_H_ */
