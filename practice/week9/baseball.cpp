#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// 각 자릿수가 서로 다른지 확인하는 함수
bool areDigitsUnique(int number) {
    int first = number / 100;
    int second = (number % 100) / 10;
    int third = number % 10;

    return (first != second && first != third && second != third);
}

int main() {
    srand(time(0)); // 난수 생성 초기화 - 매번 다른 랜덤 숫자를 생성하기 위해 사용

    int randomNum; // 맞춰야 하는 3자리수
    int firstNum, secondNum, thirdNum; // 랜덤 숫자의 각 자리 숫자

    // 랜덤 숫자 생성 및 자릿수 중복 체크
    while (true) {        
        randomNum = rand() % 900 + 100; // 3자리 랜덤 숫자 생성

        if (areDigitsUnique(randomNum)) {
            // 각 자릿수 추출 (디버깅용, 필요 없다면 생략 가능)
            firstNum = randomNum / 100;
            secondNum = (randomNum % 100) / 10;
            thirdNum = randomNum % 10;
            break;
        }
    }

    int turn = 0;
    while (true) {
        cout << turn + 1 << "번째 시도입니다. " << endl;

        int userNumber; // 사용자가 입력한 세자리수
        int guessFirst, guessSecond, guessThird;

        // 사용자가 세자리 수를 입력하도록 요청
        while (true) {
            cout << "세자리 수를 입력해주세요: ";
            cin >> userNumber;

            // 입력값이 3자리 숫자인지 확인
            if (to_string(userNumber).length() != 3) {
                cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
                continue;
            }

            // 자릿수가 서로 다른지 확인
            if (areDigitsUnique(userNumber)) {
                guessFirst = userNumber / 100;
                guessSecond = (userNumber % 100) / 10;
                guessThird = userNumber % 10;
                break;
            } else {
                cout << "모든 자릿수가 다른 세자리 숫자를 입력하세요." << endl;
            }
        }

        int strike = 0, ball = 0;

        // 스트라이크 계산
        if (firstNum == guessFirst) strike++;
        if (secondNum == guessSecond) strike++;
        if (thirdNum == guessThird) strike++;

        // 볼 계산 (스트라이크가 아닌 경우만)
        if (guessFirst == secondNum || guessFirst == thirdNum) ball++;
        if (guessSecond == firstNum || guessSecond == thirdNum) ball++;
        if (guessThird == firstNum || guessThird == secondNum) ball++;

        // 추측 결과 출력
        cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << " 볼 입니다." << endl;

        if (strike == 3) {
            cout << "정답을 맞췄습니다. 축하합니다!" << endl;
            break;
        }

        turn++;
    }

    return 0;
}