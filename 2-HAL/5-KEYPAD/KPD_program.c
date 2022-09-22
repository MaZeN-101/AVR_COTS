/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : KPD                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/




#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"





//detect the pressed key in keypad//
u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KPD_NOT_PRESSED_KEY , Local_u8ColsIndx , Local_u8RowsIndx , Local_u8PinState;
	static u8 KPD_ARR[ROWS_NUM][COLUMNS_NUM] = KPD_ARR_VALUES;
	static u8 KPD_u8ROWS[ROWS_NUM] = {KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN , KPD_ROW3_PIN};
	static u8 KPD_u8COLUMNS[COLUMNS_NUM] = {KPD_COL0_PIN , KPD_COL1_PIN , KPD_COL2_PIN , KPD_COL3_PIN};
	
	
	for(Local_u8ColsIndx = 0 ; Local_u8ColsIndx < COLUMNS_NUM ; Local_u8ColsIndx++)
	{
		//Activate current column//
		DIO_u8SetPinValue(KPD_PORT , KPD_u8COLUMNS[Local_u8ColsIndx] , DIO_u8PIN_LOW);
		
		for(Local_u8RowsIndx = 0 ; Local_u8RowsIndx < ROWS_NUM ; Local_u8RowsIndx++)
		{
			//search for pressed key in rows//
			DIO_u8GetPinValue(KPD_PORT , KPD_u8ROWS[Local_u8RowsIndx] , &Local_u8PinState);
			
			//check if switch is pressed or not//
			if(DIO_u8PIN_LOW == Local_u8PinState)
			{
				Local_u8PressedKey = KPD_ARR[Local_u8RowsIndx][Local_u8ColsIndx];
				
				//busy waiting (polling)
				while(DIO_u8PIN_LOW == Local_u8PinState)
				{
					DIO_u8GetPinValue(KPD_PORT , KPD_u8ROWS[Local_u8RowsIndx] , &Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}

		//Deactivate current column//
		DIO_u8SetPinValue(KPD_PORT , KPD_u8COLUMNS[Local_u8ColsIndx] , DIO_u8PIN_HIGH);
	}
	
	return Local_u8PressedKey;
}



