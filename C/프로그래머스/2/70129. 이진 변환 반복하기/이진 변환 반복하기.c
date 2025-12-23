#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void
stobin(int len, char *buf)
{
    unsigned int a = (1 << 31);
    unsigned int check_zero_fg = 0, index = 0;;
    for(int i = 0; i < 32; i++)
    {
        if((len & a) == a) {buf[index++] = '1'; check_zero_fg = 1; }
        else if(check_zero_fg == 1) buf[index++] = '0';
        a >>= 1;
    }
    buf[index] = '\0';
}

int* solution(const char* s) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0;
    answer[1] = 0;
    unsigned int len = strlen(s);
    if(len < 32) len = 32;
    char *S = calloc(len + 1, sizeof(char));
    char *next = calloc(len + 1, sizeof(char));
    strcpy(S, s);
    while(strcmp(S, "1") != 0)
    {
        len = strlen(S);
        char *p = next;
        for(int i = 0; i < len; i++)
        {
            if(S[i] == '0') { answer[1]++; continue; }
            if(S[i] == '1') { *p = '1'; p++; }
        }
        *p = '\0';
        answer[0]++;
        stobin(strlen(next), S);
    }    
    return answer;
}