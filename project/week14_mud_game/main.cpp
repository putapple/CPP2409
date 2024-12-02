#include <iostream>
#include <vector>
#include "user.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>
using namespace std;

const int mapX = 5;
const int mapY = 5;

void displayMap(const vector<vector<int>>& map, const User& user);
bool checkXY(int user_x, int user_y);
void checkEncounter(vector<vector<int>>& map, User& user);

// 파일에서 맵 로드 함수 추가
void loadMap(const string& filename, vector<vector<int>>& map) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "맵 파일을 열 수 없습니다!" << endl;
        exit(1);
    }

    map.clear();
    string line;
    while (getline(file, line)) {
        vector<int> row;
        size_t pos = 0; // 현재 문자열 위치
        while (pos < line.size()) {
            // 공백을 찾음
            size_t next_space = line.find(' ', pos);
            if (next_space == string::npos) {
                next_space = line.size();
            }

            // 현재 위치에서 숫자를 파싱
            string number = line.substr(pos, next_space - pos);
            row.push_back(stoi(number));

            // 다음 숫자로 이동
            pos = next_space + 1;
        }

        map.push_back(row);
    }

    if (map.size() != 5 || map[0].size() != 5) { // 예제 크기 확인
        cerr << "맵 크기가 잘못되었습니다!" << endl;
        exit(1);
    }

    file.close();
}
// 명령어 유효성 검사 함수 ***12-02 예외 처리 
void validateCommand(const string& command) {
    vector<string> validCommands = {"up", "down", "left", "right", "attack", "info", "exit"};
    if (find(validCommands.begin(), validCommands.end(), command) == validCommands.end()) {
        throw invalid_argument("잘못된 명령어입니다: " + command);
    }
}

int main() {
    vector<vector<int>> map;
    loadMap("map.txt", map);

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

    // 게임 시작 ***12-02 명령어 잘못입력하는 예외 처리함*** 
    while (true) {
        displayMap(map, *currentUser);
        cout << "명령어를 입력하세요 (up, down, left, right, attack, info, exit): ";
        string command;
        cin >> command;

        try {
            // 명령어 유효성 검사
            validateCommand(command);

            if (command == "exit") {
                cout << "게임 종료!" << endl;
                break;
            }

            if (command == "info") {
                currentUser->displayStatus();
                continue;
            } else if (command == "attack") {
                currentUser->doAttack();
                continue;
            }

            int dx = 0, dy = 0;
            if (command == "up") dy = -1;
            else if (command == "down") dy = 1;
            else if (command == "left") dx = -1;
            else if (command == "right") dx = 1;

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
        } catch (const invalid_argument& e) {
            cerr << e.what() << endl;
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
