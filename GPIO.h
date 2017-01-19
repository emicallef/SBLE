/**********************************************************************************/
/* Header file GPIO.h KEIL                                                        */
/* Author: Eric Micallef																													*/
/* These functions setup and toggle a pin specified by user											  */
/**********************************************************************************/
#ifndef _GPIO_H__
#define _GPIO_H__

#include "common_defs.h"
#include "nrf.h"
#include <stdbool.h>
#include <stdint.h>

/* declare initialisation functions for GPIO pin 8 */
extern void INLOW (uint32_t num);
extern void INHIGH(uint32_t num);
extern void OUTHIGH(uint32_t num);
extern void OUTLOW(uint32_t num);




/** configur pin this set the bit for output
 * @brief Pin direction definitions.
*/ 
typedef enum
{
    GPIO_PIN_DIR_INPUT  = GPIO_PIN_CNF_DIR_Input,   ///< Input
    GPIO_PIN_DIR_OUTPUT = GPIO_PIN_CNF_DIR_Output   ///< Output
} GPIO_PIN_DIR;

/**
 * @brief Connection of input buffer
*/ 
typedef enum
{
    GPIO_PIN_INPUT_CONNECT    = GPIO_PIN_CNF_INPUT_Connect,   ///< Connect input buffer
    GPIO_PIN_INPUT_DISCONNECT = GPIO_PIN_CNF_INPUT_Disconnect ///< Disconnect input buffer
} GPIO_PIN_BUFF;

/**
 * @brief Enumerator used for selecting the pin to be pulled down or up at the time of pin configuration
*/ 
typedef enum
{
    GPIO_PIN_NOPULL   = GPIO_PIN_CNF_PULL_Disabled,                 ///<  Pin pullup resistor disabled
    GPIO_PIN_PULLDOWN = GPIO_PIN_CNF_PULL_Pulldown,                 ///<  Pin pulldown resistor enabled
    GPIO_PIN_PULLUP   = GPIO_PIN_CNF_PULL_Pullup,                   ///<  Pin pullup resistor enabled
} GPIO_PULL;

/**
 * @brief Enumerator used for selecting output drive mode
*/ 
typedef enum
{
    GPIO_PIN_S0S1 = GPIO_PIN_CNF_DRIVE_S0S1, ///< !< Standard '0', standard '1'
    GPIO_PIN_H0S1 = GPIO_PIN_CNF_DRIVE_H0S1, ///< !< High drive '0', standard '1'
    GPIO_PIN_S0H1 = GPIO_PIN_CNF_DRIVE_S0H1, ///< !< Standard '0', high drive '1'
    GPIO_PIN_H0H1 = GPIO_PIN_CNF_DRIVE_H0H1, ///< !< High drive '0', high 'drive '1''
    GPIO_PIN_D0S1 = GPIO_PIN_CNF_DRIVE_D0S1, ///< !< Disconnect '0' standard '1'
    GPIO_PIN_D0H1 = GPIO_PIN_CNF_DRIVE_D0H1, ///< !< Disconnect '0', high drive '1'
    GPIO_PIN_S0D1 = GPIO_PIN_CNF_DRIVE_S0D1, ///< !< Standard '0'. disconnect '1'
    GPIO_PIN_H0D1 = GPIO_PIN_CNF_DRIVE_H0D1, ///< !< High drive '0', disconnect '1'
} GPIO_DRV;

/**
 * @brief Enumerator used for selecting the pin to sense high or low level on the pin input.
*/ 
typedef enum
{
    GPIO_PIN_NOSENSE    = GPIO_PIN_CNF_SENSE_Disabled,              ///<  Pin sense level disabled.
    GPIO_PIN_SENSE_LOW  = GPIO_PIN_CNF_SENSE_Low,                   ///<  Pin sense low level.
    GPIO_PIN_SENSE_HIGH = GPIO_PIN_CNF_SENSE_High,                  ///<  Pin sense high level.
} GPIO_PIN_SENSE;


extern void GPIO_CFG_OUTPUT(uint32_t pin_number);
extern void GPIO_CFG_INPUT(uint32_t pin_number);
extern void GPIO_CFG(uint32_t pin_number,GPIO_PIN_DIR	dir,GPIO_PIN_BUFF	input,GPIO_PULL pull,GPIO_DRV	drive,GPIO_PIN_SENSE sense);



#endif
