/**
  ******************************************************************************
  * File Name          : exti.h
  * Description        : This file provides code for the configuration
  *                      of the EXTI instances.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
  
  
  /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXTI_H
#define __EXTI_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Global variables ----------------------------------------------------------*/
extern uint32_t _EXTIREG_;


/* Private defines -----------------------------------------------------------*/
#define K0_Pin                    GPIO_PIN_4
#define K0_Pin_Pos                GPIO_PIN_4_Pos
#define K0_Pin_Mask               GPIO_PIN_4_Mask
#define K0_GPIO_Port              GPIOE

#define K1_Pin                    GPIO_PIN_3
#define K1_Pin_Pos                GPIO_PIN_3_Pos
#define K1_Pin_Mask               GPIO_PIN_3_Mask
#define K1_GPIO_Port              GPIOE

#define K_WUP_Pin                 GPIO_PIN_0
#define K_WUP_Pin_Pos             GPIO_PIN_0_Pos
#define K_WUP_Pin_Mask            GPIO_PIN_0_Mask
#define K_WUP_GPIO_Port           GPIOA

// #define LCD_TC_INT_Pin            GPIO_PIN_5
// #define LCD_TC_INT_Pin_Pos        GPIO_PIN_5_Pos
// #define LCD_TC_INT_Pin_Most       GPIO_PIN_5_Msk
// #define LCD_TC_INT_GPIO_Port      GPIOC


// EXTI Registry Flags
#define _WUBAF_     0 // Wake Up Button Action Flag
#define _K0BAF_     1 // K0 Button Action Flag
#define _K1BAF_     2 // K1 Button Action Flag


/* EXTI PORT Defines */
#define EXTI_PA     0b0000
#define EXTI_PB     0b0001
#define EXTI_PC     0b0010
#define EXTI_PD     0b0011
#define EXTI_PE     0b0100
#define EXTI_PF     0b0101
#define EXTI_PG     0b0110
#define EXTI_PH     0b0111
#define EXTI_PI     0b1000

#define EXTI0_Pos   0
#define EXTI1_Pos   4
#define EXTI2_Pos   8
#define EXTI3_Pos   12
#define EXTI4_Pos   0
#define EXTI5_Pos   4
#define EXTI6_Pos   8
#define EXTI7_Pos   12
#define EXTI8_Pos   0
#define EXTI9_Pos   4
#define EXTI10_Pos  8
#define EXTI11_Pos  12
#define EXTI12_Pos  0
#define EXTI13_Pos  4
#define EXTI14_Pos  8
#define EXTI15_Pos  12



/* Exported functions prototypes ---------------------------------------------*/
void EXTI_Init(void);
void WakeUp_Button_Handler(void);
void K0_Button_Handler(void);
void K1_Button_Handler(void);



#ifdef __cplusplus
}
#endif
#endif /*__EXTI_H */
