/*                    MERGE SORT ALGORITHM 
Problem Description:
Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
Example 1:

Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9
Example 2:

Input:
N = 10
arr[] = {10 9 8 7 6 5 4 3 2 1}
Output:
1 2 3 4 5 6 7 8 9 10
*/
//------------------------------------------------------------------------------------------
/*
Some steps to understand its solution:
1. Begin by dividing the given array into two equal subarrays at the midpoint, and continue this process recursively until you have smaller, sorted subarrays.

2. At each step of the recursion, merge the two sorted subarrays together. Merging two sorted arrays takes O(n) time, where n is the total number of elements.

3. To facilitate the merging process, create two temporary arrays to hold the values from the subarrays. This allows for direct updating of values back into the original array.

4. Keep track of two pointers, each positioned at the beginning of one of the two subarrays, as well as a pointer at the start of the left subarray.

5. Compare the values pointed to by the iterators in the two subarrays, and select the smaller value to write it back into the original array.

6. If there are any remaining elements in the left subarray, add them to the original array. Then, if there are any remaining elements in the right subarray, add those as well. The order in which you add them doesn't matter since only one of these subarrays will have elements left to be added at this point in the process.

*/
//-------------------------------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
//Function to print the array
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<"\n";
}
class solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int left = m - l + 1, right = r - m;
    int leftArr[left], rightArr[right];
    for(int i=0;i<left;i++)
        leftArr[i] = arr[l + i];
    for(int i=0;i<right;i++)
        rightArr[i] = arr[m+1+i];
    int i = 0, j = 0, k = l;
    while(i < left && j < right){
        if(leftArr[i] < rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while(i < left)
        arr[k++] = leftArr[i++];
    while(j < right)
        arr[k++] = rightArr[j++];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l < r){
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
    }
};
int main()
{
    int n,t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n+1];
        for(i=0;i<n;i++)
        cin>>arr[i];
        solution x;
        x.mergeSort(arr,0,n-1);
        print(arr,n);
    }
    return 0;
}



