// Last updated: 7/1/2025, 11:10:07 PM
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int prevGroup = -1;

        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] != prevGroup) {
                res.push_back(words[i]);
                prevGroup = groups[i];
            }
        }
        return res;
    }
};