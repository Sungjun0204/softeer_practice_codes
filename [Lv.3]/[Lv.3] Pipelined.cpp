#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(int argc, char** argv)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N = 0;
    cin >> N;

    vector<int> si(N);

    for(int i=0; i<N; i++)
        cin >> si[i];

    sort(si.begin(), si.end());

    cout << si.back() + (N-1) << "\n";
    
    return 0;
}
