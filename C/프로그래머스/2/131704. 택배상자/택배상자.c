#include <stdio.h>
#include <stdlib.h>

int solution(int order[], int order_len)
{
    int* stack = (int*)malloc(sizeof(int) * order_len);
    int top = -1;
    int current = 1;
    int i = 0;
    int answer = 0;

    while (1)
    {
        if (i >= order_len)
        {
            break;
        }

        if (current == order[i])
        {
            answer++;
            current++;
            i++;
        }
        else if (top >= 0 && stack[top] == order[i])
        {
            top--;
            answer++;
            i++;
        }
        else if (current <= order_len)
        {
            stack[++top] = current;
            current++;
        }
        else
        {
            break;
        }
    }

    free(stack);
    return answer;
}