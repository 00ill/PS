#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len, int n) {
    int min = 999, index;
    for(int i = 0; i < array_len; i++)
    {
        if(abs(array[i] - n) < min)
        {
            min = abs(array[i] - n); index = i;
        }
        if(abs(array[i] - n) == min)
        {
            if(array[index] > array[i]) index = i;
        }
    }
    return array[index];
}