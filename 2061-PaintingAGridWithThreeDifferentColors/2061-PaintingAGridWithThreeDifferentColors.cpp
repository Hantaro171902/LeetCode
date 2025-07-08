// Last updated: 7/8/2025, 11:58:11 PM

const int MOD = 1e9 + 7;

class Solution {
public:
    int colorTheGrid(int m, int n) {
        vector<vector<int>> validStates;
        vector<int> state;
        generateStates(m, 0, state, validStates);

        int sz = validStates.size();
        vector<vector<int>> compatible(sz);
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (isCompatible(validStates[i], validStates[j])) {
                    compatible[i].push_back(j);
                }
            }
        }

        vector<long long> dp(sz, 1), new_dp(sz);
        for (int col = 1; col < n; ++col) {
            fill(new_dp.begin(), new_dp.end(), 0);
            for (int i = 0; i < sz; ++i) {
                for (int j : compatible[i]) {
                    new_dp[i] = (new_dp[i] + dp[j]) % MOD;
                }
            }
            dp = new_dp;
        }

        long long result = 0;
        for (long long count : dp) {
            result = (result + count) % MOD;
        }

        return static_cast<int>(result);
    }

private:
    void generateStates(int m, int idx, vector<int>& state, vector<vector<int>>& all) {
        if (idx == m) {
            all.push_back(state);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (idx > 0 && color == state[idx - 1]) continue;
            state.push_back(color);
            generateStates(m, idx + 1, state, all);
            state.pop_back();
        }
    }

    bool isCompatible(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }
};