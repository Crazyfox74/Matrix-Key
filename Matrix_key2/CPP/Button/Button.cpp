/*
 * Button.cpp
 *
 *  Created on: 17 февр. 2023 г.
 *      Author: crazy
 */

#include "Button.h"

//extern WS2812 led;
WS2812 led1;


extern uint8_t key[5][8];

Button::Button() {
	// TODO Auto-generated constructor stub
	cnt_scan = 0;
	col_numb = 0;
	row_numb = 0;
	st_kbd = 0;
	cnt_tick = 0;
	row_data = 0xFF;
	n_col = 0;
	n_row = 0;

}


void Button::COL_SCAN(){
	if(cnt_scan > 0)	cnt_scan--;
		else cnt_scan = 0;
	switch (col_numb){
	case 0:
		M_COL_A;
		break;
	case 1:
		M_COL_B;
		break;
	case 2:
		M_COL_C;
		break;
	case 3:
		M_COL_D;
		break;
	case 4:
		M_COL_E;
		break;
	case 5:
		M_COL_F;
		break;
	case 6:
		M_COL_G;
		break;
	case 7:
		M_COL_DP;
		break;
	}
}


void Button::ROW_SCAN(){
	if((GPIOA->IDR & (1 << 8)) == 0) {row_data &= 0xFE;	} else {	row_data |= 0x01;}
			if((GPIOB->IDR & (1 << 15)) == 0) {row_data &= 0xFD;	} else {	row_data |= 0x02;}
			if((GPIOB->IDR & (1 << 14)) == 0) {row_data &= 0xFB;	} else {	row_data |= 0x04;}
			if((GPIOB->IDR & (1 << 13)) == 0) {row_data &= 0xF7;	} else {	row_data |= 0x08;}
			if((GPIOB->IDR & (1 << 12)) == 0) {row_data &= 0xEF;	} else {	row_data |= 0x10;}
			switch(row_data){
			case 0xFE:
			case 0xFD:
			case 0xFB:
			case 0xF7:
			case 0xEF:
				switch(but_status){
				case 0:
					but_status = 1;
					cnt_scan = 10;
					break;
				case 1:
					if(cnt_scan == 0){
						but_status = 2;

						switch(row_data){
						case 0xFE:
							n_row = 4;
							break;
						case 0xFD:
							n_row = 3;
							break;
						case 0xFB:
							n_row = 2;
							break;
						case 0xF7:
							n_row = 1;
							break;
						case 0xEF:
							n_row = 0;
							break;
						}
						n_col = col_numb;
						b_butpres = true;
						b_enprint = true;
					}
					break;
				}
				break;

			case 0xFF:	// когда ни одна кнопка не нажата
				switch(but_status){
				case 0:
					col_numb++;
					if(col_numb == COL_COUNT){
						col_numb = 0;
					}
					break;
				case 2:
					but_status = 3;
					cnt_scan = 10;
					break;
				case 3:
					if(cnt_scan == 0){
						but_status = 0;
						b_butpres = false;

					}
					break;
				}
					break;
			}
}


void Button::Print_Key(){
	if(b_enprint == true){
		sprintf(key_print,"%d\r\n",key[n_row][n_col]);
		HAL_UART_Transmit(&huart1, (uint8_t*)&key_print, strlen(key_print), 100);
		b_enprint = false;
	}
}

void Button::Key_led_on(){
	if(b_butpres == true){
		led1.WS2812_LED_ON(n_row, n_col);
		b_butpres = false;
	}
}

void Button::Key_led_off(){
	if(but_status == 0){
		led1.WS2812_LED_OFF();
	}
}






