// Last updated: 4/20/2025, 11:27:09 AM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int k = 1;
        
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] >= target) 
                return i;		
        }
        return nums.size();
    }
};