#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string) {
    int answer = 0;
    while(*my_string)
    {
        if('1' <= my_string[0] && my_string[0] <= '9')
        {
            const char *temp = my_string + 1;
            int num = my_string[0] - '0';
            while('0' <= temp[0] && temp[0] <= '9')
            {
                num *= 10;
                num += temp[0] - '0';
                temp++;
                my_string++;
            }
            answer += num;
        }
        my_string++;
    }
    return answer;
}