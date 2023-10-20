#include <bits/stdc++.h>
using namespace std;
int main(){
    //we define two variables for tracking of values
    int first=1;
    int second=1;
int answer;
    int n;
    cin>>n;
    if(n==0||n==1) return n;
    else{
        for(int i=2;i<=n;i++)
    {
        answer=first+second;
        first=second;
        second=answer;
    }
    
}}