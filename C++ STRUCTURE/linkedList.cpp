#include<bits/stdc++.h>
using namespace std;

class Node{
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
};

