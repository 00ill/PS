#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    char **rep = (char **)calloc(report.size(), sizeof(char*));
    for(int i = 0; i < report.size(); i++)
    {
        rep[i] = (char*)calloc(22, 1);
        strcpy(rep[i], report[i].c_str());
    }
    unordered_map<string, unordered_map<string, int>> record;
    int len = report.size();
    for(int i = 0; i < len; i++)
    {
        char*token = strtok(rep[i], " ");
        char*token2 = strtok(NULL, " ");
        record[token2][token]++;
    }
    for(int i = 0; i < id_list.size(); i++)
    {
        int sum = 0;
        for(int j = 0; j < id_list.size(); j++)
        {
            if(i == j) continue;
            if(record[id_list[i]].find(id_list[j]) != record[id_list[i]].end())
            {
                sum++;
            }
        }
        if(sum >= k)
        {
            for(int q = 0; q < id_list.size(); q++)
            {
                if(q != i)
                {
                    if(record[id_list[i]].find(id_list[q]) != record[id_list[i]].end())
                    answer[q]++;
                }
            }
        }
    }
    return answer;
}