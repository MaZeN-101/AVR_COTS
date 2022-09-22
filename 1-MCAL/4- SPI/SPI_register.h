/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : SPI                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	SPI_REGISTER_H_
#define SPI_REGISTER_H_

/* SPI Data register */
#define SPDR 				*((volatile u8*)0X2F)

/* SPI control register */
#define SPCR 				*((volatile u8*)0X2D)
#define SPCR_SPR0			0			// SPI CLK rate select 0
#define SPCR_SPR1           1			// SPI CLK rate select 1
#define SPCR_CPHA           2			// SPI CLK phase select
#define SPCR_CPOL           3			// SPI CLK polarity select
#define SPCR_MSTR           4			// SPI Master | Slave select
#define SPCR_DORD           5			// SPI DATA order select
#define SPCR_SPE            6			// SPI Enable
#define SPCR_SPIE           7			// SPI Intrrupt Enable

/* SPI status register */
#define SPSR 				*((volatile u8*)0X2E)
#define SPSR_SPI2X			0			// SPI Double speed
#define SPSR_WCOL           6			// SPI Write collision Flag
#define SPSR_SPIF           7			// SPI Intrrupt Flag

#endif