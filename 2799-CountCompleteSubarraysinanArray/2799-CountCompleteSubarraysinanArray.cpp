// Last updated: 5/1/2025, 4:44:36 PM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
         int n = nums.size();
    
    // Count the number of unique elements in the entire array
    unordered_set<int> allElements(nums.begin(), nums.end());
    int totalDistinct = allElements.size();
    
    int result = 0;
    unordered_map<int, int> freq;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        freq[nums[right]]++;
        
        // Shrink the window from the left while it remains "complete"
        while (freq.size() == totalDistinct) {
            result += (n - right); // All subarrays starting from `left` to `right...n-1` are complete
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]);
            }
            left++;
        }
    }
    
    return result;
    }
};