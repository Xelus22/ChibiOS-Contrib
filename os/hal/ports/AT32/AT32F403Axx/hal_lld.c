/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    AT32F1xx/hal_lld.c
 * @brief   AT32F1xx HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   CMSIS system core clock variable.
 * @note    It is declared in system_AT32f10x.h.
 */
uint32_t SystemCoreClock = AT32_HCLK;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Initializes the backup domain.
 * @note    WARNING! Changing clock source impossible without resetting
 *          of the whole BKP domain.
 */
static void hal_lld_backup_domain_init(void) {

  /* Backup domain access enabled and left open.*/
  PWR->CR |= PWR_CR_DBP;

#if HAL_USE_RTC
  /* Reset BKP domain if different clock source selected.*/
  if ((RCC->BDCR & AT32_RTCSEL_MASK) != AT32_RTCSEL) {
    /* Backup domain reset.*/
    RCC->BDCR = RCC_BDCR_BDRST;
    RCC->BDCR = 0;
  }

  /* If enabled then the LSE is started.*/
#if AT32_LSE_ENABLED
#if defined(AT32_LSE_BYPASS)
  /* LSE Bypass.*/
  RCC->BDCR |= RCC_BDCR_LSEON | RCC_BDCR_LSEBYP;
#else
  /* No LSE Bypass.*/
  RCC->BDCR |= RCC_BDCR_LSEON;
#endif
  while ((RCC->BDCR & RCC_BDCR_LSERDY) == 0)
    ;                                     /* Waits until LSE is stable.   */
#endif /* AT32_LSE_ENABLED */

#if AT32_RTCSEL != AT32_RTCSEL_NOCLOCK
  /* If the backup domain hasn't been initialized yet then proceed with
     initialization.*/
  if ((RCC->BDCR & RCC_BDCR_RTCEN) == 0) {
    /* Selects clock source.*/
    RCC->BDCR |= AT32_RTCSEL;

    /* Prescaler value loaded in registers.*/
    rtc_lld_set_prescaler();

    /* RTC clock enabled.*/
    RCC->BDCR |= RCC_BDCR_RTCEN;
  }
#endif /* AT32_RTCSEL != AT32_RTCSEL_NOCLOCK */
#endif /* HAL_USE_RTC */
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_DMA_REQUIRED) || defined(__DOXYGEN__)
#if defined(AT32_DMA2_CH45_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   DMA2 streams 4 and 5 shared ISR.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_DMA2_CH45_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Check on channel 4 of DMA2.*/
  dmaServeInterrupt(AT32_DMA2_STREAM4);

  /* Check on channel 5 of DMA2.*/
  dmaServeInterrupt(AT32_DMA2_STREAM5);

  OSAL_IRQ_EPILOGUE();
}
#endif /* defined(AT32_DMA2_CH45_HANDLER) */

#if defined(AT32_DMA2_CH67_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   DMA2 streams 6 and 7 shared ISR.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_DMA2_CH67_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Check on channel 6 of DMA2.*/
  dmaServeInterrupt(AT32_DMA2_STREAM6);

  /* Check on channel 7 of DMA2.*/
  dmaServeInterrupt(AT32_DMA2_STREAM7);

  OSAL_IRQ_EPILOGUE();
}
#endif /* defined(AT32_DMA2_CH67_HANDLER) */
#endif /* defined(AT32_DMA_REQUIRED) */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {

  /* Reset of all peripherals.*/
  rccResetAPB1(0xFFFFFFFF);
  rccResetAPB2(0xFFFFFFFF);

  /* PWR and BD clocks enabled.*/
  rccEnablePWRInterface(true);
  rccEnableBKPInterface(true);

  /* Initializes the backup domain.*/
  hal_lld_backup_domain_init();

  /* DMA subsystems initialization.*/
#if defined(AT32_DMA_REQUIRED)
  dmaInit();
#endif

  /* IRQ subsystem initialization.*/
  irqInit();

  /* Programmable voltage detector enable.*/
