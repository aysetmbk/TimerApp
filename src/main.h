
/*
 * main.h
 *
 *  Created on: 24 Ara 2020
 *      Author: Arge_Ayþe
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "stm32f4xx.h"

#define GREEN_PORT    	GPIOD
#define GREEN_PIN	    GPIO_Pin_12

#define ORANGE_PORT     GPIOD
#define ORANGE_PIN	    GPIO_Pin_13

#define RED_PORT    	GPIOD
#define RED_PIN	  		GPIO_Pin_14

#define BLUE_PORT    	GPIOD
#define BLUE_PIN	 	GPIO_Pin_15


void LED_Init(void);
void Initials(void);



#endif /* MAIN_H_ */
