There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds after which the room opens and can be moved to. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 
Example 1:


Input: moveTime = [[0,4],[4,4]]

Output: 6

Explanation:

The minimum time required is 6 seconds.


	At time t == 4, move from room (0, 0) to room (1, 0) in one second.
	At time t == 5, move from room (1, 0) to room (1, 1) in one second.



Example 2:


Input: moveTime = [[0,0,0],[0,0,0]]

Output: 3

Explanation:

The minimum time required is 3 seconds.


	At time t == 0, move from room (0, 0) to room (1, 0) in one second.
	At time t == 1, move from room (1, 0) to room (1, 1) in one second.
	At time t == 2, move from room (1, 1) to room (1, 2) in one second.



Example 3:


Input: moveTime = [[0,1],[1,2]]

Output: 3


 
Constraints:


	2 <= n == moveTime.length <= 50
	2 <= m == moveTime[i].length <= 50
	0 <= moveTime[i][j] <= 109

# 🧠 Key Ideas
- Use a priority queue to always explore the next room with the smallest current time.
- Maintain a `dp` grid to store the minimum time to reach each room.
- From each room, explore all 4 adjacent directions.
For each adjacent room:
- You can only enter it if the `current time ≥ its moveTime` value.
- Add 1 second to represent the time it takes to move into that room.
- Use `max(moveTime[nx][ny], curTime)` + 1 to ensure you're respecting the earliest opening time.

# ⚡Time Complexity
- Time Complexity: `O(n * m * log(n * m))`
Each cell is pushed into the priority queue once, and heap operations cost log(n * m).

- Space Complexity: `O(n * m)`
For dp table and the heap.

# ☑️ Code
``` c++
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
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && dp[nx][ny] == INT_MAX) {
                int nextTime = max(moveTime[nx][ny], curTime) + 1;
                pq.push({nextTime, nx, ny});
            }
        }
    }
    return -1;
}

```



