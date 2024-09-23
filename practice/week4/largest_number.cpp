#include <iostream>
using namespace std;

int main() {
    int a,b,c,largest;

    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;
    if ( a >= b && a >= c) // 오류를 피하기 위해 논리 연산자 수정 
    {
        largest = a;
    }
    else if ( b >= a && b >= c ){
        largest = b;
    }
    else if ( c >= a && c >= b ){
        largest = c;
    }
    else {
        cout << " 잘못된 입력입니다." ;
    }

    cout << "가장 큰 정수는 " << largest << endl;
      
}