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
 * @file    SPIv3/hal_spi_v2_lld.h
 * @brief   AT32 SPI (v2) subsystem low level driver header.
 *
 * @addtogroup SPI
 * @{
 */

#ifndef HAL_SPI_V2_LLD_H
#define HAL_SPI_V2_LLD_H

#if HAL_USE_SPI || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Circular mode support flag.
 */
#define SPI_SUPPORTS_CIRCULAR           TRUE

/**
 * @brief   Slave mode support flag.
 */
#define SPI_SUPPORTS_SLAVE_MODE         TRUE

/**
 * @name    Register helpers not found in ST headers
 * @{
 */
#define SPI_CFG1_MBR_VALUE(n)           ((n) << SPI_CFG1_MBR_Pos)
#define SPI_CFG1_MBR_DIV2               SPI_CFG1_MBR_VALUE(0)
#define SPI_CFG1_MBR_DIV4               SPI_CFG1_MBR_VALUE(1)
#define SPI_CFG1_MBR_DIV8               SPI_CFG1_MBR_VALUE(2)
#define SPI_CFG1_MBR_DIV16              SPI_CFG1_MBR_VALUE(3)
#define SPI_CFG1_MBR_DIV32              SPI_CFG1_MBR_VALUE(4)
#define SPI_CFG1_MBR_DIV64              SPI_CFG1_MBR_VALUE(5)
#define SPI_CFG1_MBR_DIV128             SPI_CFG1_MBR_VALUE(6)
#define SPI_CFG1_MBR_DIV256             SPI_CFG1_MBR_VALUE(7)
#define SPI_CFG1_CRCSIZE_VALUE(n)       ((n) << SPI_CFG1_CRCSIZE_Pos)
#define SPI_CFG1_UDRDET_VALUE(n)        ((n) << SPI_CFG1_UDRDET_Pos)
#define SPI_CFG1_UDRCFG_VALUE(n)        ((n) << SPI_CFG1_UDRCFG_Pos)
#define SPI_CFG1_FTHLV_VALUE(n)         ((n) << SPI_CFG1_FTHLV_Pos)
#define SPI_CFG1_DSIZE_VALUE(n)         ((n) << SPI_CFG1_DSIZE_Pos)

#define SPI_CFG2_SP_VALUE(n)            ((n) << SPI_CFG2_SP_Pos)
#define SPI_CFG2_COMM_VALUE(n)          ((n) << SPI_CFG2_COMM_Pos)
#define SPI_CFG2_COMM_FULL_DUPLEX       SPI_CFG2_COMM_VALUE(0)
#define SPI_CFG2_COMM_TRANSMITTER       SPI_CFG2_COMM_VALUE(1)
#define SPI_CFG2_COMM_RECEIVER          SPI_CFG2_COMM_VALUE(2)
#define SPI_CFG2_COMM_HALF_DUPLEX       SPI_CFG2_COMM_VALUE(3)
#define SPI_CFG2_MIDI_VALUE(n)          ((n) << SPI_CFG2_MIDI_Pos)
#define SPI_CFG2_MSSI_VALUE(n)          ((n) << SPI_CFG2_MSSI_Pos)
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   SPI1 driver enable switch.
 * @details If set to @p TRUE the support for SPI1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_SPI_USE_SPI1) || defined(__DOXYGEN__)
#define AT32_SPI_USE_SPI1                  FALSE
#endif

/**
 * @brief   SPI2 driver enable switch.
 * @details If set to @p TRUE the support for SPI2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_SPI_USE_SPI2) || defined(__DOXYGEN__)
#define AT32_SPI_USE_SPI2                  FALSE
#endif

/**
 * @brief   SPI3 driver enable switch.
 * @details If set to @p TRUE the support for SPI3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(AT32_SPI_USE_SPI3) || defined(__DOXYGEN__)
#define AT32_SPI_USE_SPI3                  FALSE
#endif

/**
 * @brief   Filler pattern used when there is nothing to transmit.
 */
#if !defined(AT32_SPI_FILLER_PATTERN) || defined(__DOXYGEN__)
#define AT32_SPI_FILLER_PATTERN            0xFFFFFFFFU
#endif

