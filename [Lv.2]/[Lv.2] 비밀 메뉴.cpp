/*
    헷갈리므로 다시 정리하면,
        M: 비밀코드 길이
        N: 사용자가 입력한 버튼 횟수
        K: 누른 버튼의 최대 숫자
    ** 내가 고전했던 내용
        - 비밀코드 본격 알고리즘 시작하는 부분
        - 비밀코드, 입력코드 모두 같은 1개의 버튼일 때, 반복문이 실행이 안 되었음
        - 알고보니 N-M이면 위와 같은 상황은 0이 되므로 반복문 자체를 실행할 수 없게 됨
        - 따라서 +1을 해 준다
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
    for(int j=0; j<N-M+1; j++){
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

    if(flag != M) cout << "normal" << endl;
    

   return 0;
}
