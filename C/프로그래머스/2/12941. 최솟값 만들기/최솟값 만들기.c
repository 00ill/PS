#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare_low(void* a, void* b)
{
    return *(int*)a - *(int*)b;
}

int compare_high(void* a, void* b)
{
    return *(int*)b - *(int*)a;
}
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    qsort(A, A_len, sizeof(int), compare_low);
    qsort(B, B_len, sizeof(int), compare_high);
    for(int i = 0; i < A_len; i++)
    {
        answer += A[i] * B[i];
    }
    return answer;
}