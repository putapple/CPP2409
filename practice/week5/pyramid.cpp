#include <iostream>
using namespace std;

int main() {
    int floor;
    cout << "몇 층을 쌓겠습니까? (5-100)" ;
    cin >> floor;

    if(floor >= 5 && floor <= 100) {
        for (int i = 0; i < floor; i++) {
            for (int j=0; j< floor -1 - i; j++) {
                cout << " ";
            }
            for (int k=0; k < i*2+1; k++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    else{
        cout << " 숫자를 잘못입력하였습니다.";
    }
    return 0;
}