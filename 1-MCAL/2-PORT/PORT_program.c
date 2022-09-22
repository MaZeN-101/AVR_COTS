/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : PORT                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_register.h"
#include "PORT_interface.h"




//Initialize all ports direction//
void PORT_voidInit(void)
{
	//SET Direction of PORTA
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	
	//SET Initial value to PORTA
	PORTA = PORTA_INITAL_VALUE;
	PORTB = PORTB_INITAL_VALUE;
	PORTC = PORTC_INITAL_VALUE;
	PORTD = PORTD_INITAL_VALUE;
	
}




