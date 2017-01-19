// data sheet information on page 532
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "compiler_abstraction.h"
#include "nrf.h"
#include "UART.h"
#include "GPIO.h"

void apply_UART(const UART_DRV_CONFIG * config)
{
	/*Configure TX and RX */   
  GPIO_CFG_OUTPUT(config -> pseltxd);
	GPIO_CFG_INPUT(config  -> pselrxd);
  NRF_GPIO->OUTSET |= ( 1 << (config -> pseltxd));
	
	NRF_UART0 -> BAUDRATE = (config -> baudrate);
	NRF_UART0 -> CONFIG = (config -> parity | config -> hwfc);
	NRF_UART0 -> PSELTXD = (config -> pseltxd); 
	NRF_UART0 -> PSELRXD = (config -> pselrxd);
	
		if (config->hwfc == NRF_UART_HWFC_ENABLED)
      {
            GPIO_CFG_INPUT(config->pselcts);
            GPIO_CFG_OUTPUT(config->pselrts);
            NRF_GPIO-> OUTSET |= (config->pselrts);
            NRF_UART0 -> PSELRTS = (config -> pselrts);
						NRF_UART0 -> PSELCTS = (config -> pselcts);
      }
	NRF_UART0	-> ENABLE = UART_ENABLE_ENABLE_Enabled;	
 }
