#ifndef MY_INC_STDIO_H
        #define MY_INC_STDIO_H
        #include <stdio.h>
#endif
#ifndef MY_INC_STRING_H
        #define MY_INC_STRING_H
        #include <string.h>
#endif

extern int numLen(void *x, const char numtype[]);

static const char Int[][12] = {"int", "short", "long", "long long",
                                        "size_t", "unsigned int"};
static const size_t intcount = 6;

static const char Float[][11] = {"float", "double", "long double"};
static const size_t floatcount = 3;
