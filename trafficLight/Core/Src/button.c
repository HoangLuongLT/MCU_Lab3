/*
 * button.c
 *
 *  Created on: Dec 12, 2022
 *      Author: Luong
 */

#include "main.h"
#include "button.h"
#include "output_display.h"

int keyReg0[4]= {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int keyReg1[4]= {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int keyReg2[4]= {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};


int keyReg3[4]= {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int timerForKey[4] = {300,300,300,300};

int is3secondPressed[4]={0,0,0,0};

int button_flag[4]={0,0,0,0};

void subKeyProcess(int i){
	button_flag[i]=1;
}

int isButtonPress(int i){
	if(button_flag[i]==1){
		button_flag[i]=0;
		return 1;
	}
	return 0;
}

void getKeyInput(){

	for(int i=0;i<4;i++){
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];
		switch (i) {
			case 0:
				keyReg2[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port,BUTTON_1_Pin);
				break;
			case 1:
				keyReg2[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port,BUTTON_2_Pin);
				break;
			case 2:
				keyReg2[i] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port,BUTTON_3_Pin);
				break;
			case 3:
				keyReg2[i] = HAL_GPIO_ReadPin(BUTTON_4_GPIO_Port,BUTTON_4_Pin);
				break;
			default:
				break;
		}
		//Stability Signal
		if((keyReg0[i]==keyReg1[i])&&(keyReg1[i]==keyReg2[i])){
			//When signal change
			if(keyReg2[i]!=keyReg3[i]){
				keyReg3[i]=keyReg2[i];//save signal
				if(keyReg2[i]==PRESSED_STATE){
					//1->0
					if(!is3secondPressed[i]){
						//Fist press
						timerForKey[i]=300;
					}
					else{
						//Next press
						timerForKey[i]=100;
					}
					//TODO
					//Turn on button flag
					subKeyProcess(i);

				}
				else{
					//0->1
					is3secondPressed[i]=0;
				}
			}
			//When signal doesn't change
			else{
				timerForKey[i]--;
				if(timerForKey[i]==0){
					//Next cycle in press
					keyReg3[i]=NORMAL_STATE;
					is3secondPressed[i]=1;
				}
			}
		}
	}
}
