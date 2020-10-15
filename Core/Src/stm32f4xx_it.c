/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/* External variables --------------------------------------------------------*/

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void) {
  //
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void) {
  while (1) {
    //
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void) {
  while (1) {
    //
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void) {
  while (1) {
    //
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void) {
  while (1) {
    //
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void) {
  //
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void) {
  //
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void) {
  //
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void) {
  //
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles RCC global interrupt.
  */
void RCC_IRQHandler(void) {
  //
}

/**
  * @brief This function handles EXTI0 global interrupt.
  */
void EXTI0_IRQHandler(void) {
  PREG_SET(EXTI->PR, EXTI_IMR_MR0_Pos); /* clear pending bit */
  FLAG_SET(_EXTIREG_, _WUBAF_);
}

/**
  * @brief This function handles EXTI3 global interrupt.
  */
void EXTI3_IRQHandler(void) {
  PREG_SET(EXTI->PR, EXTI_IMR_MR3_Pos); /* clear pending bit */
  FLAG_SET(_EXTIREG_, _K1BAF_);
}

/**
  * @brief This function handles EXTI3 global interrupt.
  */
void EXTI4_IRQHandler(void) {
  PREG_SET(EXTI->PR, EXTI_IMR_MR4_Pos); /* clear pending bit */
  FLAG_SET(_EXTIREG_, _K0BAF_);
}

/**
  * @brief This function handles EXTI3 global interrupt.
  */
void EXTI9_5_IRQHandler(void) {
  if (PREG_SET(EXTI->PR, EXTI_IMR_MR5_Pos)) {
    PREG_SET(EXTI->PR, EXTI_IMR_MR5_Pos); /* clear pending bit */
    // FLAG_SET(_EXTIREG_, _K0BAF_);
  }
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void) {
  PREG_CLR(USART1->SR, USART_SR_RXNE_Pos);
  FLAG_SET(_USARTREG_, _USART1_RXAF_);
}

/**
  * @brief This function handles RTC alarms A and B interrupt through EXTI line 17.
  */
void RTC_Alarm_IRQHandler(void) {
  /* Clear penfing bit */
  PREG_SET(EXTI->PR, EXTI_IMR_MR17_Pos); 
  /* Alarm A */
  if (PREG_CHECK(RTC->ISR, RTC_ISR_ALRAF_Pos)) {
    PREG_CLR(RTC->ISR, RTC_ISR_ALRAF_Pos);
    PREG_CLR(RTC->ISR, RTC_ISR_INIT_Pos);
    FLAG_SET(_RTCREG_, _ALAF_);
  }
  /* Alarm B */
  if (PREG_CHECK(RTC->ISR, RTC_ISR_ALRBF_Pos)) {
    PREG_CLR(RTC->ISR, RTC_ISR_ALRBF_Pos);
    PREG_CLR(RTC->ISR, RTC_ISR_INIT_Pos);
    FLAG_SET(_RTCREG_, _ALBF_);
  }
  /* Wake Up */
  if (PREG_CHECK(RTC->ISR, RTC_ISR_WUTF_Pos)) {
    PREG_CLR(RTC->ISR, RTC_ISR_WUTF_Pos);
    PREG_CLR(RTC->ISR, RTC_ISR_INIT_Pos);
    FLAG_SET(_RTCREG_, _WUTF_);
  }
}

/**
  * @brief This function handles TIM7 global interrupt.
  */
void TIM7_IRQHandler(void) {
  PREG_CLR(TIM7->SR, TIM_SR_UIF_Pos);
  FLAG_CLR(_GLOBALREG_, _DELAYF_);
}

