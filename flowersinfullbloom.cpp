//      FLOWERS IN FULL BLOOM

// problem description:
// You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.

// Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.

// Example-1
// Input: flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
// Output: [1,2,2,2]
// Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
// For each person, we return the number of flowers in full bloom during their arrival.


// Example-2
// Input: flowers = [[1,10],[3,3]], people = [3,3,2]
// Output: [2,2,1]
// Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
// For each person, we return the number of flowers in full bloom during their arrival.

// Approach-1(Brute force): the first approach involves traversing the flowers vector for every element of people . this will thus invlove a time complexity of O(n^2) and will thus fail on complex test cases having large input values.
// Approach-2(Optimised approach using upper and lower bound function): Start by extracting the start and end days of flowers' bloom periods and store them in separate vectors s and e.

// Sort the s and e vectors to have the days in ascending order.

// Create a vector ans to store the answers for each person.

// For each person's bloom day a from the people array, find where a falls in the s and e vectors using binary search.

// Calculate the number of flowers that started blooming before a (c) and the number of flowers that finished blooming before or on a (d).

// Subtract d from c to determine how many flowers were in full bloom at the specific day a for this person.

// Store the answer in the ans vector for this person.

// Repeat this process for all people in the people array.

// Finally, return the ans vector containing answers for each person.

// the code to the solution:
#include<bits/stdc++.h>
using namespace std;
vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end;
        for(auto& t : flowers){
            start.push_back(t[0]);
            end.push_back(t[1]);
            
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int> res;
        for(int t : people){
            int started =upper_bound(start.begin(),start.end(),t)-start.begin();
            int ended =lower_bound(end.begin(),end.end(),t)-end.begin();
            res.push_back(started-ended);
        }
        return res;
        
}