/*
    헷갈리므로 다시 정리하면,
        M: 비밀코드 길이
        N: 사용자가 입력한 버튼 횟수
        K: 누른 버튼의 최대 숫자
*/

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int M, N, K=0;
    int secret_code[100] = {0,};   // 비밀 코드를 저장할 배열 변수 선언
    int input[100] = {0,};         // 내가 입력한 커맨드를 저장할 배열 변수 선언
    int flag = 0;

    cin >> M >> N >> K;   // 각 변수들 입력받음

    for(int i=0; i<M; i++)
        cin >> secret_code[i];     // 비밀코드 저장

    for(int j=0; j<N; j++)
        cin >> input[j];           // 내가 입력한 커맨드 저장

    // 비밀코드 확인 알고리즘 시작
    for(int j=0; j<N-M; j++){
        if(secret_code[0] == input[j]){
            for(int i=0; i<M; i++){
                if(secret_code[i] == input[j+i]) flag++;
                else {flag = 0; break;}
            }
            
            if(flag == M){
                cout << "secret" << endl;
                break;
            }
        }

        else continue;
    }

    if(flag == 0) cout << "normal" << endl;
    

   return 0;
}

