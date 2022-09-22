/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : SWITCH               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/




#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_


#define SW_PULL_UP_RES						0
#define SW_PULL_DOWN_RES					1
	
#define SW_TEMPERORY_SW						0
#define SW_SELF_LOCKING_SW					1	


#define SW_PRESSED							0
#define SW_NOTPRESSED						1




typedef struct 
{
	u8 Local_u8SwType;
	u8 Local_u8PullType;
	u8 Local_u8Port;
	u8 Local_u8Pin;
}SW_t;



//GET THE STATE OF THE SWITCH PRESSED OR NOT PRESSED //
u8 SW_u8GetState(SW_t *Copy_pu8SW , u8 *Copy_u8SwState);




#endif








