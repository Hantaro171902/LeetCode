// Last updated: 4/21/2025, 11:23:37 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        
        for(int i = length - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }
        
        vector<int> newDigits(length + 1, 0);
        newDigits[0] = 1;
        return newDigits;
        }
};