/**
 * @brief   SPI1 interrupt priority level setting.
 */
#if !defined(AT32_SPI_SPI1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_SPI_SPI1_IRQ_PRIORITY         10
#endif

/**
 * @brief   SPI2 interrupt priority level setting.
 */
#if !defined(AT32_SPI_SPI2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_SPI_SPI2_IRQ_PRIORITY         10
#endif

/**
 * @brief   SPI3 interrupt priority level setting.
 */
#if !defined(AT32_SPI_SPI3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_SPI_SPI3_IRQ_PRIORITY         10
#endif

/**
 * @brief   SPI1 DMA priority (0..3|lowest..highest).
 * @note    The priority level is used for both the TX and RX DMA streams but
 *          because of the streams ordering the RX stream has always priority
 *          over the TX stream.
 */
#if !defined(AT32_SPI_SPI1_DMA_PRIORITY) || defined(__DOXYGEN__)
#define AT32_SPI_SPI1_DMA_PRIORITY         1
#endif

/**
 * @brief   SPI2 DMA priority (0..3|lowest..highest).
 * @note    The priority level is used for both the TX and RX DMA streams but
 *          because of the streams ordering the RX stream has always priority
 *          over the TX stream.
 */
#if !defined(AT32_SPI_SPI2_DMA_PRIORITY) || defined(__DOXYGEN__)
#define AT32_SPI_SPI2_DMA_PRIORITY         1
#endif

/**
 * @brief   SPI3 DMA priority (0..3|lowest..highest).
 * @note    The priority level is used for both the TX and RX DMA streams but
 *          because of the streams ordering the RX stream has always priority
 *          over the TX stream.
 */
#if !defined(AT32_SPI_SPI3_DMA_PRIORITY) || defined(__DOXYGEN__)
#define AT32_SPI_SPI3_DMA_PRIORITY         1
#endif

/**
 * @brief   SPI DMA error hook.
 */
#if !defined(AT32_SPI_DMA_ERROR_HOOK) || defined(__DOXYGEN__)
#define AT32_SPI_DMA_ERROR_HOOK(spip)      osalSysHalt("DMA failure")
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if AT32_SPI_USE_SPI1 && !AT32_HAS_SPI1
#error "SPI1 not present in the selected device"
#endif

#if AT32_SPI_USE_SPI2 && !AT32_HAS_SPI2
#error "SPI2 not present in the selected device"
#endif

#if AT32_SPI_USE_SPI3 && !AT32_HAS_SPI3
#error "SPI3 not present in the selected device"
#endif

#if !AT32_SPI_USE_SPI1 && !AT32_SPI_USE_SPI2 && !AT32_SPI_USE_SPI3
#error "SPI driver activated but no SPI peripheral assigned"
#endif

#if AT32_SPI_USE_SPI1 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_SPI_SPI1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SPI1"
#endif

#if AT32_SPI_USE_SPI2 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_SPI_SPI2_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SPI2"
#endif

#if AT32_SPI_USE_SPI3 &&                                                   \
    !OSAL_IRQ_IS_VALID_PRIORITY(AT32_SPI_SPI3_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SPI3"
#endif

/* The following checks are only required when there is a DMA able to
   reassign streams to different channels.*/
#if AT32_ADVANCED_DMA
/* Check on the presence of the DMA streams settings in mcuconf.h.*/
#if AT32_SPI_USE_SPI1 && (!defined(AT32_SPI_SPI1_RX_DMA_STREAM) ||        \
                           !defined(AT32_SPI_SPI1_TX_DMA_STREAM))
#error "SPI1 DMA streams not defined"
#endif

#if AT32_SPI_USE_SPI2 && (!defined(AT32_SPI_SPI2_RX_DMA_STREAM) ||        \
                           !defined(AT32_SPI_SPI2_TX_DMA_STREAM))
#error "SPI2 DMA streams not defined"
#endif

#if AT32_SPI_USE_SPI3 && (!defined(AT32_SPI_SPI3_RX_DMA_STREAM) ||        \
                           !defined(AT32_SPI_SPI3_TX_DMA_STREAM))
#error "SPI3 DMA streams not defined"
#endif

