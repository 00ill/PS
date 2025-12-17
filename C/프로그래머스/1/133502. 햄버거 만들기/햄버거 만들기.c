#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ingredient_len은 배열 ingredient의 길이입니다.
int solution(int ingredient[], size_t ingredient_len) {
    int answer = 0, index = 0;
    int *stack = calloc(ingredient_len, sizeof(int));
    for(size_t i = 0; i < ingredient_len; i++)
    {
        switch (ingredient[i])
        {
            case 1 : 
                if(index >= 3)
                {
                    if(stack[index - 1] == 3 && stack[index - 2] == 2 && stack[index - 3] == 1)
                    {
                        index -= 3;
                        answer++;
                        break;
                    }
                }
                stack[index++] = 1;
                break;
            case 2 : 
                //if(index == 0) break;
                /*if(stack[index - 1] == 1)*/ stack[index++] = 2;
                break;
            case 3 :
                //if(index == 0) break;
                /*if(stack[index - 1] == 2)*/ stack[index++] = 3;
                break;
        }
    }
    return answer;
}