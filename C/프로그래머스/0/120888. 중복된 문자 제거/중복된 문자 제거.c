#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) {
    size_t len = strlen(my_string);
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = calloc(len + 1, 1);
    bool arr[256] = {0};
    size_t index = 0;
    for(size_t i = 0; i < len; i++)
    {
        if(arr[my_string[i]] == 0)
        {
            arr[my_string[i]] = 1;
            answer[index++] = my_string[i];   
        }
    }
    return answer;
}