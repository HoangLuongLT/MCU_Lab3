/*
 * IOLed.h
 *
 *  Created on: Oct 26, 2022
 *      Author: Luong
 */

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_

void turnOffAll();
void blinkAllRedLed();
void blinkAllYellowLed();
void blinkAllGreenLed();
void display7SEG(unsigned int led_enable,unsigned int number);
//void display7SEGValue(unsigned int number);
void turnOnOnlyRed(int road);
void turnOnOnlyYellow(int road);
void turnOnOnlyGreen(int road);
void pedGo();
void pedStop();
#endif /* INC_OUTPUT_DISPLAY_H_ */
