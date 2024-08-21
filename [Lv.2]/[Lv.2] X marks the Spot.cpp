#include<iostream>
#include<vector>
#include<utility>
#include<string>

using namespace std;

int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    // 순서쌍 갯수 입력받음
    int N;
    cin >> N;

    // 문자열 순서쌍 입력받음
    vector<pair<string, string>> words(N);
    
    for(int i=0; i<N; i++){
        cin >> words[i].first >> words[i].second;
    }

    
    // x 혹은 X의 위치를 찾음
    vector<int> index_x(N);
    int j=0;
    for(int i=0; i<N; i++){
        index_x[i] = words[i].first.find('x');   // i번째 first 문자열의 x 위치 저장
        if (index_x[i] == -1) index_x[i] = words[i].first.find('X');
    }

    // A=65, a=97
    for(int i=0; i<N; i++){
        if(words[i].second[index_x[i]] >= 97)
            cout << (char)(words[i].second[index_x[i]] - 32);
        else cout << words[i].second[index_x[i]];
    }

    
    

    return 0;
}
