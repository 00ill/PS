#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int N;
int compare(void* a, void* b)
{
    if(abs((*(int*)a)-N) > abs((*(int*)b) - N)) return 1;
    else if(abs((*(int*)a)-N) == abs((*(int*)b) - N)) return *(int*)b - *(int*)a;
    else return -1;
}

// numlist_len은 배열 numlist의 길이입니다.
int* solution(int numlist[], size_t numlist_len, int n) {
    N = n;
    int* answer = (int*)malloc(sizeof(int) * numlist_len);
    qsort(numlist, numlist_len, sizeof(int), compare);
    return numlist;
}