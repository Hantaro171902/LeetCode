// Last updated: 6/24/2025, 9:40:51 PM
class Solution {
public:
    const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        while (t--) {
            vector<long long> next(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (i == 25) {	// 'z'
                    next[0] = (next[0] + count[25]) % MOD;	// 'a'
                    next[1] = (next[1] + count[25]) % MOD;	// 'b'
                } else {
                    next[i + 1] = (next[i + 1] + count[i]) % MOD;
                }
            }
            count = next;
        }
        
        long long result = 0;
        for (int i = 0; i < 26; ++i)  {
            result = (result + count[i]) % MOD;
        }
        
        return result;
    }

};