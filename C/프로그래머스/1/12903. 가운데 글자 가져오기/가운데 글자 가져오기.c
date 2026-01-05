#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* s) {
    size_t len = strlen(s);
    char* answer = calloc(3, 1);
    if(len & 1)
    {
        answer[0] = s[(len - 1) / 2];
        
    }
    else
    {
        answer[0] = s[len / 2 - 1];
        answer[1] = s[len / 2];
        answer[2] = '\0';
    }
    return answer;
}