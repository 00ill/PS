#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// emergency_len은 배열 emergency의 길이입니다.
int* solution(int emergency[], size_t emergency_len) {
    int* answer = (int*)malloc(sizeof(int) * emergency_len);
    int max = 0;
    int max_index = 0;
    for(int j = 0; j < emergency_len; j++)
    {
        for(int i = 0; i < emergency_len; i++)
        {
            if(emergency[i] > max)
            {
                max = emergency[i];
                max_index = i;
            }
        }
        emergency[max_index] = 0;
        answer[max_index] = j + 1;
        max = 0;
    }
    
    
    return answer;
}
