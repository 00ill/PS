#include <string>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    deque<int> q;
    priority_queue<int> pq;
    if(priorities.size() == 1) return 1;
    for(auto & i : priorities)
    {
        q.push_back(i);
        pq.push(i);
    }
    
    while(!q.empty())
    {
        if(q[0] < pq.top()) 
        {
            q.push_back(q[0]);
            q.pop_front();
            if(location == 0) location = q.size() - 1;
            else location--;
            continue;
        }
        else
        {
            pq.pop();
            if(location == 0) return answer;
            else 
            {
                answer++;
                q.pop_front();
                location--;
            }
        }
    }
}
