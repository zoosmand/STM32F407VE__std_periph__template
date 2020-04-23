/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#define SWO_ITM

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "stm32f4xx.h"

/* Private includes ----------------------------------------------------------*/
#include "common.h"
#include "stm32f4xx_it.h"

/* Exported types ------------------------------------------------------------*/

/* Exported varables ---------------------------------------------------------*/
extern uint32_t sysQuantum;
extern uint32_t millis;
extern uint32_t seconds;
extern uint32_t minutes;
extern uint32_t _EREG_;
extern uint32_t SystemCoreClock;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Private defines -----------------------------------------------------------*/
// _EREG_ Flags    
#define _BT7F_    0 // Basic Timer7 Flag
// #define _RTCALAF_ 1 // RTC Alarm A Flag
// #define _RTCALBF_ 2 // RTC Alarm B Flag
// #define _RTWUPF_  3 // RTC Wake Up Flag
// #define _RDF_     4 // Run Display Flag
// #define _DDF_     5 // Display Delay Flag
// #define _DBLF_    6 // Data Buffer is Locked Flag
// #define _U1RXF_   7 // USART1 RXNE Interrupt occurs Flag
// #define _BLINKF_  8 // Blink Flaf
#define _DELAYF_  9 // Delay Flag
// #define _EWUPF_   10 // EXTI WakeUp PA0 Flag
// #define _ETSF_    11 // EXTI Touch Screen PA15 Flag

#define CCMRAM  __attribute__((section(".ccmram")))

#define NVIC_PRIORITYGROUP_0         0x00000007U /*!< 0 bits for pre-emption priority 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         0x00000006U /*!< 1 bits for pre-emption priority 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         0x00000005U /*!< 2 bits for pre-emption priority 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         0x00000004U /*!< 3 bits for pre-emption priority 1 bits for subpriority */
#define NVIC_PRIORITYGROUP_4         0x00000003U /*!< 4 bits for pre-emption priority 0 bits for subpriority */

/* Exported functions prototypes ---------------------------------------------*/
extern void Delay_Handler(uint32_t delay);
extern void Delay(uint32_t delay);
extern void Cron_Handler(void);
extern void Set_BitBandVal(uint32_t addr, uint32_t key);
extern uint32_t Get_BitBandVal(uint32_t addr);


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

