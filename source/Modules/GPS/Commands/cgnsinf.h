/**
 * @file cgnsinf.h
 * @brief
 */

#ifndef CGNSINF_H
#define CGNSINF_H

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
typedef struct CgnsInf_response_s {
  AT_CommandStatus_t status;
  int32_t runStatus;
  int32_t fixStatus;
  char date[19];
  double latitude;
  double longitude;
  double altitude;
  double speed;
  double course;
  int32_t fixMode;
  double hdop;
  double pdop;
  double vdop;
  int32_t gpsSatInView;
  int32_t gnssSatInUse;
  int32_t gnssSatInView;
  int32_t cnomax;
  double hpa;
  double vpa;
} CgnsInf_response_t;

typedef struct CgnsInf_s {
  CgnsInf_response_t response;
  AT_Command_t atcmd;
} CgnsInf_t;

/*****************************************************************************/
/* DECLARATION OF GLOBAL VARIABLES                                           */
/*****************************************************************************/

/*****************************************************************************/
/* DECLARATION OF GLOBAL FUNCTIONS                                           */
/*****************************************************************************/
void CgnsInfObjectInit(CgnsInf_t *this);

AT_Command_t *CgnsInfGetAtCommand(CgnsInf_t *this);

CgnsInf_response_t CgnsInfGetResponse(CgnsInf_t *this);

AT_CommandStatus_t CgnsInfGetResponseStatus(CgnsInf_t *this);

#endif /* CGNSINF_H */

/****************************** END OF FILE **********************************/
