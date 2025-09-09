#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
double solution(int arr[], size_t arr_len) {
    double answer = 0;
    char length = arr_len;
    while(arr_len--)
    {
        answer += (double)(*arr)/ length;
        arr++;
    }
    return answer;
}