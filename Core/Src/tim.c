/**
  ******************************************************************************
  * File Name          : TIM.c
  * Description        : This file provides code for the configuration
  *                      of timers instances.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "tim.h"

/* Global variables ---------------------------------------------------------*/
uint32_t _TIMREG_ = 0;









////////////////////////////////////////////////////////////////////////////////

/**
  * @brief  Initialises Basic Timer7
  * @param  None
  * @retval None
  */
void BasicTimer7_Init(void) {
  /* TIM7 interrupt Init */
  NVIC_SetPriority(TIM7_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));
  NVIC_EnableIRQ(TIM7_IRQn);

  TIM7->PSC = (RccClocks.PCLK2_Freq / 2000 ) - 1; // APB1 runs on max freq of SystemCoreClock/2 (here 90 MHz)
  // TIM7->ARR = 10000U - 1U;
  /* One pulse mode */ 
  PREG_SET(TIM7->CR1, TIM_CR1_OPM_Pos);
  /* Autoreload enable */ 
  PREG_SET(TIM7->CR1, TIM_CR1_ARPE_Pos);

  /* Interrupt enabling passes */
  PREG_SET(TIM7->DIER, TIM_DIER_UIE_Pos);
  PREG_CLR(TIM7->SR, TIM_SR_UIF_Pos);
  // PREG_SET(TIM7->CR1, TIM_CR1_CEN_Pos);

}



/**
  * @brief  Basic Timer Handler called from interrupt via flag's handler
  * @param  tim: pointer to a basic timer instance
  * @retval None
  */
void Delay2(uint16_t delay) {
  TIM7->ARR = (delay * 2) - 1;
  PREG_CLR(TIM7->SR, TIM_SR_UIF_Pos);
  PREG_SET(TIM7->CR1, TIM_CR1_CEN_Pos);
  FLAG_SET(_GLOBALREG_, _DELAYF_);

  if (FLAG_CHECK(_GLOBALREG_, _DELAYF_)) {
    __NOP();
  }

}
