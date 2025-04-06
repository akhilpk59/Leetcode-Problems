#include<iostream>
#include<string>

using std::string;

class BankAccount{
    string AccountNumber= "";
    double balance = 0;

    public:
    void deposit(double amount){
        balance += amount;
    }
    void withdraw(double amount){
        if ((balance - amount)<0) {
            std::cout<<"You have insufficient funds in your account, the amount of Rs. "<<amount<<"/- cannot be withdrawn at this time."<<std::endl;
            return;
        }
        balance -= amount;
    }
    void getBalance(){
        std::cout<<"The current balance in your account " <<AccountNumber<<" is : Rs. "<<balance<<"/- only."<<std::endl;
    }
    void setAccountNumber (string account){
        AccountNumber = account;
    }
    string getAccountNumber(){
        return AccountNumber;
    }
};

int main(){
    BankAccount B1;
    string s;
    std::getline(std::cin,s);
    B1.setAccountNumber(s);
    B1.deposit(150000);
    B1.getBalance();
    B1.withdraw(100000);
    B1.getBalance();
    B1.withdraw(50000);
    B1.getBalance();
    B1.withdraw(10000);
    B1.getBalance();
    return 0;
}