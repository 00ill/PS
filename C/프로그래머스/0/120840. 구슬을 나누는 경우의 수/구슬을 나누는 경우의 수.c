
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int balls, int share)
{
    int r = share;
    if (r > balls - r)
    {
        r = balls - r;
    }
    
    unsigned long long res = 1ULL;
    for (int i = 1; i <= r; i++)
    {
        unsigned long long num = (unsigned long long)(balls - r + i);
        unsigned long long den = (unsigned long long)i;
        {
            unsigned long long a = num;
            unsigned long long b = den;
            while (b != 0)
            {
                unsigned long long t = a % b;
                a = b;
                b = t;
            }
            unsigned long long g = a;
            num /= g;
            den /= g;
        }
        if (den > 1ULL)
        {
            unsigned long long a = res;
            unsigned long long b = den;
            while (b != 0)
            {
                unsigned long long t = a % b;
                a = b;
                b = t;
            }
            unsigned long long g2 = a; // gcd
            if (g2 > 1ULL)
            {
                res /= g2;
                den /= g2;
            }
        }
        res *= num;
    }

    return (int)res;
}
