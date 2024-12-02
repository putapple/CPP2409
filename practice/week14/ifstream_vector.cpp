#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// TempData 클래스 정의
class TempData {
public:
    int hour; // 시간
    double temperature; // 온도

    // 생성자
    TempData(int h, double t) : hour(h), temperature(t) {}
};

int main() {
    ifstream is("temp.txt"); // 파일 열기
    if (!is) {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        return 1;
    }

    vector<TempData> temps; // 데이터를 저장할 벡터
    int hour;
    double temperature;

    // 파일에서 데이터를 읽어 객체로 저장
    while (is >> hour >> temperature) {
        temps.emplace_back(hour, temperature); // TempData 객체 생성 및 추가
    }

    // 저장된 데이터를 출력
    for (const TempData& t : temps) {
        cout << t.hour << "시: 온도 " << t.temperature << endl;
    }

    return 0;
}
