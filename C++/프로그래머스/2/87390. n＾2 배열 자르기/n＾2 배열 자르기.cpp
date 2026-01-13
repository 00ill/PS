#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
     answer.reserve(static_cast<size_t>(right - left + 1));
    long long row = left / n;
    long long col = left - row * n;
    for(long long i = left; i <= right; i++)
    {
        answer.push_back(static_cast<int>(max(row + 1, col + 1)));
        col++;
        if(col == n)
        {
            col = 0;
            row++;
        }
    }
    return answer;
}