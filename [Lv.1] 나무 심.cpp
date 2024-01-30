#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
    int n=0;          // 땅을 심을 토지 갯수
    int F_i[100] = {0,};   // n개의 토지의 비옥함의 정도
    int max_F = -101;


    cin >> n;
    for(int i; i<n; i++){
        cin >> F_i[i];
    }

    for(int j=0; j<n-1; j++)
        for(int k=j+1; k<n; k++){
            if(max_F < F_i[j] * F_i[k])
                max_F = F_i[j] * F_i[k];
        }

    printf("%d", max_F);

   return 0;
}
