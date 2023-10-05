/*
Given two strings s1 and s2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: s1 = "abcde", s2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: s1 = "abc", s2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: s1 = "abc", s2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

i. 1 <= s1.length, s2.length <= 1000
ii. s1 and s2 consist of only lowercase English characters.
*/
//------------------------------------------------------------------------------------------------------------------------------------------
//SOLUTION
#include<bits/stdc++.h>
using namespace std;
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int dp[x+1][y+1];
        for(int i=0;i<=x;i++)
        dp[i][0]=0;
        for(int i=0;i<=y;i++)
        dp[0][i]=0;
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        return dp[x][y];
    }
};
int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        Solution ob;
        cout<<ob.lcs(n,m,s1,s2)<<endl;
    }
    return 0;
}