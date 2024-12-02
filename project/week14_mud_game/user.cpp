#include <iostream>
#include "user.h"

using namespace std;

// Magician 구현
Magician::Magician() : x(0), y(0), hp(20), hasItem(false), itemCnt(0) {}

int Magician::getX() const { return x; }
int Magician::getY() const { return y; }
bool Magician::hasItemState() const { return hasItem; }
int Magician::getItemCnt() const { return itemCnt; }

void Magician::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void Magician::setItem(bool state) {
    hasItem = state;
    if (state) {
        itemCnt++;
    }
}

void Magician::DecreaseHP(int dec_HP) { hp -= dec_HP; }
void Magician::IncreaseHP(int inc_hp) { hp += inc_hp; }
int Magician::GetHP() const { return hp; }

void Magician::displayStatus() const {
    cout << "Magician - 위치: (" << x << ", " << y << "), HP: " << hp;
    cout << ", 아이템 보유: " << (hasItem ? "예" : "아니오") << ", 획득한 아이템: " << itemCnt << endl;
}

void Magician::doAttack() const {
    cout << "Magician: 마법 사용!" << endl;
}

// Warrior 구현
Warrior::Warrior() : x(0), y(0), hp(25), hasItem(false), itemCnt(0) {}

int Warrior::getX() const { return x; }
int Warrior::getY() const { return y; }
bool Warrior::hasItemState() const { return hasItem; }
int Warrior::getItemCnt() const { return itemCnt; }

void Warrior::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void Warrior::setItem(bool state) {
    hasItem = state;
    if (state) {
        itemCnt++;
    }
}

void Warrior::DecreaseHP(int dec_HP) { hp -= dec_HP; }
void Warrior::IncreaseHP(int inc_hp) { hp += inc_hp; }
int Warrior::GetHP() const { return hp; }

void Warrior::displayStatus() const {
    cout << "Warrior - 위치: (" << x << ", " << y << "), HP: " << hp;
    cout << ", 아이템 보유: " << (hasItem ? "예" : "아니오") << ", 획득한 아이템: " << itemCnt << endl;
}

void Warrior::doAttack() const {
    cout << "Warrior: 베기 사용!" << endl;
}
