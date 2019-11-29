/**
 * @file Bluetooth.c
 * @brief
 */

/*****************************************************************************/
/* INCLUDES                                                                  */
/*****************************************************************************/
#include "At.h"
#include "Bluetooth.h"
#include "Modem.h"
#include "btpaircfg.h"
#include "btpower.h"
#include "bthost.h"

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
void GSM_BluetoothObjectInit(GSM_Bluetooth_t *this)
{
    this->notify = NULL;
}

bool GSM_BluetoothRegisterCallback(GSM_Bluetooth_t *this, GSM_BluetoothCb cb)
{
    bool result = false;
    if (!this->notify) {
        this->notify = cb;
        result = true;
    }

    return result;
}

bool GSM_BluetoothSetup(GSM_Bluetooth_t *this, const char *name, const char *pin)
{
    BtPaircfg_t btpaircfg = {0};
    BtPaircfgObjectInit(&btpaircfg);
    BtPaircfgSetupRequest(&btpaircfg, 1, pin);
    GSM_ModemExecuteAtCommand(&btpaircfg.atcmd);

    if (AT_CMD_OK != BtPaircfgGetResponseStatus(&btpaircfg))
        return false;

    BtHost_t bthost = {0};
    BtHostObjectInit(&bthost);
    BtHostSetupRequest(&bthost, name);
    GSM_ModemExecuteAtCommand(&bthost.atcmd);

    return AT_CMD_OK == BtHostGetResponseStatus(&bthost);
}

bool GSM_BluetoothStart(GSM_Bluetooth_t *this)
{
    BtPower_t btpower = {0};
    BtPowerObjectInit(&btpower);
    BtPowerSetupRequest(&btpower, 1);

    GSM_ModemExecuteAtCommand(&btpower.atcmd);

    return (AT_CMD_OK == BtPowerGetResponseStatus(&btpower));
}

bool GSM_BluetoothStop(GSM_Bluetooth_t *this)
{
    BtPower_t btpower = {0};
    BtPowerObjectInit(&btpower);
    BtPowerSetupRequest(&btpower, 0);

    AT_Command_t *atcmd = BtPowerGetAtCommand(&btpower);
    GSM_ModemExecuteAtCommand(atcmd);

    return (AT_CMD_OK == BtPowerGetResponseStatus(&btpower));
}


/****************************** END OF FILE **********************************/