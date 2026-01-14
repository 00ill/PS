#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    char **s = (char**)calloc(phone_book.size(), sizeof(char*));
    for(int i = 0; i < phone_book.size(); i++)
    {
        s[i] = (char*)calloc(phone_book[i].size() + 1, 1);
        strcpy(s[i], phone_book[i].c_str());
    }
    for(int i = 0; i < phone_book.size() - 1; i++)
    {
        if(strncmp(s[i], s[i + 1], phone_book[i].size()) == 0) return false;
    }
    return answer;
}