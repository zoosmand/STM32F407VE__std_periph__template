/**
  ******************************************************************************
  * File Name          : usart.c
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* Global variables ---------------------------------------------------------*/
uint32_t _USARTREG_ = 0;

/* Private variables ---------------------------------------------------------*/
static uint8_t usartBuf[RXBUF_LEN];
static uint8_t usartBufPrtIn = 0;
static uint8_t usartBufPrtOut = 0;



/* Private function prototypes -----------------------------------------------*/










////////////////////////////////////////////////////////////////////////////////
/**
  * @brief  Initializes USART1 peripheral 
  * @param  None
  * @return None
  */
void USART1_Init(void) {
  /* 
    PA9   ------> USART1_TX
    PA10  ------> USART1_RX 
  */

  /* - - - - 1-st step. Adjust GPIO - - - - */
  /* Define mask */
  #define USART_1_MASK     (USART_1_TX_Pin_Mask | USART_1_RX_Pin_Mask)
  /* Mode alternative */
  MODIFY_REG(USART_1_Port->MODER, USART_1_MASK, (
      (_MODE_AF << USART_1_TX_Pin_Pos * 2)
    | (_MODE_AF << USART_1_RX_Pin_Pos * 2)
  ));
  /* Speed very high */
  MODIFY_REG(USART_1_Port->OSPEEDR, USART_1_MASK, (
      (_SPEED_V << USART_1_TX_Pin_Pos * 2)
    | (_SPEED_V << USART_1_RX_Pin_Pos * 2)
  ));
  /* Output type none */
  /* Push mode none */
  /* Alternate function USART */
  MODIFY_REG(USART_1_Port->AFR[1], 0x00000ff0, (
      (GPIO_AF_7 << (USART_1_TX_Pin_Pos - 8) * 4)
    | (GPIO_AF_7 << (USART_1_RX_Pin_Pos - 8) * 4)
  ));


  /* - - - - 2-nd step. Setup USART1 - - - - */
  /* Transmit enable */
  PREG_SET(USART1->CR1, USART_CR1_TE_Pos);
  /* Receive enable */
  PREG_SET(USART1->CR1, USART_CR1_RE_Pos);
  /* Asyncronos mode */
  PREG_CLR(USART1->CR2, USART_CR2_LINEN_Pos);
  PREG_CLR(USART1->CR2, USART_CR2_CLKEN_Pos);
  PREG_CLR(USART1->CR3, USART_CR3_SCEN);
  PREG_CLR(USART1->CR3, USART_CR3_IREN);
  PREG_CLR(USART1->CR3, USART_CR3_HDSEL);
  /* Set Baudrate */
  USART1->BRR = BRR_Value;
  /* Enable USART1 */
  PREG_SET(USART1->CR1, USART_CR1_UE_Pos);
  /* Enable RXNE Interrupt */
  PREG_SET(USART1->CR1, USART_CR1_RXNEIE_Pos);


  /* - - - - 3-nd step. Adjust interrupt on receive on the USART1 - - - - */
  /* USART1 interrupt Init */
  NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));
  NVIC_EnableIRQ(USART1_IRQn);

}







void USART1_RX_Handler() {
  uint8_t tmp = USART1->DR;
  uint8_t preRxPtr = usartBufPrtIn - 1;
  preRxPtr &= RXBUF_MASK;

  usartBuf[(usartBufPrtIn++)] = tmp;
  usartBufPrtIn &= RXBUF_MASK;

  // the end of message
  if ((usartBuf[preRxPtr] == 0x0d) && (tmp == 0x0a)) {
  // if (tmp == '\n') { // 0x0a
    // if (usartBuf[preRxPtr] == '\r') { // 0x0d
      FLAG_SET(_USARTREG_, _USART1_LBNEF_);
    // }
  }
}





uint8_t USART1_RxBufferRead(uint8_t *buf, uint16_t len) {
  uint8_t payloadLen = 0;
  while (usartBufPrtOut != usartBufPrtIn) {
    buf[(payloadLen++)] = usartBuf[(usartBufPrtOut++)];
    usartBufPrtOut &= RXBUF_MASK;
  }
  return payloadLen;
}

