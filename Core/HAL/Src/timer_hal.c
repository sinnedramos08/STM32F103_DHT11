/*
 * timer_hal.c
 *
 *  Created on: Feb 9, 2025
 *      Author: denni
 */

#include "timer_hal.h"
#include "stm32f103xb.h"


void delay_us (uint32_t us){
	/*** Steps to Follow ***
	 * 1. Reset counter
	 * 2. Wait for the counter to reach the entered value. Each tick is 1 us duration
	 ***********************/
	TIM3->CR1 |= TIM_CR1_CEN;
	TIM3->CNT = 0;

	 while (TIM3->CNT < us);
}

void delay_ms (uint32_t ms){
	TIM3->CR1 |= TIM_CR1_CEN;
	TIM3->CNT = 0;

	while (TIM3->CNT < (1000*ms));
}


