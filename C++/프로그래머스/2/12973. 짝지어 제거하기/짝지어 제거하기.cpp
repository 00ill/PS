#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int len = s.length();
    int *arr = (int *)calloc(len, sizeof(4));
    int index = 0;
    for(int i = 0; i < len; i++)
    {
        if(index == 0)
        {
            arr[index++] = s[i];
        }
        else
        {
            if(arr[index - 1] == s[i])
            {
                index--;
            }
            else
            {
                arr[index++] = s[i];
            }
        }
    }
    return index == 0;
}