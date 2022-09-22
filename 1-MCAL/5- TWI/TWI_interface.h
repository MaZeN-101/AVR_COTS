/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : TWI                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
	NoErr,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddWithWriteErr,
	SlaveAddWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,

}TWI_ErrStatus;

// Initialize TWI Master node : if the passed address is 0, the master will not be addressed //
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);

// Initialize TWI Slave node //
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

// Send Start Condition //
TWI_ErrStatus TWI_SendStartCondition(void);

// Send repeated Start Condition //
TWI_ErrStatus TWI_SendRepeatedStart(void);

// Send Address packet : Send Slave Address with write request //
TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

// Send Address packet : Send Slave Address with Read request //
TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

// Send Data packet according to Slave Address //
TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8SlaveAddress);

// Receive Data packet according to Slave Address //
TWI_ErrStatus TWI_MasterReadDataByte(u8* Copy_u8SlaveAddress);

// Send Stop Condition //
void TWI_SendStopCondition(void);

#endif
