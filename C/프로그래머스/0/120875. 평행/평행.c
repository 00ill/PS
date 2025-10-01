#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int solution(int** dots, size_t dots_rows, size_t dots_cols) {
    int dx1, dy1, dx2, dy2;

    // (0,1) vs (2,3)
    dx1 = dots[0][0] - dots[1][0];
    dy1 = dots[0][1] - dots[1][1];
    dx2 = dots[2][0] - dots[3][0];
    dy2 = dots[2][1] - dots[3][1];
    if (dy1 * dx2 == dy2 * dx1) return 1;

    // (0,2) vs (1,3)
    dx1 = dots[0][0] - dots[2][0];
    dy1 = dots[0][1] - dots[2][1];
    dx2 = dots[1][0] - dots[3][0];
    dy2 = dots[1][1] - dots[3][1];
    if (dy1 * dx2 == dy2 * dx1) return 1;

    // (0,3) vs (1,2)
    dx1 = dots[0][0] - dots[3][0];
    dy1 = dots[0][1] - dots[3][1];
    dx2 = dots[1][0] - dots[2][0];
    dy2 = dots[1][1] - dots[2][1];
    if (dy1 * dx2 == dy2 * dx1) return 1;

    return 0;
}