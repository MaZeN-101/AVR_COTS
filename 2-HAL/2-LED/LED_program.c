/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : LED                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/




#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



//ENABLE LED TO BE ON//
u8 LED_u8TurnOn(LED_t *Copy_pu8LED)
{
	u8 Local_u8ErrorState = 0;
	
	if (Copy_pu8LED != NULL)
	{
		
		switch(Copy_pu8LED->Local_u8ConnectionType)
		{
			case LED_SINK_CONNECTION :
				
				DIO_u8SetPinValue(Copy_pu8LED->Local_u8Port , Copy_pu8LED->Local_u8Pin , DIO_u8PIN_LOW);
			
				break;
			case LED_SOURCE_CONNECTION :
			
				DIO_u8SetPinValue(Copy_pu8LED->Local_u8Port , Copy_pu8LED->Local_u8Pin , DIO_u8PIN_HIGH);
			
				break;
		}

	}
	else 
	{
		Local_u8ErrorState = 1;
	}
	
	return Local_u8ErrorState;
	
}





//DISABLE LED TO BE OFF//
u8 LED_u8TurnOff(LED_t *Copy_pu8LED)
{
	
	u8 Local_u8ErrorState = 0;
	
	if (Copy_pu8LED != NULL)
	{
		
		switch(Copy_pu8LED->Local_u8ConnectionType)
		{
			case LED_SINK_CONNECTION :
				
				DIO_u8SetPinValue(Copy_pu8LED->Local_u8Port , Copy_pu8LED->Local_u8Pin , DIO_u8PIN_HIGH);
			
				break;
			case LED_SOURCE_CONNECTION :
			
				DIO_u8SetPinValue(Copy_pu8LED->Local_u8Port , Copy_pu8LED->Local_u8Pin , DIO_u8PIN_LOW);
			
				break;
		}
		
	}
	else 
	{
		Local_u8ErrorState = 1;
	}
	
	return Local_u8ErrorState;
	
}






