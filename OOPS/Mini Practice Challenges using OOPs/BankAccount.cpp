#include<iostream>
using namespace std;

class BankAccount {
    public: string name; int balance;

    BankAccount (){
        string user; cout << endl <<"Enter your name : "; cin>>name;
        int initial_fund; cout << endl << "Enter your initial fund : "; cin>>initial_fund;
        name = user;
        balance = initial_fund;
    }

    public: void deposit(int amount){
        balance+=amount;
        cout<<endl<< "depositing......."<<endl <<name << " Your Updated balance is " << balance <<endl;
    }
    public: void withdrawal(int amount){
        balance-=amount;
        cout<<endl<< "withdrawaling......." <<endl <<name << " Your Updated balance is " << balance <<endl;
    }
    public: void check_balance(){
        cout<<endl<< "Your balance is "<< balance;
    }
};

int main(){
    
    BankAccount user;
    user.deposit(20);
    user.withdrawal(20);
    user.check_balance();
    cout<<endl;
    BankAccount user2;
    user2.deposit(2000);
    user2.withdrawal(20);
    user.check_balance();
    cout<<endl;
}