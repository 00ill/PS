#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// section_len은 배열 section의 길이입니다.
int solution(int n, int m, int section[], size_t section_len) {
    int answer = 0;
    int index = section[0];
    if(m == 1) return section_len;
    while(index <= section[section_len - 1])
    {
        index += m;
        answer++;
        for(int i = 0; i < section_len; i++)
        {
            if (index <=section[i])
            {
                index = section[i];
                break;
            }
        }
    }
    return answer;
}

