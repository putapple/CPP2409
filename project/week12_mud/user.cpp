#include <iostream>
#include "user.h"

using namespace std;

User::User() : x(0), y(0), hp(20), hasItem(false), itemCnt(0) {} // 체력 기본값 20으로 설정, itemCnt는 아이템 획득한 횟수로 사용하기 때문에 0으로 설정.

int User::getX() const { return x; }
int User::getY() const { return y; }
bool User::hasItemState() const { return hasItem; }
int User::getItemCnt() const { return itemCnt; }

void User::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void User::setItem(bool state) {
    hasItem = state; //아이템을 획득 시 다음 적을 만날 때 마다 사용가능, 소모 여부는 main.cpp 내에서 처리.
    if (state) {
        itemCnt++; // 아이템 획득 시 개수 증가
    }
}

// 체력 감소 메서드
void User::DecreaseHP(int dec_HP) {
    hp -= dec_HP;
}

// 체력 증가 메서드
void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

// 현재 체력 반환 메서드
int User::GetHP() const {
    return hp;
}

// 상태 출력
void User::displayStatus() const {
    cout << "현재 위치: (" << x << ", " << y << "), 체력: " << hp;
    cout << ", 아이템 보유: " << (hasItem ? "예" : "아니오") << ", 획득한 아이템: " << itemCnt << endl;
}

// << 연산자 중복 정의
ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() << " 이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다";
    return os;
}