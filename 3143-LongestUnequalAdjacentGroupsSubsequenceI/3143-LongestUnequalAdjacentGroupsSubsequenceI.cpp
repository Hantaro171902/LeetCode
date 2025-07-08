// Last updated: 7/8/2025, 11:57:44 PM
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