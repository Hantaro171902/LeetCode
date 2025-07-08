// Last updated: 7/8/2025, 11:57:56 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long count = 0, start = -1, mini = -1, maxi = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) start = i;
            if (nums[i] == maxK) maxi = i;
            if (nums[i] == minK) mini = i;
            // The earliest valid subarray ends at i and starts after leftBound
            int validStart = min(mini, maxi);
            if (validStart > start) {
                count += validStart - start;
            }
        }
        return count;
    }
};