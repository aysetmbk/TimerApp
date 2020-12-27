/*
 * timer.h
 *
 *  Created on: 24 Ara 2020
 *      Author: Arge_Ayþe
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "main.h"

uint16_t LEDS = GREEN_PIN | ORANGE_PIN | RED_PIN | BLUE_PIN;

void Time_Init(void);
void TIM1_UP_TIM10_IRQHandler(void);

#endif /* TIMER_H_ */
