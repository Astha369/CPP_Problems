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

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int t = customers[0][0] + customers[0][1];
        double waitingTime = (double)t - (double)customers[0][0];
        for(int i = 1; i<n; i++) {
            if(t<customers[i][0]) {
                t = customers[i][0];
            }
            t += customers[i][1];
            waitingTime += (double)(t-customers[i][0]);
        }
        return waitingTime/(double)n;
    }
};