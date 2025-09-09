#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* t, const char* p) {
    int answer = 0;
    int length_t = strlen(t);
    int length_p = strlen(p);
    char *part = (char*)malloc(sizeof(char) * (length_p + 1));
    for(int i = 0; i < length_t - length_p + 1; i++)
    {
        strncpy(part, t + i, length_p);
        part[length_p] = '\0';
        if(strcmp(part, p) <= 0)
        {
            answer++;
        }
    }
    return answer;
}