/*
 * global.c
 *
 *  Created on: Dec 12, 2022
 *      Author: Luong
 */
#include "global.h"

int status = AUTO_RED_GREEN;
int status_ped = UNABLE;

int numberCounter=0;

int led=1;

// value of time duration must be: green+yellow=red
int redDuration = 5;
int greenDuration = 3;
int yellowDuration = 2;