#include <iostream>
#include <vector>
using namespace std;

class BankAccount{
public:
    BankAccount(){}
    void deposit(int amount){
        balance += amount;
        cout    << "deposited " << amount
                << ", balance is " << balance << endl;
    }
    bool withdraw(int amount){
        if(balance-amount >= overdraft_limit){
            balance -= amount;
            cout    << "withdrew " << amount
                    << ", balance is " << balance << endl;
            return true;
        }
        cerr <<"Overdraft limit exceed!" << endl;
        return false;
    }
    friend ostream& operator<<(ostream& os, const BankAccount& ba){
        os << "balance is " << ba.balance;
        return os;
    }
    ~BankAccount()=default;
private:
    int balance{0};
    int overdraft_limit{-500};
};

class Command{
public:
    bool succeeded;
    virtual void call() = 0;
    virtual void undo() = 0;
};
// we create a command object, that handles modification
class BankAccountCommand: public Command{
    BankAccount& act_on_baccount;
    int amount;
public:
    enum Action{ deposit, withdraw} action;
    BankAccountCommand(BankAccount &bankAccount, Action action, int amount)
    : act_on_baccount(bankAccount), action(action), amount(amount) {
        succeeded=false;
    }

    void call() override {
        switch(action){
            case deposit:
                act_on_baccount.deposit(amount);
                succeeded = true;
                break;
            case withdraw:
                succeeded = act_on_baccount.withdraw(amount);
                break;
        }
    }

    void undo() override {
        // do opposite action of call
        if(!succeeded) return;

        switch(action){
            case deposit:
                act_on_baccount.withdraw(amount);
                break;
            case withdraw:
                act_on_baccount.deposit(amount);
                break;
        }
    }
};

//int main() {
//    BankAccount bankAccount;
//    vector<BankAccountCommand> commands{
//            BankAccountCommand{bankAccount, BankAccountCommand::deposit,100},
//            BankAccountCommand{bankAccount, BankAccountCommand::withdraw,50},
//            BankAccountCommand{bankAccount, BankAccountCommand::deposit,200},
//            BankAccountCommand{bankAccount, BankAccountCommand::withdraw,900},
//    };
//    cout << bankAccount << endl;
//    for(auto& cmd : commands){
//        cmd.call();
//        cout << bankAccount << endl;
//    }
//
//    for(auto it = commands.rbegin(); it!=commands.rend(); it++){
//        it->undo();
//    }
//    return 0;
//}
