// Last updated: 7/8/2025, 11:57:48 PM
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> freq;
        freq[0] = 1; // base case for full prefix match
        int prefix = 0;
        long long res = 0;

        for (int num : nums) {
            // increment prefix if condition met
            if (num % modulo == k) {
                prefix++;
            }

            // current prefix mod value
            int modVal = prefix % modulo;
            // look for previous prefix mod that satisfies the condition
            int target = (modVal - k + modulo) % modulo;

            if (freq.count(target)) {
                res += freq[target];
            }

            // update frequency map
            freq[modVal]++;
        }
        return res;
    }
};