#include "bthost.h"
#include "test_bthost_static.h"
#include "unity.h"

#include <string.h>

TEST_FILE("At.c");

void setUp(void)
{
}

void tearDown(void)
{
}

void test_BtHostObjectInit(void)
{
  BtHost_t bthost;
  BtHostObjectInit(&bthost);

  TEST_ASSERT_EQUAL(&bthost, bthost.atcmd.obj);
  TEST_ASSERT_EQUAL_PTR(BtHostSerialize, bthost.atcmd.serialize);
  TEST_ASSERT_EQUAL_PTR(BtHostParse, bthost.atcmd.parse);
  TEST_ASSERT_EQUAL(5, bthost.atcmd.timeout);
}

void test_BtHostSetupRequest(void)
{
  BtHost_t bthost;
  BtHostObjectInit(&bthost);
  const char *name = "gtrack";
  BtHostSetupRequest(&bthost, name);

  TEST_ASSERT_EQUAL(name, bthost.request.name);
}

void test_BtHostGetAtCommand(void)
{
  BtHost_t bthost;
  BtHostObjectInit(&bthost);

  AT_Command_t *atcmd = BtHostGetAtCommand(&bthost);

  TEST_ASSERT_EQUAL(&bthost, atcmd->obj);
  TEST_ASSERT_EQUAL_PTR(BtHostSerialize, atcmd->serialize);
  TEST_ASSERT_EQUAL_PTR(BtHostParse, atcmd->parse);
  TEST_ASSERT_EQUAL(5, atcmd->timeout);
}

void test_BtHostSerialize(void)
{
  BtHost_t bthost;
  BtHostObjectInit(&bthost);
  const char *name = "gtrack";
  BtHostSetupRequest(&bthost, name);

  char obuf[32] = {0};
  size_t n      = BtHostSerialize(&bthost, obuf, sizeof(obuf));

  TEST_ASSERT_EQUAL_STRING("AT+BTHOST=gtrack", obuf);
}

void test_BtHostParse(void)
{
  BtHost_t bthost;
  BtHostObjectInit(&bthost);

  const char *ibuf = "\r\nOK\r\n=CGNSINF...";
  size_t length    = strlen(ibuf);

  size_t n = BtHostParse(&bthost, ibuf, length);

  TEST_ASSERT_EQUAL(AT_CMD_OK, bthost.response.status);
  TEST_ASSERT_EQUAL(6, n);
}

void test_BtHostParse_Incomplete(void)
{
  BtHost_t bthost;
  BtHostObjectInit(&bthost);

  const char *ibuf = "\r\nOK\r";
  size_t length    = strlen(ibuf);

  size_t n = BtHostParse(&bthost, ibuf, length);

  TEST_ASSERT_EQUAL(AT_CMD_INVALID, bthost.response.status);
  TEST_ASSERT_EQUAL(0, n);
}

void test_BtHostParse_InvalidStatus(void)
{
  BtHost_t bthost;
  BtHostObjectInit(&bthost);

  const char *ibuf = "\r\nPROCEEDING\r\n";
  size_t length    = strlen(ibuf);

  size_t n = BtHostParse(&bthost, ibuf, length);

  TEST_ASSERT_EQUAL(AT_CMD_INVALID, bthost.response.status);
  TEST_ASSERT_EQUAL(0, n);
}
