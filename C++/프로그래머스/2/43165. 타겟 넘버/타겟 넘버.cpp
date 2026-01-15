
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers, int target)
{
    int n = (int)numbers.size();
    int answer = 0;
    int total = 1 << n;

    for (int mask = 0; mask < total; ++mask)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            int sgn = ((mask >> j) & 1) ? +1 : -1;
            sum += sgn * numbers[j];
        }
        if (sum == target)
        {
            ++answer;
        }
    }
    return answer;
}
