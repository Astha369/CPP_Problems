/* LeetCode Problem 1381. Design a Stack With Increment Operation

Design a stack that supports increment operations on its elements.

Implement the CustomStack class:

    * CustomStack(int maxSize) - Initializes the object with maxSize which is the maximum number of elements in the stack.
    * void push(int x) - Adds x to the top of the stack if the stack has not reached the maxSize.
    * int pop() - Pops and returns the top of the stack or -1 if the stack is empty.
    * void inc(int k, int val) - Increments the bottom k elements of the stack by val. If there are less than k elements in the
      stack, increment all the elements in the stack.

Example 1:

Input
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
Output
[null,null,null,2,null,null,null,null,null,103,202,201,-1]

*/

#include<iostream>
#include<vector>
using namespace std;

class CustomStack {
public:
    vector<int> stack;
    int size, top = -1;
    
    CustomStack(int maxSize) {
        stack.resize(maxSize);
        size = maxSize;
    }
    
    void push(int x) {
        if(top >= size-1) return;
        stack[++top] = x;
    }
    
    int pop() {
        if(top == -1) {
            return -1;
        }
        return stack[top--];
    }
    
    void increment(int k, int val) {
        int n = size;
        if(k<n) n = k;
        for(int i=0; i<n; i++) {
            stack[i] += val;
        }
    }
};

// Based on example 1 input ONLY
int main() {
    CustomStack* obj = new CustomStack(3);
    obj->push(1);
    obj->push(2);
    int a = obj->pop();
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->increment(5,100);
    obj->increment(2,100);
    int a = obj->pop();
    int a = obj->pop();
    int a = obj->pop();
    int a = obj->pop();
}
