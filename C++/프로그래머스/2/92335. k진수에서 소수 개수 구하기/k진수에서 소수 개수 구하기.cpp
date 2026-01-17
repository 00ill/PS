#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

string base(int n, int k)
{
    if(n == 0) return "0";
    string a = "0123456789";
    string ret;
    while(n > 0)
    {
        ret.push_back(a[n % k]);
        n /= k;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

bool is_prime(long long n)
{
    if(n == 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(long long  i = 3; i * i <= n; i += 2)
    {
        if(n % i == 0)  return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string kb = base(n,k);
    char *s = (char*)calloc(kb.size() + 1, 1);
    strcpy(s, kb.c_str());
    for(char* token = strtok(s,"0"); token != NULL; token = strtok(NULL, "0"))
    {
        long long  num;
        sscanf(token, "%ld", &num);
        if(is_prime(num)) answer++;
    }
    return answer;
}