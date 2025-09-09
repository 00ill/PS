#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool is_Number(char* str)
{
    while(*str)
    {
        if(!isdigit(*str)) return false;
        str++;
    }
    return true;
}

bool solution(const char* s) {
    if(strlen(s) == 4 || strlen(s) == 6)
    {
        return is_Number(s);
    }
    else
    {
        return false;
    }
}