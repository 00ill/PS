#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_valid(const char* s, int length) {
    char stack[1000];
    int top = -1;

    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) return false;
            char last = stack[top--];
            if ((c == ')' && last != '(') ||
                (c == '}' && last != '{') ||
                (c == ']' && last != '[')) {
                return false;
            }
        }
    }
    return top == -1;
}

int solution(const char* s) {
    int answer = 0;
    int length = strlen(s);
    char rotated[1000];

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            rotated[j] = s[(i + j) % length];
        }
        rotated[length] = '\0';

        if (is_valid(rotated, length)) {
            answer++;
        }
    }

    return answer;
}