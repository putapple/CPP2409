#include <iostream>
#include "user.h"

using namespace std;

// User 기본 생성자
User::User() : x(0), y(0), hp(20), hasItem(false), itemCnt(0) {}

int User::getX() const { return x; }
int User::getY() const { return y; }
bool User::hasItemState() const { return hasItem; }
int User::getItemCnt() const { return itemCnt; }

void User::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void User::setItem(bool state) {
    hasItem = state;
    if (state) {
        itemCnt++;
    }
}

void User::DecreaseHP(int dec_HP) {
    hp -= dec_HP;
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int User::GetHP() const {
    return hp;
}

void User::displayStatus() const {
    cout << "현재 위치: (" << x << ", " << y << "), 체력: " << hp;
    cout << ", 아이템 보유: " << (hasItem ? "예" : "아니오") << ", 획득한 아이템: " << itemCnt << endl;
}

void User::doAttack() const {
    cout << "공격합니다!" << endl;
}

ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() << " 이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다";
    return os;
}

// Magician 구현
Magician::Magician() : User() {}

void Magician::doAttack() const {
    cout << "마법 사용!" << endl;
}

// Warrior 구현
Warrior::Warrior() : User() {}

void Warrior::doAttack() const {
    cout << "베기 사용!" << endl;
}
