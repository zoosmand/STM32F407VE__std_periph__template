/**
  ******************************************************************************
  * File Name          : spi.c
  * Description        : This file provides code for the configuration
  *                      of the SPI instances.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "spi.h"

/* Global variables ---------------------------------------------------------*/
uint32_t _SPIREG_ = 0;







////////////////////////////////////////////////////////////////////////////////
/**
  * @brief  Initializes SPI1 peripheral 
  * @param  SPIx: a pointer to an SPI definition
  * @return None
  */
void SPI_Init(SPI_TypeDef *SPIx) {
  if (SPIx == SPI2) {

    /* - - - - 1-st step. Adjust GPIO - - - - */
    /* Define mask */    
    #define SPI_2_MASK     (SPI_2_SCK_Pin_Mask | SPI_2_MISO_Pin_Mask | SPI_2_MOSI_Pin_Mask)
    /* Mode alternative */
    MODIFY_REG(SPI_2_Port->MODER, SPI_2_MASK, (
        (_MODE_AF << SPI_2_SCK_Pin_Pos * 2)
      | (_MODE_AF << SPI_2_MISO_Pin_Pos * 2)
      | (_MODE_AF << SPI_2_MOSI_Pin_Pos * 2)
    ));
    /* Speed very high */
    MODIFY_REG(SPI_2_Port->OSPEEDR, SPI_2_MASK, (
        (_SPEED_V << SPI_2_SCK_Pin_Pos * 2)
      | (_SPEED_V << SPI_2_MISO_Pin_Pos * 2)
      | (_SPEED_V << SPI_2_MOSI_Pin_Pos * 2)
    ));
    /* Output type none */
    /* Push mode none */
    /* Alternate function USART */
    MODIFY_REG(SPI_2_Port->AFR[1], 0xfff00000, (
        (GPIO_AF_5 << (SPI_2_SCK_Pin_Pos - 8) * 4)
      | (GPIO_AF_5 << (SPI_2_MISO_Pin_Pos - 8) * 4)
      | (GPIO_AF_5 << (SPI_2_MOSI_Pin_Pos - 8) * 4)
    ));

    #define SPI_2_NSS_MASK  (CS_EEPROM_Pin_Mask | CS_TS_Pin_Mask)
    /* Mode output */
    MODIFY_REG(CS_EEPROM_Port->MODER, SPI_2_NSS_MASK, (
        (_MODE_OUT << LED0_Pin_Pos * 2)
      | (_MODE_OUT << LED1_Pin_Pos * 2)
    ));
    /* Speed very high */
    MODIFY_REG(CS_EEPROM_Port->OSPEEDR, SPI_2_NSS_MASK, (
        (_SPEED_V << LED0_Pin_Pos * 2)
      | (_SPEED_V << LED1_Pin_Pos * 2)
    ));
    EEPROM_CS_H;
    TS_CS_H;
  
    /* - - - - 2-nd step. Setup SPI2 - - - - */
    /* Master enable */
    /* Internal Slave Select enable */
    /* NSS managed internally. NSS pin not used and free */
    /* SPI5 enable */
    /* Bitrate divided to 16 */
    MODIFY_REG(SPI2->CR1, 0xffffffff, (
        SPI_CR1_MSTR
      | SPI_CR1_SSI
      | SPI_CR1_SSM
      | SPI_CR1_SPE
      | (3 << SPI_CR1_BR_Pos)
    ));

    // PREG_SET(SPI2->CR1, SPI_CR1_MSTR_Pos);
    // PREG_SET(SPI2->CR1, SPI_CR1_SSI_Pos);
    // PREG_SET(SPI2->CR1, SPI_CR1_SSM_Pos);
    // PREG_SET(SPI2->CR1, SPI_CR1_BR_Pos);
    // PREG_SET(SPI2->CR1, (SPI_CR1_BR_Pos + 1));
    // PREG_SET(SPI2->CR1, SPI_CR1_SPE_Pos);


    // /* Configure DMA, Channel2 - RX, Channel3 - TX */
    // uint8_t pump = 0;
    // /* Set priority high*/
    // /* Set memory to increment */
    // DMA1_Stream2->CCR = (DMA_CCR_PL_1 | DMA_CCR_MINC);
    // /* Set buffer size to 0 */
    // DMA1_Channel2->CNDTR = 0U;
    // /* Set peripheral address */
    // DMA1_Channel2->CPAR = (uint32_t)&SPI1->DR;
    // /* Set memory address */
    // // DMA1_Channel2->CMAR = (uint32_t)(W25qxx_GetDataBuf());
    // DMA1_Channel2->CMAR = (uint32_t)&pump;

    // /* Set priority high*/
    // /* Set memory to increment */
    // /* Set direction from memory to peripheral */
    // DMA1_Channel3->CCR = (DMA_CCR_PL_1 | DMA_CCR_MINC | DMA_CCR_DIR);
    // /* Set buffer size to 0 */
    // DMA1_Channel3->CNDTR = 0U;
    // /* Set peripheral address */
    // DMA1_Channel3->CPAR = (uint32_t)&SPI1->DR;
    // /* Set memory address */
    // // DMA1_Channel3->CMAR = (uint32_t)(W25qxx_GetDataBuf());
    // DMA1_Channel3->CMAR = (uint32_t)&pump;
  }

  if (SPIx == SPI3) {

    /* - - - - 1-st step. Adjust GPIO - - - - */
    /* Define mask */    
    #define SPI_3_MASK     (SPI_3_SCK_Pin_Mask | SPI_3_MISO_Pin_Mask | SPI_3_MOSI_Pin_Mask)
    /* Mode alternative */
    MODIFY_REG(SPI_3_Port->MODER, SPI_3_MASK, (
        (_MODE_AF << SPI_3_SCK_Pin_Pos * 2)
      | (_MODE_AF << SPI_3_MISO_Pin_Pos * 2)
      | (_MODE_AF << SPI_3_MOSI_Pin_Pos * 2)
    ));
    /* Speed very high */
    MODIFY_REG(SPI_3_Port->OSPEEDR, SPI_2_MASK, (
        (_SPEED_V << SPI_3_SCK_Pin_Pos * 2)
      | (_SPEED_V << SPI_3_MISO_Pin_Pos * 2)
      | (_SPEED_V << SPI_3_MOSI_Pin_Pos * 2)
    ));
    /* Output type none */
    /* Push mode none */
    /* Alternate function USART */
    MODIFY_REG(SPI_3_Port->AFR[1], 0xfff00000, (
        (GPIO_AF_6 << (SPI_3_SCK_Pin_Pos - 8) * 4)
      | (GPIO_AF_6 << (SPI_3_MISO_Pin_Pos - 8) * 4)
      | (GPIO_AF_6 << (SPI_3_MOSI_Pin_Pos - 8) * 4)
    ));

    /* CS */
    /* Mode alternative */
    MODIFY_REG(CS_EEPROM_EXT_Port->MODER, CS_EEPROM_EXT_Pin_Mask, (_MODE_OUT << CS_EEPROM_EXT_Pin_Pos * 2));
    /* Speed very high */
    MODIFY_REG(CS_EEPROM_EXT_Port->OSPEEDR, CS_EEPROM_EXT_Pin_Mask, (_SPEED_V << CS_EEPROM_EXT_Pin_Pos * 2));

    EEPROM_EXT_CS_H;
  
    /* - - - - 2-nd step. Setup SPI2 - - - - */
    /* Master enable */
    /* Internal Slave Select enable */
    /* NSS managed internally. NSS pin not used and free */
    /* SPI5 enable */
    /* Bitrate divided to 16 */
    MODIFY_REG(SPI3->CR1, 0xffffffff, (
        SPI_CR1_MSTR
      | SPI_CR1_SSI
      | SPI_CR1_SSM
      | SPI_CR1_SPE
      | (3 << SPI_CR1_BR_Pos)
    ));

    // PREG_SET(SPI2->CR1, SPI_CR1_MSTR_Pos);
    // PREG_SET(SPI2->CR1, SPI_CR1_SSI_Pos);
    // PREG_SET(SPI2->CR1, SPI_CR1_SSM_Pos);
    // PREG_SET(SPI2->CR1, SPI_CR1_BR_Pos);
    // PREG_SET(SPI2->CR1, (SPI_CR1_BR_Pos + 1));
    // PREG_SET(SPI2->CR1, SPI_CR1_SPE_Pos);


    // /* Configure DMA, Channel2 - RX, Channel3 - TX */
    // uint8_t pump = 0;
    // /* Set priority high*/
    // /* Set memory to increment */
    // DMA1_Stream2->CCR = (DMA_CCR_PL_1 | DMA_CCR_MINC);
    // /* Set buffer size to 0 */
    // DMA1_Channel2->CNDTR = 0U;
    // /* Set peripheral address */
    // DMA1_Channel2->CPAR = (uint32_t)&SPI1->DR;
    // /* Set memory address */
    // // DMA1_Channel2->CMAR = (uint32_t)(W25qxx_GetDataBuf());
    // DMA1_Channel2->CMAR = (uint32_t)&pump;

    // /* Set priority high*/
    // /* Set memory to increment */
    // /* Set direction from memory to peripheral */
    // DMA1_Channel3->CCR = (DMA_CCR_PL_1 | DMA_CCR_MINC | DMA_CCR_DIR);
    // /* Set buffer size to 0 */
    // DMA1_Channel3->CNDTR = 0U;
    // /* Set peripheral address */
    // DMA1_Channel3->CPAR = (uint32_t)&SPI1->DR;
    // /* Set memory address */
    // // DMA1_Channel3->CMAR = (uint32_t)(W25qxx_GetDataBuf());
    // DMA1_Channel3->CMAR = (uint32_t)&pump;
  }
}




