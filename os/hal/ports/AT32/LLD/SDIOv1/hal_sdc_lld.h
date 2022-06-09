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
 * @file    SDIOv1/hal_sdc_lld.h
 * @brief   AT32 SDC subsystem low level driver header.
 *
 * @addtogroup SDC
 * @{
 */

#ifndef HAL_SDC_LLD_H
#define HAL_SDC_LLD_H

#if HAL_USE_SDC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * The following definitions are missing from some implementations, fixing
 * as zeroed masks.
 */
#if !defined(SDIO_STA_STBITERR)
#define SDIO_STA_STBITERR       0
#endif

#if !defined(SDIO_ICR_STBITERRC)
#define SDIO_ICR_STBITERRC      0
#endif

#if !defined(SDIO_ICR_CEATAENDC)
#define SDIO_ICR_CEATAENDC      0
#endif

#if !defined(SDIO_MASK_STBITERRIE)
#define SDIO_MASK_STBITERRIE    0
#endif

/**
 * @brief Value to clear all interrupts flag at once.
 */
#define AT32_SDIO_ICR_ALL_FLAGS (SDIO_ICR_CCRCFAILC | SDIO_ICR_DCRCFAILC | \
                                  SDIO_ICR_CTIMEOUTC | SDIO_ICR_DTIMEOUTC | \
                                  SDIO_ICR_TXUNDERRC | SDIO_ICR_RXOVERRC |  \
                                  SDIO_ICR_CMDRENDC  | SDIO_ICR_CMDSENTC |  \
                                  SDIO_ICR_DATAENDC  | SDIO_ICR_STBITERRC | \
                                  SDIO_ICR_DBCKENDC  | SDIO_ICR_SDIOITC |   \
                                  SDIO_ICR_CEATAENDC)

/**
 * @brief Mask of error flags in STA register.
 */
#define AT32_SDIO_STA_ERROR_MASK (SDIO_STA_CCRCFAIL | SDIO_STA_DCRCFAIL |  \
                                   SDIO_STA_CTIMEOUT | SDIO_STA_DTIMEOUT |  \
                                   SDIO_STA_TXUNDERR | SDIO_STA_RXOVERR)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   SDIO1 DMA priority (0..3|lowest..highest).
 */
#if !defined(AT32_SDC_SDIO1_DMA_PRIORITY) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO1_DMA_PRIORITY         3
#endif

/**
 * @brief   SDIO1 interrupt priority level setting.
 */
#if !defined(AT32_SDC_SDIO1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO1_IRQ_PRIORITY         9
#endif

/**
 * @brief   SDIO2 DMA priority (0..3|lowest..highest).
 */
#if !defined(AT32_SDC_SDIO2_DMA_PRIORITY) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO2_DMA_PRIORITY         3
#endif

/**
 * @brief   SDIO2 interrupt priority level setting.
 */
#if !defined(AT32_SDC_SDIO2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO2_IRQ_PRIORITY         9
#endif

/**
 * @brief   Enable clock bypass.
 * @note    Allow clock speed up to 50 Mhz.
 */
#if !defined(AT32_SDC_SDIO_50MHZ) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO_50MHZ                FALSE
#endif

/**
 * @brief   Write timeout in milliseconds.
 */
#if !defined(AT32_SDC_WRITE_TIMEOUT_MS) || defined(__DOXYGEN__)
#define AT32_SDC_WRITE_TIMEOUT_MS          1000
#endif

/**
 * @brief   Read timeout in milliseconds.
 */
#if !defined(AT32_SDC_READ_TIMEOUT_MS) || defined(__DOXYGEN__)
#define AT32_SDC_READ_TIMEOUT_MS           1000
#endif

/**
 * @brief   Card clock activation delay in milliseconds.
 */
#if !defined(AT32_SDC_CLOCK_ACTIVATION_DELAY) || defined(__DOXYGEN__)
#define AT32_SDC_CLOCK_ACTIVATION_DELAY    10
#endif

/**
 * @brief   Support for unaligned transfers.
 * @note    Unaligned transfers are much slower.
 */
#if !defined(AT32_SDC_SDIO_UNALIGNED_SUPPORT) || defined(__DOXYGEN__)
#define AT32_SDC_SDIO_UNALIGNED_SUPPORT    TRUE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !AT32_HAS_SDIO1
#error "SDIO1 not present in the selected device"
#endif

#if !AT32_HAS_SDIO2 
#error "SDIO2 not present in the selected device"
#endif

//SDIO2 not implemented in the HAL
#if !AT32_SDIO_USE_SDIO2 
#error "SDIO2 not present in the selected device"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_SDC_SDIO1_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SDIO1"
#endif

#if !OSAL_IRQ_IS_VALID_PRIORITY(AT32_SDC_SDIO2_IRQ_PRIORITY)
#error "Invalid IRQ priority assigned to SDIO2"
#endif

#if !AT32_DMA_IS_VALID_PRIORITY(AT32_SDC_SDIO1_DMA_PRIORITY)
#error "Invalid DMA priority assigned to SDIO1"
#endif

#if !AT32_DMA_IS_VALID_PRIORITY(AT32_SDC_SDIO2_DMA_PRIORITY)
#error "Invalid DMA priority assigned to SDIO2"
#endif

