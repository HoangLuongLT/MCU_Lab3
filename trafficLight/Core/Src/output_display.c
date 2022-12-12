/*
 * IOLed.c
 *
 *  Created on: Oct 26, 2022
 *      Author: Luong
 */


#include <output_display.h>
#include "main.h"

int ledR=1;
int ledY=1;
int ledG=1;

void blinkAllRedLed(){
	if(ledR==1){
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_RED_2_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_RED_2_Pin, GPIO_PIN_RESET);
	}
	ledR=!ledR;
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin|LED_YELLOW_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin|LED_GREEN_2_Pin, GPIO_PIN_RESET);
}
void blinkAllYellowLed(){
	if(ledY==1){
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin|LED_YELLOW_2_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin|LED_YELLOW_2_Pin, GPIO_PIN_RESET);
	}
	ledY=!ledY;
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_RED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin|LED_GREEN_2_Pin, GPIO_PIN_RESET);
}
void blinkAllGreenLed(){
	if(ledG==1){
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin|LED_GREEN_2_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin|LED_GREEN_2_Pin, GPIO_PIN_RESET);
	}
	ledG=!ledG;
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_RED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin|LED_YELLOW_2_Pin, GPIO_PIN_RESET);
}
void display7SEG(unsigned int led_enable,unsigned int number){
	switch (led_enable) {
		case 0:
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN3_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN2_Pin|EN3_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN3_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
	uint8_t led7SegHex[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	GPIOB->ODR &= 0xff80;
	GPIOB->ODR|= led7SegHex[number];
}
/*void display7SEGValue(unsigned int number){
	uint8_t led7SegHex[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	GPIOB->ODR &= 0xc07f;
	GPIOB->ODR|= (led7SegHex[number]<<7);
}*/
void turnOffAll(){
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin|LED_GREEN_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin|LED_YELLOW_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_RED_2_Pin, GPIO_PIN_RESET);
}
void turnOnOnlyRed(int road){
	if(road==0){
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, GPIO_PIN_SET);
	}else{
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_SET);
	}
}
void turnOnOnlyYellow(int road){
	if(road==0){
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, GPIO_PIN_SET);
	}else{
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_SET);
	}
}
void turnOnOnlyGreen(int road){
	if(road==0){
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, GPIO_PIN_SET);
	}else{
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_SET);
	}
}
void pedGo(){
	HAL_GPIO_WritePin(LED_PED_GPIO_Port, LED_PED_Pin, 1);
}
void pedStop(){
	HAL_GPIO_WritePin(LED_PED_GPIO_Port, LED_PED_Pin, 0);
}

