// Last updated: 8/22/2025, 9:55:44 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};