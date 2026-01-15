#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> map;
    for(int i = 0; i < arr1.size(); i++)
    {
        map.push_back(arr1[i] | arr2[i]);
    }
    for(int i = 0; i < n; i++)
    {
        answer.push_back("");
        int mask = (1 << n - 1);
        for(int j = 0; j < n; j++)
        {   
            if((mask & map[i]) == mask)
            {
                answer[i].append("#");
            }
            else
            {
                answer[i].append(" ");
            }
            mask >>= 1;
        }
    }
    return answer;
}