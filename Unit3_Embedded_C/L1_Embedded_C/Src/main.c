/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdbool.h>
#include "Platform_Types.h"

//register address
#define RCC_BASE 	0x40021000
#define PortA_BASE 	0x40010800

#define RCC_APB2ENR	*(volatile uint32_t *) (RCC_BASE+0x18)
#define GPIOA_CRH	*(volatile uint32_t *) (PortA_BASE+0x04)
#define GPIOA_ODR	*(volatile uint32_t *) (PortA_BASE+0x0C)

//bit fields
#define RCC_IOPAEN	(1<<2)
#define GPIO13		(1UL<<13)

typedef union{
	vuint32_t	all_fields;
	struct{
		vuint32_t	reserved:13;
		vuint32_t	P_13:1;
	}Pin;
}R_ODR_t;

volatile R_ODR_t*	R_ODR =		(volatile R_ODR_t*)(PortA_BASE + 0x0C);

int main(void)
{
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH 	&= 0xff0fffff;
	GPIOA_CRH 	|= 0x00200000;
	while(1)
	{
		R_ODR->Pin.P_13	=	1;
		for(int i=0;i<5000;i++);
		R_ODR->Pin.P_13	=	0;
		for(int i=0;i<5000;i++);
	}
	return 0;
}
