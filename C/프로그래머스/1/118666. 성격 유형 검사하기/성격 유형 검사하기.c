#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void add_point(int *arr, char c, int point)
{
    if(c == 'R') {arr[0] -= point; return;}
    if(c == 'T') {arr[0] += point; return;}
    if(c == 'C') {arr[1] -= point; return;}
    if(c == 'F') {arr[1] += point; return;}
    if(c == 'J') {arr[2] -= point; return;}
    if(c == 'M') {arr[2] += point; return;}
    if(c == 'A') {arr[3] -= point; return;}
    if(c == 'N') {arr[3] += point; return;}
}

char* solution(const char* survey[], size_t survey_len, int choices[], size_t choices_len) {
    char* answer = (char*)malloc(5);
    strcpy(answer, "RCJA");
    int point[4] = {0};
    for(int i = 0; i < survey_len; i++)
    {
        if(choices[i] - 4 < 0) add_point(point,survey[i][0], abs(choices[i] - 4));
        if(choices[i] - 4 > 0) add_point(point,survey[i][1], abs(choices[i] - 4));
    }
    if(point[0] > 0) answer[0] = 'T';
    if(point[1] > 0) answer[1] = 'F';
    if(point[2] > 0) answer[2] = 'M';
    if(point[3] > 0) answer[3] = 'N';
    return answer;
}
