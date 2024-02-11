/*
    - 숫자가 오름차순인지, 내림차순인지, 아니면 섞였는지 알아보면 된다. (경우에 따른 단순 비교문제)
    - 오름차순은 1로 시작하고, 오름차순이 미리 저장된 배열과 대조/비교한다.
    - 내림차순도 8로 시작하고, 내림차순이 미리 저장된 배열과 대조/비교한다.
    - 이때 하나라도 틀리면 혼합이라고 출력한다.
*/

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int gear[8] = {0,};   // 입력받을 기어 단을 저장할 배열 변수 선언
    int ascending[8] = {1,2,3,4,5,6,7,8};   // 오름차순 판별을 위한 변수 초기화
    int descending[8] = {8,7,6,5,4,3,2,1};  // 내림차순 판별을 위한 변수 초기화
    int ascend_flag, descend_flag = 0;      // 판별 여부를 확인하기 위한 flag변수 선언

    for(int i=0; i<8; i++)
        cin >> gear[i];    // 순서대로 기어 단수를 입력받음 (8개)

    // 만일 1로 시작하게 될 때: 오름차순 가능성 있으므로 확인해본다
    if (gear[0] == 1){
        for(int i=0; i<8; i++){
            if(gear[i] == ascending[i]) ascend_flag++;
            else break;
        }

        if(ascend_flag == 8) cout << "ascending" << endl;
        else cout << "mixed" << endl;
    }

    // 만일 8로 시작하게 될 때: 내림차순 가능성 있으므로 확인해본다
    else if(gear[0] == 8){
        for(int i=0; i<8; i++){
            if(gear[i] == descending[i]) descend_flag++;
            else break;
        }

        if(descend_flag == 8) cout << "descending" << endl;
        else cout << "mixed" << endl;
    }

    else cout << "mixed" << endl;
     

    
   return 0;
}
