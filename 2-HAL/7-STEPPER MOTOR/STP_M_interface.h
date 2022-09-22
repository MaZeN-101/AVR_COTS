/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : STP_M                ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef STP_M_INTERFACE_H_
#define STP_M_INTERFACE_H_


#define STP_M_RotateCW		0
#define STP_M_RotateCCW		1

//rotate the Stepper motor counter clock wise //
void STP_M_voidRotateCCW(void);

//rotate the Stepper motor clock wise //
void STP_M_voidRotateCW(void);

//Stop Stepper motor //
void STP_M_voidStop(void);

//rotate the Stepper motor CCW or CW with specific angle //
void STP_M_voidRotate(f32 Copy_f32Angle,u8 Copy_u8Dir);




#endif
