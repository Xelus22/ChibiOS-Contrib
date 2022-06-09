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
 * @file    AT32F1xx/AT32_isr.h
 * @brief   AT32F3xx ISR handler header.
 *
 * @addtogroup AT32F1xx_ISR
 * @{
 */

#ifndef AT32_ISR_H
#define AT32_ISR_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ISR names and numbers remapping
 * @{
 */

/*
 * WWDG units.
 */
#define AT32_WWDG_HANDLER                      Vector40
#define AT32_WWDG_NUMBER                       0

/*
 * PVD units.
 */
#define AT32_PVD_HANDLER                       Vector44
#define AT32_PVD_NUMBER                        1

/*
 * TAMPER units.
 */
#define AT32_TAMPER_HANDLER                    Vector48
#define AT32_TAMPER_NUMBER                     2

/*
 * RTC units.
 */
#define AT32_RTC_HANDLER                       Vector4C
#define AT32_RTC_NUMBER                        3

#define AT32_RTCAlarm_HANDLER                  VectorE4
#define AT32_RTCAlarm_NUMBER                   41

/*
 * FLASH units.
 */
#define AT32_FMC_HANDLER                       Vector50
#define AT32_FMC_NUMBER                        4

/*
 * RCC units.
 */
#define AT32_RCC_HANDLER                       Vector54
#define AT32_RCC_NUMBER                        5

/*
 * EXTI units.
 */
#define AT32_EXTI0_HANDLER                     Vector58
#define AT32_EXTI0_NUMBER                      6

#define AT32_EXTI1_HANDLER                     Vector5C
#define AT32_EXTI1_NUMBER                      7

#define AT32_EXTI2_HANDLER                     Vector60
#define AT32_EXTI2_NUMBER                      8

#define AT32_EXTI3_HANDLER                     Vector64
#define AT32_EXTI3_NUMBER                      9

#define AT32_EXTI4_HANDLER                     Vector68
#define AT32_EXTI4_NUMBER                      10

#define AT32_EXTI9_5_HANDLER                   Vector9C
#define AT32_EXTI9_5_NUMBER                    23

#define AT32_EXTI15_10_HANDLER                 VectorE0
#define AT32_EXTI15_10_NUMBER                  40

/*
 * DMA units.
 */
#define AT32_DMA1C1_HANDLER                    Vector6C
#define AT32_DMA1C2_HANDLER                    Vector70
#define AT32_DMA1C3_HANDLER                    Vector74
#define AT32_DMA1C4_HANDLER                    Vector78
#define AT32_DMA1C5_HANDLER                    Vector7C
#define AT32_DMA1C6_HANDLER                    Vector80
#define AT32_DMA1C7_HANDLER                    Vector84
#define AT32_DMA1C1_NUMBER                     11
#define AT32_DMA1C2_NUMBER                     12
#define AT32_DMA1C3_NUMBER                     13
#define AT32_DMA1C4_NUMBER                     14
#define AT32_DMA1C5_NUMBER                     15
#define AT32_DMA1C6_NUMBER                     16
#define AT32_DMA1C7_NUMBER                     17

#define AT32_DMA2C1_HANDLER                    Vector120
#define AT32_DMA2C2_HANDLER                    Vector124
#define AT32_DMA2C3_HANDLER                    Vector128
#define AT32_DMA2C4_HANDLER                    Vector12C
#define AT32_DMA2C5_HANDLER                    Vector12C
#define AT32_DMA2C6_HANDLER                    Vector16C
#define AT32_DMA2C7_HANDLER                    Vector16C
#define AT32_DMA2C1_NUMBER                     56
#define AT32_DMA2C2_NUMBER                     57
#define AT32_DMA2C3_NUMBER                     58
#define AT32_DMA2C4_NUMBER                     59
#define AT32_DMA2C5_NUMBER                     59
#define AT32_DMA2C6_NUMBER                     75
#define AT32_DMA2C7_NUMBER                     75

/*
 * ADC units.
 */
 //both ADC1 and ADC2
#define AT32_ADC1_2_HANDLER                    Vector88
#define AT32_ADC1_2_NUMBER                     18

#define AT32_ADC3_HANDLER                      VectorFC
#define AT32_ADC3_NUMBER                       47

/*
 * CAN units.
 */
#define AT32_CAN1_TX_HANDLER       Vector8C
#define AT32_CAN1_RX0_HANDLER      Vector90
#define AT32_CAN1_RX1_HANDLER      Vector94
#define AT32_CAN1_SCE_HANDLER      Vector98
#define AT32_CAN2_TX_HANDLER       Vector150
#define AT32_CAN2_RX0_HANDLER      Vector154
#define AT32_CAN2_RX1_HANDLER      Vector158
#define AT32_CAN2_SCE_HANDLER      Vector15C

#define AT32_CAN1_TX_NUMBER        19
#define AT32_CAN1_RX0_NUMBER       20
#define AT32_CAN1_RX1_NUMBER       21
#define AT32_CAN1_SCE_NUMBER       22
#define AT32_CAN2_TX_NUMBER        68
#define AT32_CAN2_RX0_NUMBER       69
#define AT32_CAN2_RX1_NUMBER       70
#define AT32_CAN2_SCE_NUMBER       71

/*
 * I2C units.
 */
#define AT32_I2C1_EVENT_HANDLER    VectorBC
#define AT32_I2C1_ERROR_HANDLER    VectorC0
#define AT32_I2C1_EVENT_NUMBER     31
#define AT32_I2C1_ERROR_NUMBER     32

#define AT32_I2C2_EVENT_HANDLER    VectorC4
#define AT32_I2C2_ERROR_HANDLER    VectorC8
#define AT32_I2C2_EVENT_NUMBER     33
#define AT32_I2C2_ERROR_NUMBER     34

#define AT32_I2C3_EVENT_HANDLER    Vector134
#define AT32_I2C3_ERROR_HANDLER    Vector138
#define AT32_I2C3_EVENT_NUMBER     61
#define AT32_I2C3_ERROR_NUMBER     62

/*
 * SPI units.
 */
#define AT32_SPI1_HANDLER                      VectorCC
#define AT32_SPI1_NUMBER                       35

#define AT32_SPI2_HANDLER                      VectorD0
#define AT32_SPI2_NUMBER                       36

#define AT32_SPI3_HANDLER                      Vector10C
#define AT32_SPI3_NUMBER                       51

#define AT32_SPI4_HANDLER                      Vector13C
#define AT32_SPI4_NUMBER                       63

/* 
 * I2S Units.
 */
 //shares SPI2
#define AT32_I2S2EXT_HANDLER                   VectorD0
#define AT32_I2S2EXT_NUMBER                    36

 //shares SPI3
#define AT32_I2S3EXT_HANDLER                   Vector10C
#define AT32_I2S3EXT_NUMBER                    51



/*
 * SDIO unit.
 */
#define AT32_SDIO_HANDLER          Vector104
#define AT32_SDIO_NUMBER           49

#define AT32_SDIO2_HANDLER         Vector130
#define AT32_SDIO_NUMBER           60

/*
 * TIM units.
 */
#define AT32_TIM1_UP_HANDLER       VectorA4
#define AT32_TIM1_CC_HANDLER       VectorAC
#define AT32_TIM2_HANDLER          VectorB0
#define AT32_TIM3_HANDLER          VectorB4
#define AT32_TIM4_HANDLER          VectorB8
#define AT32_TIM5_HANDLER          Vector108
#define AT32_TIM6_HANDLER          Vector118
#define AT32_TIM7_HANDLER          Vector11C
#define AT32_TIM8_UP_HANDLER       VectorF0
#define AT32_TIM8_CC_HANDLER       VectorF8
#define AT32_TIM9_HANDLER          VectorA0 /* Note: same as AT32_TIM1_BRK */
#define AT32_TIM10_HANDLER         VectorA4 /* Note: same as AT32_TIM1_UP */
#define AT32_TIM11_HANDLER         VectorA8 /* Note: same as AT32_TIM1_TRG_COM */
#define AT32_TIM12_HANDLER         VectorEC /* Note: same as AT32_TIM8_BRK */
#define AT32_TIM13_HANDLER         VectorF0 /* Note: same as AT32_TIM8_UP */
#define AT32_TIM14_HANDLER         VectorF4 /* Note: same as AT32_TIM8_TRG_COM */

#define AT32_TIM1_UP_NUMBER        25
#define AT32_TIM1_CC_NUMBER        27
#define AT32_TIM2_NUMBER           28
#define AT32_TIM3_NUMBER           29
#define AT32_TIM4_NUMBER           30
#define AT32_TIM5_NUMBER           50
#define AT32_TIM6_NUMBER           54
#define AT32_TIM7_NUMBER           55
#define AT32_TIM8_UP_NUMBER        44
#define AT32_TIM8_CC_NUMBER        46
#define AT32_TIM9_NUMBER           24 /* Note: same as AT32_TIM1_BRK */
#define AT32_TIM10_NUMBER          25 /* Note: same as AT32_TIM1_UP */
#define AT32_TIM11_NUMBER          26 /* Note: same as AT32_TIM1_TRG_COM */
#define AT32_TIM12_NUMBER          43 /* Note: same as AT32_TIM8_BRK */
#define AT32_TIM13_NUMBER          44 /* Note: same as AT32_TIM8_UP */
#define AT32_TIM14_NUMBER          45 /* Note: same as AT32_TIM8_TRG_COM */

/*
 * USART units.
 */
#define AT32_USART1_HANDLER        VectorD4
#define AT32_USART2_HANDLER        VectorD8
#define AT32_USART3_HANDLER        VectorDC
#define AT32_UART4_HANDLER         Vector110
#define AT32_UART5_HANDLER         Vector114
#define AT32_USART6_HANDLER        Vector170
#define AT32_UART7_HANDLER         Vector174
#define AT32_UART8_HANDLER         Vector178

#define AT32_USART1_NUMBER         37
#define AT32_USART2_NUMBER         38
#define AT32_USART3_NUMBER         39
#define AT32_UART4_NUMBER          52
#define AT32_UART5_NUMBER          53
#define AT32_USART6_NUMBER         76
#define AT32_UART7_NUMBER          77
#define AT32_UART8_NUMBER          78

/*
 * USB units.
 */
#define AT32_USB1_HP_HANDLER       Vector8C
#define AT32_USB1_LP_HANDLER       Vector90
#define AT32_USBP1_WKUP_HANDLER    VectorE8

#define AT32_USB1_HP_NUMBER        19
#define AT32_USB1_LP_NUMBER        20
#define AT32_USBP1_WKUP_NUMBER     42

/* FSMC attributes.*/
#define STM32_HAS_FSMC                      TRUE
#define STM32_FSMC_IS_FMC                   FALSE
#define STM32_FSMC_HANDLER                  Vector100
#define STM32_FSMC_NUMBER                   48

/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   EXTI0 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXTI0_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXTI0_PRIORITY            6
#endif

/**
 * @brief   EXTI1 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXTI1_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXTI1_PRIORITY            6
#endif

/**
 * @brief   EXTI2 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXTI2_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXTI2_PRIORITY            6
#endif

/**
 * @brief   EXTI3 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXTI3_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXTI3_PRIORITY            6
#endif

/**
 * @brief   EXTI4 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXTI4_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXTI4_PRIORITY            6
#endif

/**
 * @brief   EXTI9..5 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXTI5_9_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXTI5_9_PRIORITY          6
#endif

/**
 * @brief   EXTI15..10 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXTI10_15_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXTI10_15_PRIORITY        6
#endif

/**
 * @brief   EXTI16 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXTI16_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXTI16_PRIORITY           6
#endif

/**
 * @brief   EXTI17 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXTI17_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXTI17_PRIORITY           6
#endif

/**
 * @brief   EXTI18 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXTI18_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXTI18_PRIORITY           6
#endif

/**
 * @brief   EXTI19 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXTI19_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXTI19_PRIORITY           6
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void irqInit(void);
  void irqDeinit(void);
#ifdef __cplusplus
}
#endif

#endif /* AT32_ISR_H */

/** @} */
