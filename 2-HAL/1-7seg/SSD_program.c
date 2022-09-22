/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : SSD                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/





#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"


u8 sevenSegArr[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};



//DISPLAY NUMBER ON SSD //
u8 SSD_u8SetNumber(u8 Copy_u8Number , SSD_t *Copy_pu8SSD)
{
	
	u8 Local_u8ErrorState = 0;
	
	if (Copy_pu8SSD != NULL)
	{
		switch(Copy_pu8SSD->Local_u8CommonType)
		{
			case SSD_COMMON_ANODE:
				
				DIO_u8SetPortValue(Copy_pu8SSD->Local_u8Port , ~sevenSegArr[Copy_u8Number]);
				
				break;
			case SSD_COMMON_CATHODE:
				
				DIO_u8SetPortValue(Copy_pu8SSD->Local_u8Port , sevenSegArr[Copy_u8Number]);
				
				break;
			default:
				Local_u8ErrorState = 1;
		}
	}
	else 
	{
		Local_u8ErrorState = 1;
	}
	
	return Local_u8ErrorState;
	
}





//ENABLE SSD TO BE ON //
u8 SSD_u8EnableSSD(SSD_t *Copy_pu8SSD)
{
	
	u8 Local_u8ErrorState = 0;
	
	if (Copy_pu8SSD != NULL)
	{
		switch(Copy_pu8SSD->Local_u8CommonType)
		{
			case SSD_COMMON_ANODE:
				DIO_u8SetPinValue(Copy_pu8SSD->Local_u8EnablePort , Copy_pu8SSD->Local_u8EnablePin , DIO_u8PIN_HIGH);
				
				break;
			case SSD_COMMON_CATHODE:
				DIO_u8SetPinValue(Copy_pu8SSD->Local_u8EnablePort , Copy_pu8SSD->Local_u8EnablePin , DIO_u8PIN_LOW);
			
				break;
			default:
				Local_u8ErrorState = 1;
		}
	}
	else 
	{
		Local_u8ErrorState = 1;
	}
	
	
	return Local_u8ErrorState;
}





//DISABLE SSD TO BE OFF //
u8 SSD_u8DisableSSD(SSD_t *Copy_pu8SSD)
{
	
	u8 Local_u8ErrorState = 0;
	
	if (Copy_pu8SSD != NULL)
	{
		switch(Copy_pu8SSD->Local_u8CommonType)
		{
			case SSD_COMMON_ANODE:
				DIO_u8SetPinValue(Copy_pu8SSD->Local_u8EnablePort , Copy_pu8SSD->Local_u8EnablePin , DIO_u8PIN_LOW);
				
				break;
			case SSD_COMMON_CATHODE:
				DIO_u8SetPinValue(Copy_pu8SSD->Local_u8EnablePort , Copy_pu8SSD->Local_u8EnablePin , DIO_u8PIN_HIGH);
			
				break;
			default:
				Local_u8ErrorState = 1;
		}
	}
	else 
	{
		Local_u8ErrorState = 1;
	}
	
	return Local_u8ErrorState;
}


		"<users>"
        "\n<user>"
        "\n<id>"
        "\n1"
        "\n</id>"
        "\n<name>"
        "\nAhmed Ali"
        "\n</name>"
        "\n<posts>"
        "\n<post>"
        "\n<body>"
        "\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."
        "\n</body>"
        "\n<topics>"
        "\n<topic>"
        "\neconomy"
        "\n</topic>"
        "\n<topic>"
        "\nfinance"
        "\n</topic>"
        "\n</topics>"
        "\n</post>"
        "\n<post>"
        "\n<body>"
        "\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."
        "\n</body>"
        "\n<topics>"
        "\n<topic>"
        "\nsolar_energy"
        "\n</topic>"
        "\n</topics>"
        "\n</post>"
        "\n</posts>"
        "\n<followers>"
        "\n<follower>"
        "\n<id>"
        "\n2"
        "\n</id>"
        "\n</follower>"
        "\n<follower>"
        "\n<id>"
        "\n3"
        "\n</id>"
        "\n</follower>"
        "\n</followers>"
        "\n</user>"
        "\n<user>"
        "\n<id>"
        "\n2"
        "\n</id>"
        "\n<name>"
        "\nYasser Ahmed"
        "\n</name>"
        "\n<posts>"
        "\n<post>"
        "\n<body>"
        "\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."
        "\n</body>"
        "\n<topics>"
        "\n<topic>"
        "\neducation"
        "\n</topic>"
        "\n</topics>"
        "\n</post>"
        "\n</posts>"
        "\n<followers>"
        "\n<follower>"
        "\n<id>"
        "\n1"
        "\n</id >"
        "\n</follower>"
        "\n</followers>"
        "\n</user>"
        "\n<user>"
        "\n<id>"
        "\n3"
        "\n</id >"
        "\n<name>"
        "\nMohamed Sherif"
        "\n</name>"
        "\n<posts>"
        "\n<post>"
        "\n<body>"
        "\nLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."
        "\n</body>"
        "\n<topics>"
        "\n<topic>"
        "\nsports"
        "\n</topic>"
        "\n</topics>"
        "\n</post>"
        "\n</posts>"
        "\n<followers>"
        "\n<follower>"
        "\n<id>"
        "\n1"
        "\n</id >"
        "\n</follower>"
        "\n</followers>"
        "\n</user>"
        "\n</users>";










