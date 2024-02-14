/*
    - 총 6가지의 경우를 검토하면 됨
    - 각 경우에서, 땅의 높이를 통일할 수 있는 최소한의 경우를 찾아야 함
        - 이 방법의 경우, 1. 세 땅의 높이가 다 다를 때, 2. 두 땅의 높이만 같을 때, 3. 전부 같을 때로 나눠서 판별해야 함
    - 그러고 최종 선택된 총 6가지의 경우 중에서 또 최소한의 경우를 최종 선택
    - 여기서 얘기하는 최소값은 땅의 높낮이를 맞추기 위해 든 비용을 의미 
*/

#include<iostream>
#include<math.h>

using namespace std;

int main(int argc, char** argv)
{
    int soil[3][3] = {0,};    // 땅의 높이 정보를 저장하는 배열변수 선언
    int farm[6][3] = {0,};    // 경작할 수 있는 모든 경우를 저장하는 배열변수 선언
    int cost[6] = {0,};       // 각 경작지를 평평하게 만들기 위한 최소한의 금액 정보를 저장하는 배열변수 선언
    int min = 100;            // cost 배열 변수 중 최소값을 저장하기 위한 변수 선언

    // 땅의 높이 정보를 입력
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin >> soil[i][j];

    //// 알고리즘 시작 ////
    // 그 전에, 농사를 지을 땅의 모든 경우를 별도의 배열에 저장
    for(int i=0; i<6; i++)
        for(int j=0; j<3; j++){
            if(i < 3) farm[i][j] = soil[i][j];
            else farm[i][j] = soil[j][i-3];
        }

    // 알고리즘 1. 1X3인 모든 경우에서 땅의 높이를 통일할 수 있는 최소한의 금액을 계산
    for(int i=0; i<6; i++){
        if((farm[i][0] == farm[i][1]) && (farm[i][1] == farm[i][2]) && (farm[i][0] == farm[i][2]))   // 세 땅의 높이가 같으면
            cost[i] = 0;    // 땅을 다듬을 필요가 없으므로 비용은 0

        else if((farm[i][0] == farm[i][1]) || (farm[i][1] == farm[i][2]) || (farm[i][0] == farm[i][2])){   // 두 개의 땅 높이만 같으면
            // 같은 높이인 두 땅의 높이가 몇인지 확인해서 높이가 다른 값과의 차를 계산
            if(farm[i][0] == farm[i][1]) cost[i] = abs(farm[i][0] - farm[i][2]);
            else if(farm[i][1] == farm[i][2]) cost[i] = abs(farm[i][1] - farm[i][0]);
            else if(farm[i][0] == farm[i][2]) cost[i] = abs(farm[i][2] - farm[i][1]);
        }

        else{    // 세 땅의 높이가 다 다르면: "1 2 3" 이 경우 말고는 없음
            cost[i] = 3;  // 그럼 자연스럽게 비용이 3이 됨
        }  
    }


    // 알고리즘 2. 각 경우들에서 계산된 비용 중 가장 최소인 값을 출력. 비용이 동일한 경우가 있을 수 있음
    for(int i=0; i<6; i++){
        if(min > cost[i]) min = cost[i];
        else continue;
    }


    // 출력 확인
    cout << min << endl;

    return 0;
}
