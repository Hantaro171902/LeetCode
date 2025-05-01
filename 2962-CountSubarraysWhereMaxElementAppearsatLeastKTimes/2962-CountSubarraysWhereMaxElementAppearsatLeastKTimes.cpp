// Last updated: 5/1/2025, 11:35:24 PM
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int x:nums)
            ans+=int(floor(log10(x))+1)%2==0;
        return ans;
    }
};