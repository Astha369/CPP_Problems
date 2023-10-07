#include<iostream>
using namespace std;

class ListNode {
    public:
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        ListNode* tail = head;
        for(int i=1;i<len;i++){
            tail = tail->next;
        }
        if(k == len) return head;
        if(k>len) k%=len;
        
        int kk = len-k;
        temp = head;
        for(int i=1;i<kk;i++){
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
int main(){
    ListNode* head = new ListNode(10);
    int n;
    cout<<"Enter value of n: ";
    cin>>n;
     cout<<"Enter value of ListNodes: \n";
    ListNode* temp = head;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode* t = new ListNode(x);
        temp->next = t;
        temp = temp->next;
    }
    head = head->next;
    int k;
    cout<<"Enter value of k: ";
    cin>>k;
    head = rotateRight(head,k);
    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
}
