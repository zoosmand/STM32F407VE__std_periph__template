/**
  ******************************************************************************
  * File Name          : exti.c
  * Description        : This file provides code for the configuration
  *                      of the EXTI instances.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "exti.h"

/* Global variables ---------------------------------------------------------*/
uint32_t _EXTIREG_ = 0;









void EXTI_Init(void) {
  /* GPIO Wake-Up PA0, Touch Screen PA15 */
  /* Mode */
  // MODIFY_REG(GPIOA->MODER, (GPIO_PIN_1_Mask | GPIO_PIN_15_Mask), ((_MODE_IN << GPIO_PIN_1_Pos * 2) | (_MODE_IN << GPIO_PIN_15_Pos * 2)));
  /* Speed */
  // MODIFY_REG(GPIOA->OSPEEDR, (GPIO_PIN_1_Mask | GPIO_PIN_15_Mask), ((_SPEED_L << GPIO_PIN_1_Pos * 2) | (_SPEED_L << GPIO_PIN_15_Pos * 2)));
  /* Output type */
  // MODIFY_REG(GPIOA->OTYPER, ((_OTYPE_PP << GPIO_PIN_1_Pos) | (_OTYPE_PP << GPIO_PIN_15_Pos)), ((_OTYPE_PP << GPIO_PIN_1_Pos) | (_OTYPE_PP << GPIO_PIN_15_Pos)));
  /* Push mode */
  // MODIFY_REG(GPIOA->PUPDR, (GPIO_PIN_1_Mask | GPIO_PIN_15_Mask), ((_PUPD_NO << GPIO_PIN_1_Pos * 2) | (_PUPD_NO << GPIO_PIN_15_Pos * 2)));

  MODIFY_REG(K1_GPIO_Port->PUPDR, (K0_Pin_Mask | K1_Pin_Mask), ((_PUPD_PU << (K1_Pin_Pos * 2)) | (_PUPD_PU << (K0_Pin_Pos * 2))));
  // PREG_SET(K0_GPIO_Port->PUPDR, (_PUPD_PU << (K0_Pin_Pos * 2)));

  SET_BIT(SYSCFG->EXTICR[1], (EXTI_PE << EXTI4_Pos)); // PE4, K0 button 
  SET_BIT(SYSCFG->EXTICR[0], (EXTI_PE << EXTI3_Pos)); // PE3, K1 button 
  SET_BIT(SYSCFG->EXTICR[1], (EXTI_PC << EXTI5_Pos)); // PC5, LCD Touchscreen int


  /* EXTI channel to catch an interrupt */
  // CLEAR_BIT(EXTI->EMR, (EXTI_IMR_IM0 | EXTI_IMR_IM15));   /* clear events */
  SET_BIT(EXTI->IMR, (EXTI_IMR_IM0 | EXTI_IMR_IM3 | EXTI_IMR_IM4 | EXTI_IMR_IM5));     /* set interrupts */
  // CLEAR_BIT(EXTI->FTSR, (EXTI_IMR_IM0 | EXTI_IMR_IM15));  /* clear fallng egde */
  SET_BIT(EXTI->RTSR, EXTI_IMR_IM0 | EXTI_IMR_IM3 | EXTI_IMR_IM4);    /* set rising edge */
  SET_BIT(EXTI->FTSR, EXTI_IMR_IM5);    /* set fallng edge */

  /* Wake-Up PA0, interrupt Init */
  NVIC_SetPriority(EXTI0_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));
  NVIC_EnableIRQ(EXTI0_IRQn);

  /* Button K1 PE3, interrupt Init */
  NVIC_SetPriority(EXTI3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));
  NVIC_EnableIRQ(EXTI3_IRQn);

  /* Button K0 PE4, interrupt Init */
  NVIC_SetPriority(EXTI4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));
  NVIC_EnableIRQ(EXTI4_IRQn);

  /* Touch screen PC5, interrupt Init */
  NVIC_SetPriority(EXTI9_5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));
  NVIC_EnableIRQ(EXTI9_5_IRQn);

}




void WakeUp_Button_Handler(void) {
  // LED_Blink(LED0_Port, LED0_Pin_Pos);
}




void K0_Button_Handler(void) {
  // LED_Blink(LED0_Port, LED0_Pin_Pos);
}




void K1_Button_Handler(void) {
  // LED_Blink(LED1_Port, LED1_Pin_Pos);
}

