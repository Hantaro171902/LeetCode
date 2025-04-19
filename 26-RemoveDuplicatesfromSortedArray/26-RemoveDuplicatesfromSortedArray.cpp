// Last updated: 4/19/2025, 10:08:29 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
                
            
        sort(nums.begin(), nums.end()); // Optional if input is not sorted
        auto k = unique(nums.begin(), nums.end());
        nums.erase(k, nums.end());
        return nums.size(); // Now the size matches unique elements
    }

};