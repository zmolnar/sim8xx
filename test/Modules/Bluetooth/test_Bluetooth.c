#include "unity.h"
#include "Bluetooth.h"

TEST_FILE("btpower.c");
TEST_FILE("btpaircfg.c");
TEST_FILE("Modem.c");
TEST_FILE("At.c");

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Bluetooth_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement Bluetooth");
}