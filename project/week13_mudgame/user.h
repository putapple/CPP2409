#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
public:
    virtual ~User() {}
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual bool hasItemState() const = 0;
    virtual int getItemCnt() const = 0;

    virtual void move(int dx, int dy) = 0;
    virtual void setItem(bool state) = 0;

    virtual void DecreaseHP(int dec_HP) = 0;
    virtual void IncreaseHP(int inc_hp) = 0;
    virtual int GetHP() const = 0;

    virtual void displayStatus() const = 0;
    virtual void doAttack() const = 0;

    friend ostream& operator<<(ostream& os, const User& user);
};

class Magician : public User {
private:
    int x, y, hp, itemCnt;
    bool hasItem;

public:
    Magician();
    ~Magician() override {}
    int getX() const override;
    int getY() const override;
    bool hasItemState() const override;
    int getItemCnt() const override;

    void move(int dx, int dy) override;
    void setItem(bool state) override;

    void DecreaseHP(int dec_HP) override;
    void IncreaseHP(int inc_hp) override;
    int GetHP() const override;

    void displayStatus() const override;
    void doAttack() const override;
};

class Warrior : public User {
private:
    int x, y, hp, itemCnt;
    bool hasItem;

public:
    Warrior();
    ~Warrior() override {}
    int getX() const override;
    int getY() const override;
    bool hasItemState() const override;
    int getItemCnt() const override;

    void move(int dx, int dy) override;
    void setItem(bool state) override;

    void DecreaseHP(int dec_HP) override;
    void IncreaseHP(int inc_hp) override;
    int GetHP() const override;

    void displayStatus() const override;
    void doAttack() const override;
};

#endif // USER_H
