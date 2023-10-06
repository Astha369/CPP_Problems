/* LeetCode Problem 343. Integer Break

Given an integer n, break it into the sum of k positive integers, where k >= 2, 
and maximize the product of those integers.
Return the maximum product you can get.

Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 
Constraints:

2 <= n <= 58

*/

class Solution {
public:
    int integerBreak(int n) {
        int ans = 1;
        if(n>=5) {
            while(n>0) {
                if(n>=3 && n!=4) {
                    ans *= 3;
                    n = n-3;
                } else {
                    ans *= n;
                    n=0;
                }
            }
        } else {
            ans *= (n/2);
            ans *= (n - (n/2));
        }
        return ans;
    }
};