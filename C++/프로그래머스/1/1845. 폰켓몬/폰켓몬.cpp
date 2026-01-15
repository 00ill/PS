#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int arr[200001] = {0};
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(arr[nums[i]] > 0) continue;
        arr[nums[i]]++;
        cnt++;
    }
    return min(cnt, (int)nums.size() / 2);
}