/**
  * @brief  Writes 8 bit data via SPI
  * @param  SPIx: pointer to an SPI instance
  * @param  data: a byte to send
  * @return None
  */
void SPI_Write8b(SPI_TypeDef *SPIx, uint8_t data) {
  // __IO uint8_t *spidr = (__IO uint8_t *)&SPIx->DR;
  // *spidr = data;
  // SPIx->DR = data;
  SPIx->DR = data;
  while (!(PREG_CHECK(SPIx->SR, SPI_SR_TXE_Pos)));
}




/**
  * @brief  Reads 8 bit data via SPI
  * @param  SPIx: pointer to an SPI instance
  * @return  a received byte
  */
uint8_t SPI_Read8b(SPI_TypeDef *SPIx) {
  SPIx->DR = 0;
  while (!(PREG_CHECK(SPIx->SR, SPI_SR_TXE_Pos)));
  while (!(PREG_CHECK(SPIx->SR, SPI_SR_RXNE_Pos)));
  uint8_t data_ret = (__IO uint8_t)(SPIx->DR);
  return (data_ret);
}




/**
  * @brief  Transfers 8 bit data via SPI (read and write in one iteraction)
  * @param  SPIx: pointer to an SPI instance
  * @param  data: a byte to send
  * @return a received byte
  */
