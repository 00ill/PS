#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* s) {
    int len = strlen(s), arr[26] = {0};
    char* answer = calloc(len + 1, 1);
    answer[0] = '\0';
    
    for(int i = 0; i < len; i++)
    {
        arr[s[i] - 'a']++;
    }
    
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] == 1)
        {
            char temp[2];
            temp[0] = i + 'a';
            temp[1] = '\0';
            strcat(answer, temp);
        }
    }
    return answer;
}