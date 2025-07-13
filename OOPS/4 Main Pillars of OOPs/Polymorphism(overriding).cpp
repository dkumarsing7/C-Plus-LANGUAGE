#include<iostream>
using namespace std;

class Animal{
    virtual void sound(){
        cout << "Some sound...... " << endl;
    }
};

class Cat: public Animal{
    public: void sound() override{
        cout << "Meow" << endl;
    }
};


int main(){
    Cat a;
    a.sound();
}