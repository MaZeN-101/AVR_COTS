/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : TWI                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_config.h"
#include "TWI_private.h"
#include "TWI_register.h"
#include "TWI_interface.h"


// Initialize TWI Master node : if the passed address is 0, the master will not be addressed //
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/* Initialize Clock frequency to 400 Kbps : set TWBR = 2 & TWPS = 0 */
	TWBR = 2;
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	/* Enable Master to Generate ACK After reading the data */
	SET_BIT(TWCR,TWCR_TWEA);

	/* Initialize Address of Master */
	if (Copy_u8SlaveAddress != 0)
	{
		TWAR = Copy_u8SlaveAddress << 1;
	}

	/* Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);
}

// Initialize TWI Slave node //
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/* Initialize Address of Slave */
	TWAR = Copy_u8SlaveAddress << 1;

	/* Enable Slave to Generate ACK After reading the data */
	SET_BIT(TWCR,TWCR_TWEA);

	/* Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);
}

// Send Start Condition //
TWI_ErrStatus TWI_SendStartCondition(void)
{
	TWI_ErrStatus Local_ErrStatus = NoErr;

	/* Send Start Condition on the bus */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* Clear Interrupt Flag to Start Previous Operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Wait until Interrupt Flag is set again */
	while(!GET_BIT(TWCR,TWCR_TWINT));

	/* Check the previous operation is start condition */
	if((TWSR & 0xF8) != START_ACK)
	{
		Local_ErrStatus = StartConditionErr;
	}
	return Local_ErrStatus;
}

// Send repeated Start Condition //
TWI_ErrStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrStatus Local_ErrStatus = NoErr;

	/* Send Start Condition on the bus */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* Clear Interrupt Flag to Start Previous Operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Wait until Interrupt Flag is set again */
	while(!GET_BIT(TWCR,TWCR_TWINT));

	/* Check the previous operation is start condition */
	if((TWSR & 0xF8) != REP_START_ACK)
	{
		Local_ErrStatus = RepeatedStartErr;
	}

	return Local_ErrStatus;
}

// Send Address packet : Send Slave Address with write request //
TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus = NoErr;

	/* Set Slave Address in 7 MSB in TWDR & clear the first bit for Write Request */
	TWDR = Copy_u8SlaveAddress << 1;
	CLR_BIT(TWDR,0);

	/* Clear Start Condition Bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* Clear Interrupt Flag to Start Previous Operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Wait until Interrupt Flag is set again */
	while(!GET_BIT(TWCR,TWCR_TWINT));

	/* Check the previous operation is start condition */
	if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrStatus = SlaveAddWithWriteErr;
	}

	return Local_ErrStatus;
}

// Send Address packet : Send Slave Address with Read request //
TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus = NoErr;

	/* Set Slave Address in 7 MSB in TWDR & clear the first bit for Read Request */
	TWDR = Copy_u8SlaveAddress << 1;
	SET_BIT(TWDR,0);

	/* Clear Start Condition Bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* Clear Interrupt Flag to Start Previous Operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Wait until Interrupt Flag is set again */
	while(!GET_BIT(TWCR,TWCR_TWINT));

	/* Check the previous operation is start condition */
	if((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrStatus = SlaveAddWithReadErr;
	}

	return Local_ErrStatus;
}

// Send Data packet according to Slave Address //
TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoErr;

	/* Set data Byte on the bus */
	TWDR = Copy_u8DataByte;

	/* Clear Interrupt Flag to Start Previous Operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Wait until Interrupt Flag is set again */
	while(!GET_BIT(TWCR,TWCR_TWINT));

	/* Check the previous operation is start condition */
	if((TWSR & 0xF8) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrStatus = MasterWriteByteErr;
	}

	return Local_ErrStatus;
}

// Receive Data packet according to Slave Address //
TWI_ErrStatus TWI_MasterReadDataByte(u8* Copy_pu8DataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoErr;

	/* Clear Interrupt Flag to Start Previous Operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Wait until Interrupt Flag is set again */
	while(!GET_BIT(TWCR,TWCR_TWINT));

	/* Check the previous operation is start condition */
	if((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrStatus = MasterReadByteErr;
	}
	else
	{
		/* Save Read Value */
		*Copy_pu8DataByte = TWDR;
	}

	return Local_ErrStatus;
}

// Send Stop Condition //
void TWI_SendStopCondition(void)
{
	/* Send Start Condition on the bus */
	SET_BIT(TWCR,TWCR_TWSTO);

	/* Clear Interrupt Flag to Start Previous Operation */
	SET_BIT(TWCR,TWCR_TWINT);
}
