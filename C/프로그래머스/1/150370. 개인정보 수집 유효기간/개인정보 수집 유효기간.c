#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// terms_len은 배열 terms의 길이입니다.
// privacies_len은 배열 privacies의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = calloc(privacies_len, sizeof(int));
    int today_yy, today_mm, today_dd;
    sscanf(today, "%d.%d.%d", &today_yy, &today_mm, &today_dd);
    struct term_t {char type; int mm;} *term = calloc(terms_len, sizeof(struct term_t));
    for(int i = 0; i < terms_len; i++)
    {
        sscanf(terms[i], "%c %d", &(term[i].type), &(term[i].mm));
    }
    int pri_yy, pri_mm, pri_dd, index = 0;
    char pri_type;
    for(int i = 0; i < privacies_len; i++)
    {
        sscanf(privacies[i], "%d.%d.%d %c", &pri_yy, &pri_mm, &pri_dd, &pri_type);
        for(int j = 0; j < terms_len; j++)
        {
            if(pri_type == term[j].type)
            {
                pri_dd += term[j].mm * 28;
                break;
            }
        }
        if(pri_yy * 12 * 28 + pri_mm * 28 + pri_dd <= today_yy * 12 * 28 + today_mm * 28 + today_dd)
            answer[index++] = i + 1;
    }
    return answer;
}