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
    int pos_start[10] = {0,};   // 예약 가능한 시작 시간
    int pos_end[10] = {0,};   // 예약 가능한 종료 시간
    int avail_time = 0;       // 예약 가능한 시간대 갯수
};

struct booked{
    char name[11] = {0,};   // 예약한 미팅룸 이름 저장
    int start = 0;     // 회의 시작시간
    int end = 0;        // 회의 종료시간
};

int main(int argc, char** argv)
{
    int N = 0;   // 회의실의 갯수(최대 50)
    int M = 0;   // 예약된 회의의 수(최대 100)
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

  
    
    int num = 2;          // 0, 1을 조건에 맞게 스위칭하기 위해 사용되는 변수
    int switchnum = 0;    // num % 2 값을 저장하기 위한 변수
    // 예약 가능한 시간 계산
    for(int i=0; i<N; i++){

         int pos_time = 0;     // available 횟수를 출력하기 위한 flag 변수
        
         for(int k=0; k<10; k++){
            switchnum = num % 2;   // 나머지 연산으로 0, 1 계속 바꾸게끔
            int sum=0;          
            for(int a=0; a<10; a++)     // 타임테이블의 모든 값을 다 더함 (풀예약 혹은 프리 상태인지 확인하기 위함)
                sum += room[i].time[a];
            
             // 만일 회의실 예약이 꽉 차면 해당 문구 출력하고 다음 회의실 분석으로
            if(sum == 10){
                break;
            }

            // 회의실 예약이 하나도 없을 때 출력
            else if(sum == 0){
                room[i].pos_start[pos_time] = 9;
                room[i].pos_end[pos_time++] = 18;
                break;
            }

            // 마지막 시간대만 비어있는 경우
            else if(k == 9 && room[i].time[9]==0 && sum == 9){
                room[i].pos_start[pos_time] = 17;
                room[i].pos_end[pos_time++] = 18;
                break;
            }
                
                
            /// 나머지 경우 (대부분의 경우) ///
            else if(room[i].time[k] == switchnum){
                if(k == 0) room[i].pos_start[pos_time] = 9;
                else {
                    if(switchnum == 0) room[i].pos_start[pos_time] = k+9-1;
                    else if(switchnum == 1) room[i].pos_end[pos_time++] = k+9;  
                }
                num++;
            }


                
            else if(k==9 && room[i].time[9]==0) room[i].pos_end[pos_time++] = 18; 
            
            else continue;
        }

        room[i].avail_time = pos_time;
    }


    //// 최종 출력 ////

    /// 오름차순으로 출력하기 위해 index를 sorting ///
    /*
        - 각 이름의 첫 글자만 따 와서 입력했던 순서대로 별도 저장. 
        - 이름 앞 글자들만 저장한 배열을 오름차순으로 정리
        - 해당 오름차순 배열과 meeting struct의 name[0]을 대조하면서 순서대로 출력
        
    */
    for(int i=0; i<N; i++)
        index[i][0] = room[i].name[0];

    char temp;
    for(int i=0; i<N-1; i++)
        for(int j=1; j<N; j++){
            if(index[i][0] > index[j][0]){
                temp = index[j][0];
                index[j][0] = index[i][0];
                index[i][0] = temp;
            }
            else continue;
        }

    int dash = 0;         // 구분선을 N-1번만 출력하게끔 설정하는 flag변수
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(index[i][0] == room[j].name[0]){    // 오름차순으로 출력 시작
                // 방 이름 출력
                cout << "Room " << room[j].name << ":" << endl;  

                // available 횟수 및 예약 가능 시간대 출력
                if(room[j].avail_time == 0) cout << "Not available" << endl; 
                else {
                    cout << room[j].avail_time << " available:" << endl;
                    for(int a=0; a<room[j].avail_time; a++){
                        // 9가 출력이 되면 09로 출력하는 예외처리
                        if(a == 0 && room[j].pos_start[a] == 9) cout << "09";
                        else cout << room[j].pos_start[a];

                        // 시간 사이의 dash 및 끝 시간대 출력
                        cout << "-";
                        cout << room[j].pos_end[a] << endl;

                    }
                }

            }
                
            else continue;

            if(dash++ < N-1) cout << "-----" << endl;   // 마지막은 구분선 출력하지 않도록 설정
        }
    }
    

    return 0;
}


