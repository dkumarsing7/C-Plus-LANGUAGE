#include<iostream>
using namespace std;

class Shape{
    public: int length = 10, breadth = 10, heigth = 5, radius = 2;
};

class Circle: public Shape{
    public: void area() {
        cout<<endl<<"Area of Circle is : " << 3.14*radius*radius;
    }
};
class Rectangle: public Shape{
    public: void area() {
        cout<<endl<<"Area of Rectangle is : " << length*breadth;
    }
};
class Triangle: public Shape{
    public: void area() {
        cout<<endl<<"Area of Triangle is : " << 0.5*length*heigth;
    }
};

int main(){
    Circle c;
    c.area();
    Rectangle r;
    r.area();
    Triangle t;
    t.area();
}