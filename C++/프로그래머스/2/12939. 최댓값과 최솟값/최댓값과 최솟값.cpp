#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

string solution(string s) {
    string answer = "";
    char *buffer = (char*)calloc(s.length() + 1, 1);
    strcpy(buffer, s.c_str());
    int min = INT_MAX;
    int max = INT_MIN;
    for(char *token = strtok(buffer, " "); token != NULL; token = strtok(NULL, " "))
    {
        int temp;
        sscanf(token, "%d", &temp);
        if(temp < min) min = temp;
        if(temp > max) max = temp;
    }
    answer += to_string(min) + " " + to_string(max);
    return answer;
}