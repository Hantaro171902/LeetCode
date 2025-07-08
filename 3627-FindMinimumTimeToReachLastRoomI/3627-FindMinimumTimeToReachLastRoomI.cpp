// Last updated: 7/8/2025, 11:57:33 PM
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        pq.push({0, 0, 0}); // (time, x, y)
        moveTime[0][0] = 0;

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int curTime = current[0];
            int x = current[1];
            int y = current[2];

            if (curTime >= dp[x][y]) continue;
            if (x == n - 1 && y == m - 1) return curTime;
            dp[x][y] = curTime;

            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && ny >= 0 && 
                    nx < n && ny < m && 
                    dp[nx][ny] == INT_MAX) {
                        int nextTime = max(moveTime[nx][ny], curTime) + 1;
                        pq.push({nextTime, nx, ny});
                }
            }
        }

        return -1;
    }
};