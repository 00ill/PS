#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int answer = 0;
    int left[10001] = {0}, right[10001] = {0};
    int kinds_l = 0, kinds_r = 0;
    for(int i = 0; i < topping_len; i++)
    {
        if(right[topping[i]] == 0)  kinds_r++;
        right[topping[i]]++;
    }
    
    for(int i = 0; i < topping_len; i++)
    {
        if(left[topping[i]] == 0)  kinds_l++;
        left[topping[i]]++;
        if(right[topping[i]] == 1)  kinds_r--;
        right[topping[i]]--;
        if(kinds_r == kinds_l) answer++;
    }
    
    return answer;
}