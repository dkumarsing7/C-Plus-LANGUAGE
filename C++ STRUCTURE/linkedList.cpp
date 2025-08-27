#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  Node(int val){
    data = val;
    next = NULL;
  }
};
class List{
  Node* head;
  Node* tail;

  public:
    List(){
    head = tail = NULL;
    }
    void push_front(int val){
      Node* newNode = new Node(val);
      if(head == NULL){
        head = tail = newNode;
        return;
      }else{
        newNode->next = head;
        head = newNode;
      }
    }
    
    
    void push_back(int val){
      Node* newNode = new Node(val);
      if(head == NULL){
        head = tail = newNode;
        return;
      }else{
        tail->next = newNode;
        tail = newNode;
      }
    }
    void pop_front(){
      if(head == NULL){
        cout<<endl<<"Linked List is empty"<<endl;
        return;
      }
      Node* temp = head;
      head = head->next;
      temp->next = NULL;
      
      delete temp;
    }
    void pop_back(){
      if(head == NULL){
        cout<<endl<<"Linked List is empty"<<endl;
        return;
      }
      Node* temp = head;
      while(temp->next != tail){
        temp = temp->next;
      }
      temp->next = NULL;
      delete tail;
      tail = temp;
    }

    void insert(int val, int pos){
      if(pos<0){
        cout<<endl<<"not a valid position to insert"<< endl;
        return;
      }
      if(pos==0){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode; return;
      }

       Node* temp = head;
       for(int i=1; i<pos && temp != NULL; i++){
        temp = temp->next;
       }
       if(temp == NULL){
        cout <<pos<< " Position out of range" << endl;
        return;
       }
       Node* newNode = new Node(val);
       newNode->next = temp->next;
       temp->next = newNode;
    }

    void printLL(){
      Node* temp = head;
      while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
      }
      cout<<"NULL"<<endl;
    }
};

int main(){
  List li;

  li.push_back(1);
  li.push_back(2);
  li.push_back(3);
  // li.printLL();
  // li.pop_front();
  // li.printLL();
  // li.pop_back();
  li.insert(10, 0);
  li.insert(10, 2);
  li.insert(10, 5);
  li.insert(10, 8);
  li.printLL();
}