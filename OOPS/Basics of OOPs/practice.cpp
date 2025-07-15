#include<iostream>
using namespace std;

class Teacher{
    public: 
        Teacher (int x){
            number = x;
            cout<<number;
        }
    int number;

};
int main(){
    Teacher t(2);
    Teacher te(2);

}