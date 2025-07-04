// Last updated: 7/4/2025, 11:52:15 PM
class Solution {
public:
        
    bool differByOneChar(const string& a, const string& b) {
        if (a.length() != b.length()) return false;
        int diffCount = 0;
        for (size_t i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) {
                diffCount++;
                if (diffCount > 1) return false;
            }
        }
        return diffCount == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<int> dp(n, 1), parent(n, -1);
        int maxGroup = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && 
                        differByOneChar(words[i], words[j]) && 
                            dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            maxGroup = max(maxGroup, dp[i]);
        }
        

        vector<string> result;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxGroup) {
                int index = i;
                while (index != -1) {
                    result.push_back(words[index]);
                    index = parent[index];
                }
                break;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};