// Last updated: 7/8/2025, 11:58:12 PM
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            result[i] = nums[nums[i]];
        }
        
        return result;
    }
};