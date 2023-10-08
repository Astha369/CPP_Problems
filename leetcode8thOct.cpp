#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>curr(n+1,INT_MIN);
        vector<int>prev(n+1,INT_MIN);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int p=nums1[i-1]*nums2[j-1];
                curr[j]=max({p, prev[j],curr[j-1], p+max(0,prev[j-1])});
            }
        swap(curr, prev);
        }
    return prev[n];
    }
};