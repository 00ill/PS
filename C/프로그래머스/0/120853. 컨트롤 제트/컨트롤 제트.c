#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    char *str = calloc(strlen(s) + 1, 1);
    strcpy(str, s);
    int before, current;
    for(char *token = strtok(str, " "); token != NULL; token = strtok(NULL, " "))
    {
        if(token[0] == 'Z') answer -= before;
        else
        {
            sscanf(token, "%d", &current);
            answer += current;
            before = current;
        }
    }
    return answer;
}