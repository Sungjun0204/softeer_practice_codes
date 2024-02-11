#include <iostream>
#include <stdio.h>
 
using namespace std;

int main(int argc, char** argv)
{
    int A, B = 0;
    
    cin >> A >> B;
    if (A > B){ cout << "A" << endl; }
    else if (B > A) {cout << "B" << endl;}
    else cout << "same" << endl;

   return 0;
}
