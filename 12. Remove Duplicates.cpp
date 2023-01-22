class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // vector<int> expnum;
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                    nums.erase(nums.begin()+j);
                    j--;
                }
            }
        }
        return nums.size();
    }
};
