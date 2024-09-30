#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAXPEOPLE = 5;
    string names[MAXPEOPLE];
    int ages[MAXPEOPLE];

    cout << MAXPEOPLE << "명의 회원 정보를 입력해주세요." << endl;

    for (int i=0; i <MAXPEOPLE; i++) {
        cout << "사람 " << i+1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i+1 << "의 나이: ";
        cin >> ages[i];
    }

    int number;
    int out_age = ages[0];
    string out_name = names[0];
    cout << "1: 가장 나이가 많은 사람 2: 가장 나이가 적은 사람 3: 종료";
    cin >> number;
    switch (number) {
        case 1:
            for (int i=0; i<MAXPEOPLE; i++) {
                if (out_age <= ages[i]) {
                    out_age = ages[i];
                    out_name = names[i];
                    
                }   
            }
            cout << "가장 나이가 많은 사람:" << out_name << " (" << out_age << "세)"<< endl;
            break;
        case 2: 
            for (int i=0; i < MAXPEOPLE; i++) {
                if (out_age >= ages[i]) {
                    out_age = ages[i];
                    out_name = names[i];
                }
            }
            cout << "가장 나이가 적은 사람:" << out_name << " (" << out_age << "세)"<< endl;
            break;
        case 3:
            cout << "종료합니다.";
            break;
        default: 
            cout << "잘못된 입력을 감지했습니다. 종료합니다." << endl;    
        }
    return 0;
}