#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int chicken) {
    int answer = 0;
    int ticket = chicken;
    while(ticket >= 10)
    {
        answer += ticket / 10;
        int extra = ticket % 10;
        ticket /= 10;
        ticket += extra;
    }
    return answer;
}