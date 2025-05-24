// Last updated: 5/24/2025, 1:42:19 PM
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int res = 0;
        
        for (const auto& d : dominoes) {
            // Normalize domino: min first, then max
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            int key = a * 10 + b;	// Use 2-digit key sinceq 1 <= a, b <= 9
            
            cout << a << b << key;
            
            res += count[key];	// Add of number of existing dominoes that match this one
            count[key]++;
            
        }
        
        return res;	
    }
};