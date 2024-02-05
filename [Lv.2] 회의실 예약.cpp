/*
    - 입력은 무작위로, 출력은 회의실 이름을 오름차순으로 해야 한다.
    - 일단 구조체 등을 사용하지 않고 구현해보자
    - 예약 현황은 따로 입력 받은 후, 하나씩 대조하여 해당하는 회의실 사용시간에서 소거하는 식으로 구현
    - 각 회의실은 9-18까지의 시간이 있으므로, 배열 상으로 0-9까지의 10개의 원소가 있다고 해 보자.
    - 예약시간이 10-14이면, 1-5번 index에 1로 채워넣는다.
    - 마지막에 0으로 채워져있는 원소들을 계산하여 적절히 시간대 값으로 환산 후 출력

*/


#include<iostream>
#include<stdio.h>

using namespace std;

struct meeting{
    char name[11] = {0,};   // 미팅룸 이름 저장 변수
    int time[10] = {0,};    // 예약 시간 여부 저장
};

struct booked{
    char name[11] = {0,};   // 예약한 미팅룸 이름 저장
    int start = 0;     // 회의 시작시간
    int end = 0;        // 회의 종료시간
};

int main(int argc, char** argv)
{
    int N = 0;   // 회의실의 갯수
    int M = 0;   // 예약된 회의의 수
    char index[50][1];   // 오름차순으로 출력하기 위한 인덱스 관련 배열변수

    meeting room[50] = {0,};    // 회의실 정보를 저장할 구조체 변수 선언
    booked info[100] = {0,};    // 회의실 예약 정보를 저장할 구조체 변수 선언
    

    // N, M값을 입력받음
    cin >> N >> M;

    // 각 회의실의 이름 입력
    for(int i=0; i<N; i++)
        cin >> room[i].name;

    // 각 회의실의 예약 정보 입력
    for(int j=0; j<M; j++){
        cin >> info[j].name >> info[j].start >> info[j].end;
    }


    
    
    //// 알고리즘 시작 ////
    for(int j=0; j<M; j++){

        // 1. 예약 시간 동기화
        for(int i=0; i<N; i++){
            int name1= 0;
            for(int a=0; a<11; a++)
                if(room[i].name[a] == info[j].name[a])
                    name1++;           
   
            if(name1 == 11){
                for(int k=info[j].start-9; k<info[j].end-8; k++)
                    room[i].time[k] = 1;    // 시간 예약 반영
            }
            else continue;

            name1 = 0;
        }

    }


    int num = 2;
    int switchnum = 0;
    // 예약 가능한 시간 계산
    for(int i=0; i<N; i++){
        cout << "Room " << room[i].name << ":" << endl;   // 양식 출력
            
         for(int k=0; k<10; k++){
            switchnum = num % 2;   // 나머지 연산으로 0, 1 계속 바꾸게끔
            int sum=0;
            for(int a=0; a<10; a++)
                sum += room[i].time[a];
            if(sum == 10){
                cout << "Not available" << endl;  // 만일 회의실 예약이 꽉 차면 해당 문구 출력하고 다음 회의실 분석으로
                break;
            }
            else if(room[i].time[k] == switchnum){
                if(k == 0) cout << "09";
                else {
                    if(switchnum == 0) cout << k+9-1;
                    else if(switchnum == 1) cout << "-" << k+9 << endl;
                }
                num++;
            }
            else continue;
        }
    }
    

    return 0;
}

