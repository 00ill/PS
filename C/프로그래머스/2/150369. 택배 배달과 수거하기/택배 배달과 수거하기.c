#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// deliveries_len은 배열 deliveries의 길이입니다.
// pickups_len은 배열 pickups의 길이입니다.
long long solution(int cap, int n, int deliveries[], size_t deliveries_len, int pickups[], size_t pickups_len) {
    long long answer = 0;
    int last_del_target = 1000001, last_pic_target = 1000001;
    int is_del = 0, is_pic = 0;
    
    for(int i = 0; i < n; i++)
    {
        is_del += deliveries[i];
        is_pic += pickups[i];
    }
    if(is_del + is_pic == 0) return 0;
    for(int i = 0; i < n; i++)
    {
        if(deliveries[i] > 0 && last_del_target == 1000001)
        {
            last_del_target = i;
        }
        if(pickups[i] > 0 && last_pic_target == 1000001)
        {
            last_pic_target = i;
        }
    }
    int del_index = n - 1, pic_index = n - 1, del_cap = 0, pic_cap = 0;
    if(is_pic == 0) {last_pic_target = 0; pic_index = 0;}
    if(is_del == 0) {last_del_target = 0; del_index = 0;}
    while(deliveries[last_del_target] != 0 || pickups[last_pic_target] != 0)
    {
        for(int i = del_index; i >= 0; i--)
        {
            if(deliveries[i] > 0)
            {
                del_index = i;
                break;
            }
            if(i == 0) del_index = 0;
        }
        for(int i = pic_index; i >= 0; i--)
        {
            if(pickups[i] > 0)
            {
                pic_index = i;
                break;
            }
            if(i == 0) pic_index = 0;
        }
        
        if(del_index > pic_index) {answer += 2 * (del_index + 1);}
        else {answer += 2 * (pic_index + 1);}
        
        while(del_cap < cap && is_del)
        {
            if(del_index < last_del_target) break;
            if(deliveries[del_index] > 0)
            {
                deliveries[del_index]--;
                del_cap++;
            }
            else
            {
                del_index--;
            }
        }
        while(pic_cap < cap && is_pic)
        {
            if(pic_index < last_pic_target) break;
            if(pickups[pic_index] > 0)
            {
                pickups[pic_index]--;
                pic_cap++;
            }
            else
            {
                pic_index--;
            }
        }
        del_cap = 0;
        pic_cap = 0;
    }
    return answer;
}