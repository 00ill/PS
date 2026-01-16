#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<int> dp(4, 0);
    for(int i = 0; i < 4; i++)
    {
        dp[i] = land[0][i]; //dp i 는 i번 째 열을 택했을 때의 최대 값임
    }
    vector<int> ndp(4, 0);
    
    for(int i = 1; i < land.size(); i++)
    {
        for(int j = 0; j < 4; j++)//이번 행에서 j열을 고르겠다
        {
            int best = 0;
            for(int k = 0; k < 4; k++)
            {
                if(j == k) continue;
                best = max(best, dp[k]);
            }
            ndp[j] = land[i][j] + best;
        }
        dp = ndp;
    }
    
    return *max_element(dp.begin(), dp.end());
}