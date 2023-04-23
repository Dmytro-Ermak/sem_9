#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct text {
    unsigned int count;
    unsigned int cnt_input;
    char** strings;
} Text;

void print(Text text);