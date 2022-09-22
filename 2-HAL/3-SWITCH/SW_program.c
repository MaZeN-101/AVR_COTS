/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : SWITCH               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/





#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"
#include<util/delay.h>







//GET THE STATE OF THE SWITCH PRESSED OR NOT PRESSED //
u8 SW_u8GetState(SW_t *Copy_pu8SW , u8 *Copy_u8SwState)
{
	
	u8 Local_u8ErrorState = 0;
	
	if (Copy_pu8SW != NULL)
	{
		switch(Copy_pu8SW->Local_u8PullType)
		{
			case SW_PULL_UP_RES:
				
				DIO_u8GetPinValue(Copy_pu8SW->Local_u8Port , Copy_pu8SW->Local_u8Pin , Copy_u8SwState);
				
				if (*Copy_u8SwState == 0)
				{
					*Copy_u8SwState = SW_PRESSED;
				}
				else if (*Copy_u8SwState == 1)
				{
					*Copy_u8SwState = SW_NOTPRESSED;
				}
			
				break;
			case SW_PULL_DOWN_RES:
				
				DIO_u8GetPinValue(Copy_pu8SW->Local_u8Port , Copy_pu8SW->Local_u8Pin , Copy_u8SwState);
				
				if (*Copy_u8SwState == 1)
				{
					*Copy_u8SwState = SW_PRESSED;
				}
				else if (*Copy_u8SwState == 0)
				{
					*Copy_u8SwState = SW_NOTPRESSED;
				}
			
				break;
			default:
				Local_u8ErrorState = 1;
		}
		
		if (Copy_pu8SW->Local_u8SwType == SW_TEMPERORY_SW)
		{
			_delay_ms(100);
		}
		else if (Copy_pu8SW->Local_u8SwType == SW_SELF_LOCKING_SW)
		{
			
		}
		else 
		{
			Local_u8ErrorState = 1;
		}
	}
	else 
	{
		Local_u8ErrorState = 1;
	}
	
	return Local_u8ErrorState;
	
}









