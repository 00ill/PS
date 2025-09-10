#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* cards1[], size_t cards1_len, const char* cards2[], size_t cards2_len, const char* goal[], size_t goal_len) {
    int index_1 = 0, index_2 = 0;
    for (size_t i = 0; i < goal_len; i++) {
        if (index_1 < cards1_len && strcmp(cards1[index_1], goal[i]) == 0) {
            index_1++;
        } else if (index_2 < cards2_len && strcmp(cards2[index_2], goal[i]) == 0) {
            index_2++;
        } else {
            return "No";
        }
    }
    return "Yes";
}
