#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> q;
    for(int i = 0; i < enemy.size(); i++)
    {
        n -= enemy[i];
        q.push(enemy[i]);
        if(n < 0)
        {
            if(k == 0) break;
            n += q.top();
            q.pop();
            k--;
            answer++;
        }
        else
        {
            answer++;
        }
        
    }
    return answer;
}