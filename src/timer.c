/*
 * timer.c
 *
 *  Created on: 24 Ara 2020
 *      Author: Arge_Ayþe
 */


#include "timer.h"


/*      	(Period) * (Prescaler)		5000 * 16800
*	sn   = ------------------------- = ---------------- = 500 ms
*      			(Clock Speed)			   168 MHz
*
*/
void Time_Init(void)
{
	// Time settings

	TIM_TimeBaseInitTypeDef  timer_Config;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	timer_Config.TIM_ClockDivision = TIM_CKD_DIV1;
	timer_Config.TIM_CounterMode = TIM_CounterMode_Up ;
	timer_Config.TIM_Period = 5000 - 1;       //the period value is 5000
	timer_Config.TIM_Prescaler = 16800 -1 ;   //the prescaler value is 16800
	timer_Config.TIM_RepetitionCounter = 1-1;

	TIM_TimeBaseInit(TIM1 , &timer_Config);

	// Timer interrupt settings

	NVIC_InitTypeDef  NVIC_Config;

	NVIC_Config.NVIC_IRQChannel=TIM1_UP_TIM10_IRQn ;
	NVIC_Config.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Config.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_Config.NVIC_IRQChannelSubPriority=0;


	NVIC_Init(&NVIC_Config);

	TIM_ClearITPendingBit(TIM1 , TIM_IT_Update);
	TIM_ClearFlag(TIM1 , TIM_FLAG_Update);

	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);

	TIM_Cmd(TIM1,ENABLE);

}

void TIM1_UP_TIM10_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM1 , TIM_IT_Update)==SET)
	{
		TIM_ClearITPendingBit(TIM1 , TIM_IT_Update);
		TIM_ClearFlag(TIM1 , TIM_FLAG_Update);

		GPIO_ToggleBits(GPIOD , LEDS);
	}
}
