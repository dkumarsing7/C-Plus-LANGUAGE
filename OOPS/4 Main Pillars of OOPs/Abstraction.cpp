#include<iostream>
using namespace std;

class Shape{
    virtual void area() = 0; // this class is abstract
};
class Circle: public Shape{
    public: void area() override{
        cout<< "Area of circle ......" <<endl;
    }
};

int main(){
    Circle c;
    c.area();
    // Shape p ;  this can't be used to make object

}