/*
    - 주어진 숫자들의 각 차이를 하나씩 계산해서 차이가 가장 작은 수를 계산
    - 그럼 그 작은 수의 차이가 나는 두 숫자의 조합이 얼마나 있는지 세어서 그 갯수를 출력
    - 첫 번째 반복문에서는 두 수의 차이의 최소값 min을 찾는다
    - 두 번째 반복문에서는 두 수의 차이가 min인 경우의 갯수를 센다
*/


#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(int argc, char** argv)
{
    int n=0;   // 마을의 갯수 
    int vill[1000] = {0,};    // 각 마을의 거리값 계산
    int min=1000000;   // 두 마을의 거리 중 최소값을 저장할 변수 최소화
    int min_count=0;   // 두 마을 거리가 min인 두 마을의 갯수

    
    cin >> n;   // 마을 갯수 값 입력 받음

    // 각 마을의 위치 값을 n번 입력받음
    for(int i=0; i<n; i++)
        cin >> vill[i];

    // 최소값 찾기
    for(int j=0; j<n-1; j++){
        if(vill[j+1] - vill[j] <= min)   // 새로 계산한 값이 더 최소값이면
            min = vill[j+1] - vill[j];  // 최소값 갱신
        else continue;    
    }
               
    //cout << min << endl;
    
    // min만큼 차이나는 조합 갯수 찾기
    for(int j=0; j<n-1; j++){
        if(abs(vill[j+1] - vill[j]) == min) // 저장된 최소값과 같다면
            min_count++;   // 카운트 1 추가
        else continue;
    }

    

    cout << min_count << endl;

    
    return 0;
}

