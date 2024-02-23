/*
    - 배수 관련 문제
    - 주어진 N개의 숫자 중 최대값 M을 먼저 찾는다.
    - 각 숫자들을 소수로 계속 나눠본다. 단, 나눌 소수는 최대값 M을 넘지 않는다.
    - 나눠질 숫자보다 나눌 소수 값이 커지면 계산에서 제외시킨다.
    - 원활한 계산을 위해 100 이하 소수들을 먼저 출력해서 변수로 초기화시킨다.
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
    int N = 0;                    // 집의 수 정보를 입력하는 변수 선언
    int each_boiler[100] = {0,};  // 각 집의 난로의 반지름 길이를 저장하는 배열 변수 선언
    int max = 0;                  // each_boiler 중에서 최대값을 저장하는 변수 선언
    int count_div = 0;            // prime으로 나눠지는 수의 갯수를 저장하는 변수 선언
    int max_div = 0;              // count_div 중에서 최대값을 저장하는 변수 선언
    int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        // 소수를 저장하는 배열 변수 초기화

    //집의 수 입력
    cin >> N;

    // 집의 수 만큼 각 집의 난로의 반즈름 길이 입력
    for(int i=0; i<N; i++)
        cin >> each_boiler[i];

    
    //// 알고리즘 시작 ////
    // 100 이하인 소수 파악
    // for(int num=2; num<101; num++){
    //     int t=0;
    //     for(int div=2; div<num+1; div++){
    //         if(num%div == 0) t++;
    //         else continue;
    //     }

    //     if(t==1) cout << num << ", ";
    // }


    // 최대값 찾기
    for(int i=0; i<N; i++){
       if(max < each_boiler[i]) max = each_boiler[i];
        else continue;
    }
    
    // 100 이하의 소수로 나눠가면서 최대 공약수를 찾는다. 
    for(int k=0; k<25; k++){        // prime 갯수만큼 반복
        count_div = 0;              // count_div 초기화
        if(prime[k] > max) break;   // 단, 나누는 수가 max값을 넘어가면 반복문 종료
        else{
            for(int i=0; i<N; i++){ // each_boiler를 prime로 나눠서 딱 떨어지면 카운팅
                if(each_boiler[i]%prime[k] == 0) count_div++;
                else continue;
            }
        }

        if(count_div > max_div) max_div = count_div;   // k번째 계산이 최대 공약수라면 최댓값 갱신
        else continue;
    }


    // 최종 출력
    cout << max_div << endl;
    
    return 0;
}
