// Last updated: 8/22/2025, 9:50:16 PM
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;
        
        // scan the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // update the boundaries
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j); 
                }
            }
        }
        
        // compute area
        if (maxRow == -1) {
            // no 1s found
            return 0;
        }
        
        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;
        
        return height * width;
    }
};