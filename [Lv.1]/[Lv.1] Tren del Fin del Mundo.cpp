/*
    - 설명이 복잡하지만 문제는 단순하다
    - 문제 결론) N개의 2차원 좌표를 입력했을 때, 가장 아래에 있는 점을 찾아 출력해라
    - 2차원 배열로 좌표값 저장한 다음, 반복문을 돌려 y값이 가장 작을 때의 index값을 찾으면 된다
*/
 
#include<iostream>
#include<stdio.h>

using namespace std;

int main(int argc, char** argv)
{
    int N=0;
    int coordi[1000][2] = {0,};
    int min_y = 0;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> coordi[i][0];  // x값 저장
        cin >> coordi[i][1];  // y값 저장
    }

    
  //y값 최소인 점을 찾는다
  //순서대로 비교하면서 동시에 최소로 저장해둔 index의 값과도 비교해야 함
  // -> 전체에서 최소값을 찾는 것이기 때문
    for(int j=0; j<N-1; j++){
        for(int k=1; k<N; k++){
            if(coordi[j][1] < coordi[k][1] && coordi[j][1] < coordi[min_y][1]) min_y = j;
            else if(coordi[j][1] > coordi[k][1] && coordi[min_y][1] > coordi[k][1]) min_y = k;
            else continue;

        }
    }
        
    cout << coordi[min_y][0] << " " << coordi[min_y][1] << endl;

   return 0;
}
