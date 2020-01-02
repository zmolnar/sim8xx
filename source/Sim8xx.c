/**
 * @file Sim8xx.c
 * @brief
 */

/*****************************************************************************/
/* INCLUDES                                                                  */
/*****************************************************************************/
#include "Sim8xx.h"

/*****************************************************************************/
/* DEFINED CONSTANTS                                                         */
/*****************************************************************************/

/*****************************************************************************/
/* TYPE DEFINITIONS                                                          */
/*****************************************************************************/

/*****************************************************************************/
/* MACRO DEFINITIONS                                                         */
/*****************************************************************************/

/*****************************************************************************/
/* DEFINITION OF GLOBAL CONSTANTS AND VARIABLES                              */
/*****************************************************************************/

/*****************************************************************************/
/* DECLARATION OF LOCAL FUNCTIONS                                            */
/*****************************************************************************/

/*****************************************************************************/
/* DEFINITION OF LOCAL FUNCTIONS                                             */
/*****************************************************************************/

/*****************************************************************************/
/* DEFINITION OF GLOBAL FUNCTIONS                                            */
/*****************************************************************************/
void SIM_Init(Sim8xx_t *this, Sim8xxConfig_t *config)
{
  GSM_ModemObjectInit(&this->modem);
  GSM_ModemRegisterPutFunction(&this->modem, config->put);
  GSM_BufferObjectInit(&this->buffer);
}

bool SIM_Start(Sim8xx_t *this)
{
  bool result = false;

  if (GSM_ModemIsAlive(&this->modem)) {
    result = GSM_ModemDisableEcho(&this->modem);
  }
  
  return result;
}

bool SIM_RegisterBluetoothCallback(Sim8xx_t *this, GSM_BluetoothCb_t cb)
{
  return GSM_ModemRegisterBluetoothCallback(&this->modem, cb);
}

bool SIM_IsAlive(Sim8xx_t *this)
{
  return GSM_ModemIsAlive(&this->modem);
}

bool SIM_ProcessChar(Sim8xx_t *this, char c)
{
  return GSM_BufferPushChar(&this->buffer, c);
}

void SIM_Parse(Sim8xx_t *this)
{
  size_t msglen = 0;
  do {
    GSM_BufferData_t ibuf = GSM_BufferGetData(&this->buffer);
    msglen = GSM_ModemParse(&this->modem, ibuf.data, ibuf.length);
    
    if (0 < msglen) {
      GSM_BufferPopData(&this->buffer, msglen);
    }
  } while (msglen && GSM_BufferGetLength(&this->buffer));
}

/****************************** END OF FILE **********************************/
