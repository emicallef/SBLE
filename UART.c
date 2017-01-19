// data sheet information on page 532
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "compiler_abstraction.h"
#include "nrf.h"
#include "UART.h"
#include "GPIO.h"
#include "Apply_The_Ding_Ding.h"

void app_uart_init(const UART_PARAMETERS1 * p_comm_params)
{
		/* for this to work chanfe compiler to --c99... "options for target" .. C/C++ tab add --c99 to "misc controls"  */
    UART_DRV_CONFIG config = NRF_DRV_UART_DEFAULT_CONFIG;
	
    config.baudrate = (UART_BAUDRATE)p_comm_params->baud_rate;
    config.hwfc = (p_comm_params->flow_control ==  NRF_UART_HWFC_DISABLED) ? NRF_UART_HWFC_DISABLED : NRF_UART_HWFC_ENABLED;
    config.interrupt_priority = 0x03; //irq_priority;
    config.parity = p_comm_params->use_parity ? NRF_UART_PARITY_INCLUDED : NRF_UART_PARITY_EXCLUDED;
    config.pselcts = p_comm_params->cts_pin_no;
    config.pselrts = p_comm_params->rts_pin_no;
    config.pselrxd = p_comm_params->rx_pin_no;
    config.pseltxd = p_comm_params->tx_pin_no;

		apply_UART(&config);	

		NRF_UART0 -> BAUDRATE = UART_BAUDRATE_BAUDRATE_Baud9600; 
		NRF_UART0 -> CONFIG = (UART_CONFIG_HWFC_Disabled | UART_CONFIG_PARITY_Included); 
		NRF_UART0 -> ENABLE  = UART_ENABLE_ENABLE_Enabled; // enables UART

}

void UART_LOOP_BACK (void)
{
	NRF_UART0 -> TASKS_STARTTX = 0x01;
	NRF_UART0 -> TASKS_STARTRX = 0x01;
	NRF_UART0 -> TXD = 0x0D;
	
}

void UART_init(void)
{
	/* configure the TX and RX pins */ 
	GPIO_CFG_OUTPUT(TX_PIN);
	GPIO_CFG_INPUT(RX_PIN);
  NRF_GPIO->OUTSET |= ( 1 << TX_PIN); 
	NRF_UART0 -> PSELTXD = ((uint32_t)(1 << TX_PIN));
	NRF_UART0 -> PSELRXD = ((uint32_t)(1 << RX_PIN));
	
	/* Configure RTS and CTS... if applicable  
	OUTHIGH(RTS_PIN);
	INLOW(CTS_PIN);
  NRF_UART0 -> PSELRTS = (1 << RTS_PIN);
	NRF_UART0 -> PSELCTS = (1 << CTS_PIN);
	*/
	
	/* configure the rest and enable */
  NRF_UART0 -> BAUDRATE = UART_BAUDRATE_BAUDRATE_Baud9600; 
	NRF_UART0 -> CONFIG = (UART_CONFIG_HWFC_Disabled | UART_CONFIG_PARITY_Included); 
	NRF_UART0 -> ENABLE  = UART_ENABLE_ENABLE_Enabled; // enables UART
	
}
