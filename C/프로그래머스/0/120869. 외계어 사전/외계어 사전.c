#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// spell_len은 배열 spell의 길이입니다.
// dic_len은 배열 dic의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* spell[], size_t spell_len, const char* dic[], size_t dic_len) {
    int answer = 0, pass = 0;;
    for(int i = 0; i < dic_len; i++)
    {
        int len = strlen(dic[i]);
        if(len != spell_len) continue;
        for(int j = 0; j < len; j++)
        {
            printf("%c가 %s에 있는 지 검색\n", spell[j][0], dic[i]);
            for(int k = 0; k < len; k++)
            {
                printf("%c가 인덱스 %d의 %c와 비교 : ", spell[j][0], k, dic[i][k]);
                if(spell[j][0] == dic[i][k])
                {
                    printf("스펠%c가 %c와 일치\n", spell[j][0], dic[i][k]);
                    pass++;
                    break;
                }
                else
                {
                    printf("스펠%c가 %c와 불일치\n", spell[j][0], dic[i][k]);
                }
            }
        }
        if(pass == spell_len) return 1;
        pass = 0;
    }
    return 2;
}