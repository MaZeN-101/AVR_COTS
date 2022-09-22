/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : CLCD                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/




#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include<util/delay.h>




//SEND COMMAND TO LCD//
void CLCD_voidSendCommand(u8 Copy_u8Command)
{

	//ACTIVATE SENDING COMMAND(RS)//
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_LOW);

	//ACTIVATE WRITING(RW)//
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW);

	//SEND COMMAND//
	DIO_u8SetPortValue(CLCD_DATA_PORT , Copy_u8Command);

	//ENABLE PULSE WITH 2 MS DELAY//
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH);

	_delay_ms(2);

	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW);
}


//SEND DATA TO LCD//
void CLCD_voidSendData(u8 Copy_u8Data)
{

	//ACTIVATE SENDING COMMAND(RS)//
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_HIGH);

	//ACTIVATE WRITING(RW)//
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW);

	//SEND COMMAND//
	DIO_u8SetPortValue(CLCD_DATA_PORT , Copy_u8Data);

	//ENABLE PULSE WITH 2 MS DELAY//
	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH);

	_delay_ms(2);

	DIO_u8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW);
}


//INTIALIZATION OF LCD//
void CLCD_voidInit(void)
{
	//WAIT FOR MORE THAN 30 MS //
	_delay_ms(40);

	//FUNCTION SET : 1 LINE , 5*8 FONT SIZE//
	CLCD_voidSendCommand(0b00110000);

	//DISPLAY ON/OFF CONTROL : DISPLAY ENABLED , CURSOR NOT ENABLED , BLINK CURSOR NOT ENABLED//
	CLCD_voidSendCommand(0b00001100);

	//DISPLAY CLEAR//
	CLCD_voidSendCommand(0b00000001);

	//ACTIVATE WRITING ON 2 LINES//
	CLCD_voidSendCommand(0X38);

}




//SEND STRING DATA TO LCD//
void CLCD_voidSendString(const char *Copy_pcString)
{
	u8 Local_u8Counter = 0;

	//PRINT EACH CHAR UNTIL IT REACH NULL CHAR//
	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		//SEND CHAR BY CHAR TO THE END OF THE STRING//
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);

		Local_u8Counter++;
	}
}




//GO TO SPECIFIC POSITION//
void CLCD_voidGoToXY(u8 Copy_u8Xpos , u8 Copy_u8Ypos)
{
	u8 Local_u8Address;

	//LOCATION IN THE FRIST LINE //
	if (Copy_u8Xpos == 0)
	{
		Local_u8Address = Copy_u8Ypos;
	}

	//LOCATION IN THE SECOND LINE //
	else if(Copy_u8Xpos == 1)
	{
		Local_u8Address = Copy_u8Ypos + 0X40;
	}

	//SET DDRAM ADDRESS COMMAND //
	CLCD_voidSendCommand(Local_u8Address|0X80);

}




//WRITE SPECIAL CHAR//
void CLCD_voidWriteSpeacialChar(u8 *Copy_u8Arr , u8 Copy_u8BlockNum , u8 Copy_u8Xpos , u8 Copy_u8Ypos)
{
	u8 Local_u8CGRAMAddress , Local_u8Iter;


	//SPECIFY CGRAM ADDRESS//
	Local_u8CGRAMAddress = Copy_u8BlockNum*8;


	//SET DDRAM ADDRESS COMMAND //
	CLCD_voidSendCommand(Local_u8CGRAMAddress|0X40);


	//SAVING PATTERN IN CGRAM BY SENDING EACH BYTE//
	for(Local_u8Iter = 0 ; Local_u8Iter<8 ; Local_u8Iter++)
	{
		CLCD_voidSendData(Copy_u8Arr[Local_u8Iter]);
	}


	//GO TO SPECIFIC POSITION//
	CLCD_voidGoToXY(Copy_u8Xpos , Copy_u8Ypos);



	//SEND DATA TO LCD//
	CLCD_voidSendData(Copy_u8BlockNum);

}




//WRITE NUMBER ON LCD//
void CLCD_voidWriteNumber(u32 Copy_u32Number)
{

	u32 Local_u32ReversedNum = 0 , Local_u32Temp = Copy_u32Number;
	u8 Local_u8mod , Local_u8Digits = 0 , Local_u8DigitsPrint = 0;


	//special case if entered number is 0//
	if (Copy_u32Number == 0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		//count number of digits for entered number//
		while (Local_u32Temp > 0)
		{
			Local_u32Temp /= 10;
			Local_u8Digits++;
		}

		Local_u32Temp = Copy_u32Number;

		//reverse the entered number to print each number in its right order//
		while(Local_u32Temp > 0)
		{
			Local_u8mod = Local_u32Temp%10;

			Local_u32ReversedNum = Local_u32ReversedNum*10 + Local_u8mod;

			Local_u32Temp/=10;
		}

		//print each number in its right order//
		while(Local_u32ReversedNum > 0)
		{
			Local_u8mod = Local_u32ReversedNum%10;

			CLCD_voidSendData(Local_u8mod+'0');

			Local_u32ReversedNum/=10;

			Local_u8DigitsPrint++;
		}

		//check if the printed digits equal number digits
		if(Local_u8DigitsPrint != Local_u8Digits)
		{
			CLCD_voidSendData('0');
		}

	}

	/*
	//move number to required place on DDRAM//
	while (Copy_u32Number > 0)
	{
		//hold number by number to display it//
		Local_u32mod = Copy_u32Number%10;

		//move to the required coordinates//
		CLCD_voidGoToXY(0,Local_u8Digits-1);

		//display the number to the required place//
		CLCD_voidSendData(Local_u32mod+0x30);

		//remove the number which displayed on LCD//
		Copy_u32Number/=10;

		//move to the next coordinates//
		Local_u8Digits--;
	}
	*/
}












