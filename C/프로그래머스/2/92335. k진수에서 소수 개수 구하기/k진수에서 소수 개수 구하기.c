#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *k_num(int n, int k)
{
    char buffer[4096] = {0};
    int index = 0;
    while(n / k != 0)
    {
        buffer[index++] = (n % k) + '0';
        n /= k;
    }
    buffer[index++] = n + '0';
    char *buffer_rev = calloc(4096, 1);
    int len = index;
    for(int i = 0; i < len; i++)
    {
        buffer_rev[i] = buffer[len - 1 - i];
    }
    buffer_rev[len] = '\0';
    return buffer_rev;
}
long long ctoa(char *num)
{
    long long ret = 0;
    int len = strlen(num);
    for(int i = 0; i < len; i++)
    {
        ret += (num[i] - '0');
        if(i != len - 1) ret *= 10;
    }
    return ret;
}
bool is_prime(long long n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(long long i = 3; i * i <= n; i += 2)
    {
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    char *buffer = calloc(4096, 1);
    buffer = k_num(n, k);
    for(char *token = strtok(buffer, "0"); token != NULL; token = strtok(NULL, "0"))
    {
        if(is_prime(ctoa(token))) answer++;
    }
    return answer;
}