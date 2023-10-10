#include <bits/stdc++.h>
using namespace std;
class ListNode{
   public:
   int val;
   ListNode *next;
   ListNode(int data){
      val = data;
      next = NULL;
   }
};
ListNode *make_list(vector<int> v){
   ListNode *head = new ListNode(v[0]);
   for(int i = 1; i<v.size(); i++){
      ListNode *ptr = head;
      while(ptr->next != NULL){
         ptr = ptr->next;
      }
      ptr->next = new ListNode(v[i]);
   }
   return head;
}
void print_list(ListNode *head){
   ListNode *ptr = head;
   cout << "[";
   while(ptr->next){
      cout << ptr->val << ", ";
      ptr = ptr->next;
   }
   cout << "]" << endl;
}
class Solution {
   public:
   ListNode* rotateRight(ListNode* head, int k) {
      if(!head) return head;
      int len = 1;
      ListNode* tail = head;
      while(tail->next){
         len++;
         tail = tail->next;
      }
      tail->next = head;
      k %= len;
      ListNode* newHead = NULL;
      for(int i = 0; i < len - k; i++){
         tail = tail->next;
      }
      newHead = tail->next;
      tail->next = NULL;
      return newHead;
   }
};
main(){
   Solution ob;
   vector<int> v = {1,2,3,4,5,6,7,8,9};
   ListNode *head = make_list(v);
   print_list(ob.rotateRight(head, 4));
}