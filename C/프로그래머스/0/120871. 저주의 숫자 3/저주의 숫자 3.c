#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int solution(int n) {
    int answer = n;
    for(int i = 1; i <=n; i++)
    {
        if(i % 3 == 0)
        {
            answer++;
            n++;
        }
        else
        {
            int temp = i;
            while(temp != 0)
            {
                if(temp % 10 == 3)
                {
                    answer++;
                    n++;
                    break;
                }
                temp /=10;
            }
        }
    }
    return answer;
}