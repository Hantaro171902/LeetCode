// Last updated: 4/19/2025, 10:19:41 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            
        if (nums.empty()) return 0;
        
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[k] = nums[i]; 	// overwrite the unique value in k
                k++;
                
                // cout << k << " ";
            } 
    //		else {
    //			cout << k << " ";
    //		}
        }
        return k;
    }

};