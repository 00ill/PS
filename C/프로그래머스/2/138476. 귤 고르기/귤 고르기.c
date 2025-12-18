#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp(void*a, void*b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (y > x) return 1;
    if (y < x) return -1;
    return 0;
}

// tangerine_len은 배열 tangerine의 길이입니다.
int solution(int k, int tangerine[], size_t tangerine_len) {
    if(k == 1) return 1;
    int answer = 0;
    int arr[10000001] = {0};
    for(int i = 0; i < tangerine_len; i++)
    {
        arr[tangerine[i]]++;
    }
    qsort(arr, 10000001, sizeof(int), cmp);
    int count = 0, index = 0;
    while(count < k)
    {
        count += arr[index++];
    }
    return index;
}