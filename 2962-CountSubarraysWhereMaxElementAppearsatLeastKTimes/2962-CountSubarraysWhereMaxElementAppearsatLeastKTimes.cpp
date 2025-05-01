// Last updated: 5/1/2025, 10:18:32 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        long long result = 0;
        int left = 0, freq = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == maxVal)
                freq++;

            while (freq >= k) {
                result += (n - right); // all subarrays from [left...right] to [left...n-1]
                if (nums[left] == maxVal)
                    freq--;
                left++;
            }
        }

        return result;
    }
};