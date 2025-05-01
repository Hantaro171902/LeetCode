You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 
Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].


Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.


 
Constraints:


	1 <= nums.length <= 105
	1 <= nums[i] <= 106
	1 <= k <= 105

## ✅ Approach: Sliding Window

Let’s break down the steps:
- Find the maximum element in the array `(maxVal)`.
- Use a sliding window with two pointers `left` and `right`.
- Move `right` to expand the window.
- Keep track of how many times `maxVal` appears in the current window.
- If it appears at least `k` times, all subarrays from `left` to `right` are valid.
- Shrink the window from the left to find all valid subarrays.

## 🧠 Key Insight

Once a subarray `[left, right]` contains k instances of maxVal, every subarray starting at `left...right` and ending at `right...n-1` will be valid.
So we can count `n - right` subarrays starting at `left`.

## ⚡ Time complexity
`O(n)`: each element is visited at most twice (once by right, once by `left`).

## ☑️ Code 
```c++

long long countSubarrays(vector<int>& nums, int k) {
	
    int n = nums.size();
    int maxVal = *max_element(nums.begin(), nums.end());
    long long result = 0;

    const int MAX_PRINT = 1000; // Prevent printing too many
    int printCount = 0;

    for (int start = 0; start < n; start++) {
        int maxFreq = 0;
        for (int end = start; end < n; end++) {
            if (nums[end] == maxVal) maxFreq++;

            if (maxFreq >= k) {
                result++;

                if (printCount < MAX_PRINT) {
                    // Print subarray or its indices
                    cout << "Subarray [" << start << "-" << end << "]: ";
                    for (int i = start; i <= end; i++) {
                        cout << nums[i] << ", ";
                    }
                    cout << "\n";
                    printCount++;
                }
            }
        }
    }

    if (printCount >= MAX_PRINT) {
        cout << "...(truncated printing after " << MAX_PRINT << " subarrays)\n";
    }

    return result;
}

```
