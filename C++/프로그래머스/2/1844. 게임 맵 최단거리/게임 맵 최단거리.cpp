#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, 0));
    const int dy[4] = { -1, 1, 0, 0 };
    const int dx[4] = { 0, 0, -1, 1 };
    queue<pair<int,int>> q; 
    dist[0][0] = 1;
    q.push({0, 0});
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == n - 1 && x == m - 1) return dist[y][x];
        
        for (int dir = 0; dir < 4; ++dir)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            {
                continue;
            }
            if (maps[ny][nx] == 0)
            {
                continue;
            }
            if (dist[ny][nx] != 0)
            {
                continue;
            }

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ ny, nx });
        }
    }
    return -1;
}