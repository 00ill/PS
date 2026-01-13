#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int cmp(const void* a, const void* b)
{
    return *(const int*)a - *(const int*)b;
}

int solution(vector<int> people, int limit) {
    int answer = 0, len = people.size();
    int *arr = (int*)calloc(len, sizeof(int));
    for(int i = 0; i < len; i++)    
    {
        arr[i] = people[i];
    }
    qsort(arr, len, sizeof(int), cmp);
    int heavy = len - 1, light = 0;
    while(light <= heavy)
    {
        if(arr[light] + arr[heavy] <= limit)
        {
            light++;
            heavy--;
        }
        else
        {
            heavy--;
        }
        answer++;
    }
    return answer;
}