/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : UART                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_config.h"
#include "UART_private.h"
#include "UART_register.h"
#include "UART_interface.h"




// Initialize UART //
void UART_voidInit(void)
{
	/* temp var */
	u8 Local_u8UCSRC_Value = 0;
	
	/* 
	   1- select UCSRC register  
	   2- set number of data size (character size) = 8 bits 
	   3- Asynchronous UART mode
	   4- 1 stop bit 
	   5- disable parity mode
	*/
	SET_BIT(Local_u8UCSRC_Value,7);
	SET_BIT(Local_u8UCSRC_Value,UCSZ0);
	SET_BIT(Local_u8UCSRC_Value,UCSZ1);
	
	/* determine UCSRC value */
	UCSRC = Local_u8UCSRC_Value;
	
	/* set baud rate = 9600 bit/sec */
	UBRRL = 51;
	
	/* 
		1- enable transmitter & Receiver
		2- disable double transmission speed U2X 		
	*/
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	CLR_BIT(UCSRA,U2X);
	
}


// UART send data //
void UART_voidSend(u8 data)
{
	/* check the value of UDRE bit to send new data */
	while(!GET_BIT(UCSRA,UDRE));
	
	/* determine UDR value */
	UDR = data;
	
	/* clear TXC flag */
	//SET_BIT(UCSRA,TXC);
}


// UART receive data //
u8 UART_voidRecieve(void)
{
	/* check the value of RXC bit to send new data */
	while(!GET_BIT(UCSRA,RXC));
	
	/* clear RXC flag */
	//SET_BIT(UCSRA,RXC);
	
	return UDR;
}