#if AT32_PVD_ENABLE
  PWR->CR |= PWR_CR_PVDE | (AT32_PLS & AT32_PLS_MASK);
#endif /* AT32_PVD_ENABLE */
}

/**
 * @brief   AT32 clocks and PLL initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */
#if defined(AT32F10X_LD) || defined(AT32F10X_LD_VL) ||                    \
    defined(AT32F10X_MD) || defined(AT32F10X_MD_VL) ||                    \
    defined(AT32F10X_HD) || defined(AT32F10X_XL) ||                       \
    defined(__DOXYGEN__)
/*
 * Clocks initialization for all sub-families except CL.
 */
void AT32_clock_init(void) {

#if !AT32_NO_INIT
  /* HSI setup, it enforces the reset situation in order to handle possible
     problems with JTAG probes and re-initializations.*/
  RCC->CR |= RCC_CR_HSION;                  /* Make sure HSI is ON.         */
  while (!(RCC->CR & RCC_CR_HSIRDY))
    ;                                       /* Wait until HSI is stable.    */
  RCC->CR &= RCC_CR_HSITRIM | RCC_CR_HSION; /* CR Reset value.              */
  RCC->CFGR = 0;                            /* CFGR reset value.            */
  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI)
    ;                                       /* Waits until HSI is selected. */

#if AT32_HSE_ENABLED
#if defined(AT32_HSE_BYPASS)
  /* HSE Bypass.*/
  RCC->CR |= RCC_CR_HSEON | RCC_CR_HSEBYP;
#endif
  /* HSE activation.*/
  RCC->CR |= RCC_CR_HSEON;
  while (!(RCC->CR & RCC_CR_HSERDY))
    ;                                       /* Waits until HSE is stable.   */
#endif

#if AT32_LSI_ENABLED
  /* LSI activation.*/
  RCC->CSR |= RCC_CSR_LSION;
  while ((RCC->CSR & RCC_CSR_LSIRDY) == 0)
    ;                                       /* Waits until LSI is stable.   */
#endif

#if AT32_ACTIVATE_PLL
  /* PLL activation.*/
  RCC->CFGR |= AT32_PLLMUL | AT32_PLLXTPRE | AT32_PLLSRC;
  RCC->CR   |= RCC_CR_PLLON;
  while (!(RCC->CR & RCC_CR_PLLRDY))
    ;                                       /* Waits until PLL is stable.   */
#endif

  /* Clock settings.*/
#if AT32_HAS_USB
  RCC->CFGR = AT32_MCOSEL | AT32_USBPRE | AT32_PLLMUL | AT32_PLLXTPRE |
              AT32_PLLSRC | AT32_ADCPRE | AT32_PPRE2  | AT32_PPRE1    |
              AT32_HPRE;
#else
  RCC->CFGR = AT32_MCOSEL |                AT32_PLLMUL | AT32_PLLXTPRE |
              AT32_PLLSRC | AT32_ADCPRE | AT32_PPRE2  | AT32_PPRE1    |
              AT32_HPRE;
#endif

  /* Flash setup and final clock selection.   */
  FLASH->ACR = AT32_FLASHBITS;

  /* Switching to the configured clock source if it is different from HSI.*/
#if (AT32_SW != AT32_SW_HSI)
  /* Switches clock source.*/
  RCC->CFGR |= AT32_SW;
  while ((RCC->CFGR & RCC_CFGR_SWS) != (AT32_SW << 2))
    ;                                       /* Waits selection complete.    */
#endif

#if !AT32_HSI_ENABLED
  RCC->CR &= ~RCC_CR_HSION;
#endif
#endif /* !AT32_NO_INIT */
}

#elif defined(AT32F10X_CL)
/*
 * Clocks initialization for the CL sub-family.
 */
