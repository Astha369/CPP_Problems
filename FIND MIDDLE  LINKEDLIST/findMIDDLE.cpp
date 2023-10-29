#include<iostream>
using namespace std;

class Node{
    public:

  int val;
  Node* next;

  Node( int data){

    val =  data;
    next = NULL;

  }
};

class linklist{
    public:

    Node* head;

    linklist(){
        head = NULL;

    }
  
 void  insertattail(int value){
   
   Node* new_node = new Node (value);
 if(head==NULL){
    head = new_node;
 }
Node* temp = head;
while(temp->next != NULL){
    temp = temp->next;

}
temp->next = new_node;
 new_node->next= NULL;


 }

 void display(){
    Node* temp = head;
    while (temp!= NULL){
cout<<temp->val<< "->";
temp = temp->next;

    }
    cout << "NULL"<< endl;
}
};
Node* middleelement(Node* &head){
    Node* slow = head;
    Node* fast = head;

//STOPPING CONDITITON IF EVEN AND ODD HONGYE TAB     
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

    }
    return slow;

}
 
int main()
{
linklist ll;
    ll.insertattail(1);
    ll.insertattail(2);
    ll.insertattail(3);
    ll.insertattail(4);
    ll.insertattail(5);
    ll.display();
    Node* middlenode =  middleelement(ll.head);
    cout<<middlenode->val<<endl;

 return 0;
}