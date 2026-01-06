#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int arr[1000] = {0};
    for(int i = 0; i < array_len; i++)
    {
        arr[array[i]]++;
    }
    int count = 0, index = 0;
    
    for(int i = 0; i < 1000; i++)
    {
        if(arr[i] > count) {count = arr[i]; index = i;}
    }
    
    for(int i = 0; i < 1000; i++)
    {
        if(i == index) continue;
        if(arr[i] == count) return -1;
    }
    return index;
}