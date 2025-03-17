/*
 * DHT11.h
 *
 *  Created on: Mar 10, 2025
 *      Author: denni
 */

#ifndef DHT11_HAL_INC_DHT11_H_
#define DHT11_HAL_INC_DHT11_H_
#endif /* DHT11_HAL_INC_DHT11_H_ */

#include "stm32f103xb.h"

void DHT11_Start (void);
uint8_t DHT11_Check_Response (void);
uint32_t DHT11_Read8Bit(void);
uint8_t DHT11_Read(void);
uint64_t DHT11_ReadAll(void);
