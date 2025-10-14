#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int elements[], size_t elements_len) {
    int answer = 0;
    int sum = 0;
    int record[1000000];
    for(int i = 0; i < 1000000; i++) { record[i] = 0;}
    for(int i = 1; i <= elements_len; i++) // 수열의 길이
    {
        for(int j = 0; j < elements_len; j++) // 0
        {
            for(int k = j; k < j + i; k++)
            {
                sum += elements[k%elements_len];
            }
            record[sum]++;
            sum = 0;
        }
    }
    for(int i = 0; i < 1000000; i++)
    {
        if(record[i] > 0)
        {
            answer++;
        }
    }
    return answer;
}