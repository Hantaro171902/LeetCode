// Last updated: 4/21/2025, 1:49:01 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // skip trailing spaces (hello    wo rl)
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // find the end of last word
        // int end = i;
        
        // count the length of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};