// problem description:
// You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

// Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: steps = 3, arrLen = 2
// Output: 4
// Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
// Right, Left, Stay
// Stay, Right, Left
// Right, Stay, Left
// Stay, Stay, Stay
// Example 2:

// Input: steps = 2, arrLen = 4
// Output: 2
// Explanation: There are 2 differents ways to stay at index 0 after 2 steps
// Right, Left
// Stay, Stay
// Example 3:

// Input: steps = 4, arrLen = 2
// Output: 8

// approach: Define a modulus value (mod) to handle the modulo operation to avoid integer overflow. It's set to 1000000007, which is commonly used in competitive programming.

// Calculate maxPosition, which represents the maximum position the pointer can reach. This value is the minimum of half the number of steps (steps / 2) and arrLen - 1.

// Create a 2D array dp to store the number of ways to reach each position at each step. It has dimensions [steps + 1][maxPosition + 1].

// Initialize dp[0][0] to 1, as there is one way to stay at position 0 after 0 steps.

// Loop through each step i from 1 to steps.

// For each step i, loop through each possible position j from 0 to maxPosition.

// For each position, initialize dp[i][j] with the number of ways to stay at the same position as the previous step, which is dp[i - 1][j].

// If the current position j is greater than 0, add the number of ways to reach it by moving left (subtracting 1 from j).

// If the current position j is less than the maximum position, add the number of ways to reach it by moving right (adding 1 to j).

// Take the modulo mod for each update to prevent integer overflow.

// Finally, the result is stored in dp[steps][0], which represents the number of ways to reach the initial position (position 0) after taking the specified number of steps.
// solution : 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int mod = 1000000007;
        
        int maxPosition = std::min(steps / 2, arrLen - 1);
        
        // Create a 2D vector dp to store the number of ways to reach a specific position at each step.
        vector<vector<int>> dp(steps + 1, vector<int>(maxPosition + 1, 0));
        
        // Initialize the number of ways to stay at position 0 after 0 steps to 1.
        dp[0][0] = 1;
        
        // Loop through the number of steps.
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= maxPosition; j++) {
                // Initialize the number of ways to stay at the current position with the number of ways to stay at the same position in the previous step.
                dp[i][j] = dp[i - 1][j];
                
                // If the current position is greater than 0, add the number of ways to reach it by moving left.
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                
                // If the current position is less than the maximum position, add the number of ways to reach it by moving right.
                if (j < maxPosition) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                }
            }
        }
        
        // The final result is stored in dp[steps][0], representing the number of ways to reach the initial position after taking 'steps' steps.
        return dp[steps][0];
    }
};