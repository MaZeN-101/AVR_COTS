/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : LED                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/







#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_



#define LED_SINK_CONNECTION							0
#define LED_SOURCE_CONNECTION						1



typedef struct
{
	u8 Local_u8ConnectionType;
	u8 Local_u8Port;
	u8 Local_u8Pin;
}LED_t;




//ENABLE LED TO BE ON//
u8 LED_u8TurnOn(LED_t *Copy_pu8LED);


//DISABLE LED TO BE OFF//
u8 LED_u8TurnOff(LED_t *Copy_pu8LED);





#endif






