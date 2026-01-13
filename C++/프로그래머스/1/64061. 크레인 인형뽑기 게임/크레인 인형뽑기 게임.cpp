#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, len = moves.size();
    int box_size = board.size();
    stack<int> s;
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < box_size; j++)
        {
            if(board[j][moves[i] - 1] != 0)
            {
                if(s.empty())
                {
                    s.push(board[j][moves[i] - 1]);    
                }
                else
                {
                    if(s.top() == board[j][moves[i] - 1])
                    {
                        s.pop();
                        answer += 2;
                    }
                    else {s.push(board[j][moves[i] - 1]);}
                }
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    return answer;
}