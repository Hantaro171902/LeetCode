// Last updated: 8/29/2025, 11:10:01 PM
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);
        
        int row = 0, col = 0;
        bool upward = true;
        
        while (result.size() < m * n) {
            result.push_back(mat[row][col]);
            
            if (upward) {
                if (col == n - 1) { // reached last column
                    row++;
                    upward = false;
                } else if (row == 0) {	// reached first row
                    col++;
                    upward = false;
                } else {
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) {	// reached last row
                    col++;
                    upward = true;
                } else if (col == 0) {	// reached first column
                    row++;
                    upward = true;
                } else {
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
};