#include<iostream>
using namespace std; 
class Person {
public:
    string name;

    // Constructor
    Person(string n) {
        name = n;
    }

    void showName() {
        cout << "Name is: " << name << endl;
    }
};
int main(){
    Person p("deepak");
    p.showName();
}