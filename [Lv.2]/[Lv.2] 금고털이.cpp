#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

using namespace std;

bool second_standard(pair<int,int>a, pair<int,int> b){
    return a.second > b.second;
}

int main(int argc, char** argv)
{
    cin.tie(NULL);                   // cin 버퍼 초기화
    cout.tie(NULL);                  // cout 버퍼 초기화
    ios::sync_with_stdio(false);     // C와 C++의 표준 입출력 사이의 동기화 해제 
    
    int W, N= 0;              // 필요한 변수 초기화
    int final_value = 0;      // 배낭 속 금속 가치 누산 값

    // 배낭에 무게와 귀금속의 종류 입력받음
    cin >> W >> N;

    // first: 금속 무게, second: 키로당 가격
    vector<pair<int, int>> stone(N);
    for(int i=0; i<N; i++){
        cin >> stone[i].first >> stone[i].second;
    }

    // 비싼 금속 순으로 정렬
    sort(stone.begin(), stone.end(), second_standard);
    
    for(int i=0; i<N; i++){
        if(W >= stone[i].first){
            W = W - stone[i].first;
            final_value += (stone[i].first * stone[i].second);
        }

        else if(W < stone[i].first){
            final_value += (W * stone[i].second);
            W = 0;
        }
        if(W == 0) break;
    }

    cout << final_value;
     
    return 0;
}
