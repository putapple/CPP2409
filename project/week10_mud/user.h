#ifndef USER_H
#define USER_H

class User {
private:
    int x, y;         // 유저의 위치
    int hp;           // 유저의 체력 (private로 설정)
    bool hasItem;     // 아이템 보유 여부

public:
    User();           // 기본 생성자

    int getX() const;
    int getY() const;
    bool hasItemState() const;

    void move(int dx, int dy);
    void setItem(bool state);

    // 체력 관련 메서드
    void DecreaseHP(int dec_HP);
    void IncreaseHP(int inc_hp);
    int GetHP() const;

    void displayStatus() const;
};

#endif // USER_H