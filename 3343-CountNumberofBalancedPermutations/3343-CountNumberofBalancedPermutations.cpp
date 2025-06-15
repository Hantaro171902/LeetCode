// Last updated: 6/16/2025, 12:14:45 AM
class Solution {
    static const int MOD = 1e9 + 7;
    vector<int> fact, inv, invFact;
    
void precomputeFactorials(int n) {
	fact.assign(n + 1, 1);
	inv.assign(n + 1, 1);
	invFact.assign(n + 1, 1);

	for (int i = 1; i <= n; ++i) {
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
	}

	inv[n] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] = MOD - 1LL * (MOD / i) * inv[MOD % i] % MOD;
	}

	for (int i = 1; i <= n; ++i) {
		invFact[i] = (1LL * invFact[i - 1] * inv[i]) % MOD;
	}
}

public:
    int countBalancedPermutations(const string& s) {
        int n = s.size(), sum = 0;
        for (char c : s) {
            sum += c - '0';
        }

        if (sum % 2 == 1) return 0; // If the sum is odd, no balanced permutation is possible

        precomputeFactorials(n);
        int halfSum = sum / 2;
        int halfLen = n / 2;

        vector<vector<int>> dp(halfSum + 1, vector<int>(halfLen + 1, 0));
        dp[0][0] = 1; // Base case: one way to form sum 0 with length 0

        vector<int> digits(10, 0);
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            digits[d]++;
            for (int j = halfSum; j >= d; --j) {
                for (int k = halfLen; k >= 1; --k) {
                    dp[j][k] = (dp[j][k] + dp[j - d][k - 1]) % MOD;
                }
            }
        }

        int result = dp[halfSum][halfLen];
        result = (1LL * result * fact[halfLen]) % MOD; // Multiply by the number of ways to arrange halfLen digits
        result = (1LL * result * fact[n - halfLen]) % MOD; // Divide by the number of ways to arrange the digits in each half

        for (int cnt : digits) {
            result = (1LL * result * invFact[cnt]) % MOD; // Divide by the factorial of each digit count
        }

	return result;
    }
};