/* The following checks are only required when there is a DMA able to
   reassign streams to different channels.*/
#if AT32_ADVANCED_DMA
/* Check on the presence of the DMA streams settings in mcuconf.h.*/
#if !defined(AT32_SDC_SDIO_DMA_STREAM)
#error "SDIO DMA streams not defined"
#endif

/* Check on the validity of the assigned DMA channels.*/
#if !AT32_DMA_IS_VALID_ID(AT32_SDC_SDIO_DMA_STREAM, AT32_SDC_SDIO_DMA_MSK)
#error "invalid DMA stream associated to SDIO"
#endif
#endif /* AT32_ADVANCED_DMA */

#if !defined(AT32_DMA_REQUIRED)
#define AT32_DMA_REQUIRED
#endif

/*
 * SDIO clock divider.
 */
#if AT32_HCLK > 48000000
#define AT32_SDIO_DIV_HS                   1
#define AT32_SDIO_DIV_LS                   178
#else

#define AT32_SDIO_DIV_HS                   0
#define AT32_SDIO_DIV_LS                   118
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of card flags.
 */
typedef uint32_t sdcmode_t;

/**
 * @brief   SDC Driver condition flags type.
 */
typedef uint32_t sdcflags_t;

/**
 * @brief   Type of a structure representing an SDC driver.
 */
typedef struct SDCDriver SDCDriver;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Bus width.
   */
  sdcbusmode_t  bus_width;
  /* End of the mandatory fields.*/
} SDCConfig;

/**
 * @brief   @p SDCDriver specific methods.
 */
#define _sdc_driver_methods                                                 \
  _mmcsd_block_device_methods

/**
 * @extends MMCSDBlockDeviceVMT
 *
 * @brief   @p SDCDriver virtual methods table.
 */
struct SDCDriverVMT {
  _sdc_driver_methods
};

/**
 * @brief   Structure representing an SDC driver.
 */
struct SDCDriver {
  /**
   * @brief Virtual Methods Table.
   */
  const struct SDCDriverVMT *vmt;
  _mmcsd_block_device_data
  /**
   * @brief Current configuration data.
   */
  const SDCConfig           *config;
  /**
   * @brief Various flags regarding the mounted card.
   */
  sdcmode_t                 cardmode;
  /**
   * @brief Errors flags.
   */
  sdcflags_t                errors;
  /**
   * @brief Card RCA.
   */
  uint32_t                  rca;
  /* End of the mandatory fields.*/
  /**
   * @brief Thread waiting for I/O completion IRQ.
   */
  thread_reference_t        thread;
  /**
   * @brief     DMA mode bit mask.
   */
  uint32_t                  dmamode;
  /**
   * @brief     Transmit DMA channel.
   */
  const at32_dma_stream_t  *dma;
  /**
   * @brief     Pointer to the SDIO registers block.
   * @note      Needed for debugging aid.
   */
  SDIO_TypeDef              *sdio;
  /**
   * @brief   Buffer for internal operations.
   */
  uint8_t                   buf[MMCSD_BLOCK_SIZE];
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
#if AT32_SDIO_USE_SDIO1 || AT32_SDIO_USE_SDIO
extern I2CDriver SDCD1;
#endif
#if AT32_SDIO_USE_SDIO2
extern I2CDriver SDCD2;
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void sdc_lld_init(void);
  void sdc_lld_start(SDCDriver *sdcp);
  void sdc_lld_stop(SDCDriver *sdcp);
  void sdc_lld_start_clk(SDCDriver *sdcp);
  void sdc_lld_set_data_clk(SDCDriver *sdcp, sdcbusclk_t clk);
  void sdc_lld_stop_clk(SDCDriver *sdcp);
  void sdc_lld_set_bus_mode(SDCDriver *sdcp, sdcbusmode_t mode);
  void sdc_lld_send_cmd_none(SDCDriver *sdcp, uint8_t cmd, uint32_t arg);
  bool sdc_lld_send_cmd_short(SDCDriver *sdcp, uint8_t cmd, uint32_t arg,
                              uint32_t *resp);
  bool sdc_lld_send_cmd_short_crc(SDCDriver *sdcp, uint8_t cmd, uint32_t arg,
                                  uint32_t *resp);
  bool sdc_lld_send_cmd_long_crc(SDCDriver *sdcp, uint8_t cmd, uint32_t arg,
                                 uint32_t *resp);
  bool sdc_lld_read_special(SDCDriver *sdcp, uint8_t *buf, size_t bytes,
                            uint8_t cmd, uint32_t argument);
  bool sdc_lld_read(SDCDriver *sdcp, uint32_t startblk,
                    uint8_t *buf, uint32_t blocks);
  bool sdc_lld_write(SDCDriver *sdcp, uint32_t startblk,
                     const uint8_t *buf, uint32_t blocks);
  bool sdc_lld_sync(SDCDriver *sdcp);
  bool sdc_lld_is_card_inserted(SDCDriver *sdcp);
  bool sdc_lld_is_write_protected(SDCDriver *sdcp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_SDC */

#endif /* HAL_SDC_LLD_H */

/** @} */
