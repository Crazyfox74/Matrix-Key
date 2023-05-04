/*
 * main.cpp
 *
 *  Created on: 21 февр. 2023 г.
 *      Author: crazy
 */

#include "main.h"
#include "Button/Button.h"
//#include  "WS2812/WS2812.h"
//WS2812 led;
Button keyboard;



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
		if(htim -> Instance == TIM3){
		//	led.WS2812_LED_OFF();
			keyboard.COL_SCAN();
			keyboard.ROW_SCAN();
		}

		if(htim->Instance == TIM7){


		}
	}

void CppMain(){



	//led.WS2812_LED_OFF();

	while(1){

		keyboard.Key_led_on();
		keyboard.Key_led_off();

		keyboard.Print_Key();


	}
}
