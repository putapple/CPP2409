#include <iostream>
using namespace std;

int main() {
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y ;

    //초기화
    for (x = 0; x < numCell; x++) {
        for (y =0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }
    // 차례 결정
    int k = 0;
    char currentUser = 'X';
    while(true) {
        switch (k%2) {
            case 0:
                cout << "첫번째 유저(x)의 차례입니다. -> ";
                currentUser = 'X';
                break;
            case 1:
                cout << "두번째 유저(o)의 차례입니다. -> ";
                currentUser = 'O';
                break;
        }
    

        // 좌표 입력 이 때 y와 x를 바뀌어서 x,y 좌표 바뀌는 것을 수정
        cout << "(x,y) 좌표를 입력하세요: " ;
        cin >> y >> x;


        // 좌표 유효성 체크
        if (x >= numCell || y>= numCell) {
            cout<< y << ', ' << x << ": " ;
            cout<< "x 와 y 둘 중 하나가 칸을 벗어났습니다." << endl;
            continue;
        }
        if (board[x][y] != ' ' ) {
            cout << y << ' ' << x << ": 이미 돌이 놓아져있습니다." << endl;
            continue;
        }
        
        board[x][y] = currentUser;

        //보드판 만들기. 반복문이 굳이 2개나 반복될 필요가 없어 수정
        for (int i = 0; i < numCell; i++) {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
            if (i < numCell - 1) {
                cout << "---|---|---" << endl;
            }
        }

        k++;// 턴 증가

        //승리 코드
        bool isWin = false;
        for ( int i =0 ; i < numCell; i++){
            if ( board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
                cout<< "가로에 모두 돌이 놓였습니다!";
                isWin = true;
            }
            if ( board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
                cout<< "세로에 모두 돌이 놓였습니다!";  
                isWin = true;               
            }
        }
        if ( board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
                cout<< "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!";  
                isWin = true;               
            }
        if ( board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
                cout<< "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!";  
                isWin = true;               
            }

        if (isWin == true){
            cout << k % 2 + 1 <<"번 유저( " << currentUser << ")의 승리입니다!" <<endl;
            cout << "종료합니다!" << endl;
            break;
        }
        // 칸이 다 찼는지 체크
        int checked = 0;
        for (int i = 0; i <numCell; i++) {
            for (int j = 0 ; j <numCell; j++){
                if(board[i][j] == ' '){
                    checked++;
                }
            }
        }
        if (checked== 0) {
            cout << "모든 칸이 다 찼습니다. 종료합니다" <<endl;
            break;
        }

    }
    return 0;   
}
