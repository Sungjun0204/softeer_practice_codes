/*
    - 1~4개까지는 "|"로 표시하나, 5개는 "++++ "로 표시
    - 그렇다는 건 득표 수를 5로 나눈 뒤, 몫 갯수만큼 "++++ " 출력
    - 그리고 나머지에 따라 "|" 출력
*/

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int T= 0;           // 후보 명수
    int n[100] = {0,};  // 각 후보마다의 득표수를 저장할 배열 변수

    cin >> T;        

    // 후보 각각의 득표수 입력
    for(int i=0; i<T; i++){
        cin >> n[i];
    }

    // 각 후보들의 득표수를 기호로 출력
    for(int j=0; j<T; j++){
        for(int k=0; k < n[j]/5; k++)
            printf("++++ "); 

        for(int s=0; s < n[j]%5; s++)
            printf("|");

        printf("\n");
    }

   return 0;
}
