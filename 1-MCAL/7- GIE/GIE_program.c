/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : GIE                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_register.h"
#include "GIE_interface.h"


// Enable GLobal Interrupt // 
void GIE_voidEnable(void)
{
	/* Enable Global Interrupt Bit */
	SET_BIT(SREG,SREG_I);
}

// Disable GLobal Interrupt flag // 
void GIE_voidDisable(void)
{
	/* Disable Global Interrupt Bit */
	CLR_BIT(SREG,SREG_I);
}

