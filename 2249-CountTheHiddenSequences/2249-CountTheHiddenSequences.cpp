// Last updated: 7/8/2025, 11:58:04 PM
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long int prefix = 0, minPrefix = 0, maxPrefix = 0;
    
        for (int i : differences) {
            prefix += i;
            minPrefix = min(minPrefix, prefix);
            maxPrefix = max(maxPrefix, prefix);
        }
        
        long long int minStart = lower - minPrefix;
        long long int maxStart = upper - maxPrefix;
        
        return max(0LL, maxStart - minStart + 1);
    }
};