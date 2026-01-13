#include <iostream>

using namespace std;

int solution(int n, int A, int B)
{
    int answer = 0;
    while(A != B)
    {
        if(A & 1) A = ((A + 1) >> 1);
        else A >>= 1;
        if(B & 1) B = ((B + 1) >> 1);
        else B >>= 1;
        answer++;
    }
    return answer;
}