#include<iostream>
#include <stdio.h>

using namespace std;

int change_min(char *time);

int main(int argc, char** argv)
{
    char workstart[5][6] = {0,};   // 월~금 출퇴근 시간을 입력받는 변수 초기화
    char workend[5][6] = {0,};
    volatile int worktime = 0;
    volatile int worktime_buf = 0;

    for(int i=0; i < 5; i++){   // 5번 반복
        scanf("%s", workstart[i]);
        scanf("%s", workend[i]);
    }    

    for(int j; j < 5; j++){
        worktime_buf = change_min(workend[j]) - change_min(workstart[j]);
        worktime = worktime + worktime_buf;
    }

    printf("%d", worktime); 
    
    return 0;
}



int change_min(char *time){
    int hours, minutes = 0;

    hours = ((time[0]-48)*10) + (time[1]-48);
    minutes = ((time[3]-48)*10) + (time[4]-48);

    return (minutes + (hours * 60));
}
