#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool check_skip(const char* skip, char alpha, unsigned int len)
{
    for(unsigned int i = 0; i < len; i++)
    {
        if(skip[i] == alpha) 
        {
            printf("문자 %c 는 스킵 문자 %c와 동일합니다.\n", alpha, skip[i]);
            return true;
        }
    }
    return false;
}

char increase_alpha(char input)
{
    char ret = input + 1;
    if(ret > 'z') ret = 'a';
    printf("문자 %c는 %c가 됩니다.\n", input, ret);
    return ret;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s, const char* skip, int index) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    unsigned int len = strlen(s);
    unsigned int len_skip = strlen(skip);
    char* answer = calloc(len + 1, 1);
    strcpy(answer, s);
    printf("입력 문자 : %s, 스킵 문자 : %s\n", s, skip);
    for(unsigned int i = 0; i < len; i++)
    {
        for(unsigned int j = 0; j < index; j++)
        {
            char temp;
            if(j == 0)
            {
                printf("문자 %c를 처리 중입니다.\n", answer[i]);
                temp = answer[i];
            }
            answer[i] = increase_alpha(answer[i]);
            while(check_skip(skip, answer[i], len_skip)) 
            {
                answer[i] = increase_alpha(answer[i]);
            }
        }
    }
    return answer;
}