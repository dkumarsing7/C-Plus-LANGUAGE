#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    set<int> s;
    // Basic Insertion and Iteration
    // Write a program to insert 5 integers into a set and print them in ascending order.
    s.insert(5);
    s.insert(4);
    s.insert(7);
    s.insert(3);
    s.insert(5);
    cout << endl <<"Elements in ascending order: ";
    for (auto elem : s) {
        cout << elem << " ";
    }
    cout<<endl;

    // Check for Element
    // Given a set of integers, write a function to check if a given number exists in the set.
    int target = 4;
    auto it = s.find(target); 
    if(it != s.end()) 
    {
        int index =  distance(s.begin(), it);
        cout << endl <<"element " << target << " is found at index " << index <<endl ;
    }
    else cout << endl << "element not found "<<endl;


    // Unique Elements
    // Accept n numbers from the user and use a set to print only unique numbers in sorted order.
    // cout<< endl <<"enter number of element to insert in set : ";int len; cin>>len;
    // set<int> set;
    // cout << endl << "enter your element : ";
    // for(int i=0; i<len; i++){
    //     int ele; cin>>ele; set.insert(ele);
    // }
    // cout<<endl <<endl << "elements of set (only unique number with sorted order) "<<endl;
    // for (auto elem : set) {
    //     cout << elem << " ";
    // }
    // cout<<endl;


    // Erase Elements
    // Write a program to erase a specific element from the set and display the updated set.
    int erase = 3;
    cout<<endl <<"erasing element "<<erase << " from first set " <<endl;
    s.erase(erase);
    for (auto elem : s) cout << elem << " ";
    cout<<endl;


    // Size of Set
    // Input elements into a set and print the total number of unique elements.
    cout<<endl << "size of first set is : " <<s.size()<< endl;


    // Set Union
    // Given two arrays, store their elements in two sets and print the union using set operations.
    int arr1[3] = {1,2,3};    
    int arr2[5] = {4,5,6,7,8};

    int l1 = sizeof(arr1) / sizeof(arr1[0]);
    int l2 = sizeof(arr2) / sizeof(arr1[0]);

    cout<< endl<< "these are our arrays ==>"<<endl<< "first array : ";
    for(int i=0; i<l1; i++) cout<<arr1[i]<<" ";
    cout<< endl <<"second array : ";
    for(int i=0; i<l2; i++) cout<<arr2[i]<<" ";cout<<endl; 

    set<int> first;
    set<int> second;
    set<int> union_set;

    int max;
    (l1 >= l2) ? max = l1 : max = l2;
    
    for(int i=0; i<max; i++){
        if ( i<l1 ) first.insert(arr1[i]); 
        if ( i<l2 ) second.insert(arr2[i]); 
    }
    cout<<endl <<"union of array using set are : ";
    set_union(first.begin(), first.end(),
                   second.begin(), second.end(),
                   std::inserter(union_set, union_set.begin()));
    for(int ele : union_set) cout<<ele<< " ";cout<<endl;

    // Descending Order
    // Store elements in a set and print them in descending order using a custom comparator..
    
}



