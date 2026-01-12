#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int cnt = 1;
    for(int i = yellow; ; i = (yellow / cnt))
    {
        if(((cnt * 2) + (i + 2) * 2) == brown)
        {
            answer.push_back(i + 2);
            answer.push_back(cnt + 2);
            break;
        }
        
        cnt++;
        while(yellow % cnt != 0)
        {
            cnt++;
        }
    }
    return answer;
}