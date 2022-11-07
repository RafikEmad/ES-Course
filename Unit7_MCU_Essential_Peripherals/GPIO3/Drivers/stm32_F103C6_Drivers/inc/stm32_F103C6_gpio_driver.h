/*
 * stm32_F103C6_gpio_driver.h
 *
 *  Created on: Nov 6, 2022
 *      Author: rafik
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_

//includes
#include "stm32f103x6.h"

//-----------------------

//Config Structure

typedef struct
{
	uint16_t GPIO_PinNumber; //specifies the GPIO pins to be configured.
							 //this parameter can be a value of @ref GPIO_PINS_define
	uint8_t  GPIO_MODE	   ; //specifies the operating mode for the selected pins.
	 	 	 	 	 	 	 //this parameter can be a value of @ref GPIO_MODE_define
	uint8_t  GPIO_OUTPUT_SPEED	   ; //specifies the speed for the selected pins.
		 	 	 	 	 	 	 //this parameter can be a value of @ref GPIO_SPEED_define


}GPIO_PinConfig_t;

//@ref GPIO_PIN_state
#define GPIO_PIN_SET	1
#define GPIO_PIN_RESET	0

//@ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_ENABLED	1
#define GPIO_RETURN_LOCK_ERROR		0

//======================
//Macro Configuration References
//======================

//@ref GPIO_PINS_define
#define GPIO_PIN_0			((uint16_t)0x0001)
#define GPIO_PIN_1			((uint16_t)0x0002)
#define GPIO_PIN_2			((uint16_t)0x0004)
#define GPIO_PIN_3			((uint16_t)0x0008)
#define GPIO_PIN_4			((uint16_t)0x0010)
#define GPIO_PIN_5			((uint16_t)0x0020)
#define GPIO_PIN_6			((uint16_t)0x0040)
#define GPIO_PIN_7			((uint16_t)0x0080)
#define GPIO_PIN_8			((uint16_t)0x0100)
#define GPIO_PIN_9			((uint16_t)0x0200)
#define GPIO_PIN_10			((uint16_t)0x0400)
#define GPIO_PIN_11			((uint16_t)0x0800)
#define GPIO_PIN_12			((uint16_t)0x1000)
#define GPIO_PIN_13			((uint16_t)0x2000)
#define GPIO_PIN_14			((uint16_t)0x4000)
#define GPIO_PIN_15			((uint16_t)0x8000)
#define GPIO_PIN_All		((uint16_t)0xFFFF)

#define GPIO_PIN_MASK		0x0000FFFFu


//@ref GPIO_MODE_define
//0: Analog mode
//1: Floating input (reset state)
//2: input with pull up
//3: pull down
//4: general purpose output push-pull
//5: general purpose output open-drain
//6: Alternate function output push-pull
//7: Alternate function output open-drain
//8: Alternate function INPUT
#define GPIO_MODE_Analog			0x00000000u //analog mode
#define GPIO_MODE_INPUT_FLO			0x00000001u //floating input
#define GPIO_MODE_INPUT_PU			0x00000002u //input with pull up
#define GPIO_MODE_INPUT_PD			0x00000003u //input with pull down
#define GPIO_MODE_OUTPUT_PP			0x00000004u //general purpose output push pull
#define GPIO_MODE_OUTPUT_OD			0x00000005u //general purpose output open drain
#define GPIO_MODE_OUTPUT_AF_PP		0x00000006u //alternate function output push pull
#define GPIO_MODE_OUTPUT_AF_OD		0x00000007u //alternate function output open drain
#define GPIO_MODE_AF_INPUT			0x00000008u //alternate function input


//@ref GPIO_SPEED_define
//1: output mode,max speed 10 MHz
//2: output mode,max speed 2 MHz
//3: output mode,max speed 50 MHz

#define GPIO_SPEED_10M		0x00000001u
#define GPIO_SPEED_2M		0x00000002u
#define GPIO_SPEED_50M		0x00000003u



//====================================
//APIs supported by "MCAL GPIO DRIVER"
//====================================

void MCAL_GPIO_Init (GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig);

void MCAL_GPIO_DeInit (GPIO_TypeDef* GPIOx);

uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef* GPIOx,uint16_t PinNumber);

uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef* GPIOx);

void MCAL_GPIO_WritePin (GPIO_TypeDef* GPIOx,uint16_t PinNumber,uint8_t Value);

void MCAL_GPIO_WritePort (GPIO_TypeDef* GPIOx,uint16_t Value);

void MCAL_GPIO_TogglePin (GPIO_TypeDef* GPIOx,uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin (GPIO_TypeDef* GPIOx,uint16_t PinNumber);

#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
