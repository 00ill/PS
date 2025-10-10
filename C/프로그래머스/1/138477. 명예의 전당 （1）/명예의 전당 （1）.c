#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(void* a, void* b)
{
    return *(int*)a - *(int*)b;
}
// score_len은 배열 score의 길이입니다.
int* solution(int k, int score[], size_t score_len) {
    int* answer = (int*)malloc(sizeof(int) * score_len);
    int* record = (int*)malloc(sizeof(int) * k);
    for(int i = 0; i < k; i++)
    {
        record[i] = -1;
    }
    int index = k - 1;
    for(int i = 0; i < score_len; i++)
    {
        if(score[i] > record[0])
        {
            record[0] = score[i];
        }
        qsort(record, k, sizeof(int), compare);
        answer[i] = record[index];
        if(index > 0) index--;
    }
    return answer;
}