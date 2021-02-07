#include <iostream>

class Memento{
    int balance;
public:
    Memento(int balance): balance(balance){}
    friend class BankAccount;
};


class BankAccount{
    int balance{0};
public:
    BankAccount(int balance): balance(balance){}

    Memento deposit(int amount){
        balance += amount;
        return {balance};
    }

    void restore(const Memento& m){
        balance = m.balance;
    }

    friend std::ostream& operator<<(std::ostream& os, const BankAccount &account){
        os << "balance : " << account.balance;
        return os;
    }
};

int main() {
    BankAccount ba{100};
    auto m1 = ba.deposit(50);
    std::cout << ba << std::endl;
    auto m2 = ba.deposit(50);
    std::cout << ba << std::endl;
    ba.restore(m1);
    std::cout << "Restoring old m1 : "<< ba <<"\n";
    ba.restore(m2);
    std::cout << "Restoring old m2 : "<< ba <<"\n";
    return 0;
}
