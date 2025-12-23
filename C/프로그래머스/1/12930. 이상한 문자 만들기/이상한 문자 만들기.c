#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* s) {
    size_t len = strlen(s), index = 0;
    char *S = calloc(len + 1, 1);
    for(int i = 0; i < len; i++)
    {
        if(s[i] == ' ') { S[i] = ' '; index = 0; }
        else
        {
            if(index % 2 == 0) 
            {
                S[i] = toupper(s[i]);
            }
            else
            {
                S[i] = tolower(s[i]);
            }
            index++;
        }
    }
    return S;
}