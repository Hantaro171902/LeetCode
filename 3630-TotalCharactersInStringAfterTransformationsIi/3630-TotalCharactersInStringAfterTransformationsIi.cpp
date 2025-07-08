// Last updated: 7/8/2025, 11:57:29 PM
class Solution {
public:
    const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix& a, Matrix& b) {
        int n = a.size();
        Matrix res(n, vector<long long>(n));
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k)
                for (int j = 0; j < n; ++j)
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
        return res;
    }

    Matrix matrixExpo(Matrix base, long long power) {
        int n = base.size();
        Matrix res(n, vector<long long>(n));
        for (int i = 0; i < n; ++i) res[i][i] = 1;
        while (power) {
            if (power & 1) res = multiply(res, base);
            base = multiply(base, base);
            power >>= 1;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n = 26;

        // Frequency vector of characters in s
        vector<long long> freq(n);
        for (char c : s)
            freq[c - 'a']++;

        // Build transformation matrix
        Matrix T(n, vector<long long>(n));
        for (int i = 0; i < n; ++i) {
            int cnt = nums[i];
            for (int j = 1; j <= cnt; ++j) {
                int next = (i + j) % 26;
                T[next][i] = (T[next][i] + 1) % MOD;
            }
        }

        // Raise T to the power t
        Matrix T_pow = matrixExpo(T, t);

        // Multiply T^t with freq vector
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long total = 0;
            for (int j = 0; j < n; ++j)
                total = (total + T_pow[i][j] * freq[j]) % MOD;
            result = (result + total) % MOD;
        }

        return result;
    }
};