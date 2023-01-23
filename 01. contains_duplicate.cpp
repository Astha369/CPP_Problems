class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return false;
        }
        
        std::sort(nums.begin(), nums.end());
        int check = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == check) {
                return true;
            } else {
                check = nums[i];
            }
        }
        
        return false;
    }
};