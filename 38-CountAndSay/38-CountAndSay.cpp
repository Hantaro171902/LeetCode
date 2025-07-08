// Last updated: 7/8/2025, 11:58:35 PM
class Solution {
public:
string rle(const string& s) {
        string result;
        int count = 1;
        for (size_t i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                result += to_string(count) + s[i - 1];
                count = 1;
            }
        }
        result += to_string(count) + s.back();
        return result;
    }
    string countAndSay(int n) {
        if (n == 1) return "1";
        return rle(countAndSay(n-1));
        
    }
};