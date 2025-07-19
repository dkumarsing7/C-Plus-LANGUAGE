#include<iostream>
using namespace std;

// Task:
// 1.  Create a base class named `Shape`.
// 2.  The `Shape` class should have a pure virtual function called `calculateArea()` which returns a `double`. This will make `Shape` an abstract class.
class Shape{
public:
    virtual double calculateArea() = 0;

};

// 3.  Create two derived classes: `Circle` and `Rectangle`.

//     *   `Circle` should have a private member `radius`. Its constructor should initialize the radius. It should override the `calculateArea()` function to return the area of the circle (π * r²).
class Circle: public Shape{
    float radius;
public:
    Circle(float radius) {
        this->radius = radius;
    }
    double calculateArea(){
        return 3.14*radius*radius;
    }
};
//`Rectangle` should have private members `width` and `height`. Its constructor should initialize these values. It should override the `calculateArea()` function to return the area of the rectangle (width * height).
class Rectangle: public Shape{
    float width, height;
public:
    Rectangle(float width, float height) {
        this->width = width;
        this->height = height;
    }

    double calculateArea(){
        return width*height;
    }
};
// 4.  In the `main()` function, demonstrate polymorphism:
//     *   Create a `Shape` pointer.
//     *   Dynamically create a `Circle` object and assign its address to the `Shape` pointer. Call `calculateArea()` and print the result.
//     *   Dynamically create a `Rectangle` object and assign its address to the same `Shape` pointer. Call `calculateArea()` again and print the result.
int main(){
    Circle c(5);
    cout<<"\nArea of Circle: " << c.calculateArea();
    Rectangle r(4,5);
    cout<<"\n\nArea of Rectangle: " << r.calculateArea();
}
//     *   Remember to deallocate the dynamic memory.

// Area of Circle: 78.5398
// Area of Rectangle: 50