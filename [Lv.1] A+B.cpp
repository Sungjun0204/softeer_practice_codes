#include <stdio.h>
#include <iostream>


using namespace std;

int main(int argc, char** argv)
{
  int try_num = 0; 
  int a, b;
  
  cin >> try_num ;
  
  for (int i = 0; i < try_num; i++){
    cin >> a >> b;
    cout << "Case #" << i+1 << ":" << " " << a+b << endl;
  }

   return 0;
}

