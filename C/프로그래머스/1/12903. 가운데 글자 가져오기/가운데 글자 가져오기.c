#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    int length = strlen(s);
    char* answer = (char*)malloc(sizeof(char) * 3);
    
    if(length % 2 == 0)
    {
        answer[0] = s[length/2 - 1];
        answer[1] = s[length/2];
        answer[2] = '\0';
    }
    else
    {
        answer[0] = s[length/2];
        answer[1] = '\0';
    }
    
    return answer;
}