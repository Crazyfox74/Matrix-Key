/*
 * WS2812.h
 *
 *  Created on: Feb 15, 2023
 *      Author: crazy
 */

#ifndef SRC_WS2812_H_
#define SRC_WS2812_H_

#include "stm32f0xx_hal.h"
#include "Button/Button.h"

#define DELAY_LEN 48
#define LED_COUNT 90
#define ARRAY_LEN DELAY_LEN + LED_COUNT*24
#define HIGH 41
#define LOW 19

#define BitIsSet(reg, bit) ((reg & (1<<bit)) != 0)



extern TIM_HandleTypeDef htim2;
extern DMA_HandleTypeDef hdma_tim2_ch4;


class WS2812 {
public:
	WS2812();

	void WS2812_init(void);
	void WS2812_RGB_to_DMA(uint8_t BlBite, uint8_t ReBite, uint8_t GrBite, uint16_t _posX);
	uint16_t WS_NUM_TO_LED(uint8_t row, uint8_t col);

	void WS2812_Flashing(void);
	void WS2812_LED_ON(uint8_t led_row, uint8_t led_col);
	void WS2812_LED_OFF(void);


private:
	uint16_t posX;
	uint8_t BlBite;
	uint8_t ReBite;
	uint8_t GrBite;
	bool _led_stat;
	uint32_t BUF_DMA [ARRAY_LEN] = {0};
	uint16_t pos_ws;
	uint8_t row_to_led;
	uint8_t col_to_led;
};



#endif /* SRC_WS2812_H_ */
