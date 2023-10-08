#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* tail = head;

        // Calculate the length of the linked list and find the tail node
        while (tail->next) {
            len++;
            tail = tail->next;
        }

        // Make it a circular linked list
        tail->next = head;

        // Calculate the new head and tail positions
        k = len - (k % len);
        while (k > 0) {
            tail = tail->next;
            k--;
        }

        // Update head and tail pointers
        head = tail->next;
        tail->next = nullptr;

        return head;
    }
};
