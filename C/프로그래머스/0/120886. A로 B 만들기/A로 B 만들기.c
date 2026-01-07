#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* before, const char* after) {
    int answer = 1, arr[26] = {0};
    int len = strlen(before);
    for(int i = 0; i < len; i++)
    {
        arr[before[i] - 'a']++;
        arr[after[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] != 0) return 0;
    }
    return answer;
}