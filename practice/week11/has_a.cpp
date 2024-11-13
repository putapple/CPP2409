#include <iostream>
#include <string>
using namespace std;

class Date {
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    // 복사 생성자 추가
    Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}

    void Print() {
        cout << year << "." << month << "." << day << endl;
    }
};

class Person {
    string name;
    Date birth;
public:
    // Person 생성자에서 Date 객체를 복사 초기화
    Person(string n, const Date& d) : name(n), birth(d) {}

    void Print() {
        cout << name << ":";
        birth.Print();
        cout << endl;
    }
};

int main() {
    Date d{ 1998, 3, 1 };
    Person p{ "김철수", d };
    p.Print();
    return 0;
}
