///*
// * input_processing.c
// *
// *  Created on: Oct 24, 2022
// *      Author: Luong
// */
//
//#include "main.h"
//#include "button.h"
//#include "output_display.h"
//#include "software_timer.h"
//
//enum Mode{AUTO_RED_GREEN,AUTO_RED_YELLOW,AUTO_GREEN_RED,AUTO_YELLOW_RED,MODIFY_RED, MODIFY_YELLOW, MODIFY_GREEN} ;
//enum Mode mode = AUTO_RED_GREEN;
//
//
//
//// value of time duration must be: green+yellow=red
//int redDuration = 5;
//int greenDuration = 3;
//int yellowDuration = 2;
//
//int cnt = 0;//set 1 seccond
//int change =0;//set 250 for LED 7SEG
//
//int wait_50ms[3]={1,1,1};
//
//int increase = 0;
//
//void fsm_mode_processing(void){
//	switch(mode){
//	case AUTO_RED_GREEN:
//		if(timer0_flag==1){
//			setTimer0(250);
//			switch (change) {
//				case 0:
//					display7SEG(0,(int)(redDuration-cnt)/10);
//					change++;
//
//					turnOffAll();
//					turnOnOnlyRed(0);//ROAD 0
//					turnOnOnlyGreen(1);//ROAD 1
//
//					break;
//				case 1:
//					display7SEG(1,(redDuration-cnt)%10);
//					change++;
//					break;
//				case 2:
//					display7SEG(2,(greenDuration-cnt)/10);
//					change++;
//					break;
//				case 3:
//					display7SEG(3,(greenDuration-cnt)%10);
//					change=0;
//
//					cnt++;
//
//					if(cnt==greenDuration){
//						mode=AUTO_RED_YELLOW;
//					}
//					break;
//				default:
//					break;
//			}
//		}
//		if(isButtonPress(0)&&timer1_flag==1){
//			mode=MODIFY_RED;
//			timer0_flag=1;
//			setTimer1(200);
//		}
//		break;
//	case AUTO_RED_YELLOW:
//		if(timer0_flag==1){
//			setTimer0(250);
//			switch (change) {
//				case 0:
//					display7SEG(0,(redDuration-cnt)/10);
//					change++;
//
//					turnOffAll();
//					turnOnOnlyRed(0);
//					turnOnOnlyYellow(1);
//
//					break;
//				case 1:
//					display7SEG(1,(redDuration-cnt)%10);
//					change++;
//					break;
//				case 2:
//					display7SEG(2,(redDuration-cnt)/10);
//					change++;
//					break;
//				case 3:
//					display7SEG(3,(redDuration-cnt)%10);
//					change=0;
//
//					cnt++;
//					if(cnt==redDuration){
//						mode=AUTO_GREEN_RED;
//					}
//					break;
//				default:
//					break;
//			}
//		}
//		if(isButtonPress(0)){
//			mode=MODIFY_RED;
//			timer0_flag=1;
//			setTimer1(200);
//		}
//		break;
//	case AUTO_GREEN_RED:
//		if(timer0_flag==1){
//			setTimer0(250);
//			switch (change) {
//				case 0:
//					display7SEG(0,(int)(redDuration+greenDuration-cnt)/10);
//					change++;
//
//					turnOffAll();
//					turnOnOnlyGreen(0);
//					turnOnOnlyRed(1);
//
//					break;
//				case 1:
//					display7SEG(1,(redDuration+greenDuration-cnt)%10);
//					change++;
//					break;
//				case 2:
//					display7SEG(2,(int)(2*redDuration-cnt)/10);
//					change++;
//					break;
//				case 3:
//					display7SEG(3,(2*redDuration-cnt)%10);
//					change=0;
//
//					cnt++;
//					if(cnt==(redDuration+greenDuration)){
//						mode=AUTO_YELLOW_RED;
//					}
//					break;
//				default:
//					break;
//			}
//		}
//		if(isButtonPress(0)){
//			mode=MODIFY_RED;
//			timer0_flag=1;
//			setTimer1(200);
//		}
//		break;
//	case AUTO_YELLOW_RED:
//		if(timer0_flag==1){
//			setTimer0(250);
//			switch (change) {
//				case 0:
//					display7SEG(0,(int)(2*redDuration-cnt)/10);
//					change++;
//
//					turnOffAll();
//					turnOnOnlyYellow(0);
//					turnOnOnlyRed(1);
//
//					break;
//				case 1:
//					display7SEG(1,(2*redDuration-cnt)%10);
//					change++;
//					break;
//				case 2:
//					display7SEG(2,(int)(2*redDuration-cnt)/10);
//					change++;
//					break;
//				case 3:
//					display7SEG(3,(2*redDuration-cnt)%10);
//					change=0;
//
//					cnt++;
//					if(cnt==(2*redDuration)){
//						mode=AUTO_RED_GREEN;
//						cnt=0;
//					}
//					break;
//				default:
//					break;
//			}
//		}
//		if(isButtonPress(0)){
//			mode=MODIFY_RED;
//			increase=0;
//			timer0_flag=1;
//			setTimer1(200);
//		}
//		break;
//	case MODIFY_RED:
//		if(timer0_flag==1){
//			setTimer0(250);
//			switch (change) {
//				case 0:
//					blinkAllRedLed();
//					display7SEG(0,0);
//					change++;
//					break;
//				case 1:
//					display7SEG(1,2);
//					change++;
//					break;
//				case 2:
//					blinkAllRedLed();
//					display7SEG(2,(int)((redDuration+increase)/10));
//					change++;
//					break;
//				case 3:
//					display7SEG(3,(redDuration+increase)%10);
//					change=0;
//					break;
//				default:
//					break;
//			}
//		}
//		if(isButtonPress(0)&&timer1_flag){
//			mode=MODIFY_YELLOW;
//			increase=0;
//			setTimer1(200);
//			timer0_flag=1;
//		}
//		if(isButtonPress(1)&&timer2_flag){
//			setTimer2(200);
//			if((increase+redDuration)<99)increase++;
//		}
//		if(isButtonPress(2)&&timer2_flag){
//			setTimer2(200);
//			redDuration+=increase;
//			increase=0;
//		}
//		break;
//	case MODIFY_YELLOW:
//		if(timer0_flag==1){
//			setTimer0(250);
//			switch (change) {
//				case 0:
//					blinkAllYellowLed();
//					display7SEG(0,0);
//					change++;
//					break;
//				case 1:
//					display7SEG(1,3);
//					change++;
//					break;
//				case 2:
//					blinkAllYellowLed();
//					display7SEG(2,(int)((yellowDuration+increase)/10));
//					change++;
//					break;
//				case 3:
//					display7SEG(3,(yellowDuration+increase)%10);
//					change=0;
//					break;
//				default:
//					break;
//			}
//		}
//		if(isButtonPress(0)&&timer1_flag){
//			mode=MODIFY_GREEN;
//			increase=0;
//			setTimer1(200);
//			timer0_flag=1;
//		}
//		if(isButtonPress(1)&&timer2_flag){
//			setTimer2(200);
//			if((increase+yellowDuration)<99) increase++;
//		}
//		if(isButtonPress(2)&&timer2_flag){
//			setTimer2(200);
//			yellowDuration+=increase;
//			increase=0;
//		}
//		break;
//	case MODIFY_GREEN:
//		if(timer0_flag==1){
//			setTimer0(250);
//			switch (change) {
//				case 0:
//					blinkAllGreenLed();
//					display7SEG(0,0);
//					change++;
//					break;
//				case 1:
//					display7SEG(1,4);
//					change++;
//					break;
//				case 2:
//					blinkAllGreenLed();
//					display7SEG(2,(int)((greenDuration+increase)/10));
//					change++;
//					break;
//				case 3:
//					display7SEG(3,(greenDuration+increase)%10);
//					change=0;
//					break;
//				default:
//					break;
//			}
//		}
//		if(isButtonPress(0)&&timer1_flag){
//			mode=AUTO_RED_GREEN;
//			setTimer1(200);
//			timer0_flag=1;
//
//			cnt = 0;//set 1 seccond
//			change =0;//set 250 for LED 7SEG
//
//		}
//		if(isButtonPress(1)&&timer2_flag){
//			setTimer2(200);
//			if((increase+greenDuration)<99)increase++;
//		}
//		if(isButtonPress(2)&&timer2_flag){
//			setTimer2(200);
//			greenDuration+=increase;
//			increase=0;
//		}
//		break;
//	}
//}
