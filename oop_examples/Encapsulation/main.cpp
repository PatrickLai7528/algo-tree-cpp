#include <iostream>
#include <string>

using namespace std;

class BankAccount1
{
public:
    string name;
    double balance;
};

class BankAccount2
{
private:
    string name;
    double balance;

public:
    BankAccount2(string accName, double initial)
    {
        name = accName;
        balance = (initial >= 0) ? initial : 0; // 初始金額不能為負
    }

    void deposit(double amount)
    {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance!" << endl;
    }

    double getBalance() const
    {
        return balance;
    }

    string getName() const
    {
        return name;
    }
};

int main()
{
    // 沒有封裝
    BankAccount1 a;
    a.name = "Alice";
    a.balance = -1000; // ❌ 不合理！餘額不應該是負的！

    BankAccount2 b("Alice", 1000);
    b.deposit(500);
    b.withdraw(2000);  // ❌ 會輸出錯誤提示

    cout << b.getName() << " has $" << b.getBalance() << endl;
}
