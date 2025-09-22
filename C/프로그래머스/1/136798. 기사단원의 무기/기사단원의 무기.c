#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int solution(int number, int limit, int power) {
    int answer = 0;
    int count = 0;
    for(int i = 1; i <= number; i++)
    {
        for(int j = 1; j * j<= i; j++)
        {
            if(i%j == 0)
            {
                if(j * j == i)
                {
                    count++;    
                }
                else
                {
                    count += 2;
                }
                
                if(count > limit)
                {
                    count = power;
                    break;
                }
            }
        }
        answer += count;
        count = 0;
    }
    return answer;
}