uint8_t SPI_Transfer8b(SPI_TypeDef *SPIx, uint8_t data) {
  __IO uint8_t *spidr = (__IO uint8_t *)&SPIx->DR;
  *spidr = data;
  // SPIx->DR = data;
  while (!(PREG_CHECK(SPIx->SR, SPI_SR_TXE_Pos)));
  Delay(1);
  uint8_t data_ret = (__IO uint8_t)(SPIx->DR);
  while (PREG_CHECK(SPIx->SR, SPI_SR_RXNE_Pos));
  return (data_ret);
}






/**
  * @brief  Two-way transfer 8 bit data via SPI into/from a buffer
  * @param  SPIx: pointer to an SPI instance
  * @param  buf: pointer to a buffer to store data
  * @param  cnt: counter of bytes to get
  * @return  a received byte
  */
void SPI_Transfer8bBuf(SPI_TypeDef *SPIx, uint8_t *buf, uint16_t cnt) {
  while (cnt--) {
    __IO uint8_t *spidr = (__IO uint8_t *)&SPIx->DR;
    *spidr = *buf;
    // SPIx->DR = *buf;
    while (!(PREG_CHECK(SPIx->SR, SPI_SR_TXE_Pos)));
    Delay(1);
    *buf = (__IO uint8_t)(SPIx->DR);
    while (PREG_CHECK(SPIx->SR, SPI_SR_RXNE_Pos));
    buf++;
  }
 
}
