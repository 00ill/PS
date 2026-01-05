#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
int cmp(const void *a, const void *b)
{
    return *(const int*)a - *(const int*)b;
}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int arr[100], index = 0;
    for(int i = 0; i < commands.size(); i++)
    {
        for(int j = commands[i][0] - 1; j <= commands[i][1] - 1; j++)
        {
            arr[index++] = array[j];
        }
        qsort(arr, index, sizeof(int), cmp);
        answer.push_back(arr[commands[i][2] - 1]);
        index = 0;
    }
    return answer;
}