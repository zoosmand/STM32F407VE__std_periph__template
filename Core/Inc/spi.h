/**
  ******************************************************************************
  * File Name          : spi.h
  * Description        : This file provides code for the configuration
  *                      of the SPI instances.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#ifndef __SPI_H
#define __SPI_H

#ifdef __cplusplus
  extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Global variables ----------------------------------------------------------*/
extern uint32_t _SPIREG_;

/* Private defines -----------------------------------------------------------*/
// PB5
#define CS_EEPROM_Pin             GPIO_PIN_5
#define CS_EEPROM_Pin_Pos         GPIO_PIN_5_Pos
#define CS_EEPROM_Pin_Mask        GPIO_PIN_5_Mask
#define CS_EEPROM_Port            GPIOB
// PB12
#define CS_TS_Pin                 GPIO_PIN_12
#define CS_TS_Pin_Pos             GPIO_PIN_12_Pos
#define CS_TS_Pin_Mask            GPIO_PIN_12_Mask
#define CS_TS_Port                GPIOB
// PB13, PB14, PB15
#define SPI_2_SCK_Pin             GPIO_PIN_13
#define SPI_2_SCK_Pin_Pos         GPIO_PIN_13_Pos
#define SPI_2_SCK_Pin_Mask        GPIO_PIN_13_Mask
#define SPI_2_MISO_Pin            GPIO_PIN_14
#define SPI_2_MISO_Pin_Pos        GPIO_PIN_14_Pos
#define SPI_2_MISO_Pin_Mask       GPIO_PIN_14_Mask
#define SPI_2_MOSI_Pin            GPIO_PIN_15
#define SPI_2_MOSI_Pin_Pos        GPIO_PIN_15_Pos
#define SPI_2_MOSI_Pin_Mask       GPIO_PIN_15_Mask
#define SPI_2_Port                GPIOB

// PD2
#define CS_EEPROM_EXT_Pin         GPIO_PIN_2
#define CS_EEPROM_EXT_Pin_Pos     GPIO_PIN_2_Pos
#define CS_EEPROM_EXT_Pin_Mask    GPIO_PIN_2_Mask
#define CS_EEPROM_EXT_Port        GPIOD
// PC10, PC11, PC12
#define SPI_3_SCK_Pin             GPIO_PIN_10
#define SPI_3_SCK_Pin_Pos         GPIO_PIN_10_Pos
#define SPI_3_SCK_Pin_Mask        GPIO_PIN_10_Mask
#define SPI_3_MISO_Pin            GPIO_PIN_11
#define SPI_3_MISO_Pin_Pos        GPIO_PIN_11_Pos
#define SPI_3_MISO_Pin_Mask       GPIO_PIN_11_Mask
#define SPI_3_MOSI_Pin            GPIO_PIN_12
#define SPI_3_MOSI_Pin_Pos        GPIO_PIN_13_Pos
#define SPI_3_MOSI_Pin_Mask       GPIO_PIN_14_Mask
#define SPI_3_Port                GPIOC



typedef enum {
  NEUTRAL   = 2,
  READ      = 1,
  WRITE     = 0
} Direction_TypeDef;



// SPI Registry Flags
#define _SPI_1_LBNEF_    0 // Local Buffer Not Empty Flag
#define _SPI_1_RXAF_     1 // RX Action Flag


/* Private macro -------------------------------------------------------------*/
#define EEPROM_CS_H               PIN_H(CS_EEPROM_Port, CS_EEPROM_Pin_Pos)
#define EEPROM_CS_L               PIN_L(CS_EEPROM_Port, CS_EEPROM_Pin_Pos)
#define TS_CS_H                   PIN_H(CS_TS_Port, CS_TS_Pin_Pos)
#define TS_CS_L                   PIN_L(CS_TS_Port, CS_TS_Pin_Pos)
#define EEPROM_EXT_CS_H           PIN_H(CS_EEPROM_EXT_Port, CS_EEPROM_EXT_Pin_Pos)
#define EEPROM_EXT_CS_L           PIN_L(CS_EEPROM_EXT_Port, CS_EEPROM_EXT_Pin_Pos)


/* Exported functions prototypes ---------------------------------------------*/
void SPI_Init(SPI_TypeDef *SPIx);
void SPI_Write8b(SPI_TypeDef *SPIx, uint8_t data);
uint8_t SPI_Read8b(SPI_TypeDef *SPIx);
uint8_t SPI_Transfer8b(SPI_TypeDef *SPIx, uint8_t data);
void SPI_Transfer8bBuf(SPI_TypeDef *SPIx, uint8_t *buf, uint16_t cnt);


#ifdef __cplusplus
}
#endif

#endif /* __SPI_H */
