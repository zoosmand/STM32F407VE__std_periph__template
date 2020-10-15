/**
  ******************************************************************************
  * File Name          : w25qxx.c
  * Description        : This file provides code for the configuration
  *                      of the EEPROM W25Wxx instances.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "w25qxx.h"

/* Private variables ---------------------------------------------------------*/
static uint8_t dataBuf[1024];
/* -- w25q capacities in blocks -- */
const uint16_t w25q[] = {
    0x0002
  , 0x0004
  , 0x0008
  , 0x0010
  , 0x0020
  , 0x0040
  , 0x0080
  , 0x0100
  , 0x0200
  , 0x0400
};

w25qxx_t w25qxx;

/* Private function prototypes -----------------------------------------------*/
static void SPI_Transfer_DMA(uint16_t cnt, Direction_TypeDef dir, uint32_t offset, uint8_t *buf);
static void SPI_Transfer(uint8_t cmd, int32_t addr, uint16_t cnt, Direction_TypeDef dir, uint32_t offset, uint8_t *buf);
static void W25qxx_Reset();
static void W25qxx_IsBusy();
static uint8_t W25qxx_WriteStatusRegister(uint8_t type, uint8_t status);






// ////////////////////////////////////////////////////////////////////////////////
// /**
//   * @brief  Returns pointer of data buffer
//   * @param  none
//   * @retval pointer address
//   */
// uint8_t* W25qxx_GetDataBuf(void) {
//   return (uint8_t*)dataBuf;
// }




/**
  * @brief  Transfesr SPI data via DMA
  * @param  cnt: Count of bytes to transfer
  * @param  dir: Direction - READ or WRITE EEPROM
  * @param  offset: Offset of a particular address of EEPROM
  * @retval None
  */
static void SPI_Transfer_DMA(uint16_t cnt, Direction_TypeDef dir, uint32_t offset, uint8_t *buf) {
  // // SetFlag(&_EREG_, _DBLF_, FLAG_SET);
  // uint8_t pump = 0;

  // if (dir == WRITE) {
  //   SET_BIT(SPI1->CR2, SPI_CR2_TXDMAEN);
  //   SET_BIT(DMA1_Channel3->CCR, DMA_CCR_MINC);
  //   DMA1_Channel3->CMAR = ((uint32_t)buf) + (offset * PAGE_SIZE);
  //   DMA1_Channel3->CNDTR = cnt;
  //   SET_BIT(DMA1_Channel3->CCR, DMA_CCR_EN);
  // } else {
  //   SET_BIT(SPI1->CR2, (SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN));
  //   CLEAR_BIT(DMA1_Channel3->CCR, DMA_CCR_MINC);
  //   DMA1_Channel2->CMAR = (uint32_t)buf;
  //   DMA1_Channel3->CMAR = (uint32_t)&pump;
  //   DMA1_Channel2->CNDTR = cnt;
  //   DMA1_Channel3->CNDTR = cnt;
  //   SET_BIT(DMA1_Channel2->CCR, DMA_CCR_EN);
  //   SET_BIT(DMA1_Channel3->CCR, DMA_CCR_EN);
  // }

  // while (!(READ_BIT(DMA1->ISR, DMA_ISR_TCIF3)));
  // SET_BIT(DMA1->IFCR, (DMA_IFCR_CTCIF3 | DMA_IFCR_CTCIF2));

  
  // if (dir == WRITE) {
  //   while (READ_BIT(SPI1->SR, SPI_SR_BSY));

  //   CLEAR_BIT(SPI1->CR2, SPI_CR2_TXDMAEN);
  //   CLEAR_BIT(DMA1_Channel3->CCR, DMA_CCR_EN);
  // } else {
  //   while (READ_BIT(SPI1->SR, SPI_SR_BSY));

  //   CLEAR_BIT(SPI1->CR2, (SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN));
  //   CLEAR_BIT(DMA1_Channel2->CCR, DMA_CCR_EN);
  //   CLEAR_BIT(DMA1_Channel3->CCR, DMA_CCR_EN);
  // }

  // // SetFlag(&_EREG_, _DBLF_, FLAG_SET);
}





