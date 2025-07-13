#include<iostream>
using namespace std;

class Print{
    public: void show(int x){
        cout << "Integer ==> " << x << endl;
    }
    public: void show(string x){
        cout << "Integer ==> " << x << endl;
    }
};


int main(){
    Print p;
    p.show(22);
    p.show("number");   
}