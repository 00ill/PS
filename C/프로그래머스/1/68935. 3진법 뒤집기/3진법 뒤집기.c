#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0, index = 0;
    int tri[100000] = {0};
    
    while(n > 0)
    {
        tri[index++] = n % 3;
        n /= 3;
    }

    for(int i = 0; i < index; i++)
    {
        answer += tri[i] * pow(3, (index - 1 - i));
    }
    
    return answer;
}