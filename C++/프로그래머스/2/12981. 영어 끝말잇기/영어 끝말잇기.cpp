#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_set<string> used;
    int len = words.size();
    for(int i = 0; i < len; i++)
    {
        if(used.find(words[i]) == used.end())
        {   
            if(i > 0 && words[i - 1].back() != words[i][0])
            {
                answer[0] = static_cast<int>(i % n) + 1;
                answer[1] = static_cast<int>(i / n) + 1;
                return answer;
            }
            used.insert(words[i]);
        }
        else
        {
            answer[0] = static_cast<int>(i % n) + 1;
            answer[1] = static_cast<int>(i / n) + 1;
            return answer;
        }
    }
    return answer;
}