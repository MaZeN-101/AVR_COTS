/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : DIO                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

//DIO GROUP A REGISTERS//
#define PINA 			*((volatile u8*)0X39)
#define PORTA 			*((volatile u8*)0X3B)

//DIO GROUP B REGISTERS//
#define PINB 			*((volatile u8*)0X36)
#define PORTB			*((volatile u8*)0X38)

//DIO GROUP C REGISTERS//
#define PINC		 	*((volatile u8*)0X33)
#define PORTC 			*((volatile u8*)0X35)

//DIO GROUP D REGISTERS//
#define PIND 			*((volatile u8*)0X30)
#define PORTD 			*((volatile u8*)0X32)



#endif

