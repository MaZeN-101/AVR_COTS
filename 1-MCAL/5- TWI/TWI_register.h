/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : TWI                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	TWI_REGISTER_H_
#define TWI_REGISTER_H_

/* TWI Bit Rate Register : generate CLK in the master mode */
#define TWBR 				*((volatile u8*)0X20)
#define TWBR_TWBR0			0
#define TWBR_TWBR1          1
#define TWBR_TWBR2          2
#define TWBR_TWBR3          3
#define TWBR_TWBR4          4
#define TWBR_TWBR5          5
#define TWBR_TWBR6          6
#define TWBR_TWBR7          7


/* TWI Control Register */
#define TWCR 				*((volatile u8*)0X56)
#define TWCR_TWIE			0			// TWI Interrupt Enable
#define TWCR_TWEN           2			// TWI Enable bit
#define TWCR_TWWC           3			// TWI Collision Flag
#define TWCR_TWSTO          4			// TWI Stop Condition bit
#define TWCR_TWSTA          5			// TWI Start Condition bit
#define TWCR_TWEA           6			// TWI Enable Acknowledge bit
#define TWCR_TWINT          7			// TWI Interrupt Flag


/* TWI Status Register */
#define TWSR 				*((volatile u8*)0X21)
#define TWSR_TWPS0			0			// TWI Control bit rate prescaler bit 0
#define TWSR_TWPS1          1           // TWI Control bit rate prescaler bit 1
#define TWSR_TWS3           3           // TWI Status bit 0
#define TWSR_TWS4           4           // TWI Status bit 1
#define TWSR_TWS5           5           // TWI Status bit 2
#define TWSR_TWS6           6           // TWI Status bit 3
#define TWSR_TWS7           7           // TWI Status bit 4


/* TWI Data Register */
#define TWDR 				*((volatile u8*)0X23)
#define TWDR_TWD0			0
#define TWDR_TWD1           1
#define TWDR_TWD2           2
#define TWDR_TWD3           3
#define TWDR_TWD4           4
#define TWDR_TWD5           5
#define TWDR_TWD6           6
#define TWDR_TWD7           7


/* TWI Data Register : determine slave address & recognition of a General Call */
#define TWAR 				*((volatile u8*)0X22)
#define TWAR_TWGCE			0
#define TWAR_TWA0           1
#define TWAR_TWA1           2
#define TWAR_TWA2           3
#define TWAR_TWA3           4
#define TWAR_TWA4           5
#define TWAR_TWA5           6
#define TWAR_TWA6           7

#endif
