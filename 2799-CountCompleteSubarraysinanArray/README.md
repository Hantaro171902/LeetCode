You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:


	The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.


Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

 
Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].


Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.

### ✅ In an array of size n, the number of contiguous non-empty subarrays is:

$`\frac{ n * (n + 1)} { 2} `$ 

### 🔢 Complete Subarrays:

- Length 1: [5], [5], [5], [5] → 4 subarrays
- Length 2: [5,5], [5,5], [5,5] → 3 subarrays
- Length 3: [5,5,5], [5,5,5] → 2 subarrays
- Length 4: [5,5,5,5] → 1 subarray
→ Total = 4 + 3 + 2 + 1 = 10

Constraints:


	1 <= nums.length <= 1000
	1 <= nums[i] <= 2000

# 💡 Problem Summary
Given an array of positive integers, count the number of complete subarrays, where a complete subarray is defined as a subarray that contains all the distinct elements present in the entire array.

# ✅ Approach 1: Brute-force with Hash Set
## 🧠 Idea
- Count how many distinct elements exist in the entire array (k).
- Iterate over all possible subarrays using two nested loops.
- For each subarray, use a ```set``` to track its distinct elements.
- If the subarray contains exactly ```k``` distinct elements, it is considered complete, so we increment our result counter.

## ⚡Time Complexity
- ```O(n²)```: Two nested loops to generate all subarrays.
- ```O(n)``` per subarray (in the worst case) to maintain the set of distinct elements.
So, total complexity is ```O(n³)``` in the worst case. Acceptable for small n.

## ☑️ Code 
```c++
int countCompleteSubarrays(vector<int>& nums) {
    // Step 1: Get the total number of distinct elements in the full array
    int k = unordered_set<int>(nums.begin(), nums.end()).size();
    int res = 0;

    // Step 2: Try every possible subarray
    for (int i = 0; i < nums.size(); i++) {
        unordered_set<int> st;
        for (int j = i; j < nums.size(); j++) {
            st.insert(nums[j]); // Track distinct elements in current subarray
            if (st.size() == k) // If this subarray is complete
                res++;
        }
    }

    return res;
}
```

# ✅ Approach 2: Using sliding window and hashing
##⚡Time Complexity:

O(n) on average (amortized): Each element is processed at most twice (once entering the window, once leaving).

Much faster than brute-force ```O(n²)```

## ☑️ Code 

```c++
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    
    // Count the number of unique elements in the entire array
    unordered_set<int> allElements(nums.begin(), nums.end());
    int totalDistinct = allElements.size();
    
    int result = 0;
    unordered_map<int, int> freq;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        freq[nums[right]]++;
        
        // Shrink the window from the left while it remains "complete"
        while (freq.size() == totalDistinct) {
            result += (n - right); // All subarrays starting from `left` to `right...n-1` are complete
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]);
            }
            left++;
        }
    }
    
    return result;
}
```
