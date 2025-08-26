#include<bits/stdc++.h>
using namespace std;

void passByValue(int a){ // pass by value
    a = 20;
};
void passByReference(int &a){ // pass by reference (using alias)
    a = 20;
};
int main(){
    int a = 10;
    int* ptr = &a;
    cout<<endl<< "a = " << a << endl <<endl << "dereferencing ptr = " << *ptr << endl;

    passByValue(a);
    cout<< "pass by value a = " << a << endl;
    passByReference(a);
    cout<<endl<< "pass by reference a = " << a << endl;
}