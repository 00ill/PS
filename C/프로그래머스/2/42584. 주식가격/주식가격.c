#include <stdio.h>
#include <stdlib.h>

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    int* answer = (int*)malloc(sizeof(int) * prices_len);
    
    for (int i = 0; i < prices_len; i++) {
        answer[i] = 0;
        for (int j = i + 1; j < prices_len; j++) {
            answer[i]++;
            if (prices[j] < prices[i]) {
                break;
            }
        }
    }
    
    return answer;
}