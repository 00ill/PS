
#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<double, int>& a, const pair<double, int>& b)
{
    if (fabs(a.first - b.first) < 1e-12)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    answer.resize(N);

    vector<int> stay(N + 2, 0);
    for (int s : stages)
    {
        if (1 <= s && s <= N)
        {
            stay[s] += 1;
        }
    }

    int reached = static_cast<int>(stages.size());

    vector<pair<double, int>> v;
    v.reserve(N);

    for (int i = 1; i <= N; ++i)
    {
        double rate = 0.0;
        if (reached > 0)
        {
            rate = static_cast<double>(stay[i]) / static_cast<double>(reached);
        }
        v.emplace_back(rate, i);
        reached -= stay[i];
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; ++i)
    {
        answer[i] = v[i].second;
    }

    return answer;
}
