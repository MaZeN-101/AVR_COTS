/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : ADC                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	ADC_REGISTER_H_
#define ADC_REGISTER_H_

/* ADC Multiplexer Selection Register */
#define ADMUX 				*((volatile u8*)0X27)
#define ADMUX_MUX0			0			// (MUX0 -> MUX4) select the ADC pins 
#define ADMUX_MUX1          1
#define ADMUX_MUX2          2
#define ADMUX_MUX3          3
#define ADMUX_MUX4			4
#define ADMUX_ADLAR         5			// enable the left adjestment 
#define ADMUX_REFS0         6			// (REFS0 -> REFS1) select the reference voltage 
#define ADMUX_REFS1         7


/* ADC Control and Status Register A : contains control bits for interrupt sense control (ADC 2) */
#define ADCSRA 				*((volatile u8*)0X26)
#define ADCSRA_ADPS0		0			// ADC Prescaler bit 0 
#define ADCSRA_ADPS1        1			// ADC Prescaler bit 1 
#define ADCSRA_ADPS2        2			// ADC Prescaler bit 2 
#define ADCSRA_ADIE         3			// ADC Interrupt enable
#define ADCSRA_ADIF			4			// ADC Interrupt Flag
#define ADCSRA_ADATE        5			// ADC Auto Trigger enable
#define ADCSRA_ADSC         6			// ADC start conversion 
#define ADCSRA_ADEN         7			// ADC enable


/* General Interrupt Control Register Enable */
#define SFIOR 				*((volatile u8*)0X50)
#define SFIOR_ADTS0			5
#define SFIOR_ADTS1         6           
#define SFIOR_ADTS2         7           


/* ADC HIGH : ADLAR = 0 */
#define ADCH 				*((volatile u8*)0X25)		//ADC HIGH register

/* ADC LOW : ADLAR = 1 */
#define ADCL 				*((volatile u8*)0X24)		//ADC LOW register

#endif
