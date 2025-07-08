// Last updated: 7/8/2025, 11:58:30 PM
class Solution {
public:
        
    string trimLeadingZero(const string &s) {
        
        // Find the position of the first '1'
        size_t firstOne = s.find('1');
        return (firstOne == string::npos) ? "0" : s.substr(firstOne);
    }

    string addBinary(string a, string b) {

        // Trim leading zeros
        a = trimLeadingZero(a);
        b = trimLeadingZero(b);
        
        int n = a.size();
        int m = b.size();
        
        // swap the strings if a is of smaller length
        if (n < m) {
            return addBinary(b, a);
        } 
        
        int j = m - 1;
        int carry = 0;
        
        // Traverse both strings from the end
        for (int i = n - 1; i >= 0; i--) {
            
            // Current bit of a
            int bit1 = a[i] - '0';
            int sum = bit1 + carry;
            
            // If there are remaining bits in b, add them to sum
            if (j >= 0) {
                
                // Current bit of b
                int bit2 = b[j] - '0';
                sum += bit2;
                j--;
            }
            
            // Calculate the result bit and update carry
            int bit = sum % 2;
            carry = sum / 2;
            
            // Update the current bit in a
            a[i] = (char)(bit + '0');
        }
        
        // If there's any carry left, update a
        if (carry > 0) {
            a = '1' + a;
        }
        
        return a;
    } 
};