void AT32_clock_init(void) {

#if !AT32_NO_INIT
  /* HSI setup, it enforces the reset situation in order to handle possible
     problems with JTAG probes and re-initializations.*/
  RCC->CR |= RCC_CR_HSION;                  /* Make sure HSI is ON.         */
  while (!(RCC->CR & RCC_CR_HSIRDY))
    ;                                       /* Wait until HSI is stable.    */

  /* HSI is selected as new source without touching the other fields in
     CFGR. Clearing the register has to be postponed after HSI is the
     new source.*/
  RCC->CFGR &= ~RCC_CFGR_SW;                /* Reset SW, selecting HSI.     */
  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI)
    ;                                       /* Wait until HSI is selected.  */

  /* Registers finally cleared to reset values.*/
  RCC->CR &= RCC_CR_HSITRIM | RCC_CR_HSION; /* CR Reset value.              */
  RCC->CFGR = 0;                            /* CFGR reset value.            */

#if AT32_HSE_ENABLED
#if defined(AT32_HSE_BYPASS)
  /* HSE Bypass.*/
  RCC->CR |= RCC_CR_HSEBYP;
#endif
  /* HSE activation.*/
  RCC->CR |= RCC_CR_HSEON;
  while (!(RCC->CR & RCC_CR_HSERDY))
    ;                                       /* Waits until HSE is stable.   */
#endif

#if AT32_LSI_ENABLED
  /* LSI activation.*/
  RCC->CSR |= RCC_CSR_LSION;
  while ((RCC->CSR & RCC_CSR_LSIRDY) == 0)
    ;                                       /* Waits until LSI is stable.   */
#endif

  /* Settings of various dividers and multipliers in CFGR2.*/
  RCC->CFGR2 = AT32_PLL3MUL | AT32_PLL2MUL | AT32_PREDIV2 |
               AT32_PREDIV1 | AT32_PREDIV1SRC;

  /* PLL2 setup, if activated.*/
#if AT32_ACTIVATE_PLL2
  RCC->CR |= RCC_CR_PLL2ON;
  while (!(RCC->CR & RCC_CR_PLL2RDY))
    ;                                        /* Waits until PLL2 is stable. */
#endif

  /* PLL3 setup, if activated.*/
#if AT32_ACTIVATE_PLL3
  RCC->CR |= RCC_CR_PLL3ON;
  while (!(RCC->CR & RCC_CR_PLL3RDY))
    ;                                        /* Waits until PLL3 is stable. */
#endif

  /* PLL1 setup, if activated.*/
#if AT32_ACTIVATE_PLL1
  RCC->CFGR |= AT32_PLLMUL | AT32_PLLSRC;
  RCC->CR   |= RCC_CR_PLLON;
  while (!(RCC->CR & RCC_CR_PLLRDY))
    ;                           /* Waits until PLL1 is stable.              */
#endif

  /* Clock settings.*/
#if AT32_HAS_OTG1
  RCC->CFGR = AT32_MCOSEL | AT32_OTGFSPRE | AT32_PLLMUL | AT32_PLLSRC |
              AT32_ADCPRE | AT32_PPRE2    | AT32_PPRE1  | AT32_HPRE;
#else
  RCC->CFGR = AT32_MCO    |                  AT32_PLLMUL | AT32_PLLSRC |
              AT32_ADCPRE | AT32_PPRE2    | AT32_PPRE1  | AT32_HPRE;
#endif

  /* Flash setup and final clock selection.   */
  FLASH->ACR = AT32_FLASHBITS; /* Flash wait states depending on clock.    */
  while ((FLASH->ACR & FLASH_ACR_LATENCY_Msk) !=
         (AT32_FLASHBITS & FLASH_ACR_LATENCY_Msk)) {
  }

  /* Switching to the configured clock source if it is different from HSI.*/
#if (AT32_SW != AT32_SW_HSI)
  RCC->CFGR |= AT32_SW;        /* Switches on the selected clock source.   */
  while ((RCC->CFGR & RCC_CFGR_SWS) != (AT32_SW << 2))
    ;
#endif

#if !AT32_HSI_ENABLED
  RCC->CR &= ~RCC_CR_HSION;
#endif
#endif /* !AT32_NO_INIT */
}
#else
void AT32_clock_init(void) {}
#endif

/** @} */
