#include<iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;      // Interface
    virtual ~Shape() {            // Virtual destructor
        cout << "Shape destroyed\n";
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing circle\n";
    }

    ~Circle() {
        cout << "Circle destroyed\n";
    }
};

int main() {
    Shape* s = new Circle();
    s->draw();
    delete s; // Calls both destructors due to virtual
}
