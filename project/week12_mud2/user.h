#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    int x, y;         // 유저의 위치
    int hp;           // 유저의 체력
    bool hasItem;     // 아이템 보유 여부
    int itemCnt;      // 획득한 아이템 개수

public:
    User();           // 기본 생성자

    int getX() const;
    int getY() const;
    bool hasItemState() const;
    int getItemCnt() const;

    void move(int dx, int dy);
    void setItem(bool state);

    void DecreaseHP(int dec_HP);
    void IncreaseHP(int inc_hp);
    int GetHP() const;

    void displayStatus() const;
    void doAttack() const; // 공격 함수 (기본)

    friend ostream& operator<<(ostream& os, const User& user);
};

// Magician 클래스
class Magician : public User {
public:
    Magician();
    void doAttack() const; // 마법 사용
};

// Warrior 클래스
class Warrior : public User {
public:
    Warrior();
    void doAttack() const; // 베기 사용
};

#endif // USER_H
