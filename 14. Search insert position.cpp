class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int p=nums.size();
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]>=target)
            {
                p=i;
                break;
            }
        }
return p;
    }
};
