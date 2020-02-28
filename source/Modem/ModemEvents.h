/**
 * @file ModemEvents.h
 * @brief
 */

#ifndef MODEM_EVENT_H
#define MODEM_EVENT_H

/*****************************************************************************/
/* INCLUDES                                                                  */
/*****************************************************************************/

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
  MODEM_NO_EVENT,
  MODEM_EVENT_SIM_UNLOCKED,
} GSM_ModemEventType_t;

typedef struct ModemEvent_s {
  GSM_ModemEventType_t type;
  union {
    
  } payload;
} GSM_ModemEvent_t;

typedef void (*GSM_ModemCb_t)(GSM_ModemEvent_t *p);

/*****************************************************************************/
/* DECLARATION OF GLOBAL VARIABLES                                           */
/*****************************************************************************/

/*****************************************************************************/
/* DECLARATION OF GLOBAL FUNCTIONS                                           */
/*****************************************************************************/

#endif /* MODEM_EVENT_H */

/****************************** END OF FILE **********************************/