/* Check on the validity of the assigned DMA channels.*/
#if AT32_SPI_USE_SPI1 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_SPI_SPI1_RX_DMA_STREAM, AT32_SPI1_RX_DMA_MSK)
#error "invalid DMA stream associated to SPI1 RX"
#endif

#if AT32_SPI_USE_SPI1 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_SPI_SPI1_TX_DMA_STREAM, AT32_SPI1_TX_DMA_MSK)
#error "invalid DMA stream associated to SPI1 TX"
#endif

#if AT32_SPI_USE_SPI2 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_SPI_SPI2_RX_DMA_STREAM, AT32_SPI2_RX_DMA_MSK)
#error "invalid DMA stream associated to SPI2 RX"
#endif

#if AT32_SPI_USE_SPI2 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_SPI_SPI2_TX_DMA_STREAM, AT32_SPI2_TX_DMA_MSK)
#error "invalid DMA stream associated to SPI2 TX"
#endif

#if AT32_SPI_USE_SPI3 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_SPI_SPI3_RX_DMA_STREAM, AT32_SPI3_RX_DMA_MSK)
#error "invalid DMA stream associated to SPI3 RX"
#endif

#if AT32_SPI_USE_SPI3 &&                                                   \
    !AT32_DMA_IS_VALID_ID(AT32_SPI_SPI3_TX_DMA_STREAM, AT32_SPI3_TX_DMA_MSK)
#error "invalid DMA stream associated to SPI3 TX"
#endif

#endif /* AT32_ADVANCED_DMA */

#if !defined(AT32_DMA_REQUIRED)
#define AT32_DMA_REQUIRED
#endif

#if SPI_SELECT_MODE == SPI_SELECT_MODE_LLD
#error "SPI_SELECT_MODE_LLD not supported by this driver"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

#define spi_lld_driver_fields                                               \
  /* Pointer to the SPIx registers block.*/                                 \
  SPI_TypeDef               *spi;                                           \
  /** DMA type for this instance.*/                                         \
  bool                      is_bdma;                                        \
  /* Receive DMA stream.*/                                                  \
  const at32_dma_stream_t  *dmarx;                                         \
  /* Transmit DMA stream.*/                                                 \
  const at32_dma_stream_t  *dmatx;                                         \
  /* RX DMA mode bit mask.*/                                                \
  uint32_t                  rxdmamode;                                      \
  /* TX DMA mode bit mask.*/                                                \
  uint32_t                  txdmamode;                                      \
  /* Sink for discarded data.*/                                             \
  uint32_t                  rxsink;                                         \
  /* Source for default TX pattern.*/                                       \
  uint32_t                  txsource

/**
 * @brief   Low level fields of the SPI configuration structure.
 */
#define spi_lld_config_fields                                               \
  /* SPI CR1 register initialization data.*/                                \
  uint16_t                  cr1;                                            \
  /* SPI CR2 register initialization data.*/                                \
  uint16_t                  cr2

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if AT32_SPI_USE_SPI1 && !defined(__DOXYGEN__)
extern SPIDriver SPID1;
#endif

#if AT32_SPI_USE_SPI2 && !defined(__DOXYGEN__)
extern SPIDriver SPID2;
#endif

#if AT32_SPI_USE_SPI3 && !defined(__DOXYGEN__)
extern SPIDriver SPID3;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void spi_lld_init(void);
  msg_t spi_lld_start(SPIDriver *spip);
  void spi_lld_stop(SPIDriver *spip);
#if (SPI_SELECT_MODE == SPI_SELECT_MODE_LLD) || defined(__DOXYGEN__)
  void spi_lld_select(SPIDriver *spip);
  void spi_lld_unselect(SPIDriver *spip);
#endif
  msg_t spi_lld_ignore(SPIDriver *spip, size_t n);
  msg_t spi_lld_exchange(SPIDriver *spip, size_t n,
                         const void *txbuf, void *rxbuf);
  msg_t spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf);
  msg_t spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf);
  msg_t spi_lld_stop_transfer(SPIDriver *spip, size_t *sizep);
  uint16_t spi_lld_polled_exchange(SPIDriver *spip, uint16_t frame);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SPI */

#endif /* HAL_SPI_V2_LLD_H */

/** @} */
