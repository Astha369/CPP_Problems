#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int>& s, int target){
    //base case
    if(s.empty() || (!s.empty() && s.top()>target)){
        s.push(target);
        return;
    }
    
    int topElement=s.top();
    s.pop();
    insertSorted(s,target);

    //backtracking
    s.push(topElement);
}


void sortStack(stack<int>&s){
    //base case
    if(s.empty()){
        return;
    }
    int topElement=s.top();
    s.pop();
    sortStack(s);
    insertSorted(s,topElement);
}

int main(){
    stack<int>st;
    st.push(22);
    st.push(3);
    st.push(10);
    st.push(2);
    st.push(413);
    st.push(9);

    sortStack(st);
     cout<<"Print stack after sorting"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}