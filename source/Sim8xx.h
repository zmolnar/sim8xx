/**
 * @file Sim8xx.h
 * @brief
 */

#ifndef SIM_8XX_H
#define SIM_8XX_H

/*****************************************************************************/
/* INCLUDES                                                                  */
/*****************************************************************************/
#include <stdbool.h>
#include <stddef.h>

#include "BluetoothEvent.h"

/*****************************************************************************/
/* DEFINED CONSTANTS                                                         */
/*****************************************************************************/

/*****************************************************************************/
/* MACRO DEFINITIONS                                                         */
/*****************************************************************************/

/*****************************************************************************/
/* TYPE DEFINITIONS                                                          */
/*****************************************************************************/

/*****************************************************************************/
/* DECLARATION OF GLOBAL VARIABLES                                           */
/*****************************************************************************/

/*****************************************************************************/
/* DECLARATION OF GLOBAL FUNCTIONS                                           */
/*****************************************************************************/
void SIM_Init(void);

bool SIM_BluetoothRegisterCallback(GSM_BluetoothCb_t cb);

size_t SIM_ProcessInput(const char ibuf[], size_t ilen);


#endif /* SIM_8_XX_H */

/****************************** END OF FILE **********************************/
