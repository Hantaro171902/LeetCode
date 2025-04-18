// Last updated: 4/18/2025, 6:59:56 PM
class Solution {
public:
    int romanToInt(string s) {
            
            
                
        int total = 0;

        // Create an unordered_map
        unordered_map<char, int> map;
        
        // Insert key-value pairs into the unordered_map
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        
        for (int i=0; i<s.length(); i++) {
        
                    
            if (map[s[i]] < map[s[i+1]]) {
                total -= map[s[i]];	// If the current num smaller than the next num (IV = 5 - 1)
                //cout << total << endl;;
            } else {
                total += map[s[i]];	// Add otherwise
                //cout << total << endl;
            }
            
            // cout << prev << endl;
        }
        return total;

    }
};