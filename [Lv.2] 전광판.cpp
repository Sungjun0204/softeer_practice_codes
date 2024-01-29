#include <iostream>
#include <stdio.h>

using namespace std;

int segments[10][7] = {  {1,1,1,1,1,1,0},  // 0
                         {0,1,1,0,0,0,0},  // 1
                         {1,1,0,1,1,0,1},  // 2
                         {1,1,1,1,0,0,1},  // 3
                         {0,1,1,0,0,1,1},  // 4
                         {1,0,1,1,0,1,1},  // 5
                         {1,0,1,1,1,1,1},  // 6
                         {1,1,1,0,0,1,0},  // 7
                         {1,1,1,1,1,1,1},  // 8
                         {1,1,1,1,0,1,1}}; // 9

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
    int switch_count = 0;
                           
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

    for(int j=0; j<5; j++){
        for(int k=0; k<7; k++){
            if (segments[num_A_char[j]][k] != segments[num_B_char[j]][k]){
                 switch_count++;
            }
        }
    }

    return switch_count;
}

// 자릿수 없는 경우에서 다음 숫자로 켜는 경우는 예외처리 또 해야 함.





