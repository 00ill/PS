#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int bin = 0, temp = n;
    while(temp > 0)
    {
        bin += temp % 2;
        temp /= 2;
    }
    int a = n + 1;
    
    while(1)
    {
        int a_temp = a;    
        int a_cnt = 0;
        while(a_temp > 0)
        {
            a_cnt += a_temp % 2;
            a_temp /= 2;
        }
        if(a_cnt == bin) return a;
        a++;
    }
    return answer;
}