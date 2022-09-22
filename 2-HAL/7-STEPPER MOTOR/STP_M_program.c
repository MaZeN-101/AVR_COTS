/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : STP_M                ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "STP_M_interface.h"
#include "STP_M_config.h"
#include "STP_M_private.h"




//rotate the Stepper motor counter clock wise //
void STP_M_voidRotateCW(void)
{
	DIO_u8SetPinValue(STP_M_PORT , STP_M_BLUE_PIN 	, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_PINK_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_YELLOW_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_ORANGE_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(STP_M_PORT , STP_M_BLUE_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_PINK_PIN 	, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_YELLOW_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_ORANGE_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(STP_M_PORT , STP_M_BLUE_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_PINK_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_YELLOW_PIN , DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_ORANGE_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(STP_M_PORT , STP_M_BLUE_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_PINK_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_YELLOW_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_ORANGE_PIN , DIO_u8PIN_LOW);
	_delay_ms(2);
}




//rotate the Stepper motor clock wise //
void STP_M_voidRotateCCW(void)
{
	DIO_u8SetPinValue(STP_M_PORT , STP_M_BLUE_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_PINK_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_YELLOW_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_ORANGE_PIN , DIO_u8PIN_LOW);
	_delay_ms(2);
	
	DIO_u8SetPinValue(STP_M_PORT , STP_M_BLUE_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_PINK_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_YELLOW_PIN , DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_ORANGE_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
	
	DIO_u8SetPinValue(STP_M_PORT , STP_M_BLUE_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_PINK_PIN 	, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_YELLOW_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_ORANGE_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
	
	DIO_u8SetPinValue(STP_M_PORT , STP_M_BLUE_PIN 	, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_PINK_PIN 	, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_YELLOW_PIN , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_ORANGE_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
}



//Stop Stepper motor //
void STP_M_voidStop(void)
{
	DIO_u8SetPinValue(STP_M_PORT , STP_M_BLUE_PIN 	, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_PINK_PIN 	, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_YELLOW_PIN , DIO_u8PIN_LOW);
	DIO_u8SetPinValue(STP_M_PORT , STP_M_ORANGE_PIN , DIO_u8PIN_LOW);
	_delay_ms(2);
}



//rotate the Stepper motor CCW or CW with specific angle //
void STP_M_voidRotate(f32 Copy_f32Angle,u8 Copy_u8Dir)
{
	u16 Local_u16Iter , Local_u16NoOfIter;
	
	//calculate number of steps and then calculate number of iteration 
	Local_u16NoOfIter = (Copy_f32Angle/0.175) / 4;   
	
	//detect the direction of motor
	switch (Copy_u8Dir)
	{
		case STP_M_RotateCW :
			for(Local_u16Iter = 0 ; Local_u16Iter < Local_u16NoOfIter ; Local_u16Iter++)
			{
				STP_M_voidRotateCW();
			}
			break;
		case STP_M_RotateCCW :
			for(Local_u16Iter = 0 ; Local_u16Iter < Local_u16NoOfIter ; Local_u16Iter++)
			{
				STP_M_voidRotateCCW();
			}
			break;
	}
}





