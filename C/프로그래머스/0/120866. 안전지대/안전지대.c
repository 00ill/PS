#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// board_rows는 2차원 배열 board의 행 길이, board_cols는 2차원 배열 board의 열 길이입니다.
int solution(int** board, size_t board_rows, size_t board_cols) {
    int answer = 0;
    for(int i = 0; i < board_rows; i++)
    {
        for(int j = 0; j < board_cols; j++)
        {
            if(board[i][j] == 1)
            {
                for(int k = i - 1; k <= i + 1; k++)
                {
                    for(int l = j - 1; l <= j + 1; l++)
                    {
                        if(0 <= k && k < board_rows && 0<= l && l < board_cols)
                        {
                            if(board[k][l] != 1)
                            {
                                board[k][l] = 2;    
                            }
                        }
                    }
                }
            }
        }
    }
       for(int i = 0; i < board_rows; i++)
    {
        for(int j = 0; j < board_cols; j++)
        {
             if(board[i][j] == 0)
             {
                 answer++;
             }
        }
    }
    return answer;
}