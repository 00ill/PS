#include <iostream>
#include<vector>
#include <stdlib.h>
using namespace std;
int cmp (const void *a, const void *b)
{
    return *(const int*)a - *(const int*)b;
}
int cmp_rev (const void *a, const void *b)
{
    return *(const int*)b - *(const int*)a;
}
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int *a = &A[0], *b = &B[0];
    qsort(a, A.size(), sizeof(int), cmp);
    qsort(b, B.size(), sizeof(int), cmp_rev);
    for(int i = 0; i < A.size(); i++)
    {
        answer += a[i] * b[i];
    }

    return answer;
}