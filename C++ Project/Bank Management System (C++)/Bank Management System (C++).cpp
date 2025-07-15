#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;
class Account {
    int accountNumber;
    char name[50];
    double balance;
    char accountType;

public:
    void createAccount();
    void displayAccount() const;
    void modify();
    void deposit(double);
    void withdraw(double);
    void report() const;
    int getAccountNumber() const;
    double getBalance() const;
    char getAccountType() const;
};

void Account::createAccount() {
    cout << "\nEnter The Account No. : ";
    cin >> accountNumber;
    cout << "\nEnter The Name of The Account Holder : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nEnter Type of The Account (C/S) : ";
    cin >> accountType;
    accountType = toupper(accountType);
    cout << "\nEnter The Initial amount : ";
    cin >> balance;
    cout << "\n\nAccount Created..";
}

void Account::displayAccount() const {
    cout << "\nAccount No. : " << accountNumber;
    cout << "\nAccount Holder Name : ";
    cout << name;
    cout << "\nType of Account : " << accountType;
    cout << "\nBalance amount : " << balance;
}

void Account::modify() {
    cout << "\nAccount No. : " << accountNumber;
    cout << "\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nModify Type of Account : ";
    cin >> accountType;
    accountType = toupper(accountType);
    cout << "\nModify Balance amount : ";
    cin >> balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    balance -= amount;
}

void Account::report() const {
    cout << accountNumber << setw(10) << " " << name << setw(10) << " " << accountType << setw(6) << balance << endl;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}

char Account::getAccountType() const {
    return accountType;
}

void writeAccount();
void displaySp(int);
void modifyAccount(int);
void deleteAccount(int);
void displayAll();
void depositWithdraw(int, int);

void writeAccount() {
    Account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    ac.createAccount();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
    outFile.close();
}

void displaySp(int n) {
    Account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\nBALANCE DETAILS\n";
    while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
        if (ac.getAccountNumber() == n) {
            ac.displayAccount();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nAccount number does not exist";
}

void modifyAccount(int n) {
    bool found = false;
    Account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        if (ac.getAccountNumber() == n) {
            ac.displayAccount();
            cout << "\n\nEnter The New Details of account" << endl;
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(Account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}

void deleteAccount(int n) {
    Account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
        if (ac.getAccountNumber() != n) {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat", "account.dat");
    cout << "\n\n\tRecord Deleted ..";
}

void displayAll() {
    Account ac;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================\n";
    cout << "A/c no.      NAME           Type  Balance\n";
    cout << "====================================================\n";
    while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
        ac.report();
    }
    inFile.close();
}

void depositWithdraw(int n, int option) {
    double amount;
    bool found = false;
    Account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        if (ac.getAccountNumber() == n) {
            ac.displayAccount();
            if (option == 1) {
                cout << "\n\n\tTO DEPOSITE AMOUNT ";
                cout << "\n\nEnter The amount to be deposited: ";
                cin >> amount;
                ac.deposit(amount);
            }
            if (option == 2) {
                cout << "\n\n\tTO WITHDRAW AMOUNT ";
                cout << "\n\nEnter The amount to be withdraw: ";
                cin >> amount;
                double bal = ac.getBalance() - amount;
                if (bal < 0)
                    cout << "Insufficience balance";
                else
                    ac.withdraw(amount);
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}

int main() {
    char ch;
    int num;
    do {
        cout << "\n\n\t\t\t\tBANK MANAGEMENT SYSTEM";
        cout << "\n\n\t\t\t\t     ::MAIN MENU::\n";
        cout << "\n\t\t\t\t1. NEW ACCOUNT";
        cout << "\n\t\t\t\t2. DEPOSIT AMOUNT";
        cout << "\n\t\t\t\t3. WITHDRAW AMOUNT";
        cout << "\n\t\t\t\t4. BALANCE ENQUIRY";
        cout << "\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
        cout << "\n\t\t\t\t6. CLOSE AN ACCOUNT";
        cout << "\n\t\t\t\t7. MODIFY AN ACCOUNT";
        cout << "\n\t\t\t\t8. EXIT";
        cout << "\n\n\t\t\t\tSelect Your Option (1-8): ";
        cin >> ch;
        switch (ch) {
        case '1':
            writeAccount();
            break;
        case '2':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            depositWithdraw(num, 1);
            break;
        case '3':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            depositWithdraw(num, 2);
            break;
        case '4':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            displaySp(num);
            break;
        case '5':
            displayAll();
            break;
        case '6':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            deleteAccount(num);
            break;
        case '7':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            modifyAccount(num);
            break;
        case '8':
            cout << "\n\n\tThanks for using bank managemnt system";
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (ch != '8');
    return 0;
}