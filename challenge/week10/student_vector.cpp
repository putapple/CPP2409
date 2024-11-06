#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores;
    int score;
    int sum = 0;
    int count = 0;
    
    //점수 입력 받은 후 벡터에 집어넣기
    while(true) {
        cout << "성적을 입력하세요 (종료는 -1): ";
        cin >> score;
        if (score == -1) {
            break;
        }
        scores.push_back(score);
    }

    //벡터에 입력된 점수를 합한 후 count 1씩 올림.
    for (int i=0; i < scores.size(); ++i) {
        sum += scores[i];
        ++count;
    }


    //평균 계산후 출력
    if (count > 0) {
        double average = sum / count;
        cout << "평균 성적 : " << average << endl;
    }
    else { //점수를 입력하지 않았을 경우
        cout << "입력된 성적이 없습니다." <<endl;
    }
}