#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    int h = citations.back(), count = 0;
    while(1)
    {
        for(int i = citations.size() - 1; i >= 0; i--)
        {
            if(citations[i] >= h) {count++;}
            else break;
        }
        if(count >= h) return h;
        count = 0;
        h--;
    }
    return answer;
}