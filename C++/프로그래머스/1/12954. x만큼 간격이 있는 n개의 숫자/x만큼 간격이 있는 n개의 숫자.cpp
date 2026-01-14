#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n, 0);
    for(long long i = 0; i < n; i++)
    {
        answer[i] = x * (1 + i);
    }
    
    return answer;
}