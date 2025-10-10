#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int n) {
    int answer = 0;
    int all = n;
    while(all >= a)
    {
        int get = all/a;
        answer += get * b;
        all -= get*a;
        all += get*b;
    }
    return answer;
}