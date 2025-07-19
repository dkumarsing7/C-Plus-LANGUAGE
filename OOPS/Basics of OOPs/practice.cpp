#include<iostream>
using namespace std;

class Teacher{
public: 
    string name;
    Teacher (string name){
        this->name = name;
    }
    void info(){
        cout<< "my name is : " << name << endl;
    }

};
int main(){
    Teacher t("depeak");
    t.info();

}