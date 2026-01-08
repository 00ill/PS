#include <stdio.h>

int main(void)
{
    int input;
    scanf("%d", &input);
    int output;
    if(input / 5 == 0) output = 1;
    else if(input % 5 != 0) output = input / 5 + 1;
    else output = input / 5;
    printf("%d", output);
    return 0;
}