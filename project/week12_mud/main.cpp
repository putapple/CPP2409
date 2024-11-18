#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;
const int initialHealth = 20;

bool checkXY(int user_x, int user_y);
void displayMap(vector<vector<int>>& map, const User& user);
bool checkGoal(vector<vector<int>>& map, const User& user);
void checkEncounter(vector<vector<int>>& map, User& user);

int main() {
    vector<vector<int>> map = { {0, 1, 2, 0, 4},
                            {1, 0, 0, 2, 0},
                            {0, 0, 0, 0, 0},
                            {0, 2, 3, 0, 0},
                            {3, 0, 0, 0, 2} };

    User user;

    cout << "게임을 시작합니다!" << endl;
    user.displayStatus();
    displayMap(map, user);

    while (true) {
        string user_input = "";
        cout << "명령어를 입력하세요 (up, down, left, right, map, info, exit): "; //info 추가
        cin >> user_input;

        int dx = 0, dy = 0;
        if (user_input == "up") dy = -1;
        else if (user_input == "down") dy = 1;
        else if (user_input == "left") dx = -1;
        else if (user_input == "right") dx = 1;
        else if (user_input == "map") {
            displayMap(map, user);
            continue;
        } else if (user_input == "info") {
            cout << user << endl; // info 입력 할 때 사용자 정보 출력
            continue;
        } else if (user_input == "exit") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다. up, down, left, right, map, info, exit 중에서 선택하세요." << endl;
            continue;
        }

        int new_x = user.getX() + dx;
        int new_y = user.getY() + dy;
        if (!checkXY(new_x, new_y)) {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        } else {
            user.move(dx, dy);
            cout << (dy == -1 ? "위" : dy == 1 ? "아래" : dx == -1 ? "왼쪽" : "오른쪽") << "으로 한 칸 이동합니다." << endl;
            user.DecreaseHP(1); // 이동 시 체력 감소
            checkEncounter(map, user); // 만남 이벤트 확인
            displayMap(map, user);
        }

        user.displayStatus();
        if (user.GetHP() <= 0) {
            cout << "체력이 모두 소진되었습니다. 게임 오버!" << endl;
            break;
        }

        if (checkGoal(map, user)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }
    return 0;
}

// 유효한 좌표인지 체크
bool checkXY(int user_x, int user_y) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

// 지도와 사용자 위치 출력
void displayMap(vector<vector<int>>& map, const User& user) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user.getY() && j == user.getX()) {
                cout << " USER |";
            } else {
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

// 유저의 위치가 목적지인지 확인
bool checkGoal(vector<vector<int>>& map, const User& user) {
    return map[user.getY()][user.getX()] == 4;
}

// 아이템, 포션, 적을 만났을 때의 처리
void checkEncounter(vector<vector<int>>& map, User& user) {
    int posState = map[user.getY()][user.getX()];
    switch (posState) {
        case 1:
            cout << "아이템을 발견했습니다! 다음 적과의 전투에서 피해를 입지 않습니다." << endl;
            user.setItem(true); 
            //아이템을 먹어도 그 자리에 계속 남게 설정.
            break;
        case 2:
            if (user.hasItemState()) {
                cout << "적을 만났지만, 아이템이 소비되지 않았습니다!" << endl;
            } else {
                cout << "적을 만났습니다! 체력이 2 감소했습니다." << endl; 
                // 아이템 먹은 횟수를 저장하기 위해 소모 하지 않음.
                user.DecreaseHP(2);
            }
            break;
        case 3:
            cout << "포션을 발견하여 체력이 5 증가했습니다." << endl;
            user.IncreaseHP(5);
            break;
    }
}
