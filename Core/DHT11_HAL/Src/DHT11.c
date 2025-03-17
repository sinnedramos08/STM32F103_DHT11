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

#define DHT11_OLD		1
#define my_code			1

void DHT11_Start (void){
	Set_Pin_Output (DHT11_PORT, DHT11_PIN);
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, 0); //Write 0 for at least 18ms
	delay_ms(20);
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, 1); //Write 1 for 20us to 40us
	delay_us(10);

	//Set PIN as Input
	Set_Pin_Input(DHT11_PORT, DHT11_PIN);
	//while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));	// Wait for the Pin to be low
}

uint8_t DHT11_Check_Response (void){
	uint8_t response = 0;
	//uint8_t time = 0;


	delay_us(40); // wait for 40us then check if Pin is 0

	if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == 0){
		delay_us(80); // wait for 80us then check if Pin is 1

		// Check if Pin is 1
		if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)==1){
			response = 1;	// Sensor is present
		}
		else response = -1;	// Sensor is not present

	}

	//while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));
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

    if (time > 60)     // Approximately 70us for bit 1
        return 1;
    else               // Approximately 26-28us for bit 0
        return 0;
}

uint32_t DHT11_Read8Bit(void){
	uint32_t buffer = 0b0;


	// Loop for 8 times to fill the buffer
#if 0
	for (int i = 0; i < 8; i++){

			buffer <<=1;	// Shift Bit to right to make room for next bit
			buffer |= util_DHT11_Read_1Bit();	// Add the bits read to the buffer

			while(!HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));		// Wait for the pin to go 1 to account for the delay of next bit
	}
	return buffer <<= 1;
#endif

#if 1
	//uint8_t bit = util_DHT11_Read_1Bit();
	for (int i = 0; i < 8; i++){
		if (util_DHT11_Read_1Bit()){	// if read 1
			buffer |= (1<<(7-i));
		}
		else{		// if read 0
			buffer &= ~(1<<(7-i));
		}
		while(!HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));

	}
	return buffer;
#endif
}

uint64_t DHT11_ReadAll(void) {
	while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));	// Wait until Pin is Low then start data transfer

	uint64_t buffer = 0;  // Initialize a 64-bit variable (only 40 bits used)

    for (int i = 0; i < 40; i++) {
        buffer <<= 1;  // Shift left to make space for the next bit
        buffer |= util_DHT11_Read_1Bit();  // Read one bit and store in buffer
        while(!HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));
    }

    buffer<<=1;		// Shift 1 to left since there is another 0 read at the start

    return buffer;  // Return the full 40-bit data
}
