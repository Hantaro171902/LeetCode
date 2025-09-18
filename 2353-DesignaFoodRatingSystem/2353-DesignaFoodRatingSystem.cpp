// Last updated: 9/18/2025, 9:24:29 PM
class Solution {
public:

    vector<int> getNoZeroIntegers(int n) {
        for (int A = 1; A < n; A++) {
            int B = n - A;
            if ((to_string(A) + to_string(B)).find('0') == string::npos) {
                return {A, B};
            }
        }
        return {};
    }
};