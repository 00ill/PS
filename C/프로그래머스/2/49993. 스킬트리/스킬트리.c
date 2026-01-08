#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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