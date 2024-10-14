#include <iostream>
#include <string>
using namespace std;

//소문자로 변환하는 함수
string toLowerStr(string str) {
    for (int i = 0; i < str.length(); ++i){
        str[i] = tolower(str[i]); // 모든 문자열 배열을 소문자로 변환
    }
    return str;
}

//대문자로 변환하는 함수
string toUpperStr(string str) {
    for (int i = 0; i < str.length(); ++i){
        str[i] = toupper(str[i]); // 모든 문자열 배열을 대문자로 변환
    }
    return str;
}
// 소대문자 구분없이 해밍거리 구하는 함수
int calcHammingDist(string s1, string s2) {
    
    // 입력받은 문자열을 모두 소문자로 변환
    s1 = toLowerStr(s1); 
    s2 = toLowerStr(s2);

    int count = 0;
    for (int i = 0; i< s1.length(); ++i) {
        if (s1[i] != s2[i]){
            //문자열이 틀릴 시 count 증가 
            count++;
        }
    }
    return count;
}

int main() {
    string s1, s2;
    //문자열 길이가 틀리면 계속 입력받게 하기 위해 while문으로 입력받음
    while (true) {
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;

        //문자열 길이가 틀릴 시 다시 while문으로 돌아감
        if (s1.length() != s2.length()) {
            cout<< "문자열의 길이가 다릅니다. 다시 시도하세요" << endl;

        }
        //문자열 길이가 같으면 다음 단계로 진행
        else {
            break;
        }
    }
    
    int count = calcHammingDist(s1, s2); //함수를 통해 게산된 count값 받기

    cout << "해밍 거리는 " << count << endl;

    return 0;
}
