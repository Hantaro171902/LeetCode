You are given a 0-indexed array of n integers differences, which describes the differences between each pair of consecutive integers of a hidden sequence of length (n + 1). More formally, call the hidden sequence hidden, then we have that differences[i] = hidden[i + 1] - hidden[i].

You are further given two integers lower and upper that describe the inclusive range of values [lower, upper] that the hidden sequence can contain.


	For example, given differences = [1, -3, 4], lower = 1, upper = 6, the hidden sequence is a sequence of length 4 whose elements are in between 1 and 6 (inclusive).

	
		[3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.
		[5, 6, 3, 7] is not possible since it contains an element greater than 6.
		[1, 2, 3, 4] is not possible since the differences are not correct.
	
	


Return the number of possible hidden sequences there are. If there are no possible sequences, return 0.

 
Example 1:

Input: differences = [1,-3,4], lower = 1, upper = 6
Output: 2
Explanation: The possible hidden sequences are:
- [3, 4, 1, 5]
- [4, 5, 2, 6]
Thus, we return 2.


Example 2:

Input: differences = [3,-4,5,1,-2], lower = -4, upper = 5
Output: 4
Explanation: The possible hidden sequences are:
- [-3, 0, -4, 1, 2, 0]
- [-2, 1, -3, 2, 3, 1]
- [-1, 2, -2, 3, 4, 2]
- [0, 3, -1, 4, 5, 3]
Thus, we return 4.


Example 3:

Input: differences = [4,-7,2], lower = 3, upper = 6
Output: 0
Explanation: There are no possible hidden sequences. Thus, we return 0.


 
Constraints:


	n == differences.length
	1 <= n <= 105
	-105 <= differences[i] <= 105
	-105 <= lower <= upper <= 105

# 💡 Strategy

Let’s say the hidden sequence starts with some value ```x```. Then the rest of the sequence is:

```c++
x,
x + differences[0],
x + differences[0] + differences[1],
...

```

That means each element is:
```c++
a[i] = x + prefix_sum[i]
```
- ```prefix_sum[i]``` is the sum of differences from index 0 up to i - 1 in the differences array.

```c++
prefix_sum[i] = differences[0] + differences[1] + ... + differences[i - 1]
```
It represents how much we have to add or subtract from the first value ```x``` to get the value at position ```i```.

So, the full hidden sequence looks like:

| i |	Formula |	Value |
|---|-----------|-------------|
| 0 |	a[0] = x |	Starting value |
| 1 |	a[1] = x + differences[0] |	x + prefix_sum[1] |
| 2 |	a[2] = x + differences[0] + differences[1] |	x + prefix_sum[2] |
| 3 |	a[3] = x + differences[0] + differences[1] + differences[2] |	x + prefix_sum[3] |

# 🧾 Example

```c++
differences = [1, -3, 4]
```
We build the prefix sums step by step:

- prefix_sum[0] = 0 (no difference yet)
- prefix_sum[1] = 1 (just differences[0])
- prefix_sum[2] = 1 + (-3) = -2
- prefix_sum[3] = -2 + 4 = 2

So:
- a[0] = x
- a[1] = x + 1
- a[2] = x - 2
- a[3] = x + 2

Each element is just the first value plus the total of the differences up to that point.
<hr>

To ensure all values in the sequence stay within [lower, upper], we need:

```c++
lower ≤ x + prefix_sum[i] ≤ upper
=> lower - prefix_sum[i] ≤ x ≤ upper - prefix_sum[i]
```

# 🧠 Final Formula 
Let:


- min_prefix_sum = minimum prefix sum (can be negative)
- max_prefix_sum = maximum prefix sum

Then the valid range for x is:

```c++
[lower - min_prefix_sum, upper - max_prefix_sum]
```

And the count of valid starting values is:

```c++
max(0, (upper - max_prefix_sum) - (lower - min_prefix_sum) + 1)
```

# ✅ Solution

```c++
int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long int prefix = 0, minPrefix = 0, maxPrefix = 0;
    
    for (int i : differences) {
    	prefix += i;
    	minPrefix = min(minPrefix, prefix);
    	maxPrefix = max(maxPrefix, prefix);
	}
	
	long long int minStart = lower - minPrefix;
	long long int maxStart = upper - maxPrefix;
	
	return max(0LL, maxStart - minStart + 1);
}
```
