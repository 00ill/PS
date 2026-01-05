#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    size_t len = s.length();
    for(size_t i = 0; i < len; i++)
    {
        if('a' <= s[i] && s[i] <= 'z')
        {
            answer.push_back(s[i] + n > 'z' ? s[i] + n - ('z' - 'a' + 1) : s[i] + n);
        }
        else if('A' <= s[i] && s[i] <= 'Z')
        {
            answer.push_back(s[i] + n > 'Z' ? s[i] + n - ('Z' - 'A' + 1) : s[i] + n);
        }
        else answer.push_back(s[i]);
    }
    return answer;
}