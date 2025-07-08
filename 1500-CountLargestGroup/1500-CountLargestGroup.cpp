// Last updated: 7/8/2025, 11:58:14 PM
class Solution {
public:
    
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> groupCount;
        int maxSize = 0;
        int count = 0;
        
        for (int i=1; i<=n; i++) {
            int sum = digitSum(i);
            groupCount[sum]++;
            maxSize = max(maxSize, groupCount[sum]);
        }
        
        for (auto& entry : groupCount) {
            if (entry.second == maxSize) {
                count++;
            }
        }
        
        return count;
    }
};