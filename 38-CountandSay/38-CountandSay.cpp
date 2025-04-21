// Last updated: 4/21/2025, 3:44:02 PM
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string result = "1";
        
        for (int i = 2; i <= n; i++) {
            string curr = "";
            int count = 1;
            
            for (int j = 1; j < result.size(); j++) {
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    curr += to_string(count) + result[j-1];
                    count = 1;
                }
            }
            
            // append the last group
            curr += to_string(count) + result.back();
            result = curr;
        }
        
        return result;
    }
};