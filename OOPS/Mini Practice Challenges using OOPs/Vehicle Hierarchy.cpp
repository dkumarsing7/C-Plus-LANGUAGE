#include<iostream>
using namespace std;

// Task:
// Create a base class called Vehicle.
// The Vehicle class should have:
// A public constructor that prints "Vehicle constructor called."
// A public destructor that prints "Vehicle destructor called."
// A protected member variable brand (string).
class Vehicle{
public:
    Vehicle(){
        cout<<endl<< "Vehicle constructor called.\n";
    }
    ~Vehicle(){
        cout<<endl<< "Vehicle destructor called.\n";
    }
protected: string brand;
};

// Create a derived class called Car that inherits publicly from Vehicle.
// The Car class should have:
// A public constructor that takes a brand name, sets the inherited brand variable, and prints "Car constructor called."
// A public destructor that prints "Car destructor called."
// A public method honk() that prints "Honk! Honk!".
class Car: public Vehicle{
public:
    Car(string brand){
        this->brand = brand;
        cout<<"\nCar constructor called.\n";
    }
    ~Car(){
        cout<<"\nCar destructor called.\n";
    }
    void honk(){
        cout<<endl<<"Honk! Honk!\n";
    }
};

// In the main() function, create an object of the Car class. After creation, call its honk() method. Observe the order of constructor and destructor calls.
int main(){
    Car c("BMW");
    c.honk();
}
// Example Output:
// Generated code
// Vehicle constructor called.
// Car constructor called.
// Honk! Honk!
// Car destructor called.
// Vehicle destructor called.```
