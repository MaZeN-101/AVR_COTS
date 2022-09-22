/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : EXTI                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

/* MCU Control Register : contains control bits for interrupt sense control (EXTI 0, EXTI 1) */
#define MCUCR 				*((volatile u8*)0X55)
#define MCUCR_ISC00			0
#define MCUCR_ISC01         1
#define MCUCR_ISC10         2
#define MCUCR_ISC11         3


/* MCU Control and Status Register : contains control bits for interrupt sense control (EXTI 2) */
#define MCUCSR 				*((volatile u8*)0X54)
#define MCUCSR_ISC2			6


/* General Interrupt Control Register Enable */
#define GICR 				*((volatile u8*)0X5B)
#define GICR_INT2			5				// Enable interrupt 2
#define GICR_INT0           6               // Enable interrupt 0
#define GICR_INT1           7               // Enable interrupt 1


/* General Interrupt Flag Register Enable */
#define GIFR 				*((volatile u8*)0X5A)
#define GIFR_INTF2			5
#define GIFR_INTF0          6        
#define GIFR_INTF1          7        


#endif
