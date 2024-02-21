/*
    - S문자열에서 X 위치를 찾아야 하고, 또한 S와 T 사이의 공백 위치를 찾아야 함
    - S와 T의 길이는 동일하므로, 한 문자열 쌍에서 출력할 문자의 위치는 다음과 같이 계산됨
       - [공백 위치] + [S 문자열에서의 X 위치] + 1
*/

#include <iostream>
#include <stdio.h>

using namespace std;


int main(int argc, char** argv)
{
    int N = 0;                                // 문자열 쌍의 개수 정보를 저장하는 변수 선언
    int search_flag = 0;                      // 순서대로 X 위치와 공백 위치를 찾게 설정해주는 플래그 변수 선언
    // char sentence[50][100];
    int space = 0;                            // 두 문자열 사이의 공백 위치 값을 저장하는 변수 선언
    int x_pos = 0;                            // S 문자열에 있는 X(x)의 위치 값을 저장하는 변수 선언


    // 입력할 문자열 쌍의 갯수를 입력
    cin >> N;

    char** sentence = new char*[N];      // 문자열 S, T를 저장하는 배열 변수 선언

    // 문자열 저장에 대한 메모리 동적 할당 설정
    for(int i=0; i<N; i++)
        sentence[i] = new char[1001];


    // N번 동안 문자열 쌍을 입력받음
    for(int i=0; i<N; i++){
        scanf("%[^\n]", sentence[i]);
    }

    //// 알고리즘 시작 ////
    for(int i=0; i<N; i++){ 
        int k=0;   // X(x)를 찾기 위한 index변수 초기화
        while(search_flag == 0){                                     // search_flag가 0이면: X(x)의 위치를 찾을 때까지 탐색
            if(sentence[i][k] == 'X' || sentence[i][k] == 'x'){      // 만약 해당 위치가 X 또는 x라면
                x_pos = k++;                                         // 현재 위치를 x_pos 변수에 따로 저장
                search_flag = 1;                                     // 플래그 변수를 1로 설정 (=X(x)탐색 반복문 종료)
            }
            else k++;                                                // X(x)가 아니면 다음 문자 확인 
        }

        while(search_flag == 1){                                    // search_flag가 0이면: 두 문자열 사이의 공백을 찾을 때까지 탐색
            if(sentence[i][k] == ' '){                              // 만약 해당 위치가 공백이라면
                space = k++;                                        // 현재 위치를 space 변수에 따로 저장
                search_flag = 2;                                    // 플래그 변수를 2로 설정 (=X(x)탐색 반복문 종료)
            }
            else k++;                                               // 공백이 아니면 다음 문자 확인 
        }

        if(sentence[i][x_pos + space + 1] >= 97) printf("%c", sentence[i][x_pos + space + 1] - 22);   // 소문자라면 대문자로 바꿔서 출력
        else printf("%c", sentence[i][x_pos + space + 1]);                                            // 대문자라면 그대로 출력
    }
    



    // 문자열 저장에 대한 메모리 동적 할당 해제
    for(int i=0; i<N; i++)
       delete[] sentence[i];
    
    delete[] sentence;

    return 0;
}