static void SPI_Transfer(uint8_t cmd, int32_t addr, uint16_t cnt, Direction_TypeDef dir, uint32_t offset, uint8_t *buf) {
  // SPI1_Enable();
  SPI_TypeDef *SPI = SPI3;
  EEPROM_EXT_CS_L;

  /* Send command and skip dummy byte */
  // *(__IO uint8_t*)&SPI1->DR = cmd;
  // while (!(READ_BIT(SPI1->SR, SPI_SR_TXE)));
  // SPI1->DR;
  // while (!(READ_BIT(SPI1->SR, SPI_SR_RXNE)));
  SPI_Write8b(SPI, cmd);

  if (addr >= 0) {
    int i = 4;
    while (--i) {
      // *(__IO uint8_t*)&SPI->DR = ((addr >> (8 * i)) & 0xff);
      // while (!(READ_BIT(SPI->SR, SPI_SR_TXE)));
      // SPI1->DR;
      // while (!(READ_BIT(SPI->SR, SPI_SR_RXNE)));
      SPI_Write8b(SPI, ((addr >> (8 * i)) & 0xff));
    }
  }
  
  if (cmd == FastRead) {
    *(__IO uint8_t*)&SPI1->DR = 0;
    while (!(READ_BIT(SPI->SR, SPI_SR_TXE)));
    SPI1->DR;
    while (!(READ_BIT(SPI->SR, SPI_SR_RXNE)));
  }


  if (cnt) {
    // SPI_Transfer_DMA(cnt, dir, offset, buf);
    uint8_t *tmp_data;

    tmp_data = &(dataBuf[0]);
    while (cnt--) {
      // *(__IO uint8_t*)&SPI->DR = 0;
      // while (!(READ_BIT(SPI->SR, SPI_SR_TXE)));
      // *tmp_data++ = SPI->DR;
      // while (READ_BIT(SPI->SR, SPI_SR_RXNE));
      *buf++ = SPI_Read8b(SPI);
      // buf[0] = cmd;
      // SPI_Transfer8bBuf(SPI, buf, 12);
    }
  }

  EEPROM_EXT_CS_H;
  // SPI1_Disable();
}





// static uint8_t buffer[12];

uint8_t W25qxx_Init(void) {
  uint8_t status = 0;
  uint8_t buf[12];
  
  // w25qxx.Lock = 1;
  // /* Lock buffer */
  // // FLAG_SET(_EREG_, _TBLF_); 
  // buf[0] = Read_UniqueID;
  // EEPROM_EXT_CS_L;
  // SPI_Transfer8bBuf(SPI3, buf, 12);
  // EEPROM_EXT_CS_H;
  SPI_Transfer(Read_DeviceID, -1, 12, READ, 0, buf);
  // w25qxx.ManID = buf[0];
  // w25qxx.Type = buf[1];
  // w25qxx.BlockCount = w25q[((buf[2] - 1) & 0x0f)];  
  // w25qxx.Capacity = w25qxx.BlockCount * BLOCK_SIZE;

  // SPI_Transfer(Read_UniqueID, -1, 12, READ, 0, buf);
  // w25qxx.UniqID = *(uint64_t*)(&buf[4]);

  // SPI_Transfer(Read_DeviceID, -1, 4, READ, 0, buf);
  // w25qxx.ID = buf[3];

  // w25qxx.Lock = 0;

  // if ((w25qxx.ManID == 0xef) && (w25qxx.Type = 0x40)) status = 1;

  /* Unlock buffer */
  // FLAG_CLR(_EREG_, _TBLF_);


  // W25qxx_Erase(0x00000000, 32);

  // W25qxx_Write(0x00000000, 576, (uint8_t*)font_5x7);
  // W25qxx_Write(0x00000003, 2304, (uint8_t*)font_10x14);
  // W25qxx_Write(0x00000010, 5184, (uint8_t*)font_15x21);
  // W25qxx_Write(0x00000030, 9216, (uint8_t*)font_20x28);

  // W25qxx_Read(0x00000000, 1024, dataBuf);
  // W25qxx_Read(0x00000003, 1024, dataBuf);
  // W25qxx_Read(0x00000010, 1024, dataBuf);
  // W25qxx_Read(0x00000030, 1024, dataBuf);
  // W25qxx_Read(0x00000050, 1024, dataBuf);

  /* To protect first 32K */
  // uint8_t ddd;
  // // ddd = W25qxx_WriteStatusRegister(0, (_SEC_ | _TB_ | _BP2_));
  // SPI_Transfer(Read_StatusRegister_1, -1, 1, READ, 0, &ddd);
  // printf("%x\n", ddd);



  return (status);
}







// -------------------------------------------------------------  
void W25qxx_Read (uint32_t addr, uint16_t cnt, uint8_t *buf) {
  uint32_t phy_addr = 0;
  W25qxx_IsBusy();
  
  phy_addr = BLOCK_SIZE * ((addr >> 8) & 0xffff);
  phy_addr += SECTOR_SIZE * ((addr >> 4) & 0xf);
  phy_addr += PAGE_SIZE * (addr & 0xf);
  
  SPI_Transfer(FastRead, (phy_addr << 8), cnt, READ, 0, buf);  
}





