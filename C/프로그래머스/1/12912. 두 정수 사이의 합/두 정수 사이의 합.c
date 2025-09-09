#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = a;
    int low = a, high = b;
    if(a == b)
    {
        return a;
    }
    else if(a > b)
    {
        answer = b;
        low = b;
        high = a;
    }
    while(low < high)
    {
        answer += ++low;
    }
    return answer;
}