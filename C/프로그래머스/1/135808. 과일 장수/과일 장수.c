#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare (void* a, void* b)
{
    return *(int*)a - *(int*)b;
}
// score_len은 배열 score의 길이입니다.
int solution(int k, int m, int score[], size_t score_len) {
    int answer = 0;
    int count = 0;
    int min = k;
    qsort(score, score_len, sizeof(int), compare);
    for(int i = score_len - 1; i > -1; i--)
    {
        count++;
        if(min > score[i]) min = score[i];
        if(count == m) { answer+= min * m; count = 0;}
    }
    return answer;
}