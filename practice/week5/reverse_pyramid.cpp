#include <iostream>
using namespace std;

int main() {
    int floor;
    cout << "몇 층을 쌓겠습니까? (5-100)" ;
    cin >> floor;


    if(floor >= 5 && floor <= 100) //숫자 범위내를 입력했을 때
    {
        for (int i = floor; i > 0; i--) {
            for (int j=0; j< floor - i; j++) {
                cout << " ";
            }
            for (int k=0; k < i*2-1; k++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    else{ //숫자 범위외를 입력했을 때
        cout << "숫자를 잘못입력하였습니다.";
    }
    return 0;
}