#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int cmp(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;
    char *str = (char *)calloc(s.size() + 1, 1);
    strcpy(str, s.c_str());
    char **s_arr = (char**)calloc(500, sizeof(char*));
    int index = 0;
    
    for(char *token = strtok(str, "}"); token != NULL; token = strtok(NULL, "}"))
    {
        s_arr[index] = (char*)calloc(strlen(token) + 1, 1);
        strcpy(s_arr[index], token);
        index++;
    }
    
    for(int i = 0; i < index; i++)
    {
        v.push_back(vector<int>(0, 0));
        for(char *token = strtok(s_arr[i], "{},"); token != NULL; token = strtok(NULL, "{},"))
        {
            int num;
            
            sscanf(token, "%d", &num);
            v[i].push_back(num);
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    unordered_set<int> set;
    
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            if(set.find(v[i][j]) == set.end()) 
            {
                answer.push_back(v[i][j]);
                set.insert(v[i][j]);
            }
            else continue;
        }
    }
    return answer;
}