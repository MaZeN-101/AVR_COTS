/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : KPD                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_



#define KPD_PORT					DIO_u8PORTA

#define KPD_ARR_VALUES				{{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}}


#define KPD_NOT_PRESSED_KEY			0XFF


#define KPD_ROW0_PIN				DIO_u8PIN4
#define KPD_ROW1_PIN				DIO_u8PIN5
#define KPD_ROW2_PIN                DIO_u8PIN6
#define KPD_ROW3_PIN                DIO_u8PIN7

#define KPD_COL0_PIN				DIO_u8PIN3
#define KPD_COL1_PIN				DIO_u8PIN2
#define KPD_COL2_PIN                DIO_u8PIN1
#define KPD_COL3_PIN                DIO_u8PIN0

#endif
