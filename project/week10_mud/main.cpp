#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
const int initialHealth = 20; // 초기 체력

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkEncounter(int map[][mapX], int user_x, int user_y, int &health, bool &hasItem);
void movePlayer(int &user_x, int &user_y, int dx, int dy, int map[][mapX], int &health, bool &hasItem); // 이동 함수 추가

// 메인 함수
int main() {
    int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                            {1, 0, 0, 2, 0},
                            {0, 0, 0, 0, 0},
                            {0, 2, 3, 0, 0},
                            {3, 0, 0, 0, 2} };

    int user_x = 0; // 유저의 가로 위치
    int user_y = 0; // 유저의 세로 위치
    int health = initialHealth; // 유저의 체력
    bool hasItem = false; // 아이템 보유 여부를 나타내는 플래그

    // 초기 상태 출력
    cout << "게임을 시작합니다!" << endl;
    cout << "현재 체력: " << health << endl;
    displayMap(map, user_x, user_y);

    while (true) {
        string user_input = "";
        cout << "명령어를 입력하세요 (up, down, left, right, map, exit): ";
        cin >> user_input;

        if (user_input == "up") {
            movePlayer(user_x, user_y, 0, -1, map, health, hasItem);
        } else if (user_input == "down") {
            movePlayer(user_x, user_y, 0, 1, map, health, hasItem);
        } else if (user_input == "left") {
            movePlayer(user_x, user_y, -1, 0, map, health, hasItem);
        } else if (user_input == "right") {
            movePlayer(user_x, user_y, 1, 0, map, health, hasItem);
        } else if (user_input == "map") {
            displayMap(map, user_x, user_y);
        } else if (user_input == "exit") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다. up, down, left, right, map, exit 중에서 선택하세요." << endl;
            continue;
        }

        // 체력 확인
        cout << "현재 체력: " << health << endl;
        if (health <= 0) {
            cout << "체력이 모두 소진되었습니다. 게임 오버!" << endl;
            break;
        }

        // 목적지 도착 확인
        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }
    return 0;
}

// 이동하려는 위치가 유효한지 확인 후 이동하는 함수
void movePlayer(int &user_x, int &user_y, int dx, int dy, int map[][mapX], int &health, bool &hasItem) {
    int new_x = user_x + dx;
    int new_y = user_y + dy;
    if (!checkXY(new_x, mapX, new_y, mapY)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
    } else {
        user_x = new_x;
        user_y = new_y;
        cout << (dy == -1 ? "위" : dy == 1 ? "아래" : dx == -1 ? "왼쪽" : "오른쪽") << "으로 한 칸 이동합니다." << endl;
        health--; // 이동 시 체력 감소
        checkEncounter(map, user_x, user_y, health, hasItem); // 만남 이벤트 확인
        displayMap(map, user_x, user_y);
    }
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
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
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}

// 아이템, 포션, 적을 만났을 때의 처리를 담당하는 함수
void checkEncounter(int map[][mapX], int user_x, int user_y, int &health, bool &hasItem) {
    int posState = map[user_y][user_x];
    switch (posState) {
        case 1: // 아이템
            cout << "아이템을 발견했습니다! 다음 적과의 전투에서 피해를 입지 않습니다." << endl;
            hasItem = true; // 아이템 획득 시 다음 적 피해 방지
            map[user_y][user_x] = 0; // 아이템을 발견한 후 빈 공간으로 변경
            break;
        case 2: // 적
            if (hasItem) {
                cout << "적을 만났지만, 아이템 덕분에 피해를 입지 않았습니다!" << endl;
                hasItem = false; // 아이템 사용 후 초기화
            } else {
                cout << "적을 만났습니다! 체력이 2 감소했습니다." << endl;
                health -= 2; // 아이템이 없을 경우에만 피해
            }
            // 적은 위치에 그대로 남아있음
            break;
        case 3: // 포션
            cout << "포션을 발견하여 체력이 5 증가했습니다." << endl;
            health += 5;
            // 포션은 위치에 그대로 남아있음
            break;
    }
}