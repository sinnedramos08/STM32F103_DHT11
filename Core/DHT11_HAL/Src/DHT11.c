/*
 * DHT11.c
 *
 *  Created on: Mar 10, 2025
 *      Author: denni
 */
#include "stm32f1xx_hal.h"

#include "timer_hal.h"
#include "DHT11.h"
#include "SetPin.h"


void DHT11_Start (void){
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, 0); //Write 0 for at least 18ms
	delay_ms(20);
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, 1); //Write 1 for 20us to 40us
	delay_us(10);

	//Set PIN as Input
	Set_Pin_Input(DHT11_PORT, DHT11_PIN);
	while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));	// Wait for the Pin to be low
}

uint8_t DHT11_Check_Response (void){
	uint8_t response = 0;
	delay_us(40); // wait for 40us then check if Pin is 0

	if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == 0){
		delay_us(80); // wait for 80us then check if Pin is 1

		// Check if Pin is 1
		if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)==1){
			response = 1;	// Sensor is present
		}
		else response = -1;	// Sensor is not present

	}

	// Wait for pin to go 0 again
	while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));

	return response;

}

uint8_t util_DHT11_Read_1Bit(void){
	uint8_t time = 0;
	TIM3->CR1 |= TIM_CR1_CEN;	// Enable TIM3
	TIM3->CNT = 0;				// Reset Timer Counter

	// Wait for the whole high bit time then record the time
	while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));
	time = TIM3->CNT;

	TIM3->CR1 &= ~TIM_CR1_CEN;  // Disable TIM3

    if (time > 50)     // Approximately 70us for bit 1
        return 1;
    else               // Approximately 26-28us for bit 0
        return 0;
}
uint32_t DHT11_Read8Bit(void){
	uint32_t buffer = 0;

	// Loop for 8 times to fill the buffer
	for (int i = 0; i < 8; i++){
		buffer <<=1;	// Shift Bit to right to make room for next bit
		buffer |= util_DHT11_Read_1Bit();	// Add the bits read to the buffer

		while(!HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));		// Wait for the pin to go 1 to account for the delay of next bit

	}
	return buffer;
}


