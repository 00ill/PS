
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// HHMM 정수를 "분"으로 변환하는 헬퍼 함수
static int hhmm_to_minutes(int hhmm)
{
    int hh = hhmm / 100;
    int mm = hhmm % 100;
    return hh * 60 + mm;
}

// schedules_len은 배열 schedules의 길이입니다.
// timelogs_rows는 2차원 배열 timelogs의 행 길이, timelogs_cols는 2차원 배열 timelogs의 열 길이입니다.
// startday: 1=월, 2=화, ..., 7=일 이라고 가정합니다.
int solution(int schedules[], size_t schedules_len,
             int** timelogs, size_t timelogs_rows, size_t timelogs_cols,
             int startday)
{
    int answer = 0;

    for (size_t i = 0; i < schedules_len; i++)
    {
        int scheduled_min = hhmm_to_minutes(schedules[i]);
        bool ok = true;
        for (size_t j = 0; j < timelogs_cols; j++)
        {
            int weekday = (int)((startday - 1 + j) % 7);
            if (weekday == 5 || weekday == 6)
            {
                continue;
            }
            int log_min = hhmm_to_minutes(timelogs[i][j]);
            if (log_min > scheduled_min + 10)
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            answer++;
        }
    }
    return answer;
}
