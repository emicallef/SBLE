// Cfile for GPIO setup.  Basic LED on/off 
// page 113 is GPIO stuff 


#include "compiler_abstraction.h"
#include "nrf.h"
#include "GPIO.h"
#include <stdint.h>
	
#define Pin8							8							

void INLOW(uint32_t num)
{
	NRF_GPIO->DIRCLR |= (1UL << num);
  NRF_GPIO->OUTCLR |= (1UL << num); // dirclr = in dirset= out
	//outclr = low outset = high
}
void INHIGH(uint32_t num)
{
  NRF_GPIO->DIRCLR |= (1UL << num);
	NRF_GPIO->OUTSET |= (1UL << num);
}
void OUTHIGH(uint32_t num)
{
	NRF_GPIO->DIRSET |= (1UL << num);
	NRF_GPIO->OUTSET |= (1UL << num); 	
}
void OUTLOW(uint32_t num)
{
	NRF_GPIO->DIRSET |= (1UL << num);
	NRF_GPIO->OUTCLR |= (1UL << num);
}


void GPIO_CFG_OUTPUT(uint32_t pin_number)
{
    GPIO_CFG(pin_number,GPIO_PIN_DIR_OUTPUT,GPIO_PIN_INPUT_DISCONNECT,GPIO_PIN_NOPULL,GPIO_PIN_S0S1,GPIO_PIN_NOSENSE);
}
void GPIO_CFG_INPUT(uint32_t pin_number)
{
    GPIO_CFG(pin_number,GPIO_PIN_DIR_INPUT,GPIO_PIN_INPUT_CONNECT,GPIO_PIN_NOPULL,GPIO_PIN_S0S1,GPIO_PIN_NOSENSE);
}

void GPIO_CFG(uint32_t pin_number, GPIO_PIN_DIR dir, GPIO_PIN_BUFF input, GPIO_PULL pull,GPIO_DRV drive, GPIO_PIN_SENSE 	sense)
{
NRF_GPIO->PIN_CNF[pin_number] = ((uint32_t)dir   << GPIO_PIN_CNF_DIR_Pos)
                                  | ((uint32_t)input << GPIO_PIN_CNF_INPUT_Pos)
                                  | ((uint32_t)pull  << GPIO_PIN_CNF_PULL_Pos)
                                  | ((uint32_t)drive << GPIO_PIN_CNF_DRIVE_Pos)
                                  | ((uint32_t)sense << GPIO_PIN_CNF_SENSE_Pos);
}

