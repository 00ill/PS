#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n) {
    long long answer = 0;
    double root = sqrt(n);
    if((root - (int)root) == 0)
    {
        return pow(root + 1, 2);
    }
    else
        return -1;
}