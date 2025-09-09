#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int m, int count) {
    long long money = m;
    for(int i = 1; i <= count; i++)
    {
        money -= (price * i);
    }
    if(money >= 0) return 0;
    else return -money;
}