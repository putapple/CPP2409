#include <iostream>
#include "user.h"

using namespace std;

User::User() : x(0), y(0), hp(20), hasItem(false) {} // 체력 기본값 20으로 설정

int User::getX() const { return x; }
int User::getY() const { return y; }
bool User::hasItemState() const { return hasItem; }

void User::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void User::setItem(bool state) {
    hasItem = state;
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
    cout << ", 아이템 보유: " << (hasItem ? "예" : "아니오") << endl;
}