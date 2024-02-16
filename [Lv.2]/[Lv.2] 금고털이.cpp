/*
    - 가방에 담을 수 있는 가장 비싼 가격을 출력하라? -> 무게당 가격이 제일 높은 금속 순서대로 가방에 담으면 된다
    - 그러기 위해서는 [금속 무게][무게당 가격 정보] 로 저장되어 있는 2차원 배열을 [무게당 가격 정보] 값 기준으로 내림차순으로 정렬하면 쉽게 끝나는 문제
    - [무게 당 가격 정보] 값을 기준으로 내림차순으로 정렬 -> 정렬하면서 덩달아 [금속 무게] 값도 이동시키면 됨
*/

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int W;   // 배낭에 담을 수 있는 최대 무게 값을 저장하는 변수 선언
    int N;   // 귀금속의 종류 값을 저장하는 변수 선언
    int stones[1000000][2];  // 1. 각 금속의 무게와 2. 무게당 가격 정보를 저장하는 2차원 배열 변수 선언
    int temp_weight, temp_purchase;     // stones 배열을 내림차순으로 정렬하기 위해서 사용할 temparary 변수 선언
    int packing;                        // 가방에 귀금속들을 넣는 것을 누산하기 위한 변수 선언
    int result_purchase = 0;                // 가방에 최종적으로 담은 귀금속들의 최종 금액을 저장할 변수 선언

    // 배낭의 무게와 귀금속의 종류 대한 값 입력받음
    cin >> W >> N;
    packing = W;

    // 귀금속의 종류만큼 각 귀금속의 총 무게와 무게당 가격 정보를 입력받음
    for(int i=0; i<N; i++)
        cin >> stones[i][0] >> stones[i][1];

    //// 알고리즘 시작 ////
    // 알고리즘 1. stones 배열을 [무게당 가격 정보] 값을 기준으로 내림차순으로 정렬
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(stones[i][1] < stones[j][1]){   // 뒷 순서 데이터가 앞 순서 데이터보다 값이 클 경우: 스왑 진행
                temp_weight = stones[j][0];    // 뒷 순서 데이터의 무게 정보 임시저장
                temp_purchase = stones[j][1];  // 뒷 순서 데이터의 무게 당 가격 정보 임시저장

                stones[j][0] = stones[i][0];
                stones[j][1] = stones[i][1];    // 앞 순서 데이터를 뒷 순서로 이동

                stones[i][0] = temp_weight;
                stones[i][1] = temp_purchase;  // 임시저장했던 뒷 순서 데이터를 앞 순서로 재이동
            }

            else continue;     // 그 외의 경우는 그냥 무시하고 다음 단계 진행
        }
    }

    // 알고리즘 2. stones 배열의 0번부터 순서대로 가방에 담는다
    int i=0;
    while(i < N && packing > 0){
        if(packing >= stones[i][0]){    // 가방에 빈 공간이 더 많거나 같은 경우: i번째 금속 다 넣을 수 있음
            packing -= stones[i][0];         // 가방에 해당 금속 무게를 누산
            result_purchase += stones[i][0] * stones[i++][1];   // 금액 계산 후 누산
        }

        else{ //((W - packing) < stones[i][0]): 가방에 빈 공간보다 금속이 더 큰 경우: 가방의 빈 공간만큼만 잘라서 저장 -> 여기로 오면 가방은 꽉 찼다는 의미
            result_purchase += packing * stones[i][1];   // 금액 계산 후 누산
            break;
        }

    }

    // 최종 출력
    cout << result_purchase;
    
    return 0;
}
