#include <iostream>
using namespace std;

class Time {
private:
    int hour;      //0-23
    int minute;     //0-59

public:
    Time(int h, int m){}
    void IncHour(){
        ++hour;
        if (hour > 23){
            hour = 0 ;
        }
    }

    void Print(){
        cout << hour << ":" << minute << endl;
    }


    int GetHour() {
        return hour;
    }
    
    int GetMinute() {
        return minute;
    }
    
    void SetHour(int h) { 
        hour = h;
    }
    
    void SetMinute(int m) {
        minute = m;
    }
};
int main(){
        Time a{0,0};

        a.SetHour(6);
        a.SetMinute(30);

        a.Print();
        return 0;
    }
