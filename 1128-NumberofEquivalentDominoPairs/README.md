Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

 
Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1


Example 2:

Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3


 
Constraints:


	1 <= dominoes.length <= 4 * 104
	dominoes[i].length == 2
	1 <= dominoes[i][j] <= 9

# 🧠 Approach 
The key idea is to normalize each domino so that [a, b] and [b, a] are treated the same. We use:
```c++
int code = min(a, b) * 10 + max(a, b)
```

This ensures [1,2] and [2,1] both map to 12.
- Use a frequency array of size 100 to store the count of each normalized domino.
- For each frequency f, compute the number of pairs as `f * (f - 1) / 2.`
- Sum over all frequencies to get the final answer.

# ⚡ Time and Space Complexity
- Time Complexity: `O(n)`, where n is the number of dominoes.
- Space Complexity: `O(1)`, fixed size array (100 elements).

# ✅ Solution 
- At first I want to use `sum[a,b]` to check a pair but here is why that is not working 
## ⚠️ Why Sum Is Not a Valid Optimization ?

Let’s look at a counterexample:
- Domino `[1, 2]` → sum = 3
- Domino `[3, 0]` → sum = 3

Clearly:
`[1, 2]` and `[2, 1]` are equivalent ✅
`[1, 2]` and `[3, 0]` are not equivalent ❌

## ⚠️ Why Using min * 10 + max Works ?
The approach:
```cpp
int key = min(a, b) * 10 + max(a, b);
```
Ensures:
- `[1, 2]` and `[2, 1]` → both give 12
- `[3, 0]` → gives 3

So the encoding is both unique and rotationally consistent.
But if you only compare by `sum = 3`, you'd incorrectly group them together.

# ☑️ Code 

```c++
#include <vector>
#include <algorithm>
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int count = 0;
    vector<int> freg(100, 0);  // Frequency array for domino codes

    for (const auto& domino : dominoes) {
        int minVal = min(domino[0], domino[1]);
        int maxVal = max(domino[0], domino[1]);
        freg[minVal * 10 + maxVal]++;	// Normalize and count
    }

    for (const auto& f : freg) {
        count += f * (f - 1) / 2;
    }

    return count;
}
```


