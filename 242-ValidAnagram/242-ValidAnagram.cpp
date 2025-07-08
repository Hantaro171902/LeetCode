// Last updated: 7/8/2025, 11:58:27 PM
class Solution {
public:
    bool isAnagram(string s, string t) {
        //  if (s.length() != t.length()) {
		//         return false;
		//     }
		    
			sort(s.begin(), s.end());
			sort(t.begin(), t.end());
			
			return (s == t);
    }
};