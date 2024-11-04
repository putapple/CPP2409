#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
//잔액은 외부에서 직접 수정되지 않도록 private로 설정.
    double balance;
protected:
    string accountHolderName;
public:
    BankAccount(string name, double initialBalance){
        accountHolderName = name;
        balance = initialBalance;
    }

    //현재 잔액 조회 메소드 
    double getBalance() const {
        return balance;
    }
    //입금 메소드
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << amount << " deposited. Current balance: " << balance << endl;
        }
    }

    //출금 메소드
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount ;
            cout << amount << " withdrawn. Current balance:" << balance << endl;
        } 
        else {
            cout << " Insufficient balance or invalid amount!" << endl;
        }
    }
};

int main() {
    //계좌 생성
    BankAccount myAccount("Alice", 1000);

    //잔액조회 {public 메소드를 통해 접근}
    cout << " Initial Balance: " << myAccount.getBalance() << endl;

    //입금 및 출금 (public 메소드를 통해 접근)
    myAccount.deposit(500);
    myAccount.withdraw(200);

    //직접 접근 시도 (불가)
    //myAccount.Balance = 5000; //private 멤버에 접근 불가
    //myAccount.accountHolderName = "Bob"; //protected 멤버에 접근 불가

    return 0;
}