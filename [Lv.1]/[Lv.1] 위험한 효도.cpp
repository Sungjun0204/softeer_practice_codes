/*
    - 술래가 뒤돌아보고 있는 시간 = 남우가 이동한 거리
    - 술래를 터치하고 돌아와야 하기에 남우의 총 이동거리: 2d
    - 근데 d만큼 이동했을 때 술래의 뒤 도는 시간과 앞을 보는 시간이 서로 바뀜
*/
 
#include <iostream>
#include <stdio.h>

using namespace std;

int distance(int a, int b, int d);

int main(int argc, char** argv)
{
    int a, b = 0;    // 술래가 뒤 돌거나 앞을 보는 시간
    int d = 0;       // 남우와 술래 사이 거리

    // 각 파라미터들 입력을 받음
    cin >> a >> b >> d;

    int new_a = b;
    int new_b = a;

    cout << distance(a,b,d)+distance(new_a,new_b,d) << endl;

   return 0;
}

int distance(int a, int b, int d){
    if(a == d) return d;             // 그러나 a==d인 경우는 예외처리
    else return b * (d / a) + d;     // 이 공식 쓰면 됨
}
