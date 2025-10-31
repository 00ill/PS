#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int len = strlen(s);
    char x;
    int count_x = 0, count_other = 0;
    bool is_over = true;

    for (int i = 0; i < len; i++) {
        if (is_over == true) {
            x = s[i];
            count_x = 1;
            count_other = 0;
            is_over = false;
        } else {
            if (s[i] == x) count_x++;
            else count_other++;
        }

        if (count_x == count_other) {
            answer++;
            is_over = true;
        }
    }
    if (is_over == false) answer++;
    return answer;
}