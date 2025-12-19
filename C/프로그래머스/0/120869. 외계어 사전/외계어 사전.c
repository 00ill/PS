#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* spell[], size_t spell_len, const char* dic[], size_t dic_len) {
    int pass = 0;
    for(int i = 0; i < dic_len; i++)
    {
        int len = strlen(dic[i]);
        if(len != spell_len) continue;
        for(int j = 0; j < len; j++)
        {
            for(int k = 0; k < len; k++)
            {
                if(spell[j][0] == dic[i][k]) {pass++; break;}
            }
        }
        if(pass == spell_len) return 1;
        pass = 0;
    }
    return 2;
}