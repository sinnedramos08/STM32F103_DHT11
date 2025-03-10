/*
 * SetPin.h
 *
 *  Created on: Mar 10, 2025
 *      Author: denni
 */

#ifndef HAL_INC_SETPIN_H_
#define HAL_INC_SETPIN_H_



#endif /* HAL_INC_SETPIN_H_ */

#define DHT11_PORT	GPIOA
#define DHT11_PIN	GPIO_PIN_0


void Set_Pin_Input(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN);
void Set_Pin_Output(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_PIN);
