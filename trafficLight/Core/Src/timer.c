/*
 * timer.c
 *
 *  Created on: Oct 24, 2022
 *      Author: Luong
 */

#include "main.h"
#include "software_timer.h"
#include "input_reading.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2){
		button_reading();
		runTimer0();
		runTimer1();
		runTimer2();
		runTimer3();
		runTimer4();
	}
}
