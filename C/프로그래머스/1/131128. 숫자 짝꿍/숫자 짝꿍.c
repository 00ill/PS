#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* X, const char* Y) {
    int arr_x[10] = {0}, arr_y[10] = {0}, arr[10] = {0};
    int len_x = strlen(X), len_y = strlen(Y);
    for(int i = 0; i < len_x; i++)
    {
        arr_x[X[i] - '0']++;
    }
    for(int i = 0; i < len_y; i++)
    {
        arr_y[Y[i] - '0']++;
    }
    bool is_none = true, is_only_zero = true;
    unsigned long long len_answer = 0;
    for(int i = 0; i < 10; i++)
    {
        arr[i] = arr_x[i] < arr_y[i] ? arr_x[i] : arr_y[i];
        if(arr[i] > 0) {is_none = false; len_answer += arr[i]; if(i > 0) is_only_zero = false;}
    }
    if(is_none == true) return "-1"; if(is_only_zero == true) return "0";
    char* answer = (char*)malloc(len_answer + 1);
    int index = 0;
    for(int i = 9; i >= 0; i--)
    {
        while(arr[i] > 0)
        {
            answer[index++] = i + '0';
            arr[i]--;
        }
    }
    answer[index] = '\0';
    return answer;
}