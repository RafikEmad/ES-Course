/*
 * stm32_F103C6_gpio_driver.c
 *
 *  Created on: Nov 6, 2022
 *      Author: rafik
 */
#include "stm32_F103C6_gpio_driver.h"

uint8_t Get_CRHL_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
			return 4;
			break;
	case GPIO_PIN_2:
			return 8;
			break;
	case GPIO_PIN_3:
			return 12;
			break;
	case GPIO_PIN_4:
			return 16;
			break;
	case GPIO_PIN_5:
			return 20;
			break;
	case GPIO_PIN_6:
			return 24;
			break;
	case GPIO_PIN_7:
			return 28;
			break;
	case GPIO_PIN_8:
			return 0;
			break;
	case GPIO_PIN_9:
			return 4;
			break;
	case GPIO_PIN_10:
			return 8;
			break;
	case GPIO_PIN_11:
			return 12;
			break;
	case GPIO_PIN_12:
			return 16;
			break;
	case GPIO_PIN_13:
			return 20;
			break;
	case GPIO_PIN_14:
			return 24;
			break;
	case GPIO_PIN_15:
			return 28;
			break;

	}
	return 0;
}


/**=================================
 * @Fn			-MCAL_GPIO_Init
 * @brief		-Initializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param[in]	-GPIOx where x can be (A..E depending on the device used) to select the gpio peripheral
 * @param[in]   -Pinconfig pointer to a GPIO_PinCOnfig_t structure that contains the configuration information for the specified GPIO PIN.
 * @retval		-none
 * Note
 *
 */

void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig)
{
	//Port configuration register low (GPIOx_CRL) configure PINS from 0>>>7
	//Port configuration register High (GPIOx_CRH) configure PINS from 8>>>15
	volatile uint32_t* configregister = NULL;
	uint8_t PIN_Config = 0;

	configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH;

	//clear CNF8[1:0] MODE8[1:0]
	(*configregister) &= ~(0xf << Get_CRHL_Position(PinConfig->GPIO_PinNumber));


	//if Pin is output
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
	{
		//Set CNF8[1:0] MODE8[1:0]
		PIN_Config = ((((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_OUTPUT_SPEED)) &0x0f);
	}
	//if Pin is input
	else //MODE = 00:input mode (reset state)
	{
		if ((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog))
		{
			//Set CNF8[1:0] MODE8[1:0]00
			PIN_Config = ((((PinConfig->GPIO_MODE) << 2) | 0x0) &0x0f);
		}
		else if (PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)//consider it as input floating
		{
			//Set CNF8[1:0] MODE8[1:0]00
			PIN_Config = ((((GPIO_MODE_INPUT_FLO) << 2) | 0x0) &0x0f);
		}
		else //PU PD input
		{
			PIN_Config = ((((GPIO_MODE_INPUT_PU) << 2) | 0x0) &0x0f);

			if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				//PxODR =1 Input pull up: table.20 port bit configuration table
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}
			else
			{
				//PxODR =1 Input pull up: table.20 port bit configuration table
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}
	//write on CRL or CRH
	(*configregister) |= ((PIN_Config) << Get_CRHL_Position(PinConfig->GPIO_PinNumber));
}

/**=================================
 * @Fn			-MCAL_GPIO_DeInit
 * @brief		-reset all the GPIO Registers
 * @param[in]	-GPIOx where x can be (A..E depending on the device used) to select the gpio peripheral
 * @retval		-none
 * Note			-none
 */

void MCAL_GPIO_DeInit (GPIO_TypeDef* GPIOx)
{
	/*GPIOx->BRR = 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->CRH = 0x44444444;
	GPIOx->CRL = 0x44444444;
	//GPIOx->IDR = ;(READ only)
	GPIOx->LCKR = 0x00000000;
	GPIOx->ODR = 0x00000000;*/

	//or you can use the reset controller
	//APB2 peripheral reset register (RCC_APB2RSTR)
	//Set and Cleared by Software
	if (GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}
}

/**=================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief		-Read Specific PIN
 * @param[in]	-GPIOx where x can be (A..E depending on the device used) to select the gpio peripheral
 * @param[in]	-PinNumber: Set Pin Number According GPIO_PINS_define
 * @retval		-the input pin value (two values based on @ref GPIO_PIN_state)
 * Note			-none
 */


uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	uint8_t bitstatus;
	if(((GPIOx->IDR) & PinNumber)!= (uint32_t)GPIO_PIN_RESET)
	{
		bitstatus = GPIO_PIN_SET;
	}
	else
	{
		bitstatus = GPIO_PIN_RESET;
	}
	return bitstatus;
}

/**=================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief		-Read the input port value
 * @param[in]	-GPIOx where x can be (A..E depending on the device used) to select the gpio peripheral
 * @retval		-the input port value
 * Note			-none
 */


uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef* GPIOx)
{
	uint16_t port_value;
	port_value = (uint16_t)(GPIOx->IDR);
	return port_value;
}

/**=================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief		-write on specific input pin
 * @param[in]	-GPIOx where x can be (A..E depending on the device used) to select the gpio peripheral
 * @param[in]	-PinNumber: specifies the port bit to read. Set by @GPIO_PINS_define
 * @param[in]	-Value: Pin Value
 * @retval		-none
 * Note			-none
 */


void MCAL_GPIO_WritePin (GPIO_TypeDef* GPIOx,uint16_t PinNumber,uint8_t Value)
{
	if(Value != GPIO_PIN_RESET)
	{
		//GPIOx.ODR |= PinNumber;
		//or
		GPIOx->BSRR = (uint32_t)PinNumber;
	}
	else
	{
		GPIOx->BRR = (uint32_t)PinNumber;
	}
}
/**=================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief		-write on output port
 * @param[in]	-GPIOx where x can be (A..E depending on the device used) to select the gpio peripheral
 * @retval		-none
 * Note			-none
 */

void MCAL_GPIO_WritePort (GPIO_TypeDef* GPIOx,uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;
}
/**=================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief		-Toggle the specified gpiopin
 * @param[in]	-GPIOx where x can be (A..E depending on the device used) to select the gpio peripheral
 * @param[in]	-PinNumber: specifies the port bit to read. Set by @GPIO_PINS_define
 * @retval		-none
 * Note			-none
 */
void MCAL_GPIO_TogglePin (GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}
/**=================================
 * @Fn			-MCAL_GPIO_LockPin
 * @brief		-the locking mechanism allows the IO configuration to be frozen
 * @param[in]	-GPIOx where x can be (A..E depending on the device used) to select the gpio peripheral
 * @param[in]	-PinNumber: specifies the port bit to read. Set by @GPIO_PINS_define
 * @retval		-OK if oin config is locked or ERROR if pin not locked (OK & ERROR are defined @ref GPIO_RETURN_LOCK)
 * Note			-none
 */
uint8_t MCAL_GPIO_LockPin (GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	//Set LCKK[16]
	volatile uint32_t tmp = 1<<16;
	//Set the LCKy
	tmp |= PinNumber;
	//write 1
	GPIOx->LCKR = tmp;
	//write 0
	GPIOx->LCKR = PinNumber;
	//write 1
	GPIOx->LCKR = tmp;
	//read 0
	tmp = GPIOx->LCKR;
	//optional
	if((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_RETURN_LOCK_ENABLED;
	}
	else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}


}
