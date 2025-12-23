#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
// wallpaper_len은 배열 wallpaper의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* wallpaper[], size_t wallpaper_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(1);
    struct pos_t {int x; int y;} *pos = calloc(wallpaper_len * wallpaper_len, sizeof(struct pos_t));
    int pos_index = 0;
    int i_min = INT_MAX, i_max = INT_MIN, j_min = INT_MAX, j_max = INT_MIN;
    for(int i = 0; i < wallpaper_len; i++)
    {
        int row_len = strlen(wallpaper[i]);
        for(int j = 0; j < row_len; j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(i < i_min) i_min = i;
                if(i > i_max) i_max = i;
                if(j < j_min) j_min = j;
                if(j > j_max) j_max = j;
            }
        }
    }
    printf("i min : %d max : %d\n", i_min, i_max);
    printf("j min : %d max : %d\n", j_min, j_max);

    answer[0] = i_min;
    answer[1] = j_min;
    answer[2] = i_max + 1;
    answer[3] = j_max + 1;
    
    return answer;
}