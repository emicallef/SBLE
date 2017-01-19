// Cfile for SPI setup.  Basic initialization with EasyDMA 
// page 280 is SPIM

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "compiler_abstraction.h"
#include "nrf.h"
#include "UART.h"
#include "GPIO.h"

#define Clock_Pin		30 //for SPIM
#define MISO_Pin		29
#define MOSI_Pin		28		
#define Clock_Pin2	17 //for SPIS 
#define MISO_Pin2		16
#define MOSI_Pin2		18

void SPI_init(void)
{
	GPIO_CFG_OUTPUT(Clock_Pin2);  // configures as output
	GPIO_CFG_OUTPUT(MISO_Pin2);
	GPIO_CFG_INPUT(MOSI_Pin2);  // configues as input 
  NRF_GPIO->OUTSET |= (( 1 << Clock_Pin) | ( 1 << MISO_Pin )); // directly sets them as output
	NRF_SPI0 -> PSELMISO = MISO_Pin2;
	NRF_SPI0 -> PSELMOSI = MOSI_Pin2;
	NRF_SPI0 -> PSELSCK = Clock_Pin2;
	NRF_SPI0 -> FREQUENCY = SPI_FREQUENCY_FREQUENCY_M2; // sets the comfreq to 2Mbps... can go up to 8mbps or 4mbps.
	NRF_SPI0 -> CONFIG = 0x01;
	NRF_SPI0 -> ENABLE |= 0x01;						 //SPI_ENABLE_ENABLE_Enabled;
	NRF_SPI0 -> TXD = 0x0D;
}


void SPIM0_init(void)
{
	
	GPIO_CFG_OUTPUT(Clock_Pin);  // configures as output
	GPIO_CFG_OUTPUT(MISO_Pin);
	GPIO_CFG_INPUT(MOSI_Pin);  // configues as input 
  NRF_GPIO->OUTSET |= (( 1 << Clock_Pin) | ( 1 << MISO_Pin )); // directly sets them as output
	NRF_SPIM0 -> PSEL.MISO = MISO_Pin;
	NRF_SPIM0 -> PSEL.MOSI = MOSI_Pin;
	NRF_SPIM0 -> PSEL.SCK = Clock_Pin;
	NRF_SPIM0 -> FREQUENCY = SPI_FREQUENCY_FREQUENCY_M2; // sets the comfreq to 2Mbps... can go up to 8mbps or 4mbps.
	NRF_SPIM0 -> ENABLE = SPI_ENABLE_ENABLE_Enabled;
	
	NRF_SPIM0 -> RXD.LIST = 0x01; // sets the SPI up for DMA
	NRF_SPIM0 -> TXD.LIST = 0x01; // sets SPI up for DMA
	
	
	
}

void SPIS_init(void)
{
	GPIO_CFG_OUTPUT(Clock_Pin2);  // configures as output
	GPIO_CFG_OUTPUT(MISO_Pin2);
	GPIO_CFG_INPUT(MOSI_Pin2);  // configues as input 
  NRF_GPIO->OUTSET |= (( 1 << Clock_Pin) | ( 1 << MISO_Pin )); // directly sets them as output
	NRF_SPIS0 -> PSEL.MISO = MISO_Pin;
	NRF_SPIS0 -> PSEL.MOSI = MOSI_Pin;
	NRF_SPIS0 -> PSEL.SCK = Clock_Pin;

	NRF_SPIS0 -> ENABLE = SPI_ENABLE_ENABLE_Enabled;
	
	//NRF_SPIS0 -> RXD.LIST = 0x01; // sets the SPI up for DMA
	//NRF_SPIS0 -> TXD.LIST = 0x01; // sets SPI up for DMA
}
