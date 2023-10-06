/*
            Problem Statement
    There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

*/

// ----------------------------------------------------------SOLUTION----------------------------------------------------------


class Solution 
{
public:
    int PivotIndex(vector<int>arr)
    {
        int s =0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;

        while(s<=e)
        {
            if (s==e){
                //single element
                 return s;
            }
            if(mid <= e && arr[mid]>arr[mid+1] ){
                return mid;
            }
            if(mid - 1>= s && arr[mid]<arr[mid-1] ){
                return mid-1;
            }
            if(arr[s]>arr[mid]){
                e = mid -1;
            }else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }
    int BinarySearch(vector<int>arr,int s,int e,int target)
    {
            int mid = s + (e-s)/2;

        while(s<=e)
        {
            if(arr[mid]==target)
            {
                return mid;
            }
            if(arr[mid]>target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;  }
        return -1;
    }
    int search(vector<int>& nums, int target) 
    {
        int pi = PivotIndex(nums);
        int ans = 0;
        if(target>=nums[0] && target <= nums[pi]){
            //leftsearch from 0 index to pi
            ans = BinarySearch(nums,0,pi,target);
        }
        
        else 
        {
            //right search from pi+1 to nums.size()-1
            ans = BinarySearch(nums,pi+1,nums.size()-1,target);
        }

        return ans;
    }
};