// Last updated: 12/29/2025, 10:16:49 PM
1class Solution {
2public:
3    int countNegatives(vector<vector<int>>& grid) {
4        int m = grid.size(), n = grid[0].size();
5        int i = m - 1; // row
6        int j = 0;	// col
7        
8        int res = 0;
9        
10        while (i >= 0 && j < n) {
11            if (grid[i][j] < 0) {
12                res += n - j;
13                i--;
14            } else {
15                j++;
16            }
17        }
18        
19        return res;
20    }
21};