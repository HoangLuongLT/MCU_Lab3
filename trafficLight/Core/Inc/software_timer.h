/*
 * software_timer.h
 *
 *  Created on: Oct 26, 2022
 *      Author: Luong
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_


//Timer 0
extern int timer0_flag;
void setTimer0(int duration);

//Timer 1
extern int timer1_flag;
void setTimer1(int duration);

//Timer 2
extern int timer2_flag;
void setTimer2(int duration);

//Timer 3
extern int timer3_flag;
void setTimer3(int duration);

//Timer 4
extern int timer4_flag;
void setTimer4(int duration);

//Run timer
void runTimer();

#endif /* INC_SOFTWARE_TIMER_H_ */
