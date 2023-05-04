/*
 * Button.h
 *
 *  Created on: 17 февр. 2023 г.
 *      Author: crazy
 */

#ifndef SRC_BUTTON_BUTTON_H_
#define SRC_BUTTON_BUTTON_H_

#include "stm32f0xx_hal.h"
#include "tim.h"
#include "string.h"
#include "stdio.h"
#include "WS2812/WS2812.h"

#define COL_COUNT	8

#define M_COL_A	(GPIOF->BSRR|=GPIO_BSRR_BR_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_B	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BR_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_C	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BR_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_D	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BR_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_E	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BR_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_F	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BR_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BS_11)
#define M_COL_G	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BR_15|GPIO_BSRR_BS_11)
#define M_COL_DP	(GPIOF->BSRR|=GPIO_BSRR_BS_11, GPIOB->BSRR|=GPIO_BSRR_BS_7|GPIO_BSRR_BS_6|GPIO_BSRR_BS_5|GPIO_BSRR_BS_4|GPIO_BSRR_BS_3, GPIOA->BSRR|=GPIO_BSRR_BS_15|GPIO_BSRR_BR_11)

extern UART_HandleTypeDef huart1;







class Button {
public:
	Button();

	void COL_SCAN(void);
	void ROW_SCAN(void);
	void Print_Key(void);
	void Key_led_on(void);
	void Key_led_off(void);



private:
	uint8_t cnt_scan;
	uint8_t col_numb;
	uint8_t row_numb;
	uint8_t st_kbd;
	uint8_t cnt_tick;
	uint8_t row_data;
	uint8_t but_status;
	bool b_butpres;
	bool b_enprint;
	uint8_t n_col;
	uint8_t n_row;

	char key_print[64];


};



#endif /* SRC_BUTTON_BUTTON_H_ */
