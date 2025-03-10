/*
 * SetPin.c
 *
 *  Created on: Mar 10, 2025
 *      Author: denni
 */


#include "stm32f1xx_hal.h"
#include "SetPin.h"

#include "DHT11.h"

void Set_Pin_Input(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN){
	GPIO_InitTypeDef GPIO_InitStruct = {0}; // Create Struct for configuring Pin Modes

	// Struct for the Pin Modes
	GPIO_InitStruct.Pin = GPIO_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	// Configure/Initialize GPIO based on Struct above
	HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);

}

void Set_Pin_Output(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN){
	GPIO_InitTypeDef GPIO_InitStruct = {0}; // Create Struct for configuring Pin Modes

	// Struct for the Pin Modes
	GPIO_InitStruct.Pin = GPIO_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	// Configure/Initialize GPIO based on Struct above
	HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);

}
