/*
 * ws2812.h
 *
 *  Created on: Feb 1, 2023
 *      Author: crazy
 */

#ifndef SRC_WS2812_WS2812_H_
#define SRC_WS2812_WS2812_H_
//--------------------------------------------------
#include "stm32f0xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
//--------------------------------------------------
#define DELAY_LEN 48
#define LED_COUNT 90
#define ARRAY_LEN DELAY_LEN + LED_COUNT*24
#define HIGH 41
#define LOW 19
void ws2812_init(void);
void ws2812_pixel_rgb_to_buf_dma(uint8_t Rpixel , uint8_t Gpixel, uint8_t Bpixel, uint16_t posX);
uint16_t ws_num(uint8_t row_n, uint8_t col_n);
uint16_t ws_num_led(uint8_t row_n, uint8_t col_n);
void led_specific(uint8_t *k_pointer, uint8_t *l_pointer);
//--------------------------------------------------
#define BitIsSet(reg, bit) ((reg & (1<<bit)) != 0)
//--------------------------------------------------
//--------------------------------------------------
#endif /* SRC_WS2812_WS2812_H_ */
