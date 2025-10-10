#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// section_len은 배열 section의 길이입니다.
int solution(int n, int m, int section[], size_t section_len) {

    int answer = 0;
    int index = section[0];
    int i = 0;

    while (i < section_len) 
    {
        index = section[i] + m - 1;
        answer++;
        while (i < section_len && section[i] <= index) i++;
    }

    return answer;

}