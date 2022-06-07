/*
    Copyright (C) 2022 Harrison Chan

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
 * @file    AT32F403Axx/hal_lld.h
 * @brief   AT32F403Axx HAL subsystem low level driver header.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef AT32_REGISTRY_H
#define AT32_REGISTRY_H

#include "at32_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Platform identification
 * @{
 */
#if defined(__DOXYGEN__)
#define PLATFORM_NAME           "AT32F403Axx"

#elif defined(AT32F403xC)
#define PLATFORM_NAME           "AT32F403AxC"

#elif defined(AT32F403xE)
#define PLATFORM_NAME           "AT32F403AxE"

#elif defined(AT32F403xG)
#define PLATFORM_NAME           "AT32F403AxG"

#else
#error "unsupported or unrecognized AT32F403Axx member"
#endif

/**
 * @brief   Sub-family identifier.
 */
#if !defined(AT32F403Axx) || defined(__DOXYGEN__)
#define AT32F403Axx
#endif
/** @} */


/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Absolute Maximum Ratings
 * @{
 */
/**
 * @brief   Maximum system clock frequency.
 */
#define AT32_SYSCLK_MAX        240000000

/**
 * @brief   Maximum HSE clock frequency.
 */
#define AT32_HSECLK_MAX        25000000

/**
 * @brief   Minimum HSE clock frequency.
 */
#define AT32_HSECLK_MIN        4000000

/**
 * @brief   Maximum LSE clock frequency.
 */
#define AT32_LSECLK_MAX        1000000

/**
 * @brief   Minimum LSE clock frequency.
 */
#define AT32_LSECLK_MIN        32768

/**
 * @brief   Maximum PLLs input clock frequency. - AHBCLK
 */
#define AT32_PLLIN_MAX         240000000

/**
 * @brief   Minimum PLLs input clock frequency. - AHBCLK
 */
#define AT32_PLLIN_MIN         4000000

/**
 * @brief   Maximum PLL output clock frequency. - SCLK
 */
#define AT32_PLLOUT_MAX        240000000

/**
 * @brief   Minimum PLL output clock frequency. - SCLK
 */
#define AT32_PLLOUT_MIN        4000000

/**
 * @brief   Maximum APB1 clock frequency.
 */
#define AT32_PCLK1_MAX         120000000

/**
 * @brief   Maximum APB2 clock frequency.
 */
#define AT32_PCLK2_MAX         120000000

/**
 * @brief   Maximum ADC clock frequency.
 */
#define AT32_ADCCLK_MAX        28000000
/** @} */

/**
 * @name    RCC_CFGR register bits definitions - RCC_CFG
 * @{
 */
#define AT32_SW_HSI            (0 << 0)    /**< SYSCLK source is HSI.      */
#define AT32_SW_HSE            (1 << 0)    /**< SYSCLK source is HSE.      */
#define AT32_SW_PLL            (2 << 0)    /**< SYSCLK source is PLL.      */

#define AT32_HPRE_DIV1         (0 << 4)    /**< SYSCLK divided by 1.       */
#define AT32_HPRE_DIV2         (8 << 4)    /**< SYSCLK divided by 2.       */
#define AT32_HPRE_DIV4         (9 << 4)    /**< SYSCLK divided by 4.       */
#define AT32_HPRE_DIV8         (10 << 4)   /**< SYSCLK divided by 8.       */
#define AT32_HPRE_DIV16        (11 << 4)   /**< SYSCLK divided by 16.      */
#define AT32_HPRE_DIV64        (12 << 4)   /**< SYSCLK divided by 64.      */
#define AT32_HPRE_DIV128       (13 << 4)   /**< SYSCLK divided by 128.     */
#define AT32_HPRE_DIV256       (14 << 4)   /**< SYSCLK divided by 256.     */
#define AT32_HPRE_DIV512       (15 << 4)   /**< SYSCLK divided by 512.     */

#define AT32_PPRE1_DIV1        (0 << 8)    /**< HCLK divided by 1.         */
#define AT32_PPRE1_DIV2        (4 << 8)    /**< HCLK divided by 2.         */
#define AT32_PPRE1_DIV4        (5 << 8)    /**< HCLK divided by 4.         */
#define AT32_PPRE1_DIV8        (6 << 8)    /**< HCLK divided by 8.         */
#define AT32_PPRE1_DIV16       (7 << 8)    /**< HCLK divided by 16.        */

#define AT32_PPRE2_DIV1        (0 << 11)   /**< HCLK divided by 1.         */
#define AT32_PPRE2_DIV2        (4 << 11)   /**< HCLK divided by 2.         */
#define AT32_PPRE2_DIV4        (5 << 11)   /**< HCLK divided by 4.         */
#define AT32_PPRE2_DIV8        (6 << 11)   /**< HCLK divided by 8.         */
#define AT32_PPRE2_DIV16       (7 << 11)   /**< HCLK divided by 16.        */

#define AT32_ADCPRE_DIV2       (0 << 14)   /**< PPRE2 divided by 2.        */
#define AT32_ADCPRE_DIV4       (1 << 14)   /**< PPRE2 divided by 4.        */
#define AT32_ADCPRE_DIV6       (2 << 14)   /**< PPRE2 divided by 6.        */
#define AT32_ADCPRE_DIV8       (3 << 14)   /**< PPRE2 divided by 8.        */

#define AT32_PLLSRC_HSI        (0 << 16)   /**< PLL clock source is HSI.   */
#define AT32_PLLSRC_HSE        (1 << 16)   /**< PLL clock source is HSE.   */

#define AT32_PLLXTPRE_DIV1     (0 << 17)   /**< HSE divided by 1.          */
#define AT32_PLLXTPRE_DIVX     (1 << 17)   /**< HSE divided by AT32_HSE_PRE_PLL_DIVx */

#define AT32_USBPRE_DIV1P5     (0 << 22)   /**< PLLOUT divided by 1.5.     */
#define AT32_USBPRE_DIV1       (1 << 22)   /**< PLLOUT divided by 1.       */
#define AT32_USBPRE_DIV2P5     (2 << 22)   /**< PLLOUT divided by 2.5.     */
#define AT32_USBPRE_DIV2       (3 << 22)   /**< PLLOUT divided by 2.       */

#define AT32_MCOSEL_NOCLOCK    (0 << 24)   /**< No clock on MCO pin.       */
#define AT32_MCOSEL_SYSCLK     (4 << 24)   /**< SYSCLK on MCO pin.         */
#define AT32_MCOSEL_HSI        (5 << 24)   /**< HSI clock on MCO pin.      */
#define AT32_MCOSEL_HSE        (6 << 24)   /**< HSE clock on MCO pin.      */
#define AT32_MCOSEL_PLLDIV2    (7 << 24)   /**< PLL/2 clock on MCO pin.    */
/** @} */

/**
 * @name    RCC_BDCR register bits definitions - RCC_BDC
 * @{
 */
#define AT32_RTCSEL_MASK       (3 << 8)    /**< RTC clock source mask.     */
#define AT32_RTCSEL_NOCLOCK    (0 << 8)    /**< No clock.                  */
#define AT32_RTCSEL_LSE        (1 << 8)    /**< LSE used as RTC clock.     */
#define AT32_RTCSEL_LSI        (2 << 8)    /**< LSI used as RTC clock.     */
#define AT32_RTCSEL_HSEDIV     (3 << 8)    /**< HSE divided by 128 used as
                                                 RTC clock.                 */
/** @} */

/**
 * @name    RCC_MISC Additional Register
 * @{
 */
#define AT32_HSI_SRC_DIV6      (0 << 25)    /**< HSI 6 divider enable 8MHz*/
#define AT32_HSI_SRC_DIV1      (1 << 25)    /**< HSI outputs undivided clock 48MHz */
                                            /**< sets HSI_DIV_EN=1  */

/**
 * @name    RCC_MISC2 Additional Register
 * @{
 */
#define AT32_USB_SRC_PLL       (0 << 8)     /**< USB clock source is PLL or divider */
#define AT32_USB_SRC_HSI       (1 << 8)     /**< USB clock source is HSI            */
                                            /**< HSI_DIV_EN=1 must be guaranteed>   */

#define AT32_HSI_SYS_SRC_HSI_DIV6   (0 << 9)     /**< SCLK HSI source is 8MHz */
#define AT32_HSI_SYS_SRC_HSI_DIV_EN (1 << 9)     /**< SCLK HSI source is 48MHz or 8MHz   */
                                                 /**< HSI_DIV_EN=1, 48MHz>   */

#define AT32_HSE_PRE_PLL_DIV2  (0 << 12)    /**< HSE clock divide by 2      */
#define AT32_HSE_PRE_PLL_DIV3  (1 << 12)    /**< HSE clock divide by 3      */
#define AT32_HSE_PRE_PLL_DIV4  (2 << 12)    /**< HSE clock divide by 4      */
#define AT32_HSE_PRE_PLL_DIV5  (3 << 12)    /**< HSE clock divide by 5      */


/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define AT32_HSICLK            48000000    /**< High speed internal clock. */
#define AT32_LSICLK            40000       /**< Low speed internal clock.  */
/** @} */

/**
 * @name    PWR_CR register bits definitions PWR_CTRL
 * @{
 */
#define AT32_PLS_MASK          (7 << 5)    /**< PLS bits mask.             */
#define AT32_PLS_LEV0          (0 << 5)    /**< PVD level 0.               */
#define AT32_PLS_LEV1          (1 << 5)    /**< PVD level 1.               */
#define AT32_PLS_LEV2          (2 << 5)    /**< PVD level 2.               */
#define AT32_PLS_LEV3          (3 << 5)    /**< PVD level 3.               */
#define AT32_PLS_LEV4          (4 << 5)    /**< PVD level 4.               */
#define AT32_PLS_LEV5          (5 << 5)    /**< PVD level 5.               */
#define AT32_PLS_LEV6          (6 << 5)    /**< PVD level 6.               */
#define AT32_PLS_LEV7          (7 << 5)    /**< PVD level 7.               */
/** @} */

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Disables the PWR/RCC initialization in the HAL.
 */
#if !defined(AT32_NO_INIT) || defined(__DOXYGEN__)
#define AT32_NO_INIT               FALSE
#endif

/**
 * @brief   Enables or disables the programmable voltage detector.
 */
#if !defined(AT32_PVD_ENABLE) || defined(__DOXYGEN__)
#define AT32_PVD_ENABLE            FALSE
#endif

/**
 * @brief   Sets voltage level for programmable voltage detector.
 */
#if !defined(AT32_PLS) || defined(__DOXYGEN__)
#define AT32_PLS                   AT32_PLS_LEV0
#endif

/**
 * @brief   Enables or disables the HSI clock source.
 */
#if !defined(AT32_HSI_ENABLED) || defined(__DOXYGEN__)
#define AT32_HSI_ENABLED           TRUE
#endif

/**
 * @brief   Enables or disables the LSI clock source.
 */
#if !defined(AT32_LSI_ENABLED) || defined(__DOXYGEN__)
#define AT32_LSI_ENABLED           FALSE
#endif

/**
 * @brief   Enables or disables the HSE clock source.
 */
#if !defined(AT32_HSE_ENABLED) || defined(__DOXYGEN__)
#define AT32_HSE_ENABLED           FALSE
#endif

/**
 * @brief   Enables or disables the LSE clock source.
 */
#if !defined(AT32_LSE_ENABLED) || defined(__DOXYGEN__)
#define AT32_LSE_ENABLED           FALSE
#endif
/** @} */

// TODO:

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Main clock source selection.
 * @note    If the selected clock source is not the PLL then the PLL is not
 *          initialized and started.
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HSI crystal using the PLL.
 */
#if !defined(AT32_SW) || defined(__DOXYGEN__)
#define AT32_SW                    AT32_SW_PLL
#endif

/**
 * @brief   Clock source for the PLL.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HSI crystal using the PLL.
 */
#if !defined(AT32_PLLSRC) || defined(__DOXYGEN__)
#define AT32_PLLSRC                AT32_PLLSRC_HSI
#endif

/**
 * @brief   Clock source to control HSI SYS CTRL
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HSI crystal using the PLL.
 */
#if !defined(AT32_HSI_SYS_SRC) || defined(__DOXYGEN__)
#define AT32_HSI_SYS_SRC           AT32_HSI_SYS_SRC_HSI_DIV_EN
#endif

/**
 * @brief   Clock source to control HSI DIV EN
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HSI crystal using the PLL.
 */
#if !defined(AT32_HSI_SRC) || defined(__DOXYGEN__)
#define AT32_HSI_SRC           AT32_HSI_SRC_DIV1
#endif

/**
 * @brief   HSE Crystal divider
 * @note    This setting has only effect if the HSE is enabled
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HSI crystal using the PLL.
 */
#if !defined(AT32_HSE_DIV) || defined(__DOXYGEN__)
#define AT32_HSE_DIV               AT32_HSE_PRE_PLL_DIV2
#endif

/**
 * @brief   Crystal PLL pre-divider.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HSI crystal using the PLL.
 */
#if !defined(AT32_PLLXTPRE) || defined(__DOXYGEN__)
#define AT32_PLLXTPRE              AT32_PLLXTPRE_DIV2
#endif

/**
 * @brief   PLL multiplier value.
 * @note    The allowed range is 2...16.
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HSI crystal using the PLL.
 */
#if !defined(AT32_PLLMUL_VALUE) || defined(__DOXYGEN__)
#define AT32_PLLMUL_VALUE          60
#endif

/**
 * @brief   AHB prescaler value.
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HSI crystal using the PLL.
 */
#if !defined(AT32_HPRE) || defined(__DOXYGEN__)
#define AT32_HPRE                  AT32_HPRE_DIV1
#endif

/**
 * @brief   APB1 prescaler value.
 */
#if !defined(AT32_PPRE1) || defined(__DOXYGEN__)
#define AT32_PPRE1                 AT32_PPRE1_DIV2
#endif

/**
 * @brief   APB2 prescaler value.
 */
#if !defined(AT32_PPRE2) || defined(__DOXYGEN__)
#define AT32_PPRE2                 AT32_PPRE2_DIV2
#endif

/**
 * @brief   ADC prescaler value.
 */
#if !defined(AT32_ADCPRE) || defined(__DOXYGEN__)
#define AT32_ADCPRE                AT32_ADCPRE_DIV4
#endif

/**
 * @brief   USB clock setting.
 */
#if !defined(AT32_USB_CLOCK_REQUIRED) || defined(__DOXYGEN__)
#define AT32_USB_CLOCK_REQUIRED    TRUE
#endif

/**
 * @brief   USB prescaler initialization.
 */
#if !defined(AT32_USBPRE) || defined(__DOXYGEN__)
#define AT32_USBPRE                AT32_USBPRE_DIV1
#endif

/**
 * @brief   MCO pin setting.
 */
#if !defined(AT32_MCOSEL) || defined(__DOXYGEN__)
#define AT32_MCOSEL                AT32_MCOSEL_NOCLOCK
#endif

/**
 * @brief   RTC clock source.
 */
#if !defined(AT32_RTCSEL) || defined(__DOXYGEN__)
#define AT32_RTCSEL                AT32_RTCSEL_NOCLOCK
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
/*
 * Configuration-related checks.
 */
#if !defined(AT32F403A_MCUCONF)
#error "Using a wrong mcuconf.h file, AT32F403A_MCUCONF not defined"
#endif

/*
 * HSI related checks.
 */
#if AT32_HSI_ENABLED
#else /* !AT32_HSI_ENABLED */

#if AT32_SW == AT32_SW_HSI
#error "HSI not enabled, required by AT32_SW"
#endif

#if (AT32_SW == AT32_SW_PLL) && (AT32_PLLSRC == AT32_PLLSRC_HSI)
#error "HSI not enabled, required by AT32_SW and AT32_PLLSRC"
#endif

#if (AT32_MCOSEL == AT32_MCOSEL_HSI) ||                                   \
    ((AT32_MCOSEL == AT32_MCOSEL_PLLDIV2) &&                              \
     (AT32_PLLSRC == AT32_PLLSRC_HSI))
#error "HSI not enabled, required by AT32_MCOSEL"
#endif

#endif /* !AT32_HSI_ENABLED */

/*
 * HSE related checks.
 */
#if AT32_HSE_ENABLED

#if AT32_HSECLK == 0
#error "HSE frequency not defined"
#elif (AT32_HSECLK < AT32_HSECLK_MIN) || (AT32_HSECLK > AT32_HSECLK_MAX)
#error "AT32_HSECLK outside acceptable range (AT32_HSECLK_MIN...AT32_HSECLK_MAX)"
#endif

#else /* !AT32_HSE_ENABLED */

#if AT32_SW == AT32_SW_HSE
#error "HSE not enabled, required by AT32_SW"
#endif

#if (AT32_SW == AT32_SW_PLL) && (AT32_PLLSRC == AT32_PLLSRC_HSE)
#error "HSE not enabled, required by AT32_SW and AT32_PLLSRC"
#endif

#if (AT32_MCOSEL == AT32_MCOSEL_HSE) ||                                   \
    ((AT32_MCOSEL == AT32_MCOSEL_PLLDIV2) &&                              \
     (AT32_PLLSRC == AT32_PLLSRC_HSE))
#error "HSE not enabled, required by AT32_MCOSEL"
#endif

#if AT32_RTCSEL == AT32_RTCSEL_HSEDIV
#error "HSE not enabled, required by AT32_RTCSEL"
#endif

#endif /* !AT32_HSE_ENABLED */

/*
 * LSI related checks.
 */
#if AT32_LSI_ENABLED
#else /* !AT32_LSI_ENABLED */

#if HAL_USE_RTC && (AT32_RTCSEL == AT32_RTCSEL_LSI)
#error "LSI not enabled, required by AT32_RTCSEL"
#endif

#endif /* !AT32_LSI_ENABLED */

/*
 * LSE related checks.
 */
#if AT32_LSE_ENABLED

#if (AT32_LSECLK == 0)
#error "LSE frequency not defined"
#endif

#if (AT32_LSECLK < AT32_LSECLK_MIN) || (AT32_LSECLK > AT32_LSECLK_MAX)
#error "AT32_LSECLK outside acceptable range (AT32_LSECLK_MIN...AT32_LSECLK_MAX)"
#endif

#else /* !AT32_LSE_ENABLED */

#if AT32_RTCSEL == AT32_RTCSEL_LSE
#error "LSE not enabled, required by AT32_RTCSEL"
#endif

#endif /* !AT32_LSE_ENABLED */

/* PLL activation conditions.*/
#if AT32_USB_CLOCK_REQUIRED ||                                            \
    (AT32_SW == AT32_SW_PLL) ||                                           \
    (AT32_MCOSEL == AT32_MCOSEL_PLLDIV2) ||                               \
    defined(__DOXYGEN__)
/**
 * @brief   PLL activation flag.
 */
#define AT32_ACTIVATE_PLL          TRUE
#else
#define AT32_ACTIVATE_PLL          FALSE
#endif

/* HSE divider setting check.*/
#if (AT32_HSE_DIV != AT32_HSE_PRE_PLL_DIV2) &&                           \
    (AT32_HSE_DIV != AT32_HSE_PRE_PLL_DIV3) &&                           \
    (AT32_HSE_DIV != AT32_HSE_PRE_PLL_DIV4) &&                           \
    (AT32_HSE_DIV != AT32_HSE_PRE_PLL_DIV5)
#error "invalid AT32_PLLXTPRE value specified"
#endif

/* HSE prescaler setting check.*/
#if (AT32_PLLXTPRE != AT32_PLLXTPRE_DIV1) &&                           \
    (AT32_PLLXTPRE != AT32_PLLXTPRE_DIVX)
#error "invalid AT32_PLLXTPRE value specified"
#endif

/**
 * @brief   PLLMUL field.
 */
#if ((AT32_PLLMUL_VALUE >= 2) && (AT32_PLLMUL_VALUE <= 64)) ||            \
    defined(__DOXYGEN__)
#define AT32_PLLMUL                ((AT32_PLLMUL_VALUE - 2) << 18)
#else
#error "invalid AT32_PLLMUL_VALUE value specified"
#endif

/**
 * @brief   PLL input clock frequency.
 */
#if (AT32_PLLSRC == AT32_PLLSRC_HSE) || defined(__DOXYGEN__)
#if AT32_PLLXTPRE == AT32_PLLXTPRE_DIV1
#define AT32_PLLCLKIN              (AT32_HSECLK / 1)
#elif (AT32_PLLXTPRE == AT32_PLLXTPRE_DIVX) && (AT32_HSE_DIV == AT32_HSE_PRE_PLL_DIV2)
#define AT32_PLLCLKIN              (AT32_HSECLK / 2)
#elif (AT32_PLLXTPRE == AT32_PLLXTPRE_DIVX) && (AT32_HSE_DIV == AT32_HSE_PRE_PLL_DIV3)
#define AT32_PLLCLKIN              (AT32_HSECLK / 3)
#elif (AT32_PLLXTPRE == AT32_PLLXTPRE_DIVX) && (AT32_HSE_DIV == AT32_HSE_PRE_PLL_DIV4)
#define AT32_PLLCLKIN              (AT32_HSECLK / 4)
#elif (AT32_PLLXTPRE == AT32_PLLXTPRE_DIVX) && (AT32_HSE_DIV == AT32_HSE_PRE_PLL_DIV5)
#define AT32_PLLCLKIN              (AT32_HSECLK / 5)
#else
#error "invalid AT32_HSE_DIV value specified"
#endif
#elif AT32_PLLSRC == AT32_PLLSRC_HSI
#define AT32_PLLCLKIN              (AT32_HSICLK / 12)
#else
#error "invalid AT32_PLLSRC value specified"
#endif

/* PLL input frequency range check.*/
#if (AT32_PLLCLKIN < AT32_PLLIN_MIN) || (AT32_PLLCLKIN > AT32_PLLIN_MAX)
#error "AT32_PLLCLKIN outside acceptable range (AT32_PLLIN_MIN...AT32_PLLIN_MAX)"
#endif

/**
 * @brief   PLL output clock frequency.
 */
#define AT32_PLLCLKOUT             (AT32_PLLCLKIN * AT32_PLLMUL_VALUE)

/* PLL output frequency range check.*/
#if (AT32_PLLCLKOUT < AT32_PLLOUT_MIN) || (AT32_PLLCLKOUT > AT32_PLLOUT_MAX)
#error "AT32_PLLCLKOUT outside acceptable range (AT32_PLLOUT_MIN...AT32_PLLOUT_MAX)"
#endif

/**
 * @brief   HSI clock source out to Sys Clock
 * @note    Controlled by HSI_DIV_EN and HSI_SYS_CTRL
 */
#if (AT32_HSI_SYS_SRC == AT32_HSI_SYS_SRC_HSI_DIV_EN)
    #if (AT32_HSI_SRC == AT32_HSI_SRC_DIV1)
    #define AT32_HSI_SYS_CLK            AT32_HSICLK
    #elif (AT32_HSI_SRC == AT32_HSI_SRC_DIV6)
    #define AT32_HSI_SYS_CLK            (AT32_HSICLK / 6)
    #else
    #error "invalid AT32_HSI_SRC value specified"
    #endif
#elif (AT32_HSI_SYS_SRC == AT32_HSI_SYS_SRC_HSI_DIV6)
#define AT32_HSI_SYS_CLK            (AT32_HSICLK / 6)
#else 
#error "invalid AT32_HSI_SYS_SRC value specified"
#endif


/**
 * @brief   System clock source.
 */
#if (AT32_SW == AT32_SW_PLL) || defined(__DOXYGEN__)
#define AT32_SYSCLK                AT32_PLLCLKOUT
#elif (AT32_SW == AT32_SW_HSI)
#define AT32_SYSCLK                AT32_HSI_SYS_CLK
#elif (AT32_SW == AT32_SW_HSE)
#define AT32_SYSCLK                AT32_HSECLK
#else
#error "invalid AT32_SW value specified"
#endif

/* Check on the system clock.*/
#if AT32_SYSCLK > AT32_SYSCLK_MAX
#error "AT32_SYSCLK above maximum rated frequency (AT32_SYSCLK_MAX)"
#endif

/**
 * @brief   AHB frequency.
 */
#if (AT32_HPRE == AT32_HPRE_DIV1) || defined(__DOXYGEN__)
#define AT32_HCLK                  (AT32_SYSCLK / 1)
#elif AT32_HPRE == AT32_HPRE_DIV2
#define AT32_HCLK                  (AT32_SYSCLK / 2)
#elif AT32_HPRE == AT32_HPRE_DIV4
#define AT32_HCLK                  (AT32_SYSCLK / 4)
#elif AT32_HPRE == AT32_HPRE_DIV8
#define AT32_HCLK                  (AT32_SYSCLK / 8)
#elif AT32_HPRE == AT32_HPRE_DIV16
#define AT32_HCLK                  (AT32_SYSCLK / 16)
#elif AT32_HPRE == AT32_HPRE_DIV64
#define AT32_HCLK                  (AT32_SYSCLK / 64)
#elif AT32_HPRE == AT32_HPRE_DIV128
#define AT32_HCLK                  (AT32_SYSCLK / 128)
#elif AT32_HPRE == AT32_HPRE_DIV256
#define AT32_HCLK                  (AT32_SYSCLK / 256)
#elif AT32_HPRE == AT32_HPRE_DIV512
#define AT32_HCLK                  (AT32_SYSCLK / 512)
#else
#error "invalid AT32_HPRE value specified"
#endif

/* AHB frequency check.*/
#if AT32_HCLK > AT32_SYSCLK_MAX
#error "AT32_HCLK exceeding maximum frequency (AT32_SYSCLK_MAX)"
#endif

/**
 * @brief   APB1 frequency.
 */
#if (AT32_PPRE1 == AT32_PPRE1_DIV1) || defined(__DOXYGEN__)
#define AT32_PCLK1                 (AT32_HCLK / 1)
#elif AT32_PPRE1 == AT32_PPRE1_DIV2
#define AT32_PCLK1                 (AT32_HCLK / 2)
#elif AT32_PPRE1 == AT32_PPRE1_DIV4
#define AT32_PCLK1                 (AT32_HCLK / 4)
#elif AT32_PPRE1 == AT32_PPRE1_DIV8
#define AT32_PCLK1                 (AT32_HCLK / 8)
#elif AT32_PPRE1 == AT32_PPRE1_DIV16
#define AT32_PCLK1                 (AT32_HCLK / 16)
#else
#error "invalid AT32_PPRE1 value specified"
#endif

/* APB1 frequency check.*/
#if AT32_PCLK1 > AT32_PCLK1_MAX
#error "AT32_PCLK1 exceeding maximum frequency (AT32_PCLK1_MAX)"
#endif

/**
 * @brief   APB2 frequency.
 */
#if (AT32_PPRE2 == AT32_PPRE2_DIV1) || defined(__DOXYGEN__)
#define AT32_PCLK2                 (AT32_HCLK / 1)
#elif AT32_PPRE2 == AT32_PPRE2_DIV2
#define AT32_PCLK2                 (AT32_HCLK / 2)
#elif AT32_PPRE2 == AT32_PPRE2_DIV4
#define AT32_PCLK2                 (AT32_HCLK / 4)
#elif AT32_PPRE2 == AT32_PPRE2_DIV8
#define AT32_PCLK2                 (AT32_HCLK / 8)
#elif AT32_PPRE2 == AT32_PPRE2_DIV16
#define AT32_PCLK2                 (AT32_HCLK / 16)
#else
#error "invalid AT32_PPRE2 value specified"
#endif

/* APB2 frequency check.*/
#if AT32_PCLK2 > AT32_PCLK2_MAX
#error "AT32_PCLK2 exceeding maximum frequency (AT32_PCLK2_MAX)"
#endif

/**
 * @brief   RTC clock.
 */
#if (AT32_RTCSEL == AT32_RTCSEL_LSE) || defined(__DOXYGEN__)
#define AT32_RTCCLK                AT32_LSECLK
#elif AT32_RTCSEL == AT32_RTCSEL_LSI
#define AT32_RTCCLK                AT32_LSICLK
#elif AT32_RTCSEL == AT32_RTCSEL_HSEDIV
#define AT32_RTCCLK                (AT32_HSECLK / 128)
#elif AT32_RTCSEL == AT32_RTCSEL_NOCLOCK
#define AT32_RTCCLK                0
#else
#error "invalid source selected for RTC clock"
#endif

/**
 * @brief   ADC frequency.
 */
#if (AT32_ADCPRE == AT32_ADCPRE_DIV2) || defined(__DOXYGEN__)
#define AT32_ADCCLK                (AT32_PCLK2 / 2)
#elif AT32_ADCPRE == AT32_ADCPRE_DIV4
#define AT32_ADCCLK                (AT32_PCLK2 / 4)
#elif AT32_ADCPRE == AT32_ADCPRE_DIV6
#define AT32_ADCCLK                (AT32_PCLK2 / 6)
#elif AT32_ADCPRE == AT32_ADCPRE_DIV8
#define AT32_ADCCLK                (AT32_PCLK2 / 8)
#else
#error "invalid AT32_ADCPRE value specified"
#endif

/* ADC frequency check.*/
#if AT32_ADCCLK > AT32_ADCCLK_MAX
#error "AT32_ADCCLK exceeding maximum frequency (AT32_ADCCLK_MAX)"
#endif

/**
 * @brief   USB frequency.
 */
#if (AT32_USBPRE == AT32_USBPRE_DIV1P5) || defined(__DOXYGEN__)
#define AT32_USBCLK                ((AT32_PLLCLKOUT * 2) / 3)
#elif (AT32_USBPRE == AT32_USBPRE_DIV1)
#define AT32_USBCLK                AT32_PLLCLKOUT
#else
#error "invalid AT32_USBPRE value specified"
#endif

/**
 * @brief   Timers 2, 3, 4, 5, 6, 7, 12, 13, 14 clock.
 */
#if (AT32_PPRE1 == AT32_PPRE1_DIV1) || defined(__DOXYGEN__)
#define AT32_TIMCLK1               (AT32_PCLK1 * 1)
#else
#define AT32_TIMCLK1               (AT32_PCLK1 * 2)
#endif

/**
 * @brief   Timers 1, 8, 9, 10, 11 clock.
 */
#if (AT32_PPRE2 == AT32_PPRE2_DIV1) || defined(__DOXYGEN__)
#define AT32_TIMCLK2               (AT32_PCLK2 * 1)
#else
#define AT32_TIMCLK2               (AT32_PCLK2 * 2)
#endif

/** @} */
/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Various helpers.*/
#include "nvic.h"
#include "cache.h"
#include "mpu_v7m.h"
#include "AT32_isr.h"
#include "AT32_dma.h"
#include "AT32_rcc.h"
#include "AT32_tim.h"

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void AT32_clock_init(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */

/** @} */
