/**********************************************************************************/
/* Header file UART.h KEIL																												*/
/* Author: Eric Micallef 																													*/ 
/* This function transmits packets of data to computer														*/
/**********************************************************************************/
#ifndef _UART_H_
#define _UART_H_

#include "common_defs.h"
#include "nrf.h"
#include <stdbool.h>
#include <stdint.h>

#define RX_PIN 	8 
#define TX_PIN  15
#define CTS_PIN 9 
#define RTS_PIN 11 


/**
 * @enum nrf_uart_baudrate_t
 * @brief Baudrates supported by UART.
 */
typedef enum
{
    NRF_UART_BAUDRATE_1200   =  UART_BAUDRATE_BAUDRATE_Baud1200, /**< 1200 baud. */
    NRF_UART_BAUDRATE_2400   =  UART_BAUDRATE_BAUDRATE_Baud2400, /**< 2400 baud. */
    NRF_UART_BAUDRATE_4800   =  UART_BAUDRATE_BAUDRATE_Baud4800, /**< 4800 baud. */
    NRF_UART_BAUDRATE_9600   =  UART_BAUDRATE_BAUDRATE_Baud9600, /**< 9600 baud. */
    NRF_UART_BAUDRATE_14400  =  UART_BAUDRATE_BAUDRATE_Baud14400, /**< 14400 baud. */
    NRF_UART_BAUDRATE_19200  =  UART_BAUDRATE_BAUDRATE_Baud19200, /**< 19200 baud. */
    NRF_UART_BAUDRATE_28800  =  UART_BAUDRATE_BAUDRATE_Baud28800, /**< 28800 baud. */
    NRF_UART_BAUDRATE_38400  =  UART_BAUDRATE_BAUDRATE_Baud38400, /**< 38400 baud. */
    NRF_UART_BAUDRATE_57600  =  UART_BAUDRATE_BAUDRATE_Baud57600, /**< 57600 baud. */
    NRF_UART_BAUDRATE_76800  =  UART_BAUDRATE_BAUDRATE_Baud76800, /**< 76800 baud. */
    NRF_UART_BAUDRATE_115200 =  UART_BAUDRATE_BAUDRATE_Baud115200, /**< 115200 baud. */
    NRF_UART_BAUDRATE_230400 =  UART_BAUDRATE_BAUDRATE_Baud230400, /**< 230400 baud. */
    NRF_UART_BAUDRATE_250000 =  UART_BAUDRATE_BAUDRATE_Baud250000, /**< 250000 baud. */
    NRF_UART_BAUDRATE_460800 =  UART_BAUDRATE_BAUDRATE_Baud460800, /**< 460800 baud. */
    NRF_UART_BAUDRATE_921600 =  UART_BAUDRATE_BAUDRATE_Baud921600, /**< 921600 baud. */
    NRF_UART_BAUDRATE_1000000 = UART_BAUDRATE_BAUDRATE_Baud1M, /**< 1000000 baud. */
} UART_BAUDRATE;

/**
 * @enum nrf_uart_parity_t
 * @brief Types of UART parity modes.
 */
typedef enum
{
    NRF_UART_PARITY_EXCLUDED = UART_CONFIG_PARITY_Excluded << UART_CONFIG_PARITY_Pos, /**< Parity excluded. */
    NRF_UART_PARITY_INCLUDED = UART_CONFIG_PARITY_Included << UART_CONFIG_PARITY_Pos, /**< Parity included. */
} UART_PARITY;

/**
 * @enum nrf_uart_hwfc_t
 * @brief Types of UART flow control modes.
 */
typedef enum
{
    NRF_UART_HWFC_DISABLED = UART_CONFIG_HWFC_Disabled, /**< HW flow control disabled. */
    NRF_UART_HWFC_ENABLED  = UART_CONFIG_HWFC_Enabled,  /**< HW flow control enabled. */
} UART_HWFC;

