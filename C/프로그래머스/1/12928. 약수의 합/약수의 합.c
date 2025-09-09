#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int den = 1;
    while(den <= n)
    {
        if(n % den == 0)
        {
            answer += den;
        }
        den++;
    }        
    return answer;
}