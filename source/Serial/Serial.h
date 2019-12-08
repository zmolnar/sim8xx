/**
 * @file Serial.h
 * @brief 
 */

#ifndef SERIAL_H
#define SERIAL_H

/*****************************************************************************/
/* INCLUDES                                                                  */
/*****************************************************************************/
#include <stddef.h>
#include <string.h>


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
size_t GSM_SerialWrite(const char obuf[], size_t olen);

#endif /* SERIAL_H */

/****************************** END OF FILE **********************************/