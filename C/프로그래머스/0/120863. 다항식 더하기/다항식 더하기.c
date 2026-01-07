#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* polynomial) {
    char* answer = (char*)malloc(512);
    int len = strlen(polynomial);
    char *str = calloc(len + 1, 1);
    strcpy(str, polynomial);
    char *token = strtok(str, " ");
    int num = 0, x = 0;
    while(1)
    {
        int token_len = strlen(token);
        int temp;
        if(token[0] == '+') {}
        else if(token[0] == 'x') x++;
        else if(token[token_len - 1] == 'x')
        {
            sscanf(token, "%dx ", &temp);
            x += temp;
        }
        else
        {
            sscanf(token, "%d ", &temp);
            num += temp;
        }
        token = strtok(NULL, " ");
        if(token == NULL) break;
    }
    if(num == 0) 
    {
        if(x == 1) sprintf(answer, "%s", "x");
        else sprintf(answer, "%dx", x); 
    }
    else if(x == 0) sprintf(answer, "%d", num);
    else 
    {
        if(x == 1) {sprintf(answer, "%s + %d", "x", num);}
        else sprintf(answer, "%dx + %d", x, num); 
    }
    return answer;
}