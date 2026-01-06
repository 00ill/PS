#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void push(char* a)
{
    char buffer[100];
    int len = strlen(a);
    strcpy(&buffer[1], a);
    buffer[0] = a[len - 1];
    buffer[len] = '\0';
    strcpy(a, buffer);
}

int solution(const char* A, const char* B) {
    int answer = 0;
    if(strcmp(A, B) == 0) return 0;
    if(strlen(A) != strlen(B)) return -1;
    
    int len = strlen(A);
    for(int i = 0; i < len; i++)
    {
        push(A);
        if(strcmp(A, B) == 0) {return i + 1;}
        if(i == len - 1) return -1;
    }
}