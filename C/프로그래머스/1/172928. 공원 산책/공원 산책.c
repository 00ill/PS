#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// park_len은 배열 park의 길이입니다.
// routes_len은 배열 routes의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    int pos_x, pos_y;
    int park_x = strlen(park[0]), park_y = park_len;
    printf("공원의 크기 %d %d\n", park_x, park_y);
    for(int i = 0; i < park_y; i++)
    {
        for(int j = 0; j < park_x; j++)
        {
            if(park[i][j] == 'S') {pos_x = j; pos_y = i;}
        }
    }
    printf("시작지점 %d %d\n", pos_x, pos_y);
    for(int i = 0; i < routes_len; i++)
    {
        char op;
        int move;
        sscanf(routes[i], "%c %d", &op, &move);
        printf("명령 %c방향으로 %d만큼 이동\n", op, move);
        int temp_pos_x = pos_x, temp_pos_y = pos_y;
        bool is_valid_command = false;
        for(int j = 0; j < move; j++)
        {
            if(op == 'E') temp_pos_x++;
            if(op == 'W') temp_pos_x--;
            if(op == 'N') temp_pos_y--;
            if(op == 'S') temp_pos_y++;
            if(temp_pos_x >= park_x || temp_pos_y >= park_y || 
              (temp_pos_x < 0 || temp_pos_y < 0))
            {
                printf("공원을 벗어남\n"); 
                break; 
            }
            if(park[temp_pos_y][temp_pos_x] == 'X') {printf("%d %d에 장애물 존재\n",temp_pos_x, temp_pos_y); break; }
            if(j == move - 1) is_valid_command = true;
        }
        if(is_valid_command)
        {
            printf("%d %d에서 %d %d로 이동\n", pos_x, pos_y, temp_pos_x, temp_pos_y);
            pos_x = temp_pos_x;
            pos_y = temp_pos_y;
        }
    }
    answer[0] = pos_y;
    answer[1] = pos_x;
    return answer;
}