#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, unordered_map<string, int>> m;// string 종류의 옷 string을 저장
    for(int i = 0; i < clothes.size(); i++)
    {
        m[clothes[i][1]][clothes[i][0]]++;
    }
    
    for(auto& i : m)
    {
        answer *= i.second.size() + 1;
    }
    return answer - 1;
}