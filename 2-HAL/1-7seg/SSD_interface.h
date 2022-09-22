/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : SSD                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


#define SSD_COMMON_ANODE					0
#define SSD_COMMON_CATHODE					1

//u8 sevenSegArr[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};



typedef struct
{
	u8 Local_u8CommonType;
	u8 Local_u8Port;
	u8 Local_u8EnablePort;
	u8 Local_u8EnablePin;
}SSD_t;





//DISPLAY NUMBER ON SSD //
u8 SSD_u8SetNumber(u8 Copy_u8Number , SSD_t *Copy_pu8SSD);


//ENABLE SSD TO BE ON //
u8 SSD_u8EnableSSD(SSD_t *Copy_pu8SSD);


//DISABLE SSD TO BE OFF //
u8 SSD_u8DisableSSD(SSD_t *Copy_pu8SSD);




#endif











