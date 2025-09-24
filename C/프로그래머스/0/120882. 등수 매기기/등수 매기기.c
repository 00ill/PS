#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_rows는 2차원 배열 score의 행 길이, score_cols는 2차원 배열 score의 열 길이입니다.
int* solution(int** score, size_t score_rows, size_t score_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * score_rows);
    int* arr = (int*)malloc(sizeof(int) * score_rows);
    for(int i = 0; i < score_rows; i++)
    {
        arr[i] = score[i][0] + score[i][1];
    }
    
    int rank = 1;
    int max = -1;
    int max_old = 0;
    int old_count = 0;
    int max_index = 0;
    for(int j = 0; j < score_rows; j++)
    {
        for(int i = 0; i < score_rows; i++)
        {
            if(arr[i] > max)
            {
                max = arr[i];
                max_index = i;
            }
        }
        if(max == max_old)
        {
            answer[max_index] = rank - 1 - old_count;  
            old_count++;
        }
        else
        {
            answer[max_index] = rank;        
            old_count = 0;
        }
        rank++;
        max_old = max;
        max = -1;
        arr[max_index] = 0;
    }
    return answer;
}