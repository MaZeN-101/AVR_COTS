/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : EEPROM               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "TWI_interface.h"
#include "DIO_interface.h"


// Send Data Byte //
void EEPROM_voidSendDataByte(u8 Copy_u8dataByte,u16 Copy_u16Address)
{
	u8 Local_u8AddressPacket;

	TWI_ErrStatus errType = NoErr;

	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_PINA2 <<2) | (u8)(Copy_u16Address >>8);

	/*if 24C02 :
	 * 	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	 */

	// Send Start Condition //
	errType = TWI_SendStartCondition();
	
	/* Check if Start condition Error occurs */
	if (errType == StartConditionErr)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		errType = NoErr;
	}

	// Send Address packet : Send Slave Address with write request //
	errType = TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);
	
	/* Check if Send Slave Address With Write Error occurs */
	if (errType == SlaveAddWithWriteErr)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
		errType = NoErr;
	}

	// Send Byte Address //
	errType = TWI_MasterWriteDataByte((u8) Copy_u16Address);
	
	/* Check if Master Write Data Byte Error occurs */
	if (errType == MasterWriteByteErr)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
		errType = NoErr;
	}

	// Send Data packet //
	errType = TWI_MasterWriteDataByte(Copy_u8dataByte);
	
	/* Check if Master Write Data Byte Error occurs */
	if (errType == MasterWriteByteErr)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
		errType = NoErr;
	}

	// Send Stop Condition //
	TWI_SendStopCondition();
}


// Receive Data Byte //
void EEPROM_u8ReadDataByte(u8* Copy_u8dataByte,u16 Copy_u16Address)
{
	u8 Local_u8AddressPacket;

	TWI_ErrStatus err = NoErr;

	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_PINA2 <<2) | (u8)(Copy_u16Address >>8);

	/*if 24C02 :
	 * 	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	 */

	// Send Start Condition //
	err = TWI_SendStartCondition();

	/* Check if Start condition Error occurs */
	if (err == StartConditionErr)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		err = NoErr;
	}

	// Send Address packet : Send Slave Address with write request //
	err = TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);
	
	/* Check if Send Slave Address With Write Error occurs */
	if (err == SlaveAddWithWriteErr)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
		err = NoErr;
	}

	// Send Byte Address //
	err = TWI_MasterWriteDataByte((u8) Copy_u16Address);
	
	/* Check if Master Write Data Byte Error occurs */
	if (err == MasterWriteByteErr)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
		err = NoErr;
	}

	// Send repeated Start Condition //
	err = TWI_SendRepeatedStart();
	
	/* Check if Repeated Start condition Error occurs */
	if (err == RepeatedStartErr)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_HIGH);
		err = NoErr;
	}

	// Send Address packet : Send Slave Address with Read request //
	err = TWI_SendSlaveAddressWithRead(Local_u8AddressPacket);
	
	/* Check if Send Slave Address With Read Error occurs */
	if (err == SlaveAddWithReadErr)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN4,DIO_u8PIN_HIGH);
		err = NoErr;
	}

	// Receive Data packet //
	err = TWI_MasterReadDataByte(Copy_u8dataByte);
	
	/* Check if Master Read Data Byte Error occurs */
	if (err == MasterReadByteErr)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);
		err = NoErr;
	}

	// Send Stop Condition //
	TWI_SendStopCondition();
}



