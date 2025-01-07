#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string UserName;
    int accountNum;
    double balance;

public:
    BankAccount(string name, int num, double bal) {
        UserName = name;
        accountNum = num;
        balance = bal;
    }
    friend void showInfo(BankAccount account);
protected:
    double getBalance() const {
        return balance;
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }
    
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdrawal or insufficient funds!" << endl;
        }
    }
};
void showInfo(BankAccount account) {
    cout << "Account Holder Name : " << account.UserName << endl;
    cout << "Account Number  : " << account.accountNum << endl;
    cout << "Balance  : " << account.balance << endl;
}
class Person : public BankAccount {
public:
    Person(string name, int num, double bal) : BankAccount(name, num, bal) {
    }

    void CheckBalance() {
        cout << "Updated Balance : " << getBalance() << endl;
    }
    
    void makeDeposit(double amount) {
        deposit(amount);
        CheckBalance();
    }
    
    void makeWithdrawal(double amount) {
        withdraw(amount);
        CheckBalance();
    }
};
int main() {
    Person person1("Shrabani Mondal", 23103003, 5000.0);
    showInfo(person1);
    
    person1.makeDeposit(1000.0);
    person1.makeWithdrawal(2000.0);
    
    return 0;
} 

