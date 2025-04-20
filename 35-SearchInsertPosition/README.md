Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 
Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2


Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1


Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


 
Constraints:


	1 <= nums.length <= 104
	-104 <= nums[i] <= 104
	nums contains distinct values sorted in ascending order.
	-104 <= target <= 104
===
# 🧠 Ideas
- Sort the input in order
- Find the insert position
- Print out the output

# ✅ Solution
1. Function searchInsert()

```c++
int searchInsert(vector<int>& nums, int target) {
	int k = 1;
	
	sort(nums.begin(), nums.end());
	
	for (int i=0; i<nums.size(); i++) {
		if (nums[i] >= target) 
			return i;		
	}
	return nums.size();
}
```
2. Function printOutput()

In C++, the vector insert() is a built-in function used to insert new elements at the given position in a vector. In this article, we will learn about the vector insert() function in C++.
[GreekforGreek](https://www.geeksforgeeks.org/vector-insert-function-in-cpp-stl/)

```c++
void printOutput(vector<int>& nums, int target) {
	int insertPos = searchInsert(nums, target);
	
	// Insert at correct posistion
	nums.insert(nums.begin() + insertPos, target);
	
	// Print in order
	for (int i=0; i<nums.size(); i++) {
		cout << nums[i] << " ";
	}
}

```

