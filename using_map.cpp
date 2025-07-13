// Student Marks Record
#include<iostream>
#include<map>
using namespace std;



auto show(map<string, int>& student){
    cout<<endl<<"----------------------------------------------"<<endl<<endl;
    for(auto ele : student) cout<<ele.first<< " "<<ele.second<<endl;
    cout<<endl<<"----------------------------------------------"<<endl; 
    
    
}

auto add(map<string, int>& student){
    cout<<"enter a name of student : ";
    string name; cin>>name;
    cout<<"enter a marks : ";
    int marks; cin>>marks;
    auto it = student.find(name);
    if(it != student.end()){
        cout<<endl<<name<<" already listed in the record with marks as below"<<endl<<it->first<<" "<<it->second<<endl;
        string ask; cout<<endl<<"Enter yes to update his marks no to return to home : ";cin>>ask;
        if (ask == "yes" || ask == "y") {
            student[name] = marks;
            cout<<endl<<name<<" successfully registered in the record"<<endl;
        }
        
    }
    else {
        student[name] = marks;
        cout<<name<<" successfully registered in the record"<<endl;
    }
    // menu(student);
}

auto update(map<string, int>& student){
    cout<<"enter a name of student : ";
    string name; cin>>name;
    cout<<"enter a marks : ";
    int marks; cin>>marks;
    auto it = student.find(name);
    if(it != student.end()){
        student[name] = marks;
        cout<<endl<<name<<" updated successfully in the record"<<endl;
    }
    else cout<<endl<<"no such student found in the record";
    // menu(student);
}

auto erase(map<string, int>& student){
    cout<<endl<<"Enter name to erase from record : ";string name;cin>>name;
    auto it = student.find(name);
    if(it != student.end()){
        student.erase(it);cout<<endl<<name<<" has been removed from the record"<<endl;
    }else cout<<endl<<"no such record found"<<endl;
    // menu(student);
}
bool menu(map<string, int>& student){
    cout<<endl<<"+++++++++++++++++++++++++++++++++++++++++++"<<endl<<"+++++++++++++++++++++++++++++++++++++++++++"<<endl<<"1. TO ADD STUDENT.\n2. TO REMOVE STUDENT\n3. TO UPDATE STUDENT\n4. TO VIEW RECORD\n5. TO EXIT\n"<<"+++++++++++++++++++++++++++++++++++++++++++"<<endl<<"+++++++++++++++++++++++++++++++++++++++++++"<<endl<<"\nEnter your choice : ";
    int ch; cin>>ch;
    switch(ch){
        case 1:
            add(student);break;
        case 2: 
            erase(student);break;
        case 3: 
            update(student);break;
        case 4: 
            show(student);break;
        default: 
            cout<<"Thankyou for using me \nExiting...................................";
            return false;
    }return  true;
}
int main(){
// Input: A list of student names with their marks.
    map<string, int> student = {
        {"stu1", 10},
        {"stu2", 12},
        {"stu3", 22},
        {"stu4", 32}
    };
     while (true) {
        if (!menu(student)) break;
    }
}

// Tasks:
// a) Add/Update marks for a student.
// b) Delete a student record.
// c) Print marks of a given student.