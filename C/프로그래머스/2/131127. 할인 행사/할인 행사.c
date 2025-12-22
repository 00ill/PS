#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static int find_index(const char* want[], int want_len, const char* key)
{
    for(int i = 0; i < want_len; i++)
    {
        if(strcmp(want[i], key) == 0)
        {
            return i;
        }
    }
    return -1;
}

static bool is_match(const int window[], const int number[], int want_len)
{
    for(int i = 0; i < want_len; i++)
    {
        if(window[i] != number[i]) return false;
    }
    return true;
}
int solution(const char* want[], size_t want_len, int number[], size_t number_len, const char* discount[], size_t discount_len) {
    const int W = 10;
    int *window = calloc(want_len, sizeof(int));
    for(int i = 0; i < want_len; i++)
    {
        window[i] = 0;
    }
    for(int i = 0; i < W; i++)
    {
        int idx = find_index(want, want_len, discount[i]);
        if(idx >= 0) window[idx]++;
    }
    int answer = 0;
    if(is_match(window, number, want_len)) answer++;
    for(int i = 1; i + W - 1 < discount_len; i++)
    {
        int idx = find_index(want, want_len, discount[i - 1]);
        if(idx >= 0) window[idx]--;
        idx = find_index(want, want_len, discount[i + W - 1]);
        if(idx >= 0) window[idx]++;
        if(is_match(window, number, want_len)) answer++;
    }
    return answer;
}