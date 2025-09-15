#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
char* solution(int food[], size_t food_len) {
    for(int i = 1; i < food_len; i++)    
    {
        if((food[i]&1) == 1)
        {
            food[i]--;
        }
    }
    int capacity = 2;
    char* answer = (char*)malloc(sizeof(char) * capacity);
    answer[0] = '\0';
    char buffer[2] = "";
    for(int i = 1; i < food_len; i++)
    {
        for(int j = 0; j < food[i] / 2; j++)
        {
            capacity++;
            answer = realloc(answer, (sizeof(char) * (capacity + 1)));
            sprintf(buffer, "%d", i);
            strcat(answer, buffer);
        }
    }
    strcat(answer, "0");
    for(int i = food_len - 1; i >= 0; i--)
    {
        for(int j = 0; j < food[i] / 2; j++)
        {
            capacity++;
            answer = realloc(answer, (sizeof(char) * (capacity + 1)));
            sprintf(buffer, "%d", i);
            strcat(answer, buffer);
        }
    }
    return answer;
}