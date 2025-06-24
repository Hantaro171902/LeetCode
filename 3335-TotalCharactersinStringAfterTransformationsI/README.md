You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:


	If the character is 'z', replace it with the string "ab".
	Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.


Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

 
Example 1:


Input: s = "abcyy", t = 2

Output: 7

Explanation:


	First Transformation (t = 1):

	
		'a' becomes 'b'
		'b' becomes 'c'
		'c' becomes 'd'
		'y' becomes 'z'
		'y' becomes 'z'
		String after the first transformation: "bcdzz"
	
	
	Second Transformation (t = 2):
	
		'b' becomes 'c'
		'c' becomes 'd'
		'd' becomes 'e'
		'z' becomes "ab"
		'z' becomes "ab"
		String after the second transformation: "cdeabab"
	
	
	Final Length of the string: The string is "cdeabab", which has 7 characters.



Example 2:


Input: s = "azbk", t = 1

Output: 5

Explanation:


	First Transformation (t = 1):

	
		'a' becomes 'b'
		'z' becomes "ab"
		'b' becomes 'c'
		'k' becomes 'l'
		String after the first transformation: "babcl"
	
	
	Final Length of the string: The string is "babcl", which has 5 characters.



 
Constraints:


	1 <= s.length <= 105
	s consists only of lowercase English letters.
	1 <= t <= 105

 # 🔁 Transformation Rule
 - If a character is `z`, replace it with "ab".
 - Otherwise, replace it with the **next character** in the alphabet (e.g., `'a' -> 'b'`, `'y' -> 'z'`).

# 🧠 Approach
We split the solution into 2 parts:

## 1. Brute-Force Simulation
Used to build the **intermediate transformed strings** (for small `t`).
```c++
string transformString(const string& s);
```
Loops over each character:
- If `'z'` -> add `"ab"`
- Else -> add `c + 1`

## 2. Counting-Based Optimization
Used to calculate the **final string length** efficiently after `t` transformations.
```c++
int lengthAfterTransformations(string s, int t);
```
- Uses a **frequency array** `count[26]` to track number of occurences of each letter.
- Simulates transformations on the counts instead of building the string.
- Efficient even for large `t`.

# ⚡ Time & Space Complexity
| Part | Time Complexity | Space Complexity |
| --- | --- | --- |
| Brute-force transformation | O(n * 2^t) | O(n * 2^t) |
| Count-based length | O(26 * t) | O(26) |

# ☑️ Code 
``` c++

const int MOD = 1e9 + 7;

string transformString(const string& s) {
	string result;
	for (char c : s) {
		if (c == 'z') {
			result += "ab";  // 'z' transforms to 'a' and 'b'
		} else {
			result += c + 1; // other characters transform to the next character
		}
	}
	return result;
}

int lengthAfterTransformations(string s, int t) {
	vector<long long> count(26, 0);
	for (char c : s) {
		count[c - 'a']++;
	}
	
	while (t--) {
		vector<long long> next(26, 0);
		for (int i = 0; i < 26; ++i) {
			if (i == 25) {	// 'z'
				next[0] = (next[0] + count[25]) % MOD;	// 'a'
				next[1] = (next[1] + count[25]) % MOD;	// 'b'
			} else {
				next[i + 1] = (next[i + 1] + count[i]) % MOD;
			}
		}
		count = next;
	}
	
	long long result = 0;
	for (int i = 0; i < 26; ++i)  {
		result = (result + count[i]) % MOD;
	}
	
	return result;
}
```

# ✅ Result
![image](https://github.com/user-attachments/assets/50890e5b-53b8-4aad-9818-1b19fa6cd72f)



