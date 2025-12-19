#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len, int k) {
    return (1 + 2 * (k - 1)) % numbers_len ? (1 + 2 * (k - 1)) % numbers_len : numbers_len;
}