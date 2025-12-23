#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    int cieve[3001] = {0};
    for(int i = 2; i * i <= 3000; i++)
    {
        for(int j = i * i; j <= 3000; j+= i)
        {
            if(j % i == 0) {cieve[j] = 1;}
        }
    }
    for(int i = 0; i < nums_len; i++)
    {
        for(int j = i + 1; j < nums_len; j++)
        {
            for(int k = j + 1; k < nums_len; k++)
            {
                if(cieve[nums[i] + nums[j] + nums[k]] == 0) answer++;
            }
        }
    }
    return answer;
}