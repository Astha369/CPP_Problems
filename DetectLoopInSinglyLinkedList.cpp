/*                                  DETECT LOOP IN A SINGLY LINKED LIST 
PROBLEM DESCRIPTION:
Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

Example 1:

Input:
N = 3
value[] = {1,3,4}
x(position at which tail is connected) = 2
Output: True
Explanation: In above test case N = 3.
The linked list with nodes N = 3 is
given. Then value of x=2 is given which
means last node is connected with xth
node of linked list. Therefore, there
exists a loop.
Example 2:

Input:
N = 4
value[] = {1,8,3,4}
x = 0
Output: False
Explanation: For N = 4 ,x = 0 means
then lastNode->next = NULL, then
the Linked list does not contains
any loop.
*/
//-----------------------------------------------------------------------------------------
/*
SOLUTION DESCRIPTION:
First, we start by checking whether the 'head' or 'head->next' is null. If either of them is null,
it indicates that there is no loop, so we return false. Next, we create an unordered set and initialize
a 'curr' variable with the head of the list. We traverse the list by moving 'curr' forward until it becomes null.
During this traversal, if we encounter a node that is already in the set, we return true, indicating
the presence of a loop. Finally, if we reach the end of the list without finding a loop, we return false.
*/
//CODE:
//FUNCTION TO DETECT LOOP 
bool detectLoop(Node* head)
    {
       if(head==NULL || head->next==NULL)
       {
           return false;
       }
       unordered_set<Node*>s;
       Node *curr=head;
       while(curr!=NULL)
       {
           if(s.find(curr)!=s.end()) return true;
           else s.insert(curr);
           curr=curr->next;
       } return false;
    }