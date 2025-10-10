#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int** solution(int n) {
    long max = n * n;
    int** answer = (int**)malloc(n * sizeof(int*));
    int** mark = (int**)malloc(n * sizeof(int*));
    
    for(int i = 0 ; i < n; i++)
    {
        answer[i] = (int*)malloc(n * sizeof(int));
        mark[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0 ; j < n; j++)
        {
            mark[i][j] = 0;
        }
    }
    
    unsigned char dir = 1; 
    int x = 0, y = 0;
    for(int i = 0 ; i < max; i++)
    {
        answer[x][y] = i + 1;
        mark[x][y] = 1;
        if(dir == 1 && (y == n - 1 || mark[x][y + 1] == 1)) dir = 2;
        if(dir == 2 &&(x == n - 1 || mark[x + 1][y] == 1)) dir = 3;
        if(dir == 3 &&(y == 0 || mark[x][y - 1] == 1)) dir = 4;
        if(dir == 4 &&(x == 0 || mark[x - 1][y] == 1)) dir = 1;
        
        if(dir == 1) y++;
        else if(dir == 2) x++;
        else if(dir == 3) y--;
        else if(dir == 4) x--;
    }
    
    return answer;
}