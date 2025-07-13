#include<iostream>
using namespace std;

class Animals{
    public:void eat(){
        cout<< "eating....."<<endl;
    }
};
class Dog: public Animals{
    public: void bark(){
        cout<< "barking....."<<endl;
    }
};

int main(){
    // Animals a;
    // a.eat();
    Dog d;
    d.eat();
    d.bark();
}