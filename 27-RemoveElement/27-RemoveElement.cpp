// Last updated: 7/8/2025, 11:58:38 PM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
	
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i]; 	
    //			cout << k << endl;
            } 
    //		else {
    //			nums.erase(remove(nums.begin(), nums.end(), i), nums.end());
    //			cout << i << endl;
    //		}
        }
        return k;
    }
};