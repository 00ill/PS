#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return(*(int*)a - *(int*)b);
}
// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int w_max = 0, h_max = 0;
    for(int i = 0; i < sizes_rows; i++)
    {
        qsort(sizes[i], sizes_cols, sizeof(int), compare);
    }
    for(int i = 0; i < sizes_rows; i++)
    {
        if(w_max < sizes[i][0]) w_max = sizes[i][0];
    }
    for(int i = 0; i < sizes_rows; i++)
    {
        if(h_max < sizes[i][1]) h_max = sizes[i][1];
    }
    return w_max * h_max;
}