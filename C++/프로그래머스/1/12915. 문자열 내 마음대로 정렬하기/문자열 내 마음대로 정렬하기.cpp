#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index;
int cmp(const string& str1, const string& str2)
{
    if(str1[index] == str2[index]) return str1 < str2;
    return str1[index] < str2[index];
}

vector<string> solution(vector<string> strings, int n) {
    index = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}