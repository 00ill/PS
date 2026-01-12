#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

string solution(string s) {
    int len = s.length();
    char *buffer = (char *)calloc(len + 1, 1);
    strcpy(buffer, s.c_str());
    if('a' <= buffer[0] && buffer[0] <= 'z')
    {
        buffer[0] = toupper(buffer[0]);
    }
    for(int i = 1; i < len; i++)
    {
        
        if(buffer[i - 1] == ' ')
        {
            if('a' <= buffer[i] && buffer[i] <= 'z')
            {
                buffer[i] = toupper(buffer[i]);
            }
        }
        else
        {
            if('A' <= buffer[i] && buffer[i] <= 'Z')
            {
                buffer[i] = tolower(buffer[i]);
            }
        }
    }
  
    return buffer;
}