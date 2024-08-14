#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m = 0;
    int attack1_s, attack1_e;
    int attack2_s, attack2_e;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int> (m)); // 맵
    vector<int> map_sum(n);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> map[i][j];

    cin >> attack1_s >> attack1_e;
    cin >> attack2_s >> attack2_e;


    // 알고리즘 시작
    //1. map의 각 행들 다 더함
    for(int i=0; i<n; i++){
        map_sum[i] = accumulate(map[i].begin(), map[i].end(), 0);
    }

    // 첫 번째 공격 적용
    for(int k=attack1_s-1; k<attack1_e; k++){
        if (map_sum[k] == 0) continue;
        else map_sum[k] = map_sum[k] - 1;
    }

    // 두 번째 공격 적용
    for(int k=attack2_s-1; k<attack2_e; k++){
        if (map_sum[k] == 0) continue;
        else map_sum[k] = map_sum[k] - 1;
    }

    //결과 출력
    cout << accumulate(map_sum.begin(), map_sum.end(), 0);
    
    return 0;
}
