/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : SPI                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_register.h"
#include "SPI_interface.h"


// Initialize SPI Master node //
void SPI_voidMasterInit(void)
{
	/* SPI Enable Master mode */
	SET_BIT(SPCR,SPCR_MSTR);
	
	/* SPI CLK rate determination */
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);	
	
	/* SPI Enable */
	SET_BIT(SPCR,SPCR_SPE);
}

// Initialize SPI Slave node //
void SPI_voidSlaveInit(void)
{
	/* SPI Enable Slave mode */
	CLR_BIT(SPCR,SPCR_MSTR);
	
	/* SPI Enable */
	SET_BIT(SPCR,SPCR_SPE);
}

// SPI send & receive data //
u8 SPI_u8transceive(u8 Copy_u8data)
{
	/* SPI write data*/
	SPDR = Copy_u8data;
	
	/* wait until SPI Flag is set */
	while(!GET_BIT(SPSR,SPSR_SPIF));

	/* return received data */
	return SPDR;
}
