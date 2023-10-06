/*
                            RADIX SORT ALGORITHM
PROBLEM DESCRIPTION:
Given an array arr[] of size N, use Radix Sort Algorithm to sort arr[] in ascending order.

Example 1:

Input :
N = 5
arr[] = {1, 9, 345, 2}

Output: 1 2 9 345

Example 2:

Input :
N = 10
arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}

Output: 1 2 3 4 5 6 7 8 9 10
*/
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Few concepts to understand the RADIX SORT Algorithm


Radix Sort capitalizes on the principle of place value, operating under the assumption that sorting numbers digit by digit will eventually lead to a completely sorted list. Radix Sort 
offers various approaches, including Least Significant Digit (LSD) Radix Sort and Most Significant Digit (MSD) Radix Sort, to achieve this sorting process.


Few Steps:
Step 1: Identify the maximum element within the array, in this case, 469, which consists of three digits. Consequently, we will iterate three times, each iteration focusing on one 
significant place.
Step 2: Arrange the elements according to the digits in the unit's place (let's call it X=0). To accomplish this, we employ a stable sorting method, such as counting sort, to organize the
digits present in each significant place.
Step 3: Sort the elements based on the tens place digits.
Step 4: Sort the elements based on the hundreds place digits.
Result: The array is now sorted in Ascending order
*/
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
void countSort(int arr[],const int &n,const int &exp) {
    int count[10] = {0};
    for(int i = 0; i < n; i++) count[(arr[i]/exp) % 10]++;
    for(int i = 1; i < 10; i++) count[i] += count[i - 1];
    int output[n];
    for(int i = n - 1; i >= 0; i--) {
        output[count[(arr[i]/exp) % 10] - 1] = arr[i];
        count[(arr[i]/exp) % 10]--;
    }
    for(int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) 
{ 
   int maxElement = INT_MIN;
   for(int i = 0; i < n; i++) maxElement = max(arr[i], maxElement);
   for(int exp = 1; maxElement/exp > 0; exp *= 10)
        countSort(arr, n, exp);
} 
int main()
{
    int n,t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
        cin>>arr[i];
        radixSort(arr,n);
        print(arr,n);
        cout<<endl;
    }
    return 0;
}

