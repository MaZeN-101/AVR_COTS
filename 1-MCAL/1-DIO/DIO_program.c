/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : DIO                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "PORT_interface.h"


//SET VALUE OF A PIN TO BE HIGH OR LOW //
u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	
	u8 Local_u8ErrorState = 0;
	
	if (Copy_u8Pin <= DIO_u8PIN7)
	{
		if (Copy_u8Value == DIO_u8PIN_LOW)				//0 -> LOW
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA : CLR_BIT(PORTA , Copy_u8Pin); break;	//PORT A
				case DIO_u8PORTB : CLR_BIT(PORTB , Copy_u8Pin); break;	//PORT B
				case DIO_u8PORTC : CLR_BIT(PORTC , Copy_u8Pin); break;	//PORT C
				case DIO_u8PORTD : CLR_BIT(PORTD , Copy_u8Pin); break;	//PORT D
				default : Local_u8ErrorState = 1;

			}
		}
		else if (Copy_u8Value == DIO_u8PIN_HIGH)			//1 -> HIGH
		{
			switch(Copy_u8Port)
			{
				case DIO_u8PORTA : SET_BIT(PORTA , Copy_u8Pin); break;	//PORT A
				case DIO_u8PORTB : SET_BIT(PORTB , Copy_u8Pin); break;	//PORT B
				case DIO_u8PORTC : SET_BIT(PORTC , Copy_u8Pin); break;	//PORT C
				case DIO_u8PORTD : SET_BIT(PORTD , Copy_u8Pin); break;	//PORT D
				default : Local_u8ErrorState = 1;

			}
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




//SET VALUE OF A PORT TO BE HIGH OR LOW //
u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	
	u8 Local_u8ErrorState = 0;
	
	switch(Copy_u8Port)
	{
		case DIO_u8PORTA : PORTA = Copy_u8Value; break;	//PORT A
		case DIO_u8PORTB : PORTB = Copy_u8Value; break;	//PORT B
		case DIO_u8PORTC : PORTC = Copy_u8Value; break;	//PORT C
		case DIO_u8PORTD : PORTD = Copy_u8Value; break;	//PORT D
		default : Local_u8ErrorState = 1;

	}
	
	
	return Local_u8ErrorState;
	
}



//GET VALUE OF A PIN TO BE HIGH OR LOW AND RETURN IT IN POINTER (Copy_Pu8Value) //
u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_Pu8Value)
{
	
	u8 Local_u8ErrorState = 0;
	
	if ((Copy_Pu8Value != NULL)&&(Copy_u8Pin <= DIO_u8PIN7))
	{
		
		switch(Copy_u8Port)
		{
			case DIO_u8PORTA : *Copy_Pu8Value = GET_BIT(PINA , Copy_u8Pin); break;	//PORT A
			case DIO_u8PORTB : *Copy_Pu8Value = GET_BIT(PINB , Copy_u8Pin); break;	//PORT B
			case DIO_u8PORTC : *Copy_Pu8Value = GET_BIT(PINC , Copy_u8Pin); break;	//PORT C
			case DIO_u8PORTD : *Copy_Pu8Value = GET_BIT(PIND , Copy_u8Pin); break;	//PORT D
			default : Local_u8ErrorState = 1;

		}
		
	}
	else 
	{
		Local_u8ErrorState = 1;
	}
	
	return Local_u8ErrorState;
	
}










