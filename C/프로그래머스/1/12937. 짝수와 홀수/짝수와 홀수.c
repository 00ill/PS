#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int num) {
    if(num & 0x01)
    {
        return "Odd";
    }
    else
    {
        return "Even";
    }
}