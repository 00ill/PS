#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    for(auto& i : participant) m[i]++;
    for(auto& i : completion) m[i]--;
    for(auto& i : participant) if(m[i] > 0) return i;
}