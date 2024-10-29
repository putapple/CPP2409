#include <iostream>
using namespace std;

const int numCell= 5; // 보드 크기
char** board; // 동적 할당을 위한 보드 배열

// 좌표의 유효성 확인 함수
bool isValidMove(int x, int y) {
    if (x >= numCell || y >= numCell || x < 0 || y < 0) {
        cout << "잘못된 입력입니다. 범위를 벗어났습니다." << endl;
        return false;
    }
    if (board[x][y] != ' ') {
        cout << "이미 놓인 위치입니다. 다른 위치를 선택하세요." << endl;
        return false;
    }
    return true;
}

// 승리 조건 확인 함수
bool checkWin(char currentUser) {
    // 가로 체크
    for (int i = 0; i < numCell; i++) {
        bool rowWin = true;
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser) {
                rowWin = false;
                break;
            }
        }
        if (rowWin) {
            cout << "가로 " << i + 1 << "번째 줄에서 이겼습니다!" << endl;
            return true;
        }
    }

    // 세로 체크
    for (int i = 0; i < numCell; i++) {
        bool colWin = true;
        for (int j = 0; j < numCell; j++) {
            if (board[j][i] != currentUser) {
                colWin = false;
                break;
            }
        }
        if (colWin) {
            cout << "세로 " << i + 1 << "번째 줄에서 이겼습니다!" << endl;
            return true;
        }
    }

    // 왼쪽 위에서 오른쪽 아래로의 대각선 체크
    bool diagWin1 = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][i] != currentUser) {
            diagWin1 = false;
            break;
        }
    }
    if (diagWin1) {
        cout << "왼쪽 위에서 오른쪽 아래로의 대각선으로 이겼습니다!" << endl;
        return true;
    }

    // 오른쪽 위에서 왼쪽 아래로의 대각선 체크
    bool diagWin2 = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][numCell - i - 1] != currentUser) {
            diagWin2 = false;
            break;
        }
    }
    if (diagWin2) {
        cout << "오른쪽 위에서 왼쪽 아래로의 대각선으로 이겼습니다!" << endl;
        return true;
    }

    return false; // 승리 조건을 만족하지 않는 경우
}

int main() {
    // 보드 할당 및 초기화
    board = new char*[numCell];
    for (int i = 0; i < numCell; i++) {
        board[i] = new char[numCell];
        for (int j = 0; j < numCell; j++) {
            board[i][j] = ' ';
        }
    }

    int turn = 0; // 플레이어 차례 확인을 위한 변수
    char currentUser; // 현재 플레이어의 돌
    int x, y; // 좌표 입력 변수

    // 게임 진행
    while (true) {
        // 현재 플레이어 결정
        switch (turn % 3) {
        case 0:
            currentUser = 'X';
            break;
        case 1:            
            currentUser = 'O';
            break;
        case 2:
            currentUser = 'H';
            break;
        }
        cout << (turn % 3) + 1 << "번 유저(" << currentUser << ")의 차례입니다." << endl;

        // 좌표 입력
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 유효한 좌표인지 확인
        if (!isValidMove(x, y)) continue;

        // 돌 놓기
        board[x][y] = currentUser;

        // 현재 보드 출력
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                cout << board[i][j];
                if (j < numCell - 1) cout << " | ";
            }
            cout << endl;
            if (i < numCell - 1) cout << string(numCell * 4 - 1, '-') << endl;
        }

        // 승리 체크
        if (checkWin(currentUser)) {
            cout << (turn % 3) + 1 << "번 유저(" << currentUser << ")가 승리했습니다!" << endl;
            break;
        }

        // 보드가 꽉 찼는지 확인
        bool boardFull = true;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    boardFull = false;
                    break;
                }
            }
            if (!boardFull) break;
        }

        if (boardFull) {
            cout << "보드가 꽉 찼습니다. 무승부입니다!" << endl;
            break;
        }

        turn++;
    }

    // 보드 동적 해제
    for (int i = 0; i < numCell; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}