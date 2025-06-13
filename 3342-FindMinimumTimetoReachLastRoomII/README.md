There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 
Example 1:


Input: moveTime = [[0,4],[4,4]]

Output: 7

Explanation:

The minimum time required is 7 seconds.


	At time t == 4, move from room (0, 0) to room (1, 0) in one second.
	At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.



Example 2:


Input: moveTime = [[0,0,0,0],[0,0,0,0]]

Output: 6

Explanation:

The minimum time required is 6 seconds.


	At time t == 0, move from room (0, 0) to room (1, 0) in one second.
	At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
	At time t == 3, move from room (1, 1) to room (1, 2) in one second.
	At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.



Example 3:


Input: moveTime = [[0,1],[1,2]]

Output: 4


 
Constraints:


	2 <= n == moveTime.length <= 750
	2 <= m == moveTime[i].length <= 750
	0 <= moveTime[i][j] <= 109

# 🧩 Problem
You are given a dungeon represented by a 2D grid `moveTime` of size `n x m`, where `moveTime[i][j]` indicates the earliest time in seconds when room `(i, j)` becomes accessible.

- You start from `(0, 0)` at time `t = 0`.
- You can move to any adjacent room (up, down, left, right) only after that room is open (i.e., t >= moveTime[i][j]).
- Movement time alternates: First move takes 1 second `(t = 1)`, next 2 seconds `(t = 2)`, next 1 second, and so on.
- Return the minimum time to reach the bottom-right corner `(n-1, m-1)`.

# 🧠 Approach

### 1. State Representation:
Use a min-heap (priority queue) to always expand the room reachable at the earliest time.

### 2.  Movement Pattern:
Alternate moves: 1 second, then 2 seconds, then 1, then 2, etc.
We track this with a `step index` (called `alt` in code) and calculate move cost:
```c++
int moveCost = (alt % 2 == 0) ? 1 : 2;
```

### 3. Dijkstra-like Search:
This is similar to Dijkstra's algorithm where the “weight” is determined dynamically as:
```c++
waitTime = max(moveTime[nx][ny] - currTime, 0);
nextTime = currTime + waitTime + moveCost;
```

### 4. Pruning:
If we’ve reached a cell `(x, y)` faster before, we skip the current path.

# ⚡ Time and Space Complexity
- Time: `O(n * m * log(n * m))` due to the priority queue.
- Space: `O(n * m)` for the minTime table and priority queue storage.

☑️ Code
```c++
int minTimeToReach(vector<vector<int>>& moveTime) {
    int n = moveTime.size();
    int m = moveTime[0].size();
    vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    pq.emplace(0, 0, 0, 0); // (time, x, y, move index)
    minTime[0][0] = 0;

    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int currTime = get<0>(curr);
        int x = get<1>(curr);
        int y = get<2>(curr);
        int alt = get<3>(curr);

        if (currTime > minTime[x][y]) continue;
        if (x == n - 1 && y == m - 1) return currTime;

        for (auto& dir : dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            int waitTime = max(moveTime[nx][ny] - currTime, 0);
            int moveCost = (alt % 2 == 0) ? 1 : 2;
            int nextTime = currTime + waitTime + moveCost;

            if (nextTime < minTime[nx][ny]) {
                minTime[nx][ny] = nextTime;
                pq.emplace(nextTime, nx, ny, alt + 1);
            }
        }
    }
    return -1;
}

```

## 📦Tuple in C++
`std::tuple` is a C++ feature that lets you store multiple values of different types in one object.
```c++
priority_queue<tuple<int, int, int, int>>
```

We use it to keep:
- time
- x position
- y position
- alt (number of moves so far, to alternate move cost)

We access them using:

```c++
int t = get<0>(tuple);
int x = get<1>(tuple);
...
```
This is useful when you want to push multiple values into a heap (like Dijkstra's `priority_queue`) and compare based on the first value (i.e., time).
