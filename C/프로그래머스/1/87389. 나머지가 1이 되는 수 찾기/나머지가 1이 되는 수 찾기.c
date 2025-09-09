#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 2;
    while(n % answer != 1)
    {
        answer++;
    }
    return answer;
}