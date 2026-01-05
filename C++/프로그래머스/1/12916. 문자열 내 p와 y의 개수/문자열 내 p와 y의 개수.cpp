#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    size_t cnt = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'p' || s[i] == 'P') cnt++;
        if(s[i] == 'y' || s[i] == 'Y') cnt--;
    }
    if(cnt) return false;
    return true;
}