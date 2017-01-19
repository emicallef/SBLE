/**********************************************************************************/
/* Header file SPI.h KEIL                                                         */
/* Author: Eric Micallef																													*/
/* These functions setup and toggle a pin specified by user											  */
/**********************************************************************************/
#ifndef _SPI_H__
#define _SPI_H__

#include "common_defs.h"
#include "nrf.h"
#include <stdbool.h>
#include <stdint.h>

/* function for initializing SPI */
extern void SPI_init(void);
/* function for initializing the master */
extern void SPIM_init(void);
/* function for initilaizing the slave... for use with an external master... see datasheet pg291 */ 
extern void SPIS_init(void);

/**
 * @brief SPI data rates.
 */
typedef enum
{
    NRF_SPI_FREQ_125K = SPI_FREQUENCY_FREQUENCY_K125,   ///< 125 kbps.
    NRF_SPI_FREQ_250K = SPI_FREQUENCY_FREQUENCY_K250,   ///< 250 kbps.
    NRF_SPI_FREQ_500K = SPI_FREQUENCY_FREQUENCY_K500,   ///< 500 kbps.
    NRF_SPI_FREQ_1M   = SPI_FREQUENCY_FREQUENCY_M1,     ///< 1 Mbps.
    NRF_SPI_FREQ_2M   = SPI_FREQUENCY_FREQUENCY_M2,     ///< 2 Mbps.
    NRF_SPI_FREQ_4M   = SPI_FREQUENCY_FREQUENCY_M4,     ///< 4 Mbps.
    // [conversion to 'int' needed to prevent compilers from complaining
    //  that the provided value (0x80000000UL) is out of range of "int"]
    NRF_SPI_FREQ_8M   = (int)SPI_FREQUENCY_FREQUENCY_M8 ///< 8 Mbps.
} nrf_spi_frequency_t;

/**
 * @brief SPI modes.
 */
/*
typedef enum
{
    NRF_DRV_SPI_MODE_0 = NRF_SPI_MODE_0, ///< SCK active high, sample on leading edge of clock.
    NRF_DRV_SPI_MODE_1 = NRF_SPI_MODE_1, ///< SCK active high, sample on trailing edge of clock.
    NRF_DRV_SPI_MODE_2 = NRF_SPI_MODE_2, ///< SCK active low, sample on leading edge of clock.
    NRF_DRV_SPI_MODE_3 = NRF_SPI_MODE_3  ///< SCK active low, sample on trailing edge of clock.
} nrf_drv_spi_mode_t;
*/
/**
 * @brief SPI bit orders.
 */
/*typedef enum
{
    NRF_DRV_SPI_BIT_ORDER_MSB_FIRST = NRF_SPI_BIT_ORDER_MSB_FIRST, ///< Most significant bit shifted out first.
    NRF_DRV_SPI_BIT_ORDER_LSB_FIRST = NRF_SPI_BIT_ORDER_LSB_FIRST  ///< Least significant bit shifted out first.
} nrf_drv_spi_bit_order_t;
*/

#endif