class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
    return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));
    }
};