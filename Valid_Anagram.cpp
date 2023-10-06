#include<bits/stdc++.h>
using namespace std;

// It has the boolean func. which first check the number of characters (length) of string, and if they are equal then it check each character of the strings.
// we will sort the strings and they will be sorted according to their ascai value.
bool anagram(string s1, string s2){
    int n1= s1.length();
    int n2= s2.length();

    if(n1 != n2){
        return false;
    }
    else{
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
    
        for(int i=0; i<n1; i++){
            if(s1[i] != s2[i]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    string s1, s2;
    cout<<"enter the first string : ";
    cin>>s1;
    cout<<"enter the second string : ";
    cin>>s2;

    if(anagram( s1, s2)){
        cout<<"both the entered strings are anagram"<<endl;;
    }
    else{
        cout<<"entered strings are not anagram"<<endl;
    }
}