#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* polynomial) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
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
        else if(token[0] == 'x') {printf("x\n"); x++;}
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
    if(num == 0) {sprintf(answer, "%dx", x); if(x == 1) {sprintf(answer, "%s", "x");}}
    else if(x == 0) {sprintf(answer, "%d", num);}
    else {sprintf(answer, "%dx + %d", x, num); if(x == 1) {sprintf(answer, "%s + %d", "x", num);}}
    return answer;
}