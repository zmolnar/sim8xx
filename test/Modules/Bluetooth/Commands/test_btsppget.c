#include "btsppget.h"
#include "test_btsppget_static.h"
#include "unity.h"

#include <string.h>

TEST_FILE("AtCommand.c");
TEST_FILE("Utils.c");

void setUp(void)
{
}

void tearDown(void)
{
}

void test_BtSppGetIsURC_BTSPPDATA(void)
{
    const char *ibuf = "\r\n+BTSPPDATA: 2,15,SIMCOMSPPFORAPP\r\n";
    size_t ilen = strlen(ibuf);

    bool result = BtSppGetIsURC(ibuf, ilen);

    TEST_ASSERT(result);
}

void test_BtSppGetParseURC_BTSPPDATA(void)
{
    const char *ibuf = "\r\n+BTSPPDATA: 2,15,SIMCOMSPPFORAPP\r\n";
    size_t ilen = strlen(ibuf);

    BtSppGetURC_t urc;
    size_t n = BtSppGetParseURC(&urc, ibuf, ilen);

    TEST_ASSERT_EQUAL(ilen, n);
    TEST_ASSERT_EQUAL(BTSPPGET_SPPDATA, urc.type);
    TEST_ASSERT_EQUAL(2, urc.payload.getdata.id);
    TEST_ASSERT_EQUAL(15, urc.payload.getdata.length);
    TEST_ASSERT_EQUAL_STRING("SIMCOMSPPFORAPP", urc.payload.getdata.data);
}

void test_BtSppGetParseURC_IncompleteURC(void)
{
    const char *ibuf = "\r\n+BTSPPDATA: 2,15,SIMCOMSPP";
    size_t ilen = strlen(ibuf);

    BtSppGetURC_t urc;
    size_t n = BtSppGetParseURC(&urc, ibuf, ilen);

    TEST_ASSERT_EQUAL(0, n);
    TEST_ASSERT_EQUAL(BTSPPGET_NO_URC, urc.type);
    TEST_ASSERT_EQUAL(0, urc.payload.getdata.id);
    TEST_ASSERT_EQUAL(0, urc.payload.getdata.length);
    TEST_ASSERT_EQUAL_STRING("", urc.payload.getdata.data);
}
