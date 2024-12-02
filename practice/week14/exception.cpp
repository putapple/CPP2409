#include <iostream>
using namespace std;

int main() {
    int pizza_slice = 0;
    int persons = -1;
    int slices_per_person = 0;

    try
    {
        cout << "피자 조각수를 입력하시오: ";
        cin >> pizza_slice;
        cout << "사람수를 입력하시오: ";
        cin >> persons;
        if (persons == 0)
            throw persons;
        slices_per_person = pizza_slice / persons;
        cout << "한 사람당 피자는 " << slices_per_person << "입니다." << endl;

    }
    catch(int a)
    {
        cout << "사람이 " << 0 << "명 입니다." << endl;
    }
    return 0;    
}