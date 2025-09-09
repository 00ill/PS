#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    int count = 0;
    int temp = n;
    while(temp)
    {
        temp/=10;
        count++;
    }
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int* answer = (int*)malloc(count * sizeof(int));
    count = 0;
    while(n)
    {
        answer[count++]= n%10;
        n/=10;
    }
    return answer;
}