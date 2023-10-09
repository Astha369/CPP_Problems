#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"enter the string"<<endl;
    cin>>s;

    int l=0;
    int h= s.length()-1;

    while(h>l){
        if(s[l++] != s[h--]){
            cout<<"Entered string is not palindrom"<<endl;
            return 0;
        }
    }
    cout<<"entered string is the palindrom"<<endl;
}