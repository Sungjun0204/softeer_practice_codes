#include <iostream>
#include <stdio.h>

using namespace std;

int segments[11][7] = {  {1,1,1,1,1,1,0},  // 0
                         {0,1,1,0,0,0,0},  // 1
                         {1,1,0,1,1,0,1},  // 2
                         {1,1,1,1,0,0,1},  // 3
                         {0,1,1,0,0,1,1},  // 4
                         {1,0,1,1,0,1,1},  // 5
                         {1,0,1,1,1,1,1},  // 6
                         {1,1,1,0,0,1,0},  // 7
                         {1,1,1,1,1,1,1},  // 8
                         {1,1,1,1,0,1,1},  // 9
                         {0,0,0,0,0,0,0}}; // null

int int2char(int num1, int num2);   // 정수형을 5자리 문자형으로 변경해주는 함수

    



int main()
{
    int testcase = 0;
    int A, B = 0;

    cin >> testcase;    // 프로그램 반복 횟수 입력받음

    // 테스트케이스만큼 프로그램 반복
    for(int i=0; i < testcase; i++){
        cin >> A >> B;          // A와 B 숫자 입력받음
        cout << int2char(A, B) << endl;
    }

   return 0;
}



int int2char(int num1, int num2){
    int num_A_char[5] = {0,};
    int num_B_char[5] = {0,};
    int switch_count = 0;           // A->B 할 때 얼마나 스위치를 여닫아야 하는지
    int len_num_A, len_num_B = 0;   // 두 수의 자릿수 값을 저장하는 변수 선언
    int null_len_A, null_len_B = 0;  // 어디까지 자릿수가 없는지 
    

    // 자릿수 계산
    int numA = num1; int numB = num2;
    for(int s=0; s<5; s++){
        if((numA /= 10) > 0) len_num_A++;
        else break;
    }
    len_num_A++;

    for(int s=0; s<5; s++){
        if((numB /= 10) > 0) len_num_B++;
        else break;
    }
    len_num_B++;
    
    null_len_A = 5 - len_num_A;
    null_len_B = 5 - len_num_B;
    
    // 입력받은 두 숫자 해체작업 시작
    num_A_char[0] = (num1 / 10000);
    num_A_char[1] = ((num1 / 1000) % 10);
    num_A_char[2] = ((num1 / 100) % 10);
    num_A_char[3] = ((num1 / 10) % 10);
    num_A_char[4] = ((num1 / 1) % 10);

    num_B_char[0] = (num2 / 10000);
    num_B_char[1] = ((num2 / 1000) % 10);
    num_B_char[2] = ((num2 / 100) % 10);
    num_B_char[3] = ((num2 / 10) % 10);
    num_B_char[4] = ((num2 / 1) % 10);

    // 그런데 자릿수 없는 곳은 0이 아닌 다 꺼져야 하기에 숫자 0 대신 10을 대입
    for(int t=0; t < null_len_A; t++)
        num_A_char[t] = 10;
        
     for(int t=0; t < null_len_B; t++)
        num_B_char[t] = 10;   

    
    // 총 스위치 몇번 켜고 꺼야 하는지 계산
    for(int j=0; j<5; j++){
        for(int k=0; k<7; k++){
            if (segments[num_A_char[j]][k] != segments[num_B_char[j]][k]){
                 switch_count++;
            }
        }
    }
    
    return switch_count;
}

