/*
 * ws2812.c
 *
 *  Created on: Feb 1, 2023
 *      Author: crazy
 */
#include "ws2812.h"
//----------------------------------------------------------------------------
extern TIM_HandleTypeDef htim2;
extern uint8_t key[5][8];
//----------------------------------------------------------------------------
uint32_t BUF_DMA [ARRAY_LEN] = {0};
uint16_t pos_ws;
uint8_t led[5][8]={{0,1,2,3,4,5,6,7},
					{8,9,10,11,12,13,14,15},
					{16,17,18,19,20,21,22,23},
					{24,25,26,27,28,29,30,31},
					{32,33,34,35,36,37,38,39}};

void ws2812_init(void)
{
  int i;
  for(i=DELAY_LEN;i<ARRAY_LEN;i++) BUF_DMA[i] = LOW;
}

void ws2812_pixel_rgb_to_buf_dma(uint8_t Rpixel , uint8_t Gpixel, uint8_t Bpixel, uint16_t posX)
{
  volatile uint16_t i;
  for(i=0;i<8;i++)
  {
    if (BitIsSet(Rpixel,(7-i)) == 1)
    {
      BUF_DMA[DELAY_LEN+posX*24+i+8] = HIGH;
    }else
    {
      BUF_DMA[DELAY_LEN+posX*24+i+8] = LOW;
    }
    if (BitIsSet(Gpixel,(7-i)) == 1)
    {
      BUF_DMA[DELAY_LEN+posX*24+i+0] = HIGH;
    }else
    {
      BUF_DMA[DELAY_LEN+posX*24+i+0] = LOW;
    }
    if (BitIsSet(Bpixel,(7-i)) == 1)
    {
      BUF_DMA[DELAY_LEN+posX*24+i+16] = HIGH;
    }else
    {
      BUF_DMA[DELAY_LEN+posX*24+i+16] = LOW;
    }

  }

}

uint16_t ws_num(uint8_t row_n, uint8_t col_n){
	switch (row_n) {
		case 0:
			pos_ws = col_n;
			break;
		case 1:
			pos_ws = (2*7+1)-col_n;
			break;
		case 2:
			pos_ws = (2*8)+col_n;
			break;
		case 3:
			pos_ws = (4*8-1)-col_n;
			break;
		case 4:
			pos_ws = (4*8)+col_n;
			break;
		default:
			break;
	}
	return pos_ws;
}

uint16_t ws_num_led(uint8_t row_n, uint8_t col_n){
	switch (row_n) {
		case 0:
			pos_ws = (5*8)-key[row_n][col_n];
			break;
		case 1:
		//	pos_ws = (4*8+1)-key[row_n][col_n];
			pos_ws = (2*8-1)+key[row_n][col_n];
			break;
		case 2:
		//	pos_ws = (3*8-1)-col_n;
			pos_ws = (5*8) - key[row_n][col_n];

			break;
		case 3:
			pos_ws = key[row_n][col_n]-(2*8+1);
			break;
		case 4:
		//	pos_ws = (5*8)-col_n-key[row_n][col_n];
			pos_ws = (5*8)-key[row_n][col_n];
			break;
		default:
			break;
	}
	return pos_ws;
}

void led_specific(uint8_t *k_pointer, uint8_t *l_pointer){
	for(uint8_t i=0;i=7;i++){
		for(uint8_t j=0; j=4; j++){

		}
	}
}


