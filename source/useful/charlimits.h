#pragma once
#include <string.h>
#include <stdio.h>

extern long numLen(void *x, const char numtype[]);

static const char Int[][12] = { "int", "short", "long","long long",
                                "size_t", "unsigned int" };
static const char Float[][11] = { "float", "double", "long double" };
static const size_t intcount = 6;
static const size_t floatcount = 3;
