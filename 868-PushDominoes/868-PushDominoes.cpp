// Last updated: 7/8/2025, 11:58:23 PM
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string result = dominoes;
        int left = -1;

        for (int i = 0; i <= n; ++i) {
            char curr = (i < n ? result[i] : 'R');  // Add a virtual 'R' at end to flush pending
            if (curr == '.') continue;

            if (left == -1) {
                // Handle from start to first force
                if (curr == 'L') {
                    for (int j = 0; j < i; ++j)
                        result[j] = 'L';
                }
            } else {
                char prev = result[left];
                if (prev == 'R' && curr == 'L') {
                    int l = left + 1, r = i - 1;
                    while (l < r) {
                        result[l++] = 'R';
                        result[r--] = 'L';
                    }
                } else if (prev == 'R' && curr == 'R') {
                    for (int j = left + 1; j < i; ++j)
                        result[j] = 'R';
                } else if (prev == 'L' && curr == 'L') {
                    for (int j = left + 1; j < i; ++j)
                        result[j] = 'L';
                }
            }
            left = i;
        }

        return result;
    }
};