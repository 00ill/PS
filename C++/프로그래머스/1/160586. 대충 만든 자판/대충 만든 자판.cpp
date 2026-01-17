#include <string>
#include <vector>
#
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size(), 0);
    int arr[26]; // 알파벳별로 필요한 횟수를 저장할 거임
    for(int i = 0; i < 26; i++)
    {
        arr[i] = 101;
    }
    for(int i = 0; i < keymap.size(); i++)
    {
        for(int j = 0; j < keymap[i].size(); j++)
        {
            //j는 누르는 횟수 - 1
            if(arr[keymap[i][j] - 'A'] > j + 1)
            {
                arr[keymap[i][j] - 'A'] = j + 1;
            }
        }
    }
    for(int i = 0; i < targets.size(); i++)
    {
        for(int j = 0; j < targets[i].size(); j++)
        {
            if(arr[targets[i][j] - 'A'] == 101) {answer[i] = -1; break;}
            answer[i] += arr[targets[i][j] - 'A'];
        }
    }
    
    return answer;
}