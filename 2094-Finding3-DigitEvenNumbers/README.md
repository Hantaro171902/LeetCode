You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:


	The integer consists of the concatenation of three elements from digits in any arbitrary order.
	The integer does not have leading zeros.
	The integer is even.


For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

 
Example 1:

Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array. 
Notice that there are no odd integers or integers with leading zeros.


Example 2:

Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits. 
In this example, the digit 8 is used twice each time in 288, 828, and 882. 


Example 3:

Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.


 
Constraints:


	3 <= digits.length <= 100
	0 <= digits[i] <= 9

# ❕Requirements
- The number must be **three digits**
- No **leading zero** (e.g., `012` is not valid).
- The number must be **even** (last digit must be 0, 2, 4, 6, 8).
- Use only unique combinations of indices: no repeat.
- The digits **may contain duplicates**, but you only return **unique numbers**.

# 🧠 Approach
This code use **brute-force generation** of all possible 3-digit numbers using 3 different indices from the input array.

## Step 1: Base Case and Sort
```c++
if (digits.size() < 3) return result;
sort(digits.begin(), digits.end());
```
- If there are fewer than 3 digits, it's impossible to form a 3-digit number.
- Sorting helps produce results in **increasing order** later.

## Step 2: Triple Nested Loop
```c++
for (int i = 0; i < n; ++i) {
	if (digits[i] == 0) continue; // Skip leading zero
	for (int j = 0; j < n; ++j) {
		if (i == j) continue;
		for (int k = 0; k < n; ++k) {
			if (i != j && i != k && j != k) {
```
This part iterates over **every combination of three different indices** `(i, j, k)` from the input digits.

## Step 3: Filter Invalid Cases
``` c++
int a = digits[i];
int b = digits[j];
int c = digits[k];
```
Then it checks:
- ✅ `a` should not be zero (no leading zero).
- ✅ `c` (last digit) should be even.

## Step 4: Add Valid Number
```c++
int number = a * 100 + b * 10 + c;
result.push_back(number);
```

## Step 5: Sort and Return
```c++
sort(result.begin(), result.end());
return result;
```
Sorts the resulting number and returns them. Note that **duplicates are not removed**, which can be improved.

# ⚡ Time & Space Complexity
| Complexity | Discription |
| --- | --- |
| Time | O(n³ + n log n) |
| Space | O(n³) in the worst case |

# ☑️ Code
```c++
vector<int> findEvenNumbers(vector<int>& digits) {
	vector<int> result;
	
	int n = digits.size();
	if (n < 3) return result; // Not enough digits to form a 3-digit number
	sort(digits.begin(), digits.end());

	for (int i = 0; i < n; ++i) {
		if (digits[i] == 0) continue; // Skip leading zero
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			for (int k = 0; k < n; ++k) {
				// Make sure indices are not the same
				if (i != j && i != k && j != k) {
					int a = digits[i];
					int b = digits[j];
					int c = digits[k];

					// Leading zero check
					if (a == 0) continue;

					// Check even number
					if (c % 2 != 0) continue;

					int number = a * 100 + b * 10 + c;
					result.push_back(number);
				}
			}
		}
	}

	sort(result.begin(), result.end());
	return result;
}
```

# ✅ Result 
![image](https://github.com/user-attachments/assets/2177c3b1-d92f-4094-8938-28a551fd00bd)


