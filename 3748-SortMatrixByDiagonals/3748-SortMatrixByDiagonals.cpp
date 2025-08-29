// Last updated: 8/29/2025, 11:09:22 PM
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diag;   // key = i - j

        // 1) collect
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                diag[i - j].push_back(grid[i][j]);

        // 2) sort with required order (order along i increasing on each diagonal)
        for (auto& [k, v] : diag) {
            if (k >= 0) sort(v.begin(), v.end(), greater<int>()); // bottom-left: non-increasing
            else        sort(v.begin(), v.end());                  // top-right : non-decreasing
        }

        // 3) refill in-order (don't pop_back; keep a cursor per diagonal)
        unordered_map<int, int> ptr; // cursor for each diagonal
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                grid[i][j] = diag[i - j][ptr[i - j]++];

        return grid;
    }
};