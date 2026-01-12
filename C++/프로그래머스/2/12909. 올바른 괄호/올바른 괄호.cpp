#include<string>
#include <iostream>
#include <string.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    char *buffer = (char *)calloc(s.length() + 1, 1);
    strcpy(buffer, s.c_str());
    int count = 0;
    while(*buffer)
    {
        if(*buffer == '(')
        {
            count++;
        }
        else if(*buffer == ')')
        {
            count--;
            if(count < 0) return false;
        }
        buffer++;
    }
    if(count == 0) return true;
    return false;
}