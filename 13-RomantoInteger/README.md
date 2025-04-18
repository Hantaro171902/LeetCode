Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:


	I can be placed before V (5) and X (10) to make 4 and 9. 
	X can be placed before L (50) and C (100) to make 40 and 90. 
	C can be placed before D (500) and M (1000) to make 400 and 900.


Given a roman numeral, convert it to an integer.

 
Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.


Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.


Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


 
Constraints:


	1 <= s.length <= 15
	s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
	It is guaranteed that s is a valid roman numeral in the range [1, 3999].

# 🧠 Algorithm Idea
- Using a loop
- Using a Map to store the value of Roman into Integer
- Compare the current value with the next value [if smaller (-), if bigger (+)]
- Store in a total variable and print it

# ✅ Solution
1. Using unordered_map

```unordered_map``` is a built-in C++ Standard Library container that stores key-value pairs and allows fast lookups, insertion, and deletion using hashing (just like a HashMap in Java).

```c++
	unordered_map<char, int> map;
	
	// Insert key-value pairs into the unordered_map
	map['I'] = 1;
	map['V'] = 5;
	map['X'] = 10;
	map['L'] = 50;
	map['C'] = 100;
	map['D'] = 500;
	map['M'] = 1000;
```

2. Time Complexity:

Insert / Access / Delete: Average case O(1)





