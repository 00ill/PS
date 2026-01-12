#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
char *dectobin(unsigned long long n)
{
    char *buffer =(char*)calloc(4096, 1);
    int index = 0;
    while(n != 0)    
    {
        buffer[index++] = n % 2 + '0';
        n /= 2;
    }
    char *buffer_rev =(char*)calloc(4096, 1);
    for(int i = 0; i < index; i++)
    {
        buffer_rev[i] = buffer[index - i - 1];
    }
    return buffer_rev;
}

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    int len = s.length();
    char *buffer = (char*)calloc(len + 1, 1);
    strcpy(buffer, s.c_str());
    int count_one = 0;
    while(strcmp(buffer, "1") != 0)
    {
        int buffer_len = strlen(buffer);
        for(int i = 0; i < buffer_len; i++)
        {
            if(buffer[i] == '0') count_one++;
        }
        answer[1] += count_one;
        answer[0]++;
        strcpy(buffer, dectobin(buffer_len - count_one));
        count_one = 0;
    }
    return answer;
}