typedef struct
{
    uint32_t            pseltxd;            ///< TXD pin number.
    uint32_t            pselrxd;            ///< RXD pin number.
    uint32_t            pselcts;            ///< CTS pin number.
    uint32_t            pselrts;            ///< RTS pin number.
    void *              p_context;          ///< Context passed to interrupt handler.
    UART_HWFC				    hwfc;               ///< Flow control enumeration
    UART_PARITY   			parity;             ///< Parity configuration.
    UART_BAUDRATE				baudrate;           ///< Baudrate.
    uint8_t             interrupt_priority; ///< Interrupt priority.
    bool                use_easy_dma;
} UART_DRV_CONFIG;

/**@brief UART communication structure holding configuration settings for the peripheral.
 */
typedef struct
{
    uint8_t                 rx_pin_no;    /**< RX pin number. */
    uint8_t                 tx_pin_no;    /**< TX pin number. */
    uint8_t                 rts_pin_no;   /**< RTS pin number, only used if flow control is enabled. */
    uint8_t                 cts_pin_no;   /**< CTS pin number, only used if flow control is enabled. */
    UART_HWFC							  flow_control; /**< Flow control setting, if flow control is used, the system will use low power UART mode, based on CTS signal. */
    bool                    use_parity;   /**< Even parity if TRUE, no parity if FALSE. */
    uint32_t                baud_rate;    /**< Baud rate configuration. */
	} UART_PARAMETERS1;

/* UART  from nrf drv config.h */
//#define UART0_ENABLED 1

//#if (UART0_ENABLED == 1)
#define UART0_CONFIG_HWFC         NRF_UART_HWFC_DISABLED
#define UART0_CONFIG_PARITY       NRF_UART_PARITY_EXCLUDED
#define UART0_CONFIG_BAUDRATE     NRF_UART_BAUDRATE_9600
#define UART0_CONFIG_PSEL_TXD 8
#define UART0_CONFIG_PSEL_RXD 10
#define UART0_CONFIG_PSEL_CTS 7
#define UART0_CONFIG_PSEL_RTS 5
#define UART0_CONFIG_IRQ_PRIORITY 3 //APP_IRQ_PRIORITY_LOW	
#define UART0_CONFIG_USE_EASY_DMA false	
	
#define NRF_DRV_UART_DEFAULT_CONFIG                                                   \
    {                                                                                 \
        .pseltxd            = UART0_CONFIG_PSEL_TXD,                                  \
        .pselrxd            = UART0_CONFIG_PSEL_RXD,                                  \
        .pselcts            = UART0_CONFIG_PSEL_CTS,                                  \
        .pselrts            = UART0_CONFIG_PSEL_RTS,                                  \
        .p_context          = NULL,                                                   \
        .hwfc               = UART0_CONFIG_HWFC,                                      \
        .parity             = UART0_CONFIG_PARITY,                                    \
        .baudrate           = UART0_CONFIG_BAUDRATE,                                  \
        .interrupt_priority = UART0_CONFIG_IRQ_PRIORITY,                              \
        .use_easy_dma       = UART0_CONFIG_USE_EASY_DMA                  							\
    }
		
/**@brief Macro for safe initialization of the UART module in a single user instance.
 *
 * @param[in]   P_COMM_PARAMS   Pointer to a UART communication structure: app_uart_comm_params_t
 * @param[in]   EVT_HANDLER   Event handler function to be called when an event occurs in the
 *                              UART module.
 * @param[in]   IRQ_PRIO        IRQ priority, app_irq_priority_t, for the UART module irq handler.
 * @param[out]  ERR_CODE        The return value of the UART initialization function will be
 *                              written to this parameter.
 *
 * @note Since this macro allocates registers the module as a GPIOTE user when flow control is
 *       enabled, it must only be called once.
 */
#define APP_UART_INIT(P_COMM_PARAMS)                              \
    do                                                                                             \
    {                                                                                              \
     app_uart_init(P_COMM_PARAMS);                      \
    } while (0)
		
		
/* initializes the UART Port */ 
extern void app_uart_init(const UART_PARAMETERS1 * p_comm_params);
/* function for establishing basic loop back test. connect (TX w RX) and (CTS w RTS)... if you are using RTS and CTS */ 
extern void UART_LOOP_BACK(void);
/* fastest way to initializes UART port */		
extern void UART_init(void);
		
#endif 
