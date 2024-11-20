#include <iostream>
using namespace std;

class Person
{
protected:
    string name;    // `protected`로 변경하여 상속 클래스에서 접근 가능
    string address; // `protected`로 유지
};

class Student : public Person // public 상속으로 변경
{
public:
    void SetAddress(string add)
    {
        address = add; // `protected` 멤버에 접근 가능
    }
    string GetAddress()
    {
        return address;
    }
    void SetName(string name) { this->name = name; } // `name` 접근 가능
    string GetName() { return name; }               // 이름 반환 함수 추가
};

int main()
{
    Student obj;
    obj.SetName("미수"); // 문자열 큰따옴표 수정
    obj.SetAddress("서울시 종로구 1번지");
    cout << "Name: " << obj.GetName() << endl;        // 이름 출력
    cout << "Address: " << obj.GetAddress() << endl; // 주소 출력
    return 0;
}
