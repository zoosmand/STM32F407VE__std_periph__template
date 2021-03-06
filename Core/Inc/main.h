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
// #define SWO_USART

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


#include "stm32f4xx.h"

/* Private includes ----------------------------------------------------------*/
#include "common.h"
#include "stm32f4xx_it.h"
#include "led.h"
#include "usart.h"
#include "rtc.h"
#include "exti.h"
#include "tim.h"
#include "spi.h"
#include "fsmc.h"
#include "fonts.h"
#include "display.h"
#include "ili9341.h"
#include "w25qxx.h"

/* Global typedef ------------------------------------------------------------*/
struct __FILE {
  int handle;
  /* Whatever you require here. If the only file you are using is */
  /* standard output using printf() for debugging, no file handling */
  /* is required. */
};

/**
  * @brief  RCC Clocks Frequency Structure
  */
typedef struct
{
  uint32_t HCLK_Freq;          /* HCLK clock frequency */
  uint32_t PCLK1_Freq;         /* PCLK1 clock frequency */
  uint32_t PCLK1_Freq_Tim;     /* PCLK1 clock frequency for timers */
  uint32_t PCLK2_Freq;         /* PCLK2 clock frequency */
  uint32_t PCLK2_Freq_Tim;     /* PCLK2 clock frequency for timers */
} RCC_ClocksTypeDef;


/* Exported types ------------------------------------------------------------*/

/* Exported varables ---------------------------------------------------------*/
extern uint32_t sysQuantum;
extern uint32_t millis;
extern uint32_t seconds;
extern uint32_t minutes;
extern uint32_t _GLOBALREG_;
extern uint32_t SystemCoreClock;
extern RCC_ClocksTypeDef RccClocks;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Private defines -----------------------------------------------------------*/
// _EREG_ Flags    
#define _DELAYF_  0 // Delay Flag

/* Memory marker to CCRAM */
#define CCMRAM  __attribute__((section(".ccmram")))


/* Exported functions prototypes ---------------------------------------------*/
extern void Delay_Handler(uint32_t delay);
// extern void Delay(uint32_t delay);
extern void Cron_Handler(void);
extern void Set_BitBandVal(uint32_t addr, uint32_t key);
extern uint32_t Get_BitBandVal(uint32_t addr);


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

