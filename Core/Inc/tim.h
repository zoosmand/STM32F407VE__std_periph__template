/**
  ******************************************************************************
  * File Name          : tim.h
  * Description        : This file provides code for the configuration
  *                      of timers instances.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
  
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIM_H
#define __TIM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Global variables ---------------------------------------------------------*/
extern uint32_t _TIMREG_;



/* Private defines -----------------------------------------------------------*/
// TIM Registry Flags




/* Exported functions prototypes ---------------------------------------------*/
void BasicTimer7_Init(void);
void Delay2(uint16_t delay);



#ifdef __cplusplus
}
#endif
#endif /*__TIM_H */

