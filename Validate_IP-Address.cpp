/*
Example 1:

Input:
IPv4 address = 222.111.111.111
Output: 1
Explanation: Here, the IPv4 address is as
per the criteria mentioned and also all
four decimal numbers lies in the mentioned
range.

Example 2:

Input:
IPv4 address = 5555..555
Output: 0
Explanation: 5555..555 is not a valid
IPv4 address, as the middle two portions
are missing.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
    public:
    int isValid(string s) {
        int count = 0;
        string result = "";
    
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '.') {
                result.push_back(s[i]);
                if (!isdigit(s[i])) {
                    return false; 
                }
            } else {
                if ((result.length() > 1 && result[0] == '0') || result.empty() || stoi(result) < 0 || stoi(result) > 255) {
                    return false;
                }
                count++;
                result = ""; 
            }
        }
        if (count != 3 || (result.length() > 1 && result[0] == '0') || result.empty() || stoi(result) < 0 || stoi(result) > 255) {
            return false; 
        }
    
        return true; 
    }
};


int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.isValid(s)<<endl;
    }
}