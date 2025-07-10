// Last updated: 7/10/2025, 11:10:53 PM
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (abs(i - j) >= indexDifference && 
                    abs(nums[i] - nums[j]) >= valueDifference) {
                        return {i,j};

                }
            }
        }
        return {-1, -1};
    }
};