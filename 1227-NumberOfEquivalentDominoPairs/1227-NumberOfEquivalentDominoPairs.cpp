// Last updated: 7/8/2025, 11:58:20 PM
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        vector<int> freg(100, 0);
        
        for (const auto& domino : dominoes) {
            int minVal = min(domino[0], domino[1]);
            int maxVal = max(domino[0], domino[1]);
            freg[minVal * 10 + maxVal]++;
        }
        
        for (const auto& f : freg) {
            count += f * (f - 1) / 2;
        }
        
        return count;
    }
};