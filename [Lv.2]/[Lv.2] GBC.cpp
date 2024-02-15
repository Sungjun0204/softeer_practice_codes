/*
    - 2차원 배열을 선언하여, 1. 건물의 구간 당 길이와 제한속도, 2. 테스트한 구간 당 길이와 속도를 저장
    - 테스트한 구간 길이와 건물 구간 당 길이가 항상 똑같지는 않으므로, 구간 당 길이 값을 먼저 비교해 가면서 문제를 풀어야 함
    - 기준은 건물 당 정해져 있는 구간과 제한 속도. 구간 당 길이를 누적해서 계산하는 식으로 알고리즘 진행
    - 건물 쪽 구간, 테스트한 구간 모두 각 구간이 끝났을 때 제한 속도를 초과했는지 계산해야 한다.
    - 시작은 건물 쪽 구간 기준, 테스트 구간부터 비교하기로 한다. 구간의 양을 비교해야 하므로, 각 구간들을 누적해 나가면서 비교해야 함.
*/

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int N = 0;   // 건물에 나뉘어져 있는 구간의 수
    int M = 0;   // 광우가 임의로 테스트한 구간의 수
    int building[100][2] = {0,};   // 건물 각 구간의 길이와 속도 제한 값을 저장하는 배열변수 선언
    int test[100][2] = {0,};       // 광우가 테스트한 구간 길이와 속도 값을 저장하는 배열변수 선언
    int building_accu, test_accu = 0;   // 구간을 비교하기 위해 사용할 변수 선언
    int each_part_diff[10000] = {0,};  // 각 구간마다 초과된 속도 값을 저장할 배열 변수 선언
    int count_part = 0;                // 비교 구간이 총 얼마나 있는지 세는 변수 선언
    int max_part = 0;                  // each_part_diff 중 최대값을 저장하는 변수 선언

    // N, M값 입력받음
    cin >> N >> M;

    // N번 만큼 건물의 구간 당 길이와 제한 속도 값을 입력받음
    for(int i=0; i<N; i++)
        cin >> building[i][0] >> building[i][1];

    // M번 만큼 테스트한 구간 길이와 테스트한 속도 값을 입력받음
    for(int i=0; i<M; i++)
        cin >> test[i][0] >> test[i][1];


    //// 알고리즘 시작 ////
    building_accu = building[0][0];       // 빌딩의 첫 구간을 먼저 building_accu에 저장한 상태로 알고리즘 시작
    test_accu = test[0][0];               // 테스트한 첫 구간도 마찬가지로 test_accu에 저장한 상태로 알고리즘 시작 
    int j = 0;    // test에 대한 index 변수
    int k = 0;    // each _part_diff에 대한 index 변수
    int i = 0;    // building에 대한 index 변수
    while(i < N){   // 반복문: building_accu가 모든 건물 구간의 값을 누산하게 되면 종료
        
        if(building_accu == test_accu){   // 두 구간의 누적이 같아질 때
            if(test[j][1] < building[i][1]) each_part_diff[k++] = -1;       // 제한속도를 벗어나지 않았으면 음수 값 대입
            else each_part_diff[k++] = test[j][1] - building[i][1];         // 초과했다면 얼마나 초과했는지 계산 후 대입. 혹은 0이 대입될 것임.

            building_accu += building[++i][0];   // building_accu에 다음 building 구간 길이 누산
            test_accu += test[++j][0];           // test_accu에 다음 test 구간 길이 누산
            count_part++;
        }

            
        else if(building_accu > test_accu){  // 누적된 건물 높이가 누적된 테스트 높이보다 높을 때
            if(test[j][1] < building[i][1]) each_part_diff[k++] = -1;       // 제한속도를 벗어나지 않았으면 음수 값 대입
            else each_part_diff[k++] = test[j][1] - building[i][1];         // 초과했다면 얼마나 초과했는지 계산 후 대입. 혹은 0이 대입될 것임.
            
            test_accu += test[++j][0];    // test_accu에 다음 test구간 길이 누산
            count_part++;
        }

            
        else{   // (building_accu < test_accu) 누적된 테스트 높이가 건물 높이보다 높을 때
            if(test[j][1] < building[i][1]) each_part_diff[k++] = -1;       // 제한속도를 벗어나지 않았으면 음수 값 대입
            else each_part_diff[k++] = test[j][1] - building[i][1];         // 초과했다면 얼마나 초과했는지 계산 후 대입. 혹은 0이 대입될 것임.
            
            building_accu += building[++i][0];   // building_accu에 다음 building 구간 길이 누산
            count_part++;
        }
   
    }

    // 각 비교 파트 중 가장 크게 초과한 값을 찾음
    for(int a=0; a<count_part; a++){
        if(max_part < each_part_diff[a]) max_part = each_part_diff[a];
        else continue;
    }

    // 최종 출력
    cout << max_part << endl;
    
    
    return 0;
}

