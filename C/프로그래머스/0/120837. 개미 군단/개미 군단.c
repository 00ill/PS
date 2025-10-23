#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int hp) {
    int answer = hp / 5;
    hp -= answer * 5;
    answer += hp / 3;
    hp -= (hp / 3) * 3;
    answer += hp;
    return answer;
}