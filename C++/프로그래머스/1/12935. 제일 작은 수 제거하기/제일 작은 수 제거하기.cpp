#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size() == 1) return vector<int>(1, -1);
    int min = arr[0], index = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(min > arr[i]) {index = i; min = arr[i];}
    }
    arr.erase(arr.begin() + index);
    return arr;
}