/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Global variables ---------------------------------------------------------*/
uint32_t sysQuantum       = 0;
uint32_t millis           = 0;
uint32_t seconds          = 0;
uint32_t minutes          = 0;
uint32_t _EREG_           = 0;
uint32_t delay_tmp        = 0;
uint32_t check            = 0;
uint32_t SystemCoreClock  = 16000000;

/* Private variables ---------------------------------------------------------*/
static uint32_t millis_tmp    = 100;
static uint32_t seconds_tmp   = 1000;
static uint32_t minutes_tmp   = 60;

/* Private function prototypes -----------------------------------------------*/
static void CronSysQuantum_Handler(void);
static void CronMillis_Handler(void);
static void CronSeconds_Handler(void);
static void CronMinutes_Handler(void);
static void Flags_Handler(void);









////////////////////////////////////////////////////////////////////////////////

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void) {

  Delay(500);

  while (1) {
    Delay_Handler(0);
    Cron_Handler();
    Flags_Handler();
  }
}








/********************************************************************************/
/*                                     CRON                                     */
/********************************************************************************/
void Cron_Handler() {
  $CronStart:
  if (SysTick->CTRL & (1 << SysTick_CTRL_COUNTFLAG_Pos)) { 
    sysQuantum++;
    CronSysQuantum_Handler();
  }

  if (sysQuantum >= millis_tmp) {
    millis++;
    millis_tmp = sysQuantum + 100;
    CronMillis_Handler();
  }
  
  if (millis >= seconds_tmp) {
    seconds++;
    seconds_tmp += 1000;
    CronSeconds_Handler();
  }
  
  if (seconds >= minutes_tmp) {
    minutes++;
    minutes_tmp += 60;
    CronMinutes_Handler();
  }

  while (sysQuantum < delay_tmp) {
    goto $CronStart;
  }
  // !!!!!!!!! The bug!!!!!!!!
  delay_tmp = 0;
  FLAG_CLR(_EREG_, _DELAYF_);
}






/********************************************************************************/
/*                             CRON EVENTS HANDLERS                             */
/********************************************************************************/
// ---- System Quantum ---- //
static void CronSysQuantum_Handler(void) {
  //
}

// ---- Milliseconds ---- //
static void CronMillis_Handler(void) {
  //
}

// ---- Seconds ---- //
static void CronSeconds_Handler(void) {
  //
  // LL_IWDG_ReloadCounter(IWDG);
}

// ---- Minutes ---- //
static void CronMinutes_Handler(void) {
  //
}






/********************************************************************************/
/*                                     FLAGS                                    */
/********************************************************************************/
void Flags_Handler(void){
  if (FLAG_CHECK(_EREG_, _BT7F_)) {
    // BasicTimer_FromIT_Handler(TIM7);
    FLAG_CLR(_EREG_, _BT7F_);
  }
}










/**
  * @brief  Reset of all peripherals, Initializes the Flash interface and the Systick.
  * @retval None
  */
void SystemInit(void) {

  #if (INSTRUCTION_CACHE_ENABLE != 0U)
    PREG_SET(FLASH->ACR, FLASH_ACR_ICEN_Pos);
  #endif /* INSTRUCTION_CACHE_ENABLE */

  #if (DATA_CACHE_ENABLE != 0U)
    PREG_SET(FLASH->ACR, FLASH_ACR_DCEN_Pos);
  #endif /* DATA_CACHE_ENABLE */

  #if (PREFETCH_ENABLE != 0U)
    PREG_SET(FLASH->ACR, FLASH_ACR_PRFTEN_Pos);
  #endif /* PREFETCH_ENABLE */

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    /* SysTick */
  SysTick->CTRL     = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk;
  SysTick->LOAD     = 1680U - 1U;
  SysTick->VAL      = 0;
  SysTick->CTRL     |= SysTick_CTRL_ENABLE_Msk;

  /* SysTick interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
  NVIC_EnableIRQ(SysTick_IRQn);

  /* SysCfg */
  PREG_SET(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN_Pos);
  check = 0;
  while (!check) {
    check = PREG_CHECK(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN_Pos);
  }

  /* PWR */
  PREG_SET(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos);
  check = 0;
  while (!check) {
    check = PREG_CHECK(RCC->APB1ENR, RCC_APB1ENR_PWREN_Pos);
  }

  /* FLASH_IRQn interrupt configuration */
  NVIC_SetPriority(FLASH_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
  NVIC_EnableIRQ(FLASH_IRQn);

  /* RCC_IRQn interrupt configuration */
  NVIC_SetPriority(RCC_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
  NVIC_EnableIRQ(RCC_IRQn);





  MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_5WS);

  if (READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY) != FLASH_ACR_LATENCY_5WS) {
    Error_Handler();
  }
  
  MODIFY_REG(PWR->CR, PWR_CR_VOS, PWR_CR_VOS);

   /* HSE enable and wait till it's ready */
  PREG_SET(RCC->CR, RCC_CR_HSEON_Pos);
  check = 0;
  while(check) {
    check = PREG_CHECK(RCC->CR, RCC_CR_HSERDY_Pos);
  }
  
  /* LSI enable and wait till it's ready */
  PREG_SET(RCC->CSR, RCC_CSR_LSION_Pos);
  check = 0;
  while(check) {
    check = PREG_CHECK(RCC->CSR, RCC_CSR_LSIRDY_Pos);
  }

  /* Backup registers enable access */
  PREG_SET(PWR->CR, PWR_CR_DBP_Pos);

  /* force backup domain reset */
  PREG_SET(RCC->BDCR, RCC_BDCR_BDRST_Pos);
  PREG_CLR(RCC->BDCR, RCC_BDCR_BDRST_Pos);
  
  /* LSE enable and wait till it's ready */
  PREG_SET(RCC->BDCR, RCC_BDCR_LSEON_Pos);
  check = 0;
  while(check) {
    check = PREG_CHECK(RCC->CSR, RCC_BDCR_LSERDY_Pos);
  }
  // while(!(READ_BIT(RCC->BDCR, RCC_BDCR_LSERDY) == (RCC_BDCR_LSERDY)));

  /* RTC source is LSE */
  MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, RCC_BDCR_RTCSEL_0);

  /* Enable RTC */
  PREG_SET(RCC->BDCR, RCC_BDCR_RTCEN_Pos);

  /* Configure PLL domain end prescaller */
  MODIFY_REG(RCC->PLLCFGR, (RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN), (RCC_PLLCFGR_PLLSRC_HSE | RCC_PLLCFGR_PLLM_2 | 168 << RCC_PLLCFGR_PLLN_Pos));
  /* PLL isn't divided */
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLP, 0);
  
  /* PLL enable and wait till it's ready */
  PREG_SET(RCC->CR, RCC_CR_PLLON_Pos);
  check = 0;
  while (check) {
    check = PREG_CHECK(RCC->CR, RCC_CR_PLLRDY_Pos);
  }


  /* AHB isn't divided */
  // MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, LL_RCC_SYSCLK_DIV_1);
  /* APB1 divided by 4 */
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_CFGR_PPRE1_DIV4);
  /* APB2 divided by 2 */
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, RCC_CFGR_PPRE2_DIV2);

  /* Enable PLL as sysclock and wait till it's ready */
  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
  while(!(READ_BIT(RCC->CFGR, RCC_CFGR_SWS) == RCC_CFGR_SWS_PLL));

  SystemCoreClock = 168000000;
}


