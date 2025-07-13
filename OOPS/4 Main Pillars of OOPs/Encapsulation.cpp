#include<iostream>
using namespace std;
class Student{
    private: int marks = 22;
    public: void setMarks(int m){
        if(m>=0 && m<=100) marks = m;
    }
    int getMarks(){
        return marks;
    }
};
int main(){
    Student s;
    s.setMarks(23);
    int result = s.getMarks();
    cout<< result;
    return 0;
}