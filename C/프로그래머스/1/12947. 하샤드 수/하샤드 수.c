#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int temp = x;
    while(temp)
    {
        sum += temp % 10;
        temp /= 10;
    }
    if(x % sum == 0)
        return true;
    else
        return false;
}