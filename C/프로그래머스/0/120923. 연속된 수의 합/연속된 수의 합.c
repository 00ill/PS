#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
int* solution(int num, int total) {
    int* answer = (int*)malloc(num * sizeof(int));
    long long sum = 0, length;
    for(int i = -2000; i <= total; i++)
    {
        for(int j = 0; j < num; j++)
        {
            sum += total - i - j;
        }
        if(sum == total)
        {
            for(int j = 0; j < num; j++)
            {
                answer[num - j - 1] = total - i - j;
            }
        }
        sum = 0;
    }
    return answer;
}