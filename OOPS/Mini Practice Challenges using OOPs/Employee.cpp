#include<iostream>
using namespace std;

class Employee {
    public:int salary = 10000; int bonus =1000;
};
class Manager: public Employee{
    public: void calculateSalary(){
        salary+=bonus;
        cout<<endl<< "Manager's salary is : "<< salary<<endl;
    }
};
class Intern: public Employee{
    public: void calculateSalary(){
        cout<<endl<< "Intern's salary is : "<< salary<<endl;      
    }
};

int main(){
    Manager M1;
    M1.calculateSalary();
    Intern I1;
    I1.calculateSalary();
    cout<<endl;

}