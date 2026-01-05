#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* phone_number) {
    size_t len = strlen(phone_number);
    char* answer = calloc(len + 1, 1);
    strcpy(answer, phone_number);
    for(int i = 0; i < len - 4; i++)
    {
        answer[i] = '*';
    }
    return answer;
}