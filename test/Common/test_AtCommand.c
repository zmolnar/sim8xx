#include "AtCommand.h"
#include "unity.h"

#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_At_Parse_OK(void)
{
  const char *input         = "\r\nOK\r\n";
  AT_CommandStatus_t status = AT_CMD_INVALID;

  size_t n = AT_CommandStatusParse(input, strlen(input), &status);

  TEST_ASSERT_EQUAL(AT_CMD_OK, status);
  TEST_ASSERT_EQUAL(strlen(input), n);
}

void test_At_Parse_OK_Incomplete(void)
{
  const char *input         = "\r\nCONN";
  AT_CommandStatus_t status = AT_CMD_INVALID;

  size_t n = AT_CommandStatusParse(input, strlen(input), &status);

  TEST_ASSERT_EQUAL(AT_CMD_INVALID, status);
  TEST_ASSERT_EQUAL(0, n);
}

void test_At_Parse_CONNECT(void)
{
  const char *input         = "\r\nCONNECT\r\n";
  AT_CommandStatus_t status = AT_CMD_INVALID;

  size_t n = AT_CommandStatusParse(input, strlen(input), &status);

  TEST_ASSERT_EQUAL(AT_CMD_CONNECT, status);
  TEST_ASSERT_EQUAL(strlen(input), n);
}

void test_At_Parse_RING(void)
{
  const char *input         = "\r\nRING\r\n";
  AT_CommandStatus_t status = AT_CMD_INVALID;

  size_t n = AT_CommandStatusParse(input, strlen(input), &status);

  TEST_ASSERT_EQUAL(AT_CMD_RING, status);
  TEST_ASSERT_EQUAL(strlen(input), n);
}

void test_At_Parse_NO_CARRIER(void)
{
  const char *input         = "\r\nNO CARRIER\r\n";
  AT_CommandStatus_t status = AT_CMD_INVALID;

  size_t n = AT_CommandStatusParse(input, strlen(input), &status);

  TEST_ASSERT_EQUAL(AT_CMD_NO_CARRIER, status);
  TEST_ASSERT_EQUAL(strlen(input), n);
}

void test_At_Parse_ERROR(void)
{
  const char *input         = "\r\nERROR\r\n";
  AT_CommandStatus_t status = AT_CMD_INVALID;

  size_t n = AT_CommandStatusParse(input, strlen(input), &status);

  TEST_ASSERT_EQUAL(AT_CMD_ERROR, status);
  TEST_ASSERT_EQUAL(strlen(input), n);
}

void test_At_Parse_NO_DIALTONE(void)
{
  const char *input         = "\r\nNO DIALTONE\r\n";
  AT_CommandStatus_t status = AT_CMD_INVALID;

  size_t n = AT_CommandStatusParse(input, strlen(input), &status);

  TEST_ASSERT_EQUAL(AT_CMD_NO_DIALTONE, status);
  TEST_ASSERT_EQUAL(strlen(input), n);
}

void test_At_Parse_BUSY(void)
{
  const char *input         = "\r\nBUSY\r\n";
  AT_CommandStatus_t status = AT_CMD_INVALID;

  size_t n = AT_CommandStatusParse(input, strlen(input), &status);

  TEST_ASSERT_EQUAL(AT_CMD_BUSY, status);
  TEST_ASSERT_EQUAL(strlen(input), n);
}

void test_At_Parse_NO_ANSWER(void)
{
  const char *input         = "\r\nNO ANSWER\r\n";
  AT_CommandStatus_t status = AT_CMD_INVALID;

  size_t n = AT_CommandStatusParse(input, strlen(input), &status);

  TEST_ASSERT_EQUAL(AT_CMD_NO_ANSWER, status);
  TEST_ASSERT_EQUAL(strlen(input), n);
}

void test_At_Parse_PROCEEDING(void)
{
  const char *input         = "\r\nPROCEEDING\r\n";
  AT_CommandStatus_t status = AT_CMD_INVALID;

  size_t n = AT_CommandStatusParse(input, strlen(input), &status);

  TEST_ASSERT_EQUAL(AT_CMD_PROCEEDING, status);
  TEST_ASSERT_EQUAL(strlen(input), n);
}

void test_At_Parse_WAIT_FOR_USER_DATA(void)
{
  const char *input         = "\r\n> ";
  AT_CommandStatus_t status = AT_CMD_INVALID;

  size_t n = AT_CommandStatusParse(input, strlen(input), &status);

  TEST_ASSERT_EQUAL(AT_CMD_WAIT_FOR_USER_DATA, status);
  TEST_ASSERT_EQUAL(strlen(input), n);
}
