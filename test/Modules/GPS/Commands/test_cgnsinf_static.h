#ifndef TEST_CGNSINF_STATIC_H
#define TEST_CGNSINF_STATIC_H

#include "AtCommand.h"

size_t CgnsInfSerialize(void *obj, char *obuf, size_t length);
size_t CgnsInfParse(void *obj, const char *ibuf, size_t length);
void CgnsInfTimeout(void *p);

#endif