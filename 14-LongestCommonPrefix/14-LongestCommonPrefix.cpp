// Last updated: 4/18/2025, 3:26:27 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Sort the vector of string
        sort (strs.begin(), strs.end());

        // Compare the first and last strings in the sort list
        string first = strs.front();
        string last = strs.back();

        int minLength = min(first.size(), last.size());

        int i =0;

        // Find the common prefix between the first and last strings
        while (i < minLength && first[i] == last[i]) {
            i++;
        }

        // return the common prefix
        return first.substr(0,i);
    }
};