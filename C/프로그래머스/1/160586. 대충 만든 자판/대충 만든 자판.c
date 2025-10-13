#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// keymap_len은 배열 keymap의 길이입니다.
// targets_len은 배열 targets의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* keymap[], size_t keymap_len, const char* targets[], size_t targets_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * targets_len);
    for(int i = 0; i < targets_len; i++) { answer[i] = 0;} 
    int arr[128];
    for(int i = 0; i < 128; i++)
    {
        arr[i] = 9999;
    }
    for(int i = 0; i < keymap_len; i++)
    {
        int length = strlen(keymap[i]);
        for(int j = 0; j < length; j++)
        {
            if(arr[(int)keymap[i][j]] > j + 1)
            {
                arr[(int)keymap[i][j]] = j + 1;
            }
        }
    }
    for(int i = 0; i < targets_len; i++)
    {
        int length = strlen(targets[i]);
        for(int j = 0; j < length; j++)
        {
            if(arr[(int)targets[i][j]] == 9999) {answer[i] = -1; break;}
            else answer[i] += arr[(int)targets[i][j]];
        }
    }
    return answer;
}