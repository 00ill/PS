
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max = 0;
int call = 0;

void solve(int *arr, int** dungeons, size_t dungeons_rows, int k, int count)
{
    if (count > max) max = count;

    for (int i = 0; i < dungeons_rows; i++)
    {
        if (arr[i] == 0 && k >= dungeons[i][0])
        {
            arr[i] = 1;
            solve(arr, dungeons, dungeons_rows, k - dungeons[i][1], count + 1);
            arr[i] = 0;
        }
    }
}

// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    int *record = (int*)malloc(sizeof(int) * dungeons_rows);
    for (int i = 0; i < dungeons_rows; i++)
    {
        record[i] = 0;
    }

    max = 0;
    call = 0;
    solve(record, dungeons, dungeons_rows, k, 0);
    return max;
}
