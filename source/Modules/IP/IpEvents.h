/**
 * @file IpEvents.h
 * @brief
 */

#ifndef IP_EVENTS_H
#define IP_EVENTS_H

/*****************************************************************************/
/* INCLUDES                                                                  */
/*****************************************************************************/
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
typedef enum {
  IP_EVENT_NO_EVENT,
  IP_EVENT_NET_DISCONNECTED,
} IP_EventType_t;

typedef struct IP_EventDisconnected_s {
  int32_t id;
} IP_EventDisconnected_t;

typedef struct IP_Event_s {
  IP_EventType_t type;
  union {
      IP_EventDisconnected_t disconnected;
  } payload;
} GSM_IpEvent_t;

typedef void (*GSM_IpCb_t)(GSM_IpEvent_t *p);

/*****************************************************************************/
/* DECLARATION OF GLOBAL VARIABLES                                           */
/*****************************************************************************/

/*****************************************************************************/
/* DECLARATION OF GLOBAL FUNCTIONS                                           */
/*****************************************************************************/

#endif /* IP_EVENTS_H */

/****************************** END OF FILE **********************************/
