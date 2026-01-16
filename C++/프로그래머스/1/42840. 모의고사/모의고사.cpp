#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int arr1[] = {1,2,3,4,5};//5
    int arr2[] = {2,1,2,3,2,4,2,5};//8
    int arr3[] = {3,3,1,1,2,2,4,4,5,5};//10
    int correct[3] = {0};
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == arr1[i % 5]) correct[0]++;
        if(answers[i] == arr2[i % 8]) correct[1]++;
        if(answers[i] == arr3[i % 10]) correct[2]++;
    }
    int a = max(correct[0], max(correct[1], correct[2]));
    if(correct[0] == a) answer.push_back(1);
    if(correct[1] == a) answer.push_back(2);
    if(correct[2] == a) answer.push_back(3);
    return answer;
}