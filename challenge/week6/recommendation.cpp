#include <iostream>
using namespace std;
#define NUM_USERS 3 //상수 선언
#define NUM_ITEMS 3

void initializePreferences ( int preferences[NUM_USERS][NUM_ITEMS] );
void findRecommendedItems ( const int Preferences[NUM_USERS][NUM_ITEMS] );
int userPreferences[NUM_USERS][NUM_ITEMS]; // 2개의 함수에 쓰이므로 전역변수 선언

int main(){

    initializePreferences(userPreferences);
    findRecommendedItems(userPreferences);

    return 0;
}

void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]) {
    for (int i = 0; i < NUM_USERS; ++i) {
        cout <<"사용자" << ( i + 1 ) << "의 선호도를 입력하세요 (";
        cout << NUM_ITEMS << "개의 항목에 대해): ";
        for (int j = 0 ; j < NUM_ITEMS; ++j) {
            cin >> userPreferences[i][j] ;
        } 
    }
}

void findRecommendedItems(const int Preferences[NUM_USERS][NUM_ITEMS]){
    for (int i=0; i < NUM_USERS; ++i) {
        int maxPreferences = 0;
        for (int j = 1; j < NUM_ITEMS; ++j) {
            if (userPreferences[i][j] > userPreferences[i][maxPreferences]) {
                maxPreferences = j;
            }
            else if (userPreferences[i][j] == userPreferences[i][maxPreferences]) {
                int randNUM = rand() % 2; //숫자가 같을 경우 2개 중 랜덤한 한개를 출력하기 위한 변수
                if(randNUM == 0) {
                    maxPreferences = j; //randNUM이 0이면 바뀌고, 1이면 유지되는 형식   
                }
            }
        }
        cout << "사용자" << (i + 1) << "에게 추천하는 항목: ";
        cout << (maxPreferences + 1) << std::endl;
    }
    


}
