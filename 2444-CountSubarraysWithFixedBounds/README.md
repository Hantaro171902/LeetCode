You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:


	The minimum value in the subarray is equal to minK.
	The maximum value in the subarray is equal to maxK.


Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

 
Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].


Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.


 
Constraints:


	2 <= nums.length <= 105
	1 <= nums[i], minK, maxK <= 106


---

## ✅ Solution

The program uses a **single-pass sliding window** strategy to maintain:
- `start`: the last index where an invalid number was found
- `mini`: the last index of a number equal to `minK`
- `maxi`: the last index of a number equal to `maxK`

For each position `i`:
1. If the current number is invalid (`< minK` or `> maxK`), we reset the window.
2. If it equals `minK` or `maxK`, update `mini` or `maxi`.
3. If both `minK` and `maxK` exist in a valid range, we:
   - Count all valid subarrays ending at index `i`
   - Print the fixed-bound subarrays

---

## 🧠 Time Complexity

- Time: `O(n)` — single pass through the array with constant-time updates.
- Space: `O(1)` — uses only a few variables.

## ☑️ Code 
```c++

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
	long count = 0, start = -1, mini = -1, maxi = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) start = i;
            if (nums[i] == maxK) maxi = i;
            if (nums[i] == minK) mini = i;
            // The earliest valid subarray ends at i and starts after leftBound
            int validStart = min(mini, maxi);
            if (validStart > start) {
                count += validStart - start;
                
                // Print the subarrays
                for (int j = validStart; j > start; j--) {
                	cout << "[";
                	for (int k = validStart; k <= i; k++) {
                		cout << nums[k];
                		if (k < i) cout << ",";
					}
					cout << "]" << endl;
				}
            }
        }
    return count;
}

```
