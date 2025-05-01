// Last updated: 5/1/2025, 9:00:11 PM
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 1; i < n - 1; i++) {
            // middle = nums[i], check if sum of first and third == half of middle
            int first = nums[i - 1], middle = nums[i], third = nums[i + 1];
            if (middle % 2 == 0 && (first + third) * 2 == middle) {
                cout << "[" << first << "," << middle << "," << third << "]\n";
                count++;
            }
        }
        return count;
    }
};