#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool can_pron(const char* pron[], char* bab, int len[], char* prev)
{
    if(bab[0] == '\0') return true;
    char *p = bab;
    for(int i = 0; i < 4; i++)
    {
        if(strncmp(pron[i], p, len[i]) == 0)
        {
            if(strncmp(p, prev,len[i]) == 0) return false;
            p = p + len[i];
            return can_pron(pron, p, len, pron[i]);
        }
    }    
    return false;    
}

int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    const char* pron[4] = {"aya", "ye", "woo", "ma"};
    const int len[4] = {3, 2, 3, 2};
    for(int i = 0; i < babbling_len; i++)
    {
        if(can_pron(pron, babbling[i], len, " ") == true) answer++;
    }
    return answer;
}