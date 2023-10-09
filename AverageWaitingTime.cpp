/* LeetCode Problem 1701. Average Waiting Time

There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrival(i), time(i)]:

 * arrival(i) is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
 * time(i) is the time needed to prepare the order of the ith customer.

When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits 
till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef 
prepares food for customers in the order they were given in the input.

Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.

Constraints:

 * 1 <= customers.length <= 105
 * 1 <= arrival(i), time(i) <= 104
 * arrival(i) <= arrival(i+1)
 
*/


// Solution= according to me we will find the time that each customer have to wait and add them up, and to find the average divide it by total no. of customers
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter number of customer : ";
    cin>>n;
    int arr[2][n];
    for(int i=0; i<n; i++){
        cin>>arr[0][i]>>arr[1][i];
    }

    int custtime[n];
    for(int i=0; i<n; i++){
        custtime[i]= arr[1][i]-arr[0][i];
    }
    int sumtime= 0;
    for(int i=0; i<n; i++){
        sumtime+= custtime[i];
    }

    int final= sumtime/n;
    cout<<final<<endl;
}