#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int n;
int cmp(vector<int> a, vector<int> b)
{
    if(a[n] == b[n])
    {
        return a[0] > b[0];
    }
    return a[n] < b[n];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    n = col - 1;
    sort(data.begin(), data.end(), cmp);
    if(0){
    for(int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < data[i].size(); j++)
        {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    }
    long long temp = 0;
    for(int i = row_begin; i <= row_end; i++)
    {
        for(int j = 0; j < data[i - 1].size(); j++)
        {
            temp += data[i - 1][j] % i;    
        }
        if(i == row_begin) answer = temp;
        else
        {
            answer = answer ^ temp;
        }
        temp = 0;
    }
    return answer;
}