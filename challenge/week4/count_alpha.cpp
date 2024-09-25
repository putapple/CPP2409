#include <iostream>
using namespace std;

int main() {
    int vowel = 0;
    int consonant =0;
    cout << "영문자를 입력하고 ctrl + z를 치세요" << endl; 
    char ch; 

    while(cin >> ch) {
        bool err = ch;
        if (ch == ' '){
            cout << "잘못 입력하였습니다. 다시 입력하세요."<< endl ;
            break;
        }
        else {

        switch (ch) {
            case 'a': case 'e': case 'o': case 'i': case 'u':
                vowel= vowel +1;
                break;
            default:
                consonant= consonant+1;
                break;        
        }
     }

    }

    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;
    return 0;
}

