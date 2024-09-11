#include <iostream>
#include <string>
using namespace std;

int main() {

    double fe_temp, c_temp;

    cout << "화씨온도 입력 : ";
    cin >> fe_temp;
    
// 화씨 온도
    c_temp = (5.0 / 9.0) * (fe_temp -32);

    cout << "화씨온도 = " << fe_temp << endl;
    cout << "섭씨온도 = " << c_temp << endl;
    return 0;
    
}