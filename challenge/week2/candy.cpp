#include <iostream>
#include <string>
using namespace std;

int main() {

    int have_money, candy_money, candy_count, last_money;

    cout << "철수가 가지고 있는 돈은 얼마입니까? : ";
    cin >> have_money;
    cout << "캔디의 가격은 얼마입니까? : ";
    cin >> candy_money;

    candy_count = have_money / candy_money;
    last_money = have_money % candy_money;

    cout << "현재 가지고 있는 돈: " << have_money << endl;
    cout << "캔디의 가격: " << candy_money << endl;
    cout << "최대로 살 수 있는 캔디: " << candy_count << endl;
    cout << "캔디 구입 후 남은돈: " << last_money << endl;
}