/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : DC_M                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "DC_M_interface.h"
#include "DC_M_private.h"
#include "DC_M_config.h"





//rotate the DC motor clock wise //
void DC_M_voidRotateCCW(void)
{
	DIO_u8SetPinValue(DC_M_PORT , DC_M_PIN0 , DIO_u8PIN_LOW);
	
	DIO_u8SetPinValue(DC_M_PORT , DC_M_PIN1 , DIO_u8PIN_HIGH);
}


//rotate the DC motor counter clock wise //
void DC_M_voidRotateCW(void)
{
	DIO_u8SetPinValue(DC_M_PORT , DC_M_PIN1 , DIO_u8PIN_LOW);

	DIO_u8SetPinValue(DC_M_PORT , DC_M_PIN0 , DIO_u8PIN_HIGH);
}




