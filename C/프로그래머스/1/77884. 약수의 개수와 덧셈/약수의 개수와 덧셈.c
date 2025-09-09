#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left, int right) {
    int answer = 0;
    int count = 0;
    int den = 1;
    while(left <= right)        
    {
        while(den <= left)
        {
            if((left % den++) == 0 )
            {
                count++;
            }
        }
        if(count & 1)
        {
            answer -= left;
        }
        else
        {
            answer += left;
                        
        }
        count = 0;
        den = 1;
        left++;
    }
    return answer;
}