#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare (const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    int size = 1;
    int* answer = (int*)malloc(sizeof(int) * size);
    int record[100001] = {0};
    for(int i = 0; i < numbers_len - 1; i++)
    {
        for(int j = i + 1; j < numbers_len; j++)
        {
            int sum = numbers[i] + numbers[j];
            if(record[sum] == 0)
            {
                record[sum] = 1;
                size++;
                answer = (int*)realloc(answer, sizeof(int) * size);
                answer[size - 2] = sum;
            }
        }
    }
    qsort(answer, size - 1, sizeof(int), compare);
    return answer;
}
