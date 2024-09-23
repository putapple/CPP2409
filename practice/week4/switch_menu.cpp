#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "1. 파일 저장" << endl;
    cout << "2. 저장 없이 닫기" << endl;
    cout << "3. 종료" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "파일 저장을 선택했습니다." << endl;
            break;
        case 2:
            cout << "파일 닫기를 선택했습니다." << endl;
        case 3:
            cout << "프로그랩을 종료합니다." << endl;
        default:
            cout << "잘못된 선택입니다." << endl;
            break;
    }

    return 0;
}