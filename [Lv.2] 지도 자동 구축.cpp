/*
  - 단순 등비계차수열 발화식 찾는 문제
  - MATLAB이랑 헷갈려서 제곱 표현을 ^로 쓰면 안 됨!
  - C++에서는 <cmath>라는 표준 라이브러리 include하고 pow() 함수를 사용하자!
*/


#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
    int n = 0;
    int result = 0;

    cin >> n;

    result = pow((1 + pow(2,n)),2);

    cout << result << endl;

   return 0;
}
