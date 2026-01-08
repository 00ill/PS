#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// skill_trees_len은 배열 skill_trees의 길이입니다.
int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
    int answer = 0, target_index = 0;
    for(int i = 0; i < skill_trees_len; i++)
    {
        char *current = skill_trees[i];
        while(*current)
        {
            char temp[2];
            temp[0] = *current;
            temp[1] = '\0';
            if(strstr(skill, temp) != NULL)
            {
                if(skill[target_index] == *current) target_index++;
                else break;
            }
            current++;
            if(*current == NULL) answer++;
        }
        target_index = 0;
    }
    return answer;
}