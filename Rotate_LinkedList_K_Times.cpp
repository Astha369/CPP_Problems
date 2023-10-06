#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
//left rotation by k times
/*
class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node *ptr=head,*head1;
        int count=0;
        while(ptr!=NULL){
            count++;
            ptr=ptr->next;
        }
        if(count==k || k%count==0)
        return head;
        count=k%count;
        ptr=head;
        while(ptr->next){
            if(count==1){
                head1=ptr->next;
                ptr->next=NULL;
                ptr=head1;
                count--;
            }
            else{
                count--;
                ptr=ptr->next;
            }
        }
        ptr->next=head;
        head=head1;
        return head;
    }
};*/
  //right_rotation by k times
class Solution {
public:
    Node* rotateRight(Node* head, int k) {
        if(head==NULL || head->next==NULL)
        return head;
        Node *head1,*ptr=head,*temp;
        int count=0;
        while(ptr){
            count++;
            ptr=ptr->next;
        }
        if(k%count==0)
        return head;
        ptr=head;
        count=count-(k%count);
        // if(head->next->next==NULL)
        // count-=1;
        while(ptr->next!=NULL){
            if(count==1){
                head1=ptr->next;
                ptr->next=NULL;
                ptr=head1;
                count--;
                }
                else{
            count--;
            ptr=ptr->next;
                }
        }
        ptr->next=head;
        head=head1;
        return head;
    }
};
void print(Node *head){
      Node *ptr=head;
      while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
      }
      cout<<endl;
      return;
}
int main( ){
int n,num,k;
cin>>n;
Node *head,*tail,*temp;
cin>>num;
head=new Node(num);
tail=head;
for(int i=0;i<n-1;i++){
      cin>>num;
      tail->next=new Node(num);
      tail=tail->next;
}
cin>>k;
Solution ob;
ob. rotateRight(head,k);
print(head);
return 0;
}
