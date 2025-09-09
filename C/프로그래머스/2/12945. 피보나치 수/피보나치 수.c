#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int *arr = malloc(sizeof(int) * (n + 1));
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1234567;
    }
    return arr[n];
}