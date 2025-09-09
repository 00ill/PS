#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int num) {
    return (num & 1) ? "Odd" : "Even";
}