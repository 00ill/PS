#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int gcd(int a, int b)
{
    while(a % b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}

int lcm(int a, int b)
{
    return a*b/gcd(a,b);
}

int solution(int arr[], size_t arr_len) {
    int answer = 0;
    for(int i = 0; i < arr_len - 1; i++)
    {
        arr[i + 1] = lcm(arr[i], arr[i + 1]);
    }
    return arr[arr_len - 1];
}