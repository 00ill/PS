#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    unordered_map<int, pair<int,int>> m;
    m[10] = {0,0}; // *
    m[11] = {2,0}; // #    
    m[1] = {0,3};
    m[2] = {1,3};
    m[3] = {2,3};
    m[4] = {0,2};
    m[5] = {1,2};
    m[6] = {2,2};
    m[7] = {0,1};
    m[8] = {1,1};
    m[9] = {2,1};
    m[0] = {1,0};
    int l_hand = 10, r_hand = 11;
    for(auto & i : numbers)
    {
        if(i == 1 || i == 4 || i == 7) {answer += "L"; l_hand = i; continue;}
        if(i == 3 || i == 6 || i == 9) {answer += "R"; r_hand = i; continue;}
        else
        {
            int l_dist = abs(m[i].first - m[l_hand].first) + abs(m[i].second - m[l_hand].second);
            int r_dist = abs(m[i].first - m[r_hand].first) + abs(m[i].second - m[r_hand].second);
            if(l_dist < r_dist) {answer += "L"; l_hand = i; continue;}
            else if(l_dist > r_dist) {answer += "R"; r_hand = i; continue;}
            else
            {
                if(hand == "left") {answer += "L"; l_hand = i;}
                else {answer += "R"; r_hand = i;}
            }
        }
    }
    return answer;
}
