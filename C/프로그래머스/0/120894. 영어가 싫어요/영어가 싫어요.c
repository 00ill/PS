#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
long long solution(const char* numbers) {
    long long answer = 0;
    const char *p = numbers;
    while(*p)
    {
        if(p[0] == 'z') {answer += 0; p += 4;}
        else if(p[0] == 'o') {answer += 1; p += 3;}
        else if(p[0] == 't' && p[1] == 'w') {answer += 2; p += 3;}
        else if(p[0] == 't' && p[1] == 'h') {answer += 3; p += 5;}
        else if(p[0] == 'f' && p[1] == 'o') {answer += 4; p += 4;}
        else if(p[0] == 'f' && p[1] == 'i') {answer += 5; p += 4;}
        else if(p[0] == 's' && p[1] == 'i') {answer += 6; p += 3;}
        else if(p[0] == 's' && p[1] == 'e') {answer += 7; p += 5;}
        else if(p[0] == 'e') {answer += 8; p += 5;}
        else if(p[0] == 'n') {answer += 9; p += 4;}
        if(*p != '\0') answer *= 10;
    }
    return answer;
}