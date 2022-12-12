/*
 * fsm_pedestrian.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Luong
 */
#include "fsm_pedestrian.h"
#include "global.h"
#include "output_display.h"
#include "software_timer.h"
#include "button.h"

int change = 1;

void fsm_pedestrian_processing(){
	switch (status_ped) {
		case PED_STOP:
			if(change==1){
				pedStop();
				change=0;
			}
			if(status<=4&&status>=1){
				if(numberCounter<=5&&numberCounter>=1){
					status_ped=PED_GO;
					change=1;
				}
			}
			else{
				status_ped=UNABLE;
			}

			break;
		case PED_GO:
			if(change==1){
				pedGo();
				change=0;
			}
			if(status<=4&&status>=1){
				if(numberCounter>=6||numberCounter==0){
					status_ped=PED_STOP;
					change =1;
				}
			}
			else{
				status_ped=UNABLE;
			}

			break;
		case UNABLE:
			change=1;
			pedStop();
			break;
		default:
			break;
	}
}

