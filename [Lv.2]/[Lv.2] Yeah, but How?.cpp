#include<iostream>
#include<string>
#include<vector>

using namespace std;

int i=0;
int k=0;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    char T[500000] = {0,};
    char S[500000] = {0,};
    cin >> S;

    while(S[i+1] == '(' || S[i+1] == ')'){

        // if(S[i+1] != '(' || S[i+1] != ')') break;
        
        if(S[i] == '(' && S[i+1] == '('){
            T[k++] = '(';
            T[k++] = '1';
            T[k++] = '+';
        }

        else if(S[i] == '(' && S[i+1] == ')'){
            T[k++] = '(';
            T[k++] = '1';
            T[k++] = ')';
        }

        else if(S[i] == ')' && S[i+1] == '('){
            T[k++] = '+';
        }

        else if(S[i] == ')' && S[i+1] == ')'){
            T[k++] = ')';
        }

        i++;
    }

    cout << T;
    
    
    return 0;
}
