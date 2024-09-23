#include <iostream>
using namespace std;

int main() {
    int x,y;

    cout << "x값을 입력하세요: ";
    cin >> x;

    cout << "y값을 입력하세요: ";
    cin >> y;

    if ( x > y )
        cout << "x가 y보다 큽니다. " << endl;
    else if ( x == y )
        cout << "x와 y가 같습니다. " << endl;
    else
        cout << "y가 x보다 큽니다. " << endl;
    
    return 0;
}
