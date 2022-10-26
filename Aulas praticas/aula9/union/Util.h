#ifndef __UTIL_H
#define __UTIL_H

#include <stdio.h>

#define AVISO(msg) printf("AVISO: %s\n", #msg)

typedef enum {
    false,
    true
} bool;

typedef char *String;

#endif