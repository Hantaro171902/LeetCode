// Last updated: 7/8/2025, 11:57:28 PM
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));

        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        pq.emplace(0, 0, 0, 0); // (time, x, y)
        minTime[0][0] = 0;

        while (!pq.empty()) {
            // auto [currTime, x, y, alt] = pq.top();
            auto curr = pq.top();
            int currTime = get<0>(curr);
            int x = get<1>(curr);
            int y = get<2>(curr);
            int alt = get<3>(curr);

            pq.pop();

            if (currTime > minTime[x][y]) continue;
            if (x == n - 1 && y == m - 1) return currTime;

            
            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                
                int waitTime = max(moveTime[nx][ny] - currTime, 0);
                int moveCost = (alt % 2 == 0) ? 1 : 2; // alternate between 1 and 2 seconds
                int nextTime = currTime + waitTime + moveCost;
                if (nextTime < minTime[nx][ny]) {
                        minTime[nx][ny] = nextTime;
                        pq.emplace(nextTime, nx, ny, alt + 1); // increment alternate time
                }
            }
        }
        return -1;
    }
};