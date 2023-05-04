/*
 * WS2812.cpp
 *
 *  Created on: Feb 15, 2023
 *      Author: crazy
 */

#include "WS2812.h"

uint8_t key[5][8] = {{1,2,3,4,5,6,7,8},
				  {9,10,11,12,13,14,15,16},
				  {17,18,19,20,21,22,23,24},
				  {25,26,27,28,29,30,31,32},
				  {33,34,35,36,37,38,39,40}};



WS2812::WS2812() {
	// TODO Auto-generated constructor stub
	BlBite = 0;
	ReBite = 0;
	GrBite = 0;
	posX = 0;

}

void WS2812::WS2812_init(void){
	  int i;
	  for(i=DELAY_LEN;i<ARRAY_LEN;i++) BUF_DMA[i] = LOW;
}

void WS2812::WS2812_RGB_to_DMA(uint8_t BlBite, uint8_t ReBite, uint8_t GrBite, uint16_t _posX){
	volatile uint16_t i;
	  for(i=0;i<8;i++)
	  {
	    if (BitIsSet(ReBite,(7-i)) == 1)
	    {
	      BUF_DMA[DELAY_LEN+_posX*24+i+8] = HIGH;
	    }else
	    {
	      BUF_DMA[DELAY_LEN+_posX*24+i+8] = LOW;
	    }
	    if (BitIsSet(GrBite,(7-i)) == 1)
	    {
	      BUF_DMA[DELAY_LEN+_posX*24+i+0] = HIGH;
	    }else
	    {
	      BUF_DMA[DELAY_LEN+_posX*24+i+0] = LOW;
	    }
	    if (BitIsSet(BlBite,(7-i)) == 1)
	    {
	      BUF_DMA[DELAY_LEN+_posX*24+i+16] = HIGH;
	    }else
	    {
	      BUF_DMA[DELAY_LEN+_posX*24+i+16] = LOW;
	    }

	  }
}

uint16_t WS2812::WS_NUM_TO_LED(uint8_t row, uint8_t col){
	switch (row) {
		case 0:
			pos_ws = (5*8)-key[row][col];
			break;
		case 1:
			pos_ws = (2*8-1)+key[row][col];
			break;
		case 2:
			pos_ws = (5*8) - key[row][col];
			break;
		case 3:
			pos_ws = key[row][col]-(2*8+1);
			break;
		case 4:
			pos_ws = (5*8)-key[row][col];
			break;
		default:
			break;
	}
	return pos_ws;
}

void WS2812::WS2812_LED_ON(uint8_t led_row, uint8_t led_col){
	posX = WS2812::WS_NUM_TO_LED(led_row, led_col);
	WS2812::WS2812_init();
	WS2812::WS2812_RGB_to_DMA(0, 128, 128, posX);
	HAL_TIM_PWM_Start_DMA(&htim2,TIM_CHANNEL_4,(uint32_t*)&BUF_DMA,ARRAY_LEN);
}

void WS2812::WS2812_LED_OFF(){
	WS2812::WS2812_init();
	HAL_TIM_PWM_Start_DMA(&htim2,TIM_CHANNEL_4,(uint32_t*)&BUF_DMA,ARRAY_LEN);
}
/*  if(b_butpres == true){
	  	position_ws = ws_num_led(n_row, n_col);
	    ws2812_init();
	  ws2812_pixel_rgb_to_buf_dma(0, 128, 128, position_ws);
	  HAL_TIM_PWM_Start_DMA(&htim2,TIM_CHANNEL_4,(uint32_t*)&BUF_DMA,ARRAY_LEN);
	  	  b_butpres = false;
  } if(but_status == 0){
	  ws2812_init();
	  HAL_TIM_PWM_Start_DMA(&htim2,TIM_CHANNEL_4,(uint32_t*)&BUF_DMA,ARRAY_LEN);
  }
*/