// -------------------------------------------------------------  
void W25qxx_Write (uint32_t addr, uint16_t cnt, uint8_t *buf) {
  uint8_t pump = 0;
  uint32_t phy_addr = 0;
  W25qxx_IsBusy();

  phy_addr = BLOCK_SIZE * ((addr >> 8) & 0xffff);
  phy_addr += SECTOR_SIZE * ((addr >> 4) & 0xf);
  phy_addr += PAGE_SIZE * (addr & 0xf);
  uint32_t i = 0;
  for (i = 0; i < (cnt / 256); i++) {
    SPI_Transfer(WriteEnable, -1, 0, NEUTRAL, 0, &pump);
    SPI_Transfer(PageProgram, (phy_addr << 8), 256, WRITE, i, buf);  
    phy_addr += PAGE_SIZE;
    /* Skip four trash bytes */
    uint8_t z = 4;
    while (z--) {
      while (!(READ_BIT(SPI1->SR, SPI_SR_RXNE)));
      SPI1->DR;
    }
    W25qxx_IsBusy();
  }
  
  if (cnt % 256) {
    SPI_Transfer(WriteEnable, -1, 0, NEUTRAL, 0, &pump);
    SPI_Transfer(PageProgram, (phy_addr << 8), (cnt % 256), WRITE, i, buf);
    /* Skip four trash bytes */
    uint8_t z = 4;
    while (z--) {
      while (!(READ_BIT(SPI1->SR, SPI_SR_RXNE)));
      SPI1->DR;
    }
    W25qxx_IsBusy();
  }
}






// -------------------------------------------------------------  
void W25qxx_Erase(uint32_t addr, uint16_t sectors) {

  uint8_t pump = 0;
  
  uint32_t phy_addr = 0;
  phy_addr = BLOCK_SIZE * ((addr >> 8) & 0xffff);
  

  if (sectors > 8) {
    if (sectors > 16) {
      // *******************************  
      uint32_t blocks = (sectors / 16);
      for (int i = 0; i < blocks; i++) {
        SPI_Transfer(WriteEnable, -1, 0, NEUTRAL, 0, &pump);
        SPI_Transfer(Erase_Block_64, (phy_addr << 8), 0, NEUTRAL, 0, &pump);
        phy_addr += BLOCK_SIZE;
        W25qxx_IsBusy();
      }
      uint32_t remain_addr = (addr & 0xffffff00) + (blocks << 8);
      if (sectors % 16) {
        SPI_Transfer(WriteEnable, -1, 0, NEUTRAL, 0, &pump);
        W25qxx_Erase(remain_addr, (sectors % 16));
        W25qxx_IsBusy();
      }
      // *******************************  
    } else {
      // ******************************* 
      if (((addr >> 4) & 0xf) > 8) {
        phy_addr += SECTOR_SIZE * ((addr >> 4) & 0xf);
      }
      SPI_Transfer(WriteEnable, -1, 0, NEUTRAL, 0, &pump);
      SPI_Transfer(Erase_Block_32, (phy_addr << 8), 0, NEUTRAL, 0, &pump);
      uint32_t remain_addr = (addr & 0xffffff80) + (8 << 4);
      W25qxx_IsBusy();
      
      if (sectors - 8) {
        SPI_Transfer(WriteEnable, -1, 0, NEUTRAL, 0, &pump);
        W25qxx_Erase(remain_addr, sectors - 8);
        W25qxx_IsBusy();
      }
    // *******************************  
    }
  } else {
    // *******************************  
    phy_addr += SECTOR_SIZE * ((addr >> 4) & 0xf);
    for (int i = 0; i < sectors; i++) {
      SPI_Transfer(WriteEnable, -1, 0, NEUTRAL, 0, &pump);
      SPI_Transfer(Erase_Sector, (phy_addr << 8), 0, NEUTRAL, 0, &pump);
      phy_addr += SECTOR_SIZE;
      W25qxx_IsBusy();
    }
    // *******************************  
  }
}





static void W25qxx_IsBusy() {
  uint8_t pump = 0;
  pump = _BUSY_;
  while (pump & _BUSY_) {
    SPI_Transfer(Read_StatusRegister_1, -1, 1, READ, 0, &pump);
  }
}





static void W25qxx_Reset() {
  uint8_t pump = 0;
  SPI_Transfer(EnableReset, -1, 0, NEUTRAL, 0, &pump);
  SPI_Transfer(ResetProccess, -1, 0, NEUTRAL, 0, &pump);
  Delay(10);
  SPI_Transfer(ReleasePowerDown, -1, 0, NEUTRAL, 0, &pump);
}



/* type: 0 - non-volatile bits, 1 - volatile bits*/
static uint8_t W25qxx_WriteStatusRegister(uint8_t type, uint8_t status) {
  uint8_t pump = 0;
  if (type) {
    SPI_Transfer(Write_StatusNVRegEnable, -1, 0, NEUTRAL, 0, &pump);
  } else {
    SPI_Transfer(WriteEnable, -1, 0, NEUTRAL, 0, &pump);
  }
  
  SPI_Transfer(Write_StatusRegister_1, -1, 1, WRITE, 0, &status);
  /* Skip one trash bytes */
  while (!(READ_BIT(SPI1->SR, SPI_SR_RXNE)));
  SPI1->DR;

  W25qxx_IsBusy();
  SPI_Transfer(Read_StatusRegister_1, -1, 1, READ, 0, &pump);
  return (pump);
}