//84. Largest Rectangle in Histogram
//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
//LeetCode Url:https://leetcode.com/problems/largest-rectangle-in-histogram/description/

//SOLUTION
class Solution {
/*private:
vector<int> nextsmallerelement(vector<int>arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top() >= curr]){
        s.pop();
        if(s.empty()){
            ans[i]=arr[i];
            s.push(arr[i]);
        }else{
        ans[i] = s.top();
        s.push(i);
        }
        } 
    }
    return ans;
}
vector<int> prevsmallerelement(vector<int>arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top() >= curr]){
        s.pop();
        if(s.empty()){
            ans[i]=arr[i];
            s.push(arr[i]);
        }else{
        ans[i] = s.top();
        s.push(i);
        }
        }
    }
    return ans;
}
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next = nextsmallerelement(heights,n);
        vector<int> prev(n);
        prev = prevsmallerelement(heights,n);
        int area = 0;
        for(int i=0;i<n;i++){
            int  l = heights[i];
            if(next[i] == -1){
              next[i]=n;
            }
            int b = next[i]-prev[i]-1;
            int newarea = l*b;
            area = max(area,newarea);
        }
        return area;
    }*/
     vector<int> nextsmall(vector<int>& arr,int n){
         stack<int> s;
    s.push(-1);
        vector<int> ans(n);
        for(int i=arr.size()-1;i>=0;i--){
           
            while(s.top()!=-1&&arr[s.top()]>=arr[i])
            s.pop();
            if(s.empty()){
            ans[i]=arr[i];
            s.push(arr[i]);
            }
            else
            {
            ans[i]=s.top();
            s.push(i);
            
            }
            
        }
        return ans;
    }
    vector<int> prevsmall(vector<int>& arr,int n){
         stack<int> s;
    s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
           
            while(s.top()!=-1&&arr[s.top()]>=arr[i])
            s.pop();
            if(s.empty()){
            ans[i]=arr[i];
            s.push(arr[i]);
            }
            else
            {
            ans[i]=s.top();
            s.push(i);
            
            }
            
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        int n =heights.size();
        vector<int> next(n);
        vector<int> prev(n);
        next=nextsmall(heights,n);
        prev=prevsmall(heights,n);
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1)
            next[i]=n;
             int b=next[i]-prev[i]-1;
             int newarea=l*b;
             area=max(newarea,area);
        }
        return area;
    }
};
