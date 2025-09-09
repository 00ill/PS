#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare_char(const void* a, const void* b)
{
    char arg1 = *(const char*)a;
    char arg2 = *(const char*)b;
    return arg2 - arg1;
}

char* solution(const char* s) {
    
    char* answer = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(answer, s);
    qsort(answer, strlen(answer), sizeof(char), compare_char);
    return answer;
}