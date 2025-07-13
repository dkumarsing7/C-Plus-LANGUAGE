#include<iostream>
using namespace std;

class Car{
    public: string brand; int speed;
    void drive(){
        cout<< brand<< " is running at speed of "<< speed<< "KM/H"<< endl;
    }
};
int main (){
    Car c;
    c.brand = "BMW";
    c.speed = 22;
    c.drive();
}