/**
 * @file At.h
 * @brief
 */

#ifndef AT_H
#define AT_H

/*****************************************************************************/
/* INCLUDES                                                                  */
/*****************************************************************************/
#include "Common/AtCommand.h"

#include <stddef.h>
#include <stdint.h>

/*****************************************************************************/
/* DEFINED CONSTANTS                                                         */
/*****************************************************************************/

/*****************************************************************************/
/* MACRO DEFINITIONS                                                         */
/*****************************************************************************/

/*****************************************************************************/
/* TYPE DEFINITIONS                                                          */
/*****************************************************************************/
typedef struct At_response_s {
  AT_CommandStatus_t status;
} At_response_t;

typedef struct At_s {
  At_response_t response;
  AT_Command_t atcmd;
} At_t;

/*****************************************************************************/
/* DECLARATION OF GLOBAL VARIABLES                                           */
/*****************************************************************************/

/*****************************************************************************/
/* DECLARATION OF GLOBAL FUNCTIONS                                           */
/*****************************************************************************/
void AtObjectInit(At_t *this);

void AtSetupRequest(At_t *this);

AT_Command_t *AtGetAtCommand(At_t *this);

At_response_t AtGetResponse(At_t *this);

AT_CommandStatus_t AtGetResponseStatus(At_t *this);

#endif /* AT_H */

/****************************** END OF FILE **********************************/
