#include <iostream>
#include <vector>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

void displayMap(const vector<vector<int>>& map, const User& user);
bool checkXY(int user_x, int user_y);
void checkEncounter(vector<vector<int>>& map, User& user);

int main() {
    vector<vector<int>> map = { {0, 1, 2, 0, 4},
                                {1, 0, 0, 2, 0},
                                {0, 0, 0, 0, 0},
                                {0, 2, 3, 0, 0},
                                {3, 0, 0, 0, 2} };

    // 직업 선택
    cout << "직업을 선택하세요 (1: Magician, 2: Warrior): ";
    int choice;
    cin >> choice;

    User* currentUser;
    if (choice == 1) {
        currentUser = new Magician();
        cout << "Magician을 선택했습니다." << endl;
    } else {
        currentUser = new Warrior();
        cout << "Warrior를 선택했습니다." << endl;
    }

    // 게임 시작
    while (true) {
        displayMap(map, *currentUser);
        cout << "명령어를 입력하세요 (up, down, left, right, attack, info, exit): ";
        string command;
        cin >> command;

        if (command == "exit") {
            cout << "게임 종료!" << endl;
            break;
        }

        int dx = 0, dy = 0;
        if (command == "up") dy = -1;
        else if (command == "down") dy = 1;
        else if (command == "left") dx = -1;
        else if (command == "right") dx = 1;
        else if (command == "attack") {
            currentUser->doAttack();
            continue;
        } else if (command == "info") {
            currentUser->displayStatus();
            continue;
        } else {
            cout << "잘못된 명령어입니다." << endl;
            continue;
        }

        int new_x = currentUser->getX() + dx;
        int new_y = currentUser->getY() + dy;

        if (!checkXY(new_x, new_y)) {
            cout << "맵을 벗어났습니다!" << endl;
        } else {
            currentUser->move(dx, dy);
            currentUser->DecreaseHP(1); // 이동 시 체력 감소
            checkEncounter(map, *currentUser);
        }

        if (currentUser->GetHP() <= 0) {
            cout << "체력이 모두 소진되었습니다. 게임 오버!" << endl;
            break;
        }
    }

    delete currentUser;
    return 0;
}

void displayMap(const vector<vector<int>>& map, const User& user) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user.getY() && j == user.getX()) {
                cout << " U    |";
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

bool checkXY(int user_x, int user_y) {
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

void checkEncounter(vector<vector<int>>& map, User& user) {
    int posState = map[user.getY()][user.getX()];
    switch (posState) {
        case 1: // 아이템 발견
            cout << "아이템을 발견했습니다!" << endl;
            user.setItem(true);
            break;
        case 2: // 적
            if (user.hasItemState()) {
                cout << "적의 공격을 방어했습니다!" << endl;
                user.setItem(false);
            } else {
                cout << "적을 만나 체력이 감소합니다!" << endl;
                user.DecreaseHP(2);
            }
            break;
        case 3: // 포션
            cout << "포션을 발견하여 체력을 회복합니다!" << endl;
            user.IncreaseHP(5);
            break;
        case 4: // 목적지
            cout << "목적지에 도달했습니다. 승리!" << endl;
            exit(0);
    }
}
