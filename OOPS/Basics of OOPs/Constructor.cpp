#include<iostream>
using namespace std; 
class Person {
public:
    string name;

    // Constructor
    Person(string n) {
        name = n;
    }
    Person() {
        cout<< "I am a parent constructor\n";
    }
    ~Person() {
        cout<< "I am a parent destructor\n";
    }

    void showName() {
        cout << "Name is: " << name << endl;
    }
};

class Student: public Person {
public:
    Student() {
        cout<< "I am a child constructor\n";
    }
    ~Student() {
        cout<< "I am a child destructor\n";
    }
};
int main(){
    // Person p("deepak");
    // p.showName();
    Student p;
}