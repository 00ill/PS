#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
int compare(const void* a, const void* b)
{
    return *(const int*)a - *(const int*)b;
}

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    int *array = (int*)calloc(arr.size(), sizeof(int));
    int index = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] % divisor == 0)
        {
            array[index++] = arr[i];
        }
    }
    if(index == 0) {answer.push_back(-1); return answer;}
    qsort(array, index, sizeof(int), compare);
    for(int i = 0; i < index; i++)
    {
        answer.push_back(array[i]);
    }
    return answer;
}