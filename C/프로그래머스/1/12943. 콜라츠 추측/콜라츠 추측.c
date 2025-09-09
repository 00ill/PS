#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    long long num = n;
    while(num != 1)
    {
        if(num & 1)
            { num = 3 * num + 1;}
        else
            num /= 2;
        if(answer++ == 500)
            return -1;
    }
    return answer;
}