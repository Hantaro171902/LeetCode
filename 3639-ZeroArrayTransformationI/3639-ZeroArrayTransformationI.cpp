// Last updated: 8/5/2025, 11:17:03 PM
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> count(n + 1, 0); // difference

        // Apply range increment using different array
        for (const auto &q : queries)
        {
            int l = q[0], r = q[1];
            count[l]++;
            if (r + 1 < n)
                count[r + 1]--;
        }

        // Build the prefix sum to get actual decrement counts
        for (int i = 1; i < n; i++)
        {
            count[i] += count[i - 1];
        }

        // Check if nums[i] <= count[i] for all i
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > count[i])
            {
                return false;
            }
        }

        return true;
    }
};