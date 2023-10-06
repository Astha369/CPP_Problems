/*                          QUICK SORT ALGORITHM
Problem Description:
Quick Sort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot.
Given an array arr[], its starting position is low (the index of the array) and its ending position is high(the index of the array).

Note: The low and high are inclusive.

Implement the partition() and quickSort() functions to sort the array.

Example 1:

Input: 
N = 5 
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9

Example 2:

Input: 
N = 9
arr[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7}
Output:
1 1 2 3 4 6 7 9 10
*/
//----------------------------------------------------------------------------------------------------------------------------------------
/*
Few Points to understand the solution:
1. The quickSort function is the primary entry point for the Quick Sort algorithm, and it accepts the array 'arr' along with the starting position 'low' and ending position 'high' as its input parameters.
2. Inside the quickSort function, our initial step involves verifying whether the 'low' value is smaller than 'high.' When this condition holds true, we can then proceed with the sorting operation.
3. We call the partition function to partition the array and obtain the pivot element's final sorted position.
4. Following the partitioning step, we initiate recursive calls to the quickSort function for the subarrays situated on both sides of the pivot. Specifically, we sort the left subarray spanning from 'low' to 'p - 1' and the right subarray spanning from 'p + 1' to 'high.'
5. The partition function serves as a component of the Quick Sort algorithm, taking the array 'arr' along with the starting position 'low' and ending position 'high' as its input parameters. Its role is to execute the crucial partitioning step.
6. We designate the pivot element as the element located at the 'low' position. Additionally, we set up two pointers, 'i' and 'j,' with 'i' starting at the 'low' position and 'j' starting at the 'high' position.
7. We iterate while i is less than j.
8. In the initial inner while loop, we continuously increment the 'i' pointer until we locate an element that is greater than the pivot. This process guarantees that all elements to the left of the pivot are either smaller or equal.

Subsequently, in the second inner while loop, we steadily decrement the 'j' pointer until we encounter an element that is less than or equal to the pivot. This step ensures that all elements positioned to the right of the pivot are greater or equal.
9. When 'i' is less than 'j,' we execute a swap operation between the elements positioned at indices 'i' and 'j' to ensure the preservation of the partitioning criteria.

Upon exiting the while loop, it signifies that 'i' and 'j' have intersected, signifying the discovery of the correct placement for the pivot element.

Subsequently, we perform a swap action, relocating the pivot element to the position indicated by 'j.' This action results in all elements to the left of the pivot (ranging from 'low' to 'j-1') being either smaller or equal, while all elements to the right of the pivot (ranging from 'j+1' to 'high') are greater.
10.Finally, we return the position j, which represents the correct sorted position of the pivot.
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
//Code
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
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int p = partition(arr,low,high);
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = high;
        int l=low;
        for(int i=low;i<=high-1;i++)
        {
            if(arr[i]<arr[pivot])
            {
                swap(arr[l],arr[i]);
                l++;
            }
        }
        swap(arr[l],arr[high]);
        return l;
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
        x.quickSort(arr,0,n-1);
        print(arr,n);
    }
    return 0;
}

