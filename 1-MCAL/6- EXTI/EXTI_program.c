/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : EXTI                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"


// Initialize EXTI 0 // 
void EXTI_voidInt0Init(void)
{
	/* Set Sense Control for INT0 to falling edge */
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
	
	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT0);
}

// Initialize EXTI 1 // 
void EXTI_voidInt1Init(void)
{
	/* Set Sense Control for INT1 to falling edge */
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
	
	/* Peripheral interrupt enable for INT1 */
	SET_BIT(GICR,GICR_INT1);
}

// Initialize EXTI 2 // 
void EXTI_voidInt2Init(void)
{
	/* Set Sense Control for INT0 to falling edge */
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
	
	/* Peripheral interrupt enable for INT0 */
	SET_BIT(GICR,GICR_INT2);
}

