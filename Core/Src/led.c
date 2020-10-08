/**
  ******************************************************************************
  * File Name          : led.c
  * Description        : This file provides code for the configuration
  *                      of the GPIO instances for LEDs indication.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
  
  
/* Includes ------------------------------------------------------------------*/
#include "led.h"

/* Global variables ---------------------------------------------------------*/
/**
  * @brief  A management restry keepeng flag states for the LED routines.
  */
uint32_t _LEDREG_ = 0;



/**
  * @brief  Initiates PIN 6 and 7 on GPIOA port as outputs to blink correspondent LEDs
  *  on the board. Pins are set on the lowest speed, push-pull, no pull-up neither pull-down
  * @param  None
  * @return None
  */
void LED_Init(void) {
  MODIFY_REG(LED_Port->MODER, (LED0_Pin_Mask | LED1_Pin_Mask), ((_MODE_OUT << LED0_Pin_Pos * 2) | (_MODE_OUT << LED1_Pin_Pos * 2)));
}


/**
  * @brief  Switches a certain PIN on a certain PORT on and off.
  * @param  port: a pointer to a GPIO port
  * @param  pinSource: a number of a pin in the port
  * @return None
  */
void LED_Blink(GPIO_TypeDef* port, uint16_t pinSource) {
  (PIN_LEVEL(port, pinSource)) ? PIN_L(port, pinSource) : PIN_H(port, pinSource);
}