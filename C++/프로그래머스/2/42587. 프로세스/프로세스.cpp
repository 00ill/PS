
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int,int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < (int)priorities.size(); ++i) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int answer = 0;
    while (!q.empty()) {
        auto [p, idx] = q.front(); q.pop();

        if (p < pq.top()) {
            q.push({p, idx});
        } else {
            ++answer;
            pq.pop();
            if (idx == location) return answer;
        }
    }
    return answer;
}
