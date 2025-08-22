// Last updated: 8/22/2025, 9:50:43 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        int e = log(INT_MAX) / log(3);
        int N = pow(3, e);
        return n > 0 && N%n == 0;
    }
};