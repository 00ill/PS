#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> dots) {
    int h, w;
    if(dots[0][0] != dots[1][0]) w = abs(dots[1][0] - dots[0][0]);
    else w = abs(dots[1][0] - dots[2][0]);
    if(dots[0][1] != dots[1][1]) h = abs(dots[1][1] - dots[0][1]);
    else h = abs(dots[1][1] - dots[2][1]);
    return h * w;
}