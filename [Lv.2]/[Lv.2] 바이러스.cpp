/*
    - 모듈러 연산에 대한 문제 -> 이거 모르면 못 푸는 문제임
    - A^B mod C 를 구해야 할 때, 모듈러 곱셈법칙에 따라 다음과 같이 풀 수 있음:
        - A^2 mod C = ((A mod C) * (A mod C)) mod C -> 근데 얘는 B가 커질수록 비효율적임
    - 더 큰 수에 대해서 구하는 방법이 있음: 아래 링크 참고
    https://ko.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/fast-modular-exponentiation

    - 이 문제는 K*(P^N) mod 1000000007을 구하는 문제
    - (A * B) mod C = (A mod C * B mod C) mod C로 구하면 됨
*/

#include<iostream>
#include<math.h>

using namespace std;

int MOD_NUM = 1000000007;       // 최종 mod 연산을 할 숫자 선언
int temp[100];            // 각 2의 거듭제곱에 따른 모듈러 연산 값을 저장할 배열변수 선언
int m=0;                  // temp 배열 변수의 index 변수
int mod_cal(int num, int exp);         // 2의 거듭제곱 형태의 mod연산을 하는 재귀함수 선언

int main(int argc, char** argv)
{
    int K, P, N = 0;
    int left_part = 0;         // K mod 1000000007 값을 저장할 변수 선언
    int right_part = 0;        // (P^N) mod 1000000007 값을 저장할 변수 선언

    cin >> K >> P >> N;        // 주요 변수 입력받음

    //// 알고리즘 시작 ////
    // (A * B) mod C = (A mod C * B mod C) mod C 이므로,
    // K*(P^N) mod 1000000007 -> ((K mod 1000000007) * ((P^N) mod 1000000007)) mod 1000000007
    
    // 1. K mod 1000000007 계산
    left_part = K % MOD_NUM;

    // 2. (P^N) mod 1000000007 계산
    // 2.1. N을 이진수로 변경
    int div = 0;               // 몫을 저장할 변수 선언
    int bit_arr[10000] = {0,}; // N의 이진수를 저장할 배열변수 선언
    int k=0;                   // bit_arr의 index 변수 선언(동시에 이진수의 길이 값을 저장))

    div = N;                   // 몫이 계속 작아질 것이므로 N을 대입
    while(div != 1){           // 몫이 1이 될 때까지 반복
        bit_arr[k++] = div % 2;            // 나머지를 계속 계산하여 이진수로 변환 (단, 쓰는 순서가 반대로 저장됨)  
        div /= 2;                          // 몫 계산
        if(div == 1)bit_arr[k++] = 1;      // 이진수 변환 시의 마지막 1을 대입
    }

    
    // 2.2. 2 ≤ B 인 거듭제곱의 mod C 를 계산하고, 그 결과를 순서대로 bit_arr[k]와 곱해서 누산
    long long result=1;                  // 결과 누산 값을 저장할 변수 선언
    long long tem=0;
    for(int j=0; j<k; j++){                      // 이진수 길이만큼 연산 반복
        tem = mod_cal(P, pow(2,j));
        if(bit_arr[j] == 1) result *= tem;       // mod 연산 재귀함수 호출 후 누산
        else if(bit_arr[j] == 0) continue;       // 따라서 P^N은 result로 치환 가능
    }                                                    

    // 2.3. right_part 계산
    right_part = result % MOD_NUM;

    
    // 3. K*(P^N) mod 1000000007최종 계산
    cout << (left_part * right_part) % MOD_NUM;
    
    
    return 0;
}


// 2의 거듭제곱 형태의 mod연산을 하는 재귀함수 선언
// int mod_cal(int num, int exp){
//     if(exp == 1)                              // 1제곱이면 그냥 계산
//         temp[m] = num % MOD_NUM;
    
//     else if(exp>=2)                         // 2제곱 이상이면 이전 연산 값을 활용하여 계산
//         temp[m] = (temp[m-1] * temp[m-1]) % MOD_NUM;

//     return temp[m++];
// }

int mod_cal(int num, int exp){
    if(exp == 1) return num % MOD_NUM;
    else return (mod_cal(num, exp/2) * mod_cal(num, exp/2)) % MOD_NUM;
}
