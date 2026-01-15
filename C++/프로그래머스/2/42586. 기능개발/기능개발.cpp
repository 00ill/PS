#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> remain(progresses.size(), 0);
    int index = 0, check_index = 0;
    for(int i = 0; i < progresses.size(); i++)
    {
        remain[i] = ((100 - progresses[i]) / speeds[i]) + ((100 - progresses[i]) % speeds[i] > 0);
        if(i > 0)
        {
            if(remain[i] <= remain[check_index])
            {
                answer[index]++;
            }
            else
            {
                index++;
                answer.push_back(1);
                check_index = i;
            }
        }
        else
        {
            answer.push_back(1);
        }
    }
    return answer;
}