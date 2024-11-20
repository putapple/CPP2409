#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

void displayMap(vector<vector<int>>& map, const User& magician, const User& warrior, const User* currentUser);
bool checkXY(int user_x, int user_y);
void checkEncounter(vector<vector<int>>& map, User& user);

int main() {
    vector<vector<int>> map = { {0, 1, 2, 0, 4},
                                {1, 0, 0, 2, 0},
                                {0, 0, 0, 0, 0},
                                {0, 2, 3, 0, 0},
                                {3, 0, 0, 0, 2} };

    // Magician과 Warrior 객체 생성
    Magician magician;
    Warrior warrior;

    User* currentUser = &magician; // 초기 유저: Magician
    string currentCharacterName = "Magician";

    cout << "게임을 시작합니다!" << endl;
    magician.displayStatus();
    warrior.displayStatus();
    displayMap(map, magician, warrior, currentUser);

    while (true) {
        // 현재 이동할 차례 출력
        if (currentUser == &magician) {
            cout << "[Magician의 차례입니다.]" << endl;
            currentCharacterName = "Magician";
        } else {
            cout << "[Warrior의 차례입니다.]" << endl;
            currentCharacterName = "Warrior";
        }
        //명령어 입력 받기
        string user_input;
        cout << "명령어를 입력하세요 (up, down, left, right, map, attack, info, exit): ";
        cin >> user_input;

        //입력받은 명령어에 따라 수행.
        int dx = 0, dy = 0;
        if (user_input == "up") dy = -1;
        else if (user_input == "down") dy = 1;
        else if (user_input == "left") dx = -1;
        else if (user_input == "right") dx = 1;
        else if (user_input == "map") {
            displayMap(map, magician, warrior, currentUser);
            continue;
        } else if (user_input == "attack") {
            currentUser->doAttack();
            continue;
        } else if (user_input == "info") { //info 수정 : 아이템 갯수가 아닌 보유 여부를 확인
            // 현재 캐릭터 정보 출력
            cout << "현재 조종 중인 캐릭터: " << currentCharacterName << endl;
            cout << "HP: " << currentUser->GetHP() << ", 아이템 보유 여부: " << (currentUser->hasItemState() ? "Yes" : "No") << endl;
            continue;
        } else if (user_input == "exit") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
            continue;
        }

        // 새로운 위치 계산
        int new_x = currentUser->getX() + dx;
        int new_y = currentUser->getY() + dy;


        //맵 좌표 유효성 체크
        if (!checkXY(new_x, new_y)) {
            cout << "맵을 벗어났습니다!" << endl;
        } else {
            currentUser->move(dx, dy);
            cout << "이동했습니다!" << endl;
            currentUser->DecreaseHP(1); // 이동 시 체력 감소
            checkEncounter(map, *currentUser);

            // 이동 후 캐릭터 전환
            currentUser = (currentUser == &magician) ? (User*)&warrior : (User*)&magician;
        }

        displayMap(map, magician, warrior, currentUser);


        //Magician이나 warrior 둘 중 하나의 체력이 모두 소진되면 게임 오버
        if (magician.GetHP() <= 0 || warrior.GetHP() <= 0) {
            cout << "캐릭터의 체력이 모두 소진되었습니다. 게임 오버!" << endl;
            break;
        }
    }

    return 0;
}

bool checkXY(int user_x, int user_y) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

//지도 출력
void displayMap(vector<vector<int>>& map, const User& magician, const User& warrior, const User* currentUser) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            // Magician과 Warrior가 같은 위치에 있는 경우
            if (i == magician.getY() && j == magician.getX() && i == warrior.getY() && j == warrior.getX()) {
                if (currentUser == &magician) {
                    cout << "M*,W  |"; // Magician 차례
                } else {
                    cout << "M,W*  |"; // Warrior 차례
                }
            }
            // Magician만 있는 경우
            else if (i == magician.getY() && j == magician.getX()) {
                cout << ((currentUser == &magician) ? " M*   |" : "  M   |");
            }
            // Warrior만 있는 경우
            else if (i == warrior.getY() && j == warrior.getX()) {
                cout << ((currentUser == &warrior) ? " W*   |" : "  W   |");
            } else {
                // 맵 요소 출력
                int posState = map[i][j];
                switch (posState) {
                case 0:
                    cout << "      |";
                    break;
                case 1:
                    cout << "아이템|";
                    break;
                case 2:
                    cout << "  적  |";
                    break;
                case 3:
                    cout << " 포션 |";
                    break;
                case 4:
                    cout << "목적지|";
                    break;
                }
            }
        }
        cout << endl << " -------------------------------- " << endl;
    }
}

//이벤트 인카운터 설정.
void checkEncounter(vector<vector<int>>& map, User& user) {
    int posState = map[user.getY()][user.getX()];
    switch (posState) {
        case 1: //아이템 발견
            cout << "아이템을 발견했습니다! 다음 적과의 전투에서 피해를 입지 않습니다." << endl;
            user.setItem(true);
            break;
        case 2: // 적 발견
            if (user.hasItemState()) {
                cout << "적을 만났지만 아이템으로 피해를 방어했습니다!" << endl;
                user.setItem(false); // 아이템 사용
            } else {
                cout << "적을 만났습니다! 체력이 2 감소합니다." << endl;
                user.DecreaseHP(2);
            }
            break;
        case 3:
            cout << "포션을 발견하여 체력이 5 증가했습니다." << endl;
            user.IncreaseHP(5); //
            break